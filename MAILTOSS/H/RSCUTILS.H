/*****************************************************************************
** (C) Chris Wood 1995.
**
** RSCUTILS.H - Resource utility functions header.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _RSCUTILS_H_
#define _RSCUTILS_H_

#include "resource.h"

/**** Defs. *****************************************************************/
#define RSCSTR_LEN	128			/* Resouce string tmp buffer size. */

/**** Prototypes. ***********************************************************/
extern HMENU   FAR LoadRscMenu(LPSTR lpszRscName);
extern LPSTR   FAR LoadTmpRscString(UINT wID);
extern LPSTR   FAR LoadRscString(UINT wID, LPSTR lpszBuffer, int iBufSize);
extern HICON   FAR LoadRscIcon(LPSTR lpszRscName);
extern HBITMAP FAR LoadRscBitmap(LPSTR lpszRscName);
extern HCURSOR FAR LoadRscCursor(LPSTR lpszRscName);
extern HACCEL  FAR LoadRscAccelerators(LPSTR lpszRscName);

#endif /* _RSCUTILS_H_ */
