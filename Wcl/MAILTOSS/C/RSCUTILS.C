/*****************************************************************************
** (C) Chris Wood 1995.
**
** RSCUTILS.C - Resource utility functions.
**
******************************************************************************
*/

#include "af.h"
#include "rscutils.h"

/**** Global vars. **********************************************************/
BYTE	szRscBuf[RSCSTR_LEN];			/* Temporary resource string buffer. */

extern HINSTANCE hAppInst;			/* Application instance. */

/******************************************************************************
** Load a menu from the resource file. This checks that the resource is 
** loaded and outputs a debug message if it fails. It returns the handle to
** the menu.
*/
HMENU FAR LoadRscMenu(LPSTR lpszRscName)
{                    
	HMENU hRscMenu;

	ASSERT(IsValidPtr(lpszRscName));
	ASSERT(hAppInst);
	
	/* Do the standard call. */
	hRscMenu = LoadMenu(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscMenu)
	{
		/* Note failure on debug output. */
		TRACE("LoadMenu() Failure For ");
		TRACE(lpszRscName);
		TRACE("\n");
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

	ASSERT(hAppInst);
     
     /* Load the string. */
	bOkay = LoadString(hAppInst, wID, (LPSTR) szRscBuf, RSCSTR_LEN);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf((LPSTR) szRscBuf, "String #%u", wID);

		/* Send copy to debug output. */
		TRACE("LoadString() Failure For ");
		TRACE((LPSTR) szRscBuf);
		TRACE("\n");
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
     
	ASSERT(IsValidPtr(lpszBuffer));
	ASSERT(hAppInst);

     /* Load the string. */
	bOkay = LoadString(hAppInst, wID, lpszBuffer, iBufSize);
	
	/* Check it loaded. */	
	if (!bOkay)
	{    
		/* Return uknown ID. */
		wsprintf(lpszBuffer, "String #%u", wID);

		/* Send copy to debug output. */
		TRACE("LoadString() Failure For ");
		TRACE(lpszBuffer);
		TRACE("\n");
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
	
	ASSERT(IsValidPtr(lpszRscName));
	ASSERT(hAppInst);

	/* Do the standard call. */
	hRscIcon = LoadIcon(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscIcon)
	{
		/* Note failure on debug output. */
		TRACE("LoadIcon() Failure For ");
		TRACE(lpszRscName);
		TRACE("\n");
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
	
	ASSERT(IsValidPtr(lpszRscName));
	ASSERT(hAppInst);

	/* Do the standard call. */
	hRscBitmap = LoadBitmap(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscBitmap)
	{
		/* Note failure on debug output. */
		TRACE("LoadBitmap() Failure For ");
		TRACE(lpszRscName);
		TRACE("\n");
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
	
	ASSERT(IsValidPtr(lpszRscName));
	ASSERT(hAppInst);

	/* Do the standard call. */
	hRscCursor = LoadCursor(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscCursor)
	{
		/* Note failure on debug output. */
		TRACE("LoadCursor() Failure For ");
		TRACE(lpszRscName);
		TRACE("\n");
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

	ASSERT(IsValidPtr(lpszRscName));
	ASSERT(hAppInst);
	
	/* Do the standard call. */
	hRscAccel = LoadAccelerators(hAppInst, lpszRscName);
	
	/* Check it loaded. */
	if (!hRscAccel)
	{
		/* Note failure on debug output. */
		TRACE("LoadAccelerators() Failure For ");
		TRACE(lpszRscName);
		TRACE("\n");
	}
	
	return hRscAccel;
}
