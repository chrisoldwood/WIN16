/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPUTILS.H - Application utility functions header.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _APPUTILS_H_
#define _APPUTILS_H_

/**** Defs. *****************************************************************/
#define INIBUF_LEN	128			/* Ini string temporary buffer size. */
#define MSGBUF_LEN	256			/* Msg buffer size. */

/**** Prototypes. ***********************************************************/
extern LPSTR FAR ReadTmpIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault);
extern LPSTR FAR ReadIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszDefault, LPSTR lpszBuffer, int iBufSize);
extern VOID  FAR WriteIniString(LPSTR lpszSection, LPSTR lpszEntry, LPSTR lpszString);
extern int   FAR ReadIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iDefault);
extern VOID  FAR WriteIniInt(LPSTR lpszSection, LPSTR lpszEntry, int iValue);
extern long  FAR ReadIniLong(LPSTR lpszSection, LPSTR lpszEntry, long lDefault);
extern VOID  FAR WriteIniLong(LPSTR lpszSection, LPSTR lpszEntry, long lValue);

extern VOID FAR CentreWindow(HWND hWnd);
extern VOID FAR Busy(BOOL bBusy);
extern VOID FAR AppYield(VOID);

extern int  FAR Query(LPSTR lpszMsg);
extern int  FAR QueryEx(LPSTR lpszMsg, LPSTR lpszParam);
extern VOID FAR Alert(LPSTR lpszMsg);
extern VOID FAR AlertEx(LPSTR lpszMsg, LPSTR lpszParam);
extern VOID FAR Accept(LPSTR lpszMsg);
extern VOID FAR AcceptEx(LPSTR lpszMsg, LPSTR lpszParam);

#endif /* _APPUTILS_H_ */
