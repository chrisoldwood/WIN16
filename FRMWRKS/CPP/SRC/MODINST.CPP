/*****************************************************************************
** (C) Chris Wood 1995.
**
** MODINST.CPP - Module instance base class functions.
**
******************************************************************************
*/

#include <windows.h>  
#include <ctl3d.h>
#include "apptypes.h"
#include "debug.h"
#include "modinst.hpp"       
               
/******************************************************************************
** Load a menu from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the menu.
*/
HMENU MODINST::LoadRscMenu(LPSTR lpszRscName)
{                    
	HMENU hRscMenu;
	
	/* Do the standard call. */
	hRscMenu = LoadMenu(hCurrInst, lpszRscName);
	
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
LPSTR MODINST::LoadRscString(UINT wID)
{         
	BOOL 	bOkay;		/* Resource found? */
     
     /* Load the string. */
	bOkay = LoadString(hCurrInst, wID, (LPSTR) szRscBuf, RSCBUF_SIZE);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf((LPSTR) szRscBuf, "String #%d", wID);

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
LPSTR MODINST::LoadRscString(UINT wID, LPSTR lpszBuffer, int iBufSize)
{         
	BOOL 	bOkay;		/* Resource found? */
     
     /* Load the string. */
	bOkay = LoadString(hCurrInst, wID, lpszBuffer, iBufSize);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf(lpszBuffer, "String #%d", wID);

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
HICON MODINST::LoadRscIcon(LPSTR lpszRscName)
{                    
	HICON hRscIcon;
	
	/* Do the standard call. */
	hRscIcon = LoadIcon(hCurrInst, lpszRscName);
	
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
HBITMAP MODINST::LoadRscBitmap(LPSTR lpszRscName)
{                    
	HBITMAP	hRscBitmap;
	
	/* Do the standard call. */
	hRscBitmap = LoadBitmap(hCurrInst, lpszRscName);
	
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
HCURSOR MODINST::LoadRscCursor(LPSTR lpszRscName)
{                    
	HCURSOR	hRscCursor;
	
	/* Do the standard call. */
	hRscCursor = LoadCursor(hCurrInst, lpszRscName);
	
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
** Read a string from the ini file into the temporary buffer. A pointer to the
** temporary buffer is returned.
*/
LPSTR MODINST::ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault)
{        
	/* Get the string. */
	GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, (LPSTR) szIniBuf,
							INIBUF_SIZE, lpszIniFile);
	return (LPSTR) szIniBuf;
}

/******************************************************************************
** Read a string from the ini file into the aupplied buffer. A pointer to the
** supplied buffer is returned.
*/
LPSTR MODINST::ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault,
						LPSTR lpszBuffer, int iBufSize)
{        
	/* Get the string. */
	GetPrivateProfileString(lpszSection, lpszEntry, lpszDefault, lpszBuffer,
							iBufSize, lpszIniFile);
	return lpszBuffer;
}

/******************************************************************************
** Write a string to the ini file.
*/
VOID MODINST::WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString)
{
	WritePrivateProfileString(lpszSection, lpszEntry, lpszString, 
							(LPSTR) lpszIniFile);
}

/******************************************************************************
** Read an integer from the ini file.
*/
int MODINST::ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault)
{                             
	return GetPrivateProfileInt(lpszSection, lpszEntry, iDefault, 
							(LPSTR) lpszIniFile);
}

/******************************************************************************
** Write an integer to the ini file. This uses the tmp ini buffer when 
** converting to a string.
*/
VOID MODINST::WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue)
{                                 
     wsprintf((LPSTR) szIniBuf, (LPSTR) "%d", iValue);
	WritePrivateProfileString(lpszSection, lpszEntry, (LPSTR) szIniBuf, 
							(LPSTR) lpszIniFile);
}
