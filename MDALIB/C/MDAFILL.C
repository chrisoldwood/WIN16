/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAFILL.C - MDA Library area fill functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdadefs.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/******************************************************************************
** Clear the area of the display from (sx,sy) to (dx,dy). No checking is done
** to ensure the rectangle is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAClearRect(int iSX, int iSY, int iDX, int iDY)
{
     WORD FAR  *lpDisplay;
     WORD FAR  *lpLineStart;
     int       iXLoop, iYLoop, iXLength;
     
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop. */
     iYLoop       = iDY - iSY + 1;
     iXLength     = iDX - iSX + 1;
     lpLineStart  = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iSX * 2)));

     /* Loop for each rectangle line. */
     while(iYLoop--)
     {
          /* Setup X loop. */
          lpDisplay = lpLineStart;
          iXLoop = iXLength;

          /* Loop for rectangle width. */
          while(iXLoop--)
               *lpDisplay++ = 0x0720;
     
          /* Update line start pointer. */
          lpLineStart += MDA_WIDTH;
     }
}

/******************************************************************************
** Fill the area of the display from (sx,sy) to (dx,dy) using the character
** specified. The colour determines the characters background. No checking is
** done to ensure the rectangle is defined from top-left to bottom-right.
*/
VOID EXPORTFUNC MDAFillRect(int iSX, int iSY, int iDX, int iDY, BYTE cChar,
                              BYTE cFGCol, BYTE cBGCol)
{
     WORD FAR  *lpDisplay;
     WORD FAR  *lpLineStart;
     WORD      wChar=NULL;
     int       iXLoop, iYLoop, iXLength;
     
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Combine character and attribute. */
     cBGCol  <<= 4;
     cFGCol   |= cBGCol;
     wChar     = ((WORD) cFGCol) << 8;
     wChar    |= (WORD) cChar;

     /* Setup loop. */
     iYLoop       = iDY - iSY + 1;
     iXLength     = iDX - iSX + 1;
     lpLineStart  = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iSX * 2)));

     /* Loop for each rectangle line. */
     while(iYLoop--)
     {
          /* Setup X loop. */
          lpDisplay = lpLineStart;
          iXLoop = iXLength;

          /* Loop for rectangle width. */
          while(iXLoop--)
               *lpDisplay++ = wChar;
     
          /* Update line start pointer. */
          lpLineStart += MDA_WIDTH;
     }
}
