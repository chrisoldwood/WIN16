/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDASCROL.C - MDA Library area scroll functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdadefs.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Scroll the area from (sx,sy) to (dx,dy) up one line. The bottom line of
** characters is replaced with spaces. No checking is done to ensure that the
** area is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAScrollUp(int iSX, int iSY, int iDX, int iDY)
{
     WORD FAR  *lpSrcStart, FAR *lpSrcTmp;
     WORD FAR  *lpDstStart, FAR *lpDstTmp;
     int       iXLoop, iYLoop, iXLength;
     
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loops. */
     iYLoop      = iDY - iSY;
     iXLength    = iDX - iSX + 1;
     lpSrcStart  = (WORD FAR *) (lpMDA + (((iSY+1) * MDA_WIDTH * 2) + (iSX * 2)));     
     lpDstStart  = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iSX * 2)));

     /* Loop for each line. */
     while(iYLoop--)
     {
          /* Setup for X loop. */
          lpSrcTmp = lpSrcStart;
          lpDstTmp = lpDstStart;
          iXLoop   = iXLength;

          /* Copy one line up. */
          while(iXLoop--)
               *lpDstTmp++ = *lpSrcTmp++;
     
          /* Update line start pointers. */
          lpSrcStart += MDA_WIDTH;
          lpDstStart += MDA_WIDTH;
     }

     /* Blank last line with spaces. */
     iXLoop = iXLength;
     while(iXLoop--)
          *lpDstStart++ = (*lpDstStart & 0xFF00) | 0x0020;     
}

/*****************************************************************************
** Scroll the area from (sx,sy) to (dx,dy) down one line. The top line of
** characters is replaced with spaces. No checking is done to ensure that the
** area is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAScrollDown(int iSX, int iSY, int iDX, int iDY)
{
     WORD FAR  *lpSrcStart, FAR *lpSrcTmp;
     WORD FAR  *lpDstStart, FAR *lpDstTmp;
     int       iXLoop, iYLoop, iXLength;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loops. */
     iYLoop      = iDY - iSY;
     iXLength    = iDX - iSX + 1;
     lpSrcStart  = (WORD FAR *) (lpMDA + (((iDY-1) * MDA_WIDTH * 2) + (iSX * 2)));     
     lpDstStart  = (WORD FAR *) (lpMDA + ((iDY * MDA_WIDTH * 2) + (iSX * 2)));

     /* Loop for each line. */
     while(iYLoop--)
     {
          /* Setup for X loop. */
          lpSrcTmp = lpSrcStart;
          lpDstTmp = lpDstStart;
          iXLoop = iXLength;

          /* Copy one line down. */
          while(iXLoop--)
               *lpDstTmp++ = *lpSrcTmp++;
     
          /* Update line start pointers. */
          lpSrcStart -= MDA_WIDTH;
          lpDstStart -= MDA_WIDTH;
     }

     /* Blank last line with spaces. */
     iXLoop = iXLength;
     while(iXLoop--)
          *lpDstStart++ = (*lpDstStart & 0xFF00) | 0x0020;     
}

/*****************************************************************************
** Scroll the area from (sx,sy) to (dx,dy) left one characeter. The rightmost
** characters are replaced with spaces. No checking is done to ensure that the
** area is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAScrollLeft(int iSX, int iSY, int iDX, int iDY)
{
     WORD FAR  *lpSrcStart, FAR *lpSrcTmp;
     WORD FAR  *lpDstStart, FAR *lpDstTmp;
     int       iXLoop, iYLoop, iXLength;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop. */
     iYLoop     = iDY - iSY + 1;
     iXLength   = iDX - iSX;
     lpSrcStart = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iSX * 2)) + 2);     
     lpDstStart = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iSX * 2)));

     /* Loop for each line. */
     while(iYLoop--)
     {
          /* Setup for X loop. */
          lpSrcTmp = lpSrcStart;
          lpDstTmp = lpDstStart;
          iXLoop = iXLength;

          /* Shift line left. */
          while(iXLoop--)
               *lpDstTmp++ = *lpSrcTmp++;
          
          /* Set last character to a space. */
          *lpDstTmp = (*lpDstTmp & 0xFF00) | 0x0020;
     
          /* Update line start pointers. */
          lpSrcStart += MDA_WIDTH;
          lpDstStart += MDA_WIDTH;
     }
}

/*****************************************************************************
** Scroll the area from (sx,sy) to (dx,dy) right one characeter. The leftmost
** characters are replaced with spaces. No checking is done to ensure that the
** area is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAScrollRight(int iSX, int iSY, int iDX, int iDY)
{
     WORD FAR  *lpSrcStart, FAR *lpSrcTmp;
     WORD FAR  *lpDstStart, FAR *lpDstTmp;
     int       iXLoop, iYLoop, iXLength;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop. */
     iYLoop     = iDY - iSY + 1;
     iXLength   = iDX - iSX;
     lpSrcStart = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iDX * 2)) - 2);     
     lpDstStart = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iDX * 2)));

     /* Loop for each line. */
     while(iYLoop--)
     {
          /* Setup for X loop. */
          lpSrcTmp = lpSrcStart;
          lpDstTmp = lpDstStart;
          iXLoop = iXLength;

          /* Shift line right. */
          while(iXLoop--)
               *lpDstTmp-- = *lpSrcTmp--;
          
          /* Set first character to a space. */
          *lpDstTmp = (*lpDstTmp & 0xFF00) | 0x0020;
     
          /* Update line start pointers. */
          lpSrcStart += MDA_WIDTH;
          lpDstStart += MDA_WIDTH;
     }
}
