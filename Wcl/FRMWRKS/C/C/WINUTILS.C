/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINUTILS.C - Utilities and wrappers for some windows functions.
**
******************************************************************************
*/

#include <windows.h>
#include "winutils.h"
#include "debug.h"

/**** Global variables. ******************************************************/
BYTE szIniFile[] = "app.ini";    	/* The application .ini file name. */
BYTE szIniBuf[INIBUF_SIZE];		/* Temporary ini string buffer. */
BYTE szRscBuf[RSCBUF_SIZE];		/* Temporary resource string buffer. */

extern HWND         hAppWnd;       /* Main window. */
extern HINSTANCE    hAppInst;      /* Application instance. */

/*
** Ini file processing.
*/

/******************************************************************************
** Read a string from the ini file. If no buffer is specified then the tmp
** buffer is used instead. A pointer to the string buffer used is returned.
** NB: The size of the buffer passed must be at least INIBUF_SIZE.
*/
LPSTR FAR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault, 
					LPSTR lpszBuffer)
{        
     LPSTR	lpszString;	/* Pointer to recieve buffer. */
     
	/* Setup receieve buffer. */
	if (lpszBuffer)
		lpszString = lpszBuffer;
	else
		lpszString = (LPSTR) szIniBuf;

	/* Get the string. */
	GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, lpszString,
							INIBUF_SIZE, (LPSTR) szIniFile);
	return lpszString;
}

/******************************************************************************
** Write a string to the ini file.
*/
VOID FAR WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString)
{
	WritePrivateProfileString(lpszSection, lpszEntry, lpszString, (LPSTR) szIniFile);
}

/******************************************************************************
** Read an integer from the ini file.
*/
int FAR ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault)
{                             
	return GetPrivateProfileInt(lpszSection, lpszEntry, iDefault, (LPSTR) szIniFile);
}

/******************************************************************************
** Write an integer to the ini file. This uses the tmp ini buffer when 
** converting to a string.
*/
VOID FAR WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue)
{                                 
     wsprintf((LPSTR) szIniBuf, (LPSTR) "%d", iValue);
	WritePrivateProfileString(lpszSection, lpszEntry, (LPSTR) szIniBuf, (LPSTR) szIniFile);
}

/*
** LoadString wrapper.
*/                      

/******************************************************************************
** Read a string from the resource into either the buffer specified or the tmp
** buffer. A pointer to the bufferis returned.
** NB: The size of the buffer passed must be at least INIBUF_SIZE.
*/
LPSTR FAR LoadRscString(UINT wID, LPSTR lpszBuffer)
{         
	BOOL 	bOkay;		/* Resource found? */
     LPSTR	lpszString;	/* Pointer to recieve buffer. */
     
	/* Setup receieve buffer. */
	if (lpszBuffer)
		lpszString = lpszBuffer;
	else
		lpszString = (LPSTR) szRscBuf;

     /* Load the string. */
	bOkay = LoadString(hAppInst, wID, lpszString, RSCBUF_SIZE);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf(lpszString, "String #%d", wID);

		/* Send copy to debug output. */
		DebugMsg("LoadString() Failure For ");
		DebugMsg(lpszString);
		DebugMsg("\n");
	}
	
	return lpszString;
}

/*
** General utilities.
*/

/******************************************************************************
** Centre a window on the screen.
*/
VOID FAR CentreWindow(HWND hWnd)
{
	RECT		rcWindow;           /* Window dimensions. */
	RECT		rcScreen;           /* Screen dimensions. */
	POINT     ptOrigin;           /* New dialog origin. */

     /* Get the Screen & Window dimensions. */
	GetWindowRect(GetDesktopWindow(), (LPRECT) &rcScreen);
	GetWindowRect(hWnd, (LPRECT) &rcWindow);
	OffsetRect((LPRECT) &rcWindow, -rcWindow.left, -rcWindow.top);

     /* Adjust to centre of screen. */
	ptOrigin.x = (rcScreen.right - rcWindow.right) / 2;	
	ptOrigin.y = (rcScreen.bottom - rcWindow.bottom) / 2;

     /* Move without redrawing. */
	MoveWindow(hWnd, ptOrigin.x, ptOrigin.y, rcWindow.right, rcWindow.bottom, FALSE);
}
