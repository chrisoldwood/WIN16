/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPUTILS.C - Application utility functions.
**
******************************************************************************
*/

#include "af.h"
#include <stdlib.h>
#include "apputils.h"

/**** Global vars. **********************************************************/
char	szIniBuf[INIBUF_LEN];			/* Temporary ini file string buffer. */
char szMsgBuf[MSGBUF_LEN];			/* Temporaray message buffer. */

extern HINSTANCE hAppInst;			/* Application instance. */
extern char szIniFile[];				/* Application ini file. */
extern char szTitle[];				/* Application title. */
HWND hAppWnd=NULL;					/* Application window. */

/******************************************************************************
** Read a string from the ini file into the temporary buffer. A pointer to the
** temporary buffer is returned. The temporary buffer is limited in length, so
** any caller must be sure that it is not going to need a larger buffer.
*/
LPSTR FAR ReadTmpIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault)
{        
	ASSERT(IsValidPtr(lpszSection));
	ASSERT(IsValidPtr(lpszEntry));
	ASSERT(IsValidPtr(lpszDefault));

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
	ASSERT(IsValidPtr(lpszSection));
	ASSERT(IsValidPtr(lpszEntry));
	ASSERT(IsValidPtr(lpszDefault));
	ASSERT(IsValidPtr(lpszBuffer));
	ASSERT(iBufSize);

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
	ASSERT(IsValidPtr(lpszSection));

	WritePrivateProfileString(lpszSection, lpszEntry, lpszString, (LPSTR) szIniFile);
}

/******************************************************************************
** Read an integer from the ini file.
*/
int FAR ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault)
{                             
	ASSERT(IsValidPtr(lpszSection));
	ASSERT(IsValidPtr(lpszEntry));

	return GetPrivateProfileInt(lpszSection, lpszEntry, iDefault, (LPSTR) szIniFile);
}

/******************************************************************************
** Write an integer to the ini file.
*/
VOID FAR WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue)
{                                 
	char	szBuffer[20];			/* Temporary buffer. */
	
	ASSERT(IsValidPtr(lpszSection));

	/* Convert the number to a string. */
     wsprintf((LPSTR) szBuffer, (LPSTR) "%d", iValue);
     
     /* Write out the string. */
	WritePrivateProfileString(lpszSection, lpszEntry, (LPSTR) szBuffer, (LPSTR) szIniFile);
}

/******************************************************************************
** Read a long from the ini file.
*/
long FAR ReadIniLong(LPSTR lpszSection, LPSTR lpszEntry, long lDefault)
{                             
	char	szBuffer[30];			/* Temporary buffer. */
     
     /* Read as string. */
     ReadIniString(lpszSection, lpszEntry, "", szBuffer, 30);
     
     /* Check string. */
     if (szBuffer[0] == '\0')
     	return lDefault;
     
	return atol(szBuffer);
}

/******************************************************************************
** Write a long to the ini file.
*/
VOID FAR WriteIniLong(LPSTR lpszSection, LPSTR lpszEntry, long lValue)
{                                 
	char	szBuffer[30];			/* Temporary buffer. */
	
	/* Convert the number to a string. */
     wsprintf((LPSTR) szBuffer, (LPSTR) "%ld", lValue);
     
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

	ASSERT(IsValidWnd(hWnd));

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

/******************************************************************************
** Show or hide the busy cursor.
*/
VOID FAR Busy(BOOL bBusy)
{
	static HCURSOR hOldCursor = NULL;
	static int	iCount = NULL;
	
	if (bBusy)
	{
		/* Increment busy count. */
		iCount++;
		
		/* Show the hourglass. */
		if (!hOldCursor)
			hOldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
	}
	else /* Not busy. */
	{
		/* Decrement busy count. */
		iCount--;

#ifdef _DEBUG
		/* Validate busy count. */
		if (iCount < 0)
			TRACE("Too many calls to Busy(FALSE).\n");
#endif

		/* Back to the previous cursor. */
		if (!iCount)
		{
			SetCursor(hOldCursor);
			hOldCursor = NULL;
		}
	}
}

/******************************************************************************
** Show a query message box.
*/
int FAR Query(LPSTR lpszMsg)
{
	ASSERT(IsValidPtr(lpszMsg));

	return MessageBox(hAppWnd, lpszMsg, szTitle, MB_YESNO | MB_ICONQUESTION);
}

/******************************************************************************
** Show a query message box. This takes an additional string parameter.
*/
int FAR QueryEx(LPSTR lpszMsg, LPSTR lpszParam)
{
	ASSERT(IsValidPtr(lpszMsg));
	ASSERT(IsValidPtr(lpszParam));
     
     wsprintf(szMsgBuf, lpszMsg, lpszParam);
	return MessageBox(hAppWnd, szMsgBuf, szTitle, MB_YESNO | MB_ICONQUESTION);
}

/******************************************************************************
** Show an alert message box.
*/
VOID FAR Alert(LPSTR lpszMsg)
{
	ASSERT(IsValidPtr(lpszMsg));

	MessageBox(hAppWnd, lpszMsg, szTitle, MB_OK | MB_ICONSTOP);
}

/******************************************************************************
** Show an alert message box. This takes an additional string parameter.
*/
VOID FAR AlertEx(LPSTR lpszMsg, LPSTR lpszParam)
{
	ASSERT(IsValidPtr(lpszMsg));
	ASSERT(IsValidPtr(lpszParam));

     wsprintf(szMsgBuf, lpszMsg, lpszParam);
	MessageBox(hAppWnd, szMsgBuf, szTitle, MB_OK | MB_ICONSTOP);
}

/******************************************************************************
** Show an acception message box.
*/
VOID FAR Accept(LPSTR lpszMsg)
{
	ASSERT(IsValidPtr(lpszMsg));

	MessageBox(hAppWnd, lpszMsg, szTitle, MB_OK | MB_ICONASTERISK);
}

/******************************************************************************
** Show an acception message box. This takes an additional string parameter.
*/
VOID FAR AcceptEx(LPSTR lpszMsg, LPSTR lpszParam)
{
	ASSERT(IsValidPtr(lpszMsg));
	ASSERT(IsValidPtr(lpszParam));

     wsprintf(szMsgBuf, lpszMsg, lpszParam);
	MessageBox(hAppWnd, szMsgBuf, szTitle, MB_OK | MB_ICONASTERISK);
}

/******************************************************************************
** Yield to another application.
*/
VOID FAR AppYield(VOID)
{
	MSG	msg;
	
	/* While messages are pending. */
	while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		/* Process them. */
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
