/*****************************************************************************
** (C) Chris Wood 1995.
**
** MODINST.HPP - Module instance base class definition.
**
******************************************************************************
*/

// Check for previous inclusion.
#ifndef _MODINST_HPP_
#define _MODINST_HPP_
     
#define INIBUF_SIZE	80		// Ini string tmp buffer size.
#define RSCBUF_SIZE	80		// Resouce string tmp buffer size.

/*****************************************************************************
** Module instance class.
** This contains all the data about a particular module (Exe or Dll) and 
** provides supported functions for getting resources etc.
*/
class MODINST
{
public:
	HMENU LoadRscMenu(LPSTR lpszRscName);
	LPSTR LoadRscString(UINT wID);	
     LPSTR LoadRscString(UINT wID, LPSTR lpszBuffer, int iBufSize);
	HICON LoadRscIcon(LPSTR lpszRscName);
	HBITMAP LoadRscBitmap(LPSTR lpszRscName);
	HCURSOR LoadRscCursor(LPSTR lpszRscName);
	LPSTR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault);
	LPSTR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault, 
						LPSTR lpszBuffer, int iBufSize);
	VOID WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString);
	int  ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault);
	VOID WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue);
     
protected:   
	HINSTANCE hCurrInst;			// Current module instance.
	LPSTR	lpszIniFile;			// Application ini file.
	BYTE 	szIniBuf[INIBUF_SIZE];	// Temporary ini string buffer.
	BYTE 	szRscBuf[RSCBUF_SIZE];	// Temporary resource string buffer.
};

#endif // _MODINST_HPP_
