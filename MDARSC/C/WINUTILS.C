/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINUTILS.C - Windows utility functions.
**
******************************************************************************
*/

#include "af.h"
#include <stdio.h>
#include <math.h>
#include "winutils.h"

/**** Global vars. **********************************************************/
BYTE	szIniBuf[INIBUF_LEN];			/* Temporary ini file string buffer. */
BYTE	szRscBuf[RSCSTR_LEN];			/* Temporary resource string buffer. */
BYTE szIniFile[] = "mdadebug.ini";		/* Application ini file. */

extern HINSTANCE hAppInst;			/* Application instance. */

/******************************************************************************
** Load a menu from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the menu.
*/
HMENU FAR LoadRscMenu(LPSTR lpszRscName)
{                    
	HMENU hRscMenu;
	
	/* Do the standard call. */
	hRscMenu = LoadMenu(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscMenu)
	{
		/* Note failure on debug output. */
		TraceMsg("LoadMenu() Failure For ");
		TraceMsg(lpszRscName);
		TraceMsg("\n");
	}
	
	return hRscMenu;
}

/******************************************************************************
** Load a string from the resource file into the temporary buffer.
** It returns a pointer to the temporary buffer.
*/
LPSTR FAR LoadTmpRscString(UINT wID)
{         
	BOOL	bOkay;			/* Resource found? */
     
     /* Load the string. */
	bOkay = LoadString(hAppInst, wID, (LPSTR) szRscBuf, RSCSTR_LEN);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf((LPSTR) szRscBuf, "String #%u", wID);

		/* Send copy to debug output. */
		TraceMsg("LoadString() Failure For ");
		TraceMsg((LPSTR) szRscBuf);
		TraceMsg("\n");
	}
	
	return (LPSTR) szRscBuf;
}

/******************************************************************************
** Load a string from the resource file into the buffer supplied.
** It returns a pointer to the buffer supplied.
*/
LPSTR FAR LoadRscString(UINT wID, LPSTR lpszBuffer, int iBufSize)
{         
	BOOL 	bOkay;		/* Resource found? */
     
     /* Load the string. */
	bOkay = LoadString(hAppInst, wID, lpszBuffer, iBufSize);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf(lpszBuffer, "String #%u", wID);

		/* Send copy to debug output. */
		TraceMsg("LoadString() Failure For ");
		TraceMsg(lpszBuffer);
		TraceMsg("\n");
	}
	
	return lpszBuffer;
}

/******************************************************************************
** Load an icon from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the icon.
*/
HICON FAR LoadRscIcon(LPSTR lpszRscName)
{                    
	HICON hRscIcon;
	
	/* Do the standard call. */
	hRscIcon = LoadIcon(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscIcon)
	{
		/* Note failure on debug output. */
		TraceMsg("LoadIcon() Failure For ");
		TraceMsg(lpszRscName);
		TraceMsg("\n");
	}
	
	return hRscIcon;
}

/******************************************************************************
** Load a bitmap from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the bitmap.
*/
HBITMAP FAR LoadRscBitmap(LPSTR lpszRscName)
{                    
	HBITMAP	hRscBitmap;
	
	/* Do the standard call. */
	hRscBitmap = LoadBitmap(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscBitmap)
	{
		/* Note failure on debug output. */
		TraceMsg("LoadBitmap() Failure For ");
		TraceMsg(lpszRscName);
		TraceMsg("\n");
	}
	
	return hRscBitmap;
}

/******************************************************************************
** Load a cursor from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the cursor.
*/
HCURSOR FAR LoadRscCursor(LPSTR lpszRscName)
{                    
	HCURSOR	hRscCursor;
	
	/* Do the standard call. */
	hRscCursor = LoadCursor(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscCursor)
	{
		/* Note failure on debug output. */
		TraceMsg("LoadCursor() Failure For ");
		TraceMsg(lpszRscName);
		TraceMsg("\n");
	}
	
	return hRscCursor;
}

/******************************************************************************
** Load the accelerators from the resource file. This checks that the resource
** is loaded and outputs a debug message if it fails. It returns the handle to
** the accelerator table.
*/
HACCEL FAR LoadRscAccelerators(LPSTR lpszRscName)
{                    
	HACCEL hRscAccel;

	AssertEx(IsValidPtr(lpszRscName), "LoadRscAccelerators(lpszRscName)");
	
	/* Do the standard call. */
	hRscAccel = LoadAccelerators(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscAccel)
	{
		/* Note failure on debug output. */
		TraceMsg("LoadAccelerators() Failure For ");
		TraceMsg(lpszRscName);
		TraceMsg("\n");
	}
	
	return hRscAccel;
}

/******************************************************************************
** Read a string from the ini file into the temporary buffer. A pointer to the
** temporary buffer is returned. The temporary buffer is limited in length, so
** any caller must be sure that it is not going to need a larger buffer.
*/
LPSTR FAR ReadTmpIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault)
{        
	AssertEx(IsValidPtr(lpszSection), "ReadIniString(lpszSection)");
	AssertEx(IsValidPtr(lpszEntry),   "ReadIniString(lpszEntry)");
	AssertEx(IsValidPtr(lpszDefault), "ReadIniString(lpszDefault)");

	/* Get the string. */
	GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, (LPSTR) szIniBuf,
							INIBUF_LEN, (LPSTR) szIniFile);
	return (LPSTR) szIniBuf;
}

/******************************************************************************
** Read a string from the ini file into the supplied buffer. A pointer to the
** supplied buffer is returned.
*/
LPSTR FAR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault,
						LPSTR lpszBuffer, int iBufSize)
{        
	AssertEx(IsValidPtr(lpszSection), "ReadIniString(lpszSection)");
	AssertEx(IsValidPtr(lpszEntry),   "ReadIniString(lpszEntry)");
	AssertEx(IsValidPtr(lpszDefault), "ReadIniString(lpszDefault)");
	AssertEx(IsValidPtr(lpszBuffer),  "ReadIniString(lpszBuffer)");
	AssertEx(iBufSize,                "ReadIniString(iBufSize)");

	/* Get the string. */
	GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, lpszBuffer,
							iBufSize, (LPSTR) szIniFile);
	return lpszBuffer;
}

/******************************************************************************
** Write a string to the ini file.
*/
VOID FAR WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString)
{
	AssertEx(IsValidPtr(lpszSection), "WriteIniString(lpszSection)");

	WritePrivateProfileString(lpszSection, lpszEntry, lpszString, (LPSTR) szIniFile);
}

/******************************************************************************
** Read an integer from the ini file.
*/
int FAR ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault)
{                             
	AssertEx(IsValidPtr(lpszSection), "WriteIniString(lpszSection)");
	AssertEx(IsValidPtr(lpszEntry),   "WriteIniString(lpszEntry)");

	return GetPrivateProfileInt(lpszSection, lpszEntry, iDefault, (LPSTR) szIniFile);
}

/******************************************************************************
** Write an integer to the ini file.
*/
VOID FAR WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue)
{                                 
	BYTE	szBuffer[20];			/* Temporary buffer. */
	
	AssertEx(IsValidPtr(lpszSection), "WriteIniInt(lpszSection)");

	/* Convert the number to a string. */
     wsprintf((LPSTR) szBuffer, (LPSTR) "%d", iValue);
     
     /* Write out the string. */
	WritePrivateProfileString(lpszSection, lpszEntry, (LPSTR) szBuffer, (LPSTR) szIniFile);
}

/******************************************************************************
** Centre a window on the screen.
*/
VOID FAR CentreWindow(HWND hWnd)
{
	RECT		rcWindow;           /* Window dimensions. */
	RECT		rcScreen;           /* Screen dimensions. */
	POINT     ptOrigin;           /* New window origin. */

	AssertEx(IsValidWnd(hWnd), "CentreWindow()");

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
