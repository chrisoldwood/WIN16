/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINUTILS.H - Windows utility functions header.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _WINUTILS_H_
#define _WINUTILS_H_

/**** Defs. *****************************************************************/
#define INIBUF_LEN	128			/* Ini string temporary buffer size. */
#define RSCSTR_LEN	128			/* Resouce string tmp buffer size. */

/**** Prototypes. ***********************************************************/
HMENU   FAR LoadRscMenu(LPSTR lpszRscName);
LPSTR   FAR LoadTmpRscString(UINT wID);
LPSTR   FAR LoadRscString(UINT wID, LPSTR lpszBuffer, int iBufSize);
HICON   FAR LoadRscIcon(LPSTR lpszRscName);
HBITMAP FAR LoadRscBitmap(LPSTR lpszRscName);
HCURSOR FAR LoadRscCursor(LPSTR lpszRscName);
HACCEL  FAR LoadRscAccelerators(LPSTR lpszRscName);

LPSTR FAR ReadTmpIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault);
LPSTR FAR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault, LPSTR lpszBuffer, int iBufSize);
VOID  FAR WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString);
int   FAR ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault);
VOID  FAR WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue);

VOID FAR CentreWindow(HWND hWnd);
VOID FAR GetDlgItemRect(HWND hDlg, int iCtlID, LPRECT lprcRect);
VOID FAR SetDlgItemReal(HWND hDlg, int iCtlID, double dVal);
double FAR GetDlgItemReal(HWND hDlg, int iCtlID);

#endif /* _WINUTILS_H_ */
