/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINUTILS.H - Utilities and wrappers strcutures and prototypes.
**
******************************************************************************
*/

/**** Definitions. **********************************************************/
#define INIBUF_SIZE		128		/* Size of ini string buffer. */
#define RSCBUF_SIZE		128		/* Size of resource string buffer. */

/**** Structures. ***********************************************************/


/**** Prototypes. ***********************************************************/
extern LPSTR FAR ReadIniString(LPSTR, LPSTR, LPSTR, LPSTR);
extern VOID FAR WriteIniString(LPSTR, LPSTR, LPSTR);
extern int FAR ReadIniInt(LPSTR, LPSTR, int);
extern VOID FAR WriteIniInt(LPSTR, LPSTR, int);
extern LPSTR FAR LoadRscString(UINT, LPSTR);
extern VOID FAR CentreWindow(HWND);
