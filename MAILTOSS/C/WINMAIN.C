/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINMAIN.C - Application entry point.
**
******************************************************************************
*/

#include "af.h"
#include <dos.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <nwcalls.h>
#include <lzexpand.h>
#include "rscutils.h"
#include "ioutils.h"
#include "apputils.h"

/**** Defs. *****************************************************************/
#define TITLE_LEN		40				/* Length of application name. */
#define MAX_PATH		128				/* Maximum length of a path. */
#define MAX_ALIAS_LEN	512				/* length of alias buffer. */

/**** Global Vars. **********************************************************/
HINSTANCE hAppInst;              			/* Application instance. */
HINSTANCE	hPrevInst;					/* Previous instance. */
LPSTR	lpszArgs;						/* Command line. */
char		szExeDir[MAX_PATH];				/* Executable directory. */
char		szMailDir[MAX_PATH];				/* Path of .CNM files. */
char		szTitle[TITLE_LEN];				/* Application title. */
char		szIniFile[MAX_PATH];			/* Application ini file. */
char		szServer[48];					/* Default server name. */
char		szPostmaster[48];				/* Postmasters user name. */
char		*pszExt = "*.CNM";				/* Mail extension. */
char 	szToField[128];				/* Mail to line. */
char 	szUser[48];					/* mail user name. */
char		szMailBox[MAX_PATH];			/* Users mail box. */
char		*pszMailPrefix = "/SYS:\\MAIL\\";	/* System mailbox prefix. */
char		szLogFile[MAX_PATH];			/* error log file. */
char		*NewMailMsg = "You have new mail";	/* New mail broadcast message. */
char		szAliasList[MAX_ALIAS_LEN];		/* Buffer for storing alias' */

NWCONN_HANDLE	hServerConn;				/* Server connection handle. */

/**** Prototypes. ***********************************************************/
VOID FAR ScanMail(VOID);
BOOL FAR DeliverMail(LPSTR lpszFile, LPSTR lpszUser);
VOID FAR LogMailError(LPSTR lpszError, LPSTR lpszData);
VOID NotifyUser(NWCONN_HANDLE hServer, LPSTR lpszUser);

/*****************************************************************************
** Application entry point.
*/
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, 
				int iCmdShow)
{
     MSG	msg;                	/* Windows message. */
	int	iStrLen;				/* Length of CWD. */
	NWOBJ_ID ValidID;			/* ID for validation. */

	/* Setup this instance. */
	hAppInst  = hInstance;
	hPrevInst = hPrevInstance;
	lpszArgs  = lpszCmdLine;

     /* Check for previous instance. */
     if (hPrevInst)
     {
     	Accept("Only one instance may be run\nat one time.");
		return ERROR;
     }
     
     /* Initialise netware calls dll. */
     if (NWCallsInit(NULL, NULL))
     {
     	Alert("NWCallsInit() Failed.");
		return ERROR;
     }
	
	/* Get the current directory. */
	//_getcwd((char*) szCWD, MAX_PATH);
	GetModuleFileName(hInstance, szExeDir, MAX_PATH);
	StripFileName(szExeDir);
	
	/* Convert to lowercase. */
	AnsiLower(szExeDir);
	
	/* Get the application title. */
	LoadRscString(IDS_PROGRAM, (LPSTR) szTitle, TITLE_LEN);

	/* Create the .ini filename. */
	lstrcpy(szIniFile, szExeDir);
	lstrcat(szIniFile, "MAILTOSS.INI");

     /* Check it exists. */
     if (!FileExists(szIniFile))
     {
     	Alert("Error: MAILTOSS.INI is missing.\nIt should be located in the program directory.");
     	return FALSE;
     }

	/* Create the log file name. */
	lstrcpy(szLogFile, szExeDir);
	lstrcat(szLogFile, "MAILTOSS.LOG");

	/* Get the mail path. */
	ReadIniString("Program", "MailPath", "", szMailDir, MAX_PATH);
	if (szMailDir[0] == '\0')
	{
     	Alert("Invalid or undefined 'MailPath' line in MAILTOSS.INI");
		return ERROR;
	}

	/* Tag a \ on if not one. */
	iStrLen = lstrlen((LPSTR) szMailDir);
	if (szMailDir[iStrLen-1] != '\\')
		szMailDir[iStrLen] = '\\';
	
	/* Get server. */
	ReadIniString("Program", "Server", "", szServer, 48);

	/* Get server connection. */
	if (NWGetConnectionHandle((BYTE NWFAR*) &szServer, 0, &hServerConn, NULL))
	{
     	AlertEx("Cannot get connection for: %s", szServer);
		return ERROR;
	}

	/* Get postmaster. */
	ReadIniString("Program", "Postmaster", "", szPostmaster, 48);
	if (NWGetObjectID(hServerConn, szPostmaster, OT_USER, &ValidID))
	{
     	AlertEx("Invalid postmaster: %s", szPostmaster);
		return ERROR;
	}

	/* Read To line prefix. */
	ReadIniString("Program", "To", "", szToField, 128);
	if (szToField[0] == '\0')
	{
     	Alert("Invalid or undefined 'To' line in MAILTOSS.INI");
		return ERROR;
	}
	
	/* Create io dialog. */
	CreateFileIODlg();
	Busy(TRUE);
	
	/* Deliver the mail. */
	ScanMail();
	
	/* Destroy dialog. */
	Busy(FALSE);
	DestroyFileIODlg();
	
     /* Exit. */
     return msg.wParam;
}

/*****************************************************************************
** Scan the source directory for mail.
*/
VOID FAR ScanMail(VOID)
{
	UINT	iType;
	char	szMailPath[MAX_PATH+1];
     char szMailName[MAX_PATH+1];
     
	/* Get mail mask. */
	CreateFullPathName(szMailDir, pszExt, szMailPath);
	iType = _A_NORMAL;
	
	/* For mail file. */
	while(FindFile(szMailPath, &iType))
	{
		HFILE hSource;
		
		/* Get just the filename and show. */
		GetPathFileName(szMailPath, szMailName);
		SetFileName(szMailName);
		
		/* Yield CPU. */
		AppYield();
		
		/* Open the mail file. */
		hSource = _lopen(szMailPath, READ);
		if (hSource != HFILE_ERROR)
		{
			BOOL bDone  = FALSE;
			BOOL bError = TRUE;
			     
			/* Find To: line. */
			while (!bDone)
			{
				/* Read a line. */
				if (!ReadLine(hSource, szDataBuffer, MAX_DATABUF_LEN))
				{
					/* Read Error. */
					bDone = TRUE;
					LogMailError("No recipient line in file: %s", szMailPath);
					continue;
				}
				
				/* Pass the user name field. */
				if (_strnicmp(szToField, szDataBuffer, strlen(szToField)) != 0)
				{
					/* Not To: line. */
					continue;
				}
				 
				/* Found 'to' line. */ 
				{
					char 	*pText = szDataBuffer;
					char 	*pUser;
					NWOBJ_ID	UserID;
						
					/* Skip the to: field. */
					while ( (*pText != ' ')  && (*pText != '\t') 
					     && (*pText != '\0') && (*pText != '\r') && (*pText != '\n') )
						pText++;
					
					/* Now skip the white spaces. */
					while ( (*pText == ' ') || (*pText == '\t') )
						pText++;
	
					/* Save the start of the user name. */
					pUser = pText;
	
					/* Find @ part of address. */
					while ( (*pText != '@')  && (*pText != '\0') 
					     && (*pText != '\r') && (*pText != '\n') )
						pText++;
						
					/* And truncate. */
					*pText = '\0';
	
					/* Save the user name. */
					lstrcpy(szUser, pUser);
				     AnsiUpper(szUser);
					     
					/* Show status. */
					SetUserName(szUser);
						
					/* Get users object name. */
					if (NWGetObjectID(hServerConn, szUser, OT_USER, &UserID) == SUCCESSFUL)
					{
						/* Close source file. */
						_lclose(hSource);
						hSource = NULL;
	                         
	                         /* And deliver. */
						if (DeliverMail(szMailPath, szUser))
						{    
							/* Okay. */
							bError = FALSE;
							
							/* Send notify message. */
							NotifyUser(hServerConn, szUser);
				
							/* Delete source file. */
							if (!DelFile(szMailPath))
								LogMailError("Error deleting file: %s", szMailPath);
						}
						
						/* Finished. */
						bDone = TRUE;
					}
					else /* Could be an alias. */
					{    
						/* Check alias' */
						ReadIniString("Alias", szUser, "", szAliasList, MAX_ALIAS_LEN);
						if (szAliasList[0] != '\0')
						{
							LPSTR lpszAlias  = szAliasList;
                                   BOOL  bDelivered = FALSE;
                                   
							/* Close source file. */
							_lclose(hSource);
							hSource = NULL;
							
							/* Pass list. */
							while(*lpszAlias)
							{
								LPSTR lpszUser = szUser;
								
								/* Copy name to user buffer. */
								while ( (*lpszAlias != ' ') && (*lpszAlias != '\t') && (*lpszAlias != '\0') )
										*lpszUser++ = *lpszAlias++;
								
								/* Set EOS. */
								*lpszUser = '\0';

								/* Skip to next username. */
								while ( (*lpszAlias == ' ') || (*lpszAlias == '\t') )
									lpszAlias++;

								/* Show status. */
								SetUserName(szUser);

								if (DeliverMail(szMailPath, szUser))
								{    
									/* Set 'delivered' flag. */
								  	bDelivered = TRUE;

									/* Send notify message. */
									NotifyUser(hServerConn, szUser);
								}
							}

							/* Delete source file only if delivered to at 
							** least one person. */
							if (bDelivered)
							{
								/* Okay. */
								bError = FALSE;

								if (!DelFile(szMailPath))
									LogMailError("Error deleting file: %s", szMailPath);
							}

							/* Finished. */
							bDone = TRUE;
						}
						else /* Not an alias. */
						{
							/* Log and deliver to postmaster. */
							LogMailError("Mail for unknown user: %s", szUser);
							bDone = TRUE;
						}
					}
				}
			}
	          
	          /* On error deliver to postmaster. */
	          if (bError)
	          {
	          	if (hSource)
					_lclose(hSource);
					
				if (DeliverMail(szMailPath, szPostmaster))
				{
					/* Delete source file. */
					if (!DelFile(szMailPath))
						LogMailError("Error deleting file: %s", szMailPath);
                    }
                    
				/* Send notify message to postmaster. */
				NotifyUser(hServerConn, szPostmaster);
			}
		}
	}
}

/*****************************************************************************
** Deliver the mail file to the specified user.
*/
BOOL FAR DeliverMail(LPSTR lpszFile, LPSTR lpszUser)
{
	char 	szID[15];
	HFILE 	hSrcFile, hDstFile;
	NWOBJ_ID	UserID;
     char 	szMailName[MAX_PATH+1];
     BOOL		bDone = FALSE;
	long		lCopied;
	
	/* Get users object ID. */					
	NWGetObjectID(hServerConn, lpszUser, OT_USER, &UserID);
	
	/* Convert ID to string. */
	UserID = NWLongSwap(UserID);
	wsprintf(szID, "%8lX\\", UserID);
						
	/* Create mail box path. */
	lstrcpy(szMailBox, szServer);
	lstrcat(szMailBox, pszMailPrefix);
	lstrcat(szMailBox, szID);
						
	/* Create filename. */
	GetPathFileName(lpszFile, szMailName);
	lstrcat(szMailBox, szMailName);
     
     /* Make sure filename is unique. */
     while(!bDone)
     {
     	char szNewFile[15];
     	long lNum;
     	
		/* See if it exists. */
		if (!FileExists(szMailBox))
		{
			bDone = TRUE;
			continue;
		}
		
		/* Strip filename from path. */
		StripFileName(szMailBox);
		
		/* Generate a random number. */
		srand((UINT) GetTickCount());
		lNum   = (long) rand();
		lNum <<= 16;
		lNum  |= (long) rand();
		
		/* Convert to string. */
		wsprintf(szNewFile, "%08lX", lNum);
		
		/* Create new file name. */
		lstrcat(szMailBox, szNewFile);
		lstrcat(szMailBox, ".CNM");
	}

	/* Open source file. */
	hSrcFile = _lopen(lpszFile, READ);
	if (hSrcFile == HFILE_ERROR)
	{
		LogMailError("Error opening source file: %s", lpszFile);
		return FALSE;
	}
	
	/* Create destination file. */
	hDstFile = _lcreat(szMailBox, 0);
	if (hDstFile == HFILE_ERROR)
	{
		_lclose(hSrcFile);
		LogMailError("Error opening destination file: %s", szMailBox);
		return FALSE;
	}
	
	/* Initialise LZ buffers. */
	LZStart();
	
	/* Copy the file. */
	lCopied = CopyLZFile(hSrcFile, hDstFile);
	
	/* Close files. */
	_lclose(hSrcFile);
	_lclose(hDstFile);
     
     /* Free LZ buffers. */
	LZDone();
	
	/* Check return code. */	
	if (lCopied > 0)
		return TRUE;

	LogMailError("Error copying file: %s...", lpszFile);
	LogMailError(" to file: %s", szMailBox);
	return FALSE;
}

/*****************************************************************************
** Log an error.
*/
VOID FAR LogMailError(LPSTR lpszError, LPSTR lpszData)
{
	HFILE hLogFile;
	char  szMsg[256];
	int	 iMsgLen;
	
	/* Check for log file. */
	if (!FileExists(szLogFile))
	{
		HFILE hNewFile;
		
		/* Create it. */
		hNewFile = _lcreat(szLogFile, 0);
		_lclose(hNewFile);
	}
	
	/* Open log file. */
	hLogFile = _lopen(szLogFile, WRITE);
	if (hLogFile == HFILE_ERROR)
		return;
		
	/* Seek to end. */
	_llseek(hLogFile, 0, 2);
	
	/* Create message. */
	wsprintf(szMsg, lpszError, lpszData);
	iMsgLen = lstrlen(szMsg);
	
	/* Write it out. */
	_lwrite(hLogFile, szMsg, iMsgLen);
	_lwrite(hLogFile, "\r\n", 2);
	
	/* Close it. */
	_lclose(hLogFile);
}

/******************************************************************************
** Send a message to a user.
*/
VOID NotifyUser(NWCONN_HANDLE hServer, LPSTR lpszUser)
{
     NWNUMBER       wConns;             /* The number of connections. */
     NWCONN_NUM     ConnList[20];       /* The list of connections. */
     NWFLAGS        ResList[20];        /* The results. */

     /* Get a list of connections for the user. */
     NWGetObjectConnectionNumbers(hServer, lpszUser, OT_USER,
          (NWNUMBER NWFAR*) &wConns, (NWCONN_NUM NWFAR*) ConnList, 20);
     
     /* Send the message to all stations they are connected to. */
     NWSendBroadcastMessage(hServer, (char NWFAR *) NewMailMsg, wConns, 
          (NWCONN_NUM_WORD NWFAR*) ConnList, (NWFLAGS NWFAR*) ResList);
}
