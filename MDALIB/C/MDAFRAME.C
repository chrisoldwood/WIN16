/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAFRAME.C - MDA Library frame drawing functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Draw a frame from (sx,sy) to (dx,dy) using the single line characters in
** the colour specified.
*/
VOID EXPORTFUNC MDADrawSFrame(int iSX, int iSY, int iDX, int iDY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* First draw the main lines. */
     MDADrawHorizLine(iSX, iDX, iSY, S_HORZBAR, cColour);
     MDADrawHorizLine(iSX, iDX, iDY, S_HORZBAR, cColour);
     MDADrawVertLine (iSX, iSY, iDY, S_VERTBAR, cColour);
     MDADrawVertLine (iDX, iSY, iDY, S_VERTBAR, cColour);

     /* Then plot the corner characters. */     
     MDADrawChar(iSX, iSY, S_TOPLEFT,  cColour);
     MDADrawChar(iDX, iSY, S_TOPRIGHT, cColour);
     MDADrawChar(iDX, iDY, S_BOTRIGHT, cColour);
     MDADrawChar(iSX, iDY, S_BOTLEFT,  cColour);
}

/*****************************************************************************
** Draw a frame from (sx,sy) to (dx,dy) using the double line characters in
** the colour specified.
*/
VOID EXPORTFUNC MDADrawDFrame(int iSX, int iSY, int iDX, int iDY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* First draw the main lines. */
     MDADrawHorizLine(iSX, iDX, iSY, D_HORZBAR, cColour);
     MDADrawHorizLine(iSX, iDX, iDY, D_HORZBAR, cColour);
     MDADrawVertLine (iSX, iSY, iDY, D_VERTBAR, cColour);
     MDADrawVertLine (iDX, iSY, iDY, D_VERTBAR, cColour);

     /* Then plot the corner characters. */     
     MDADrawChar(iSX, iSY, D_TOPLEFT,  cColour);
     MDADrawChar(iDX, iSY, D_TOPRIGHT, cColour);
     MDADrawChar(iDX, iDY, D_BOTRIGHT, cColour);
     MDADrawChar(iSX, iDY, D_BOTLEFT,  cColour);
}

/*****************************************************************************
** Draw a horizontal bar from (sx,y) to (dx,y) that matches the edge of a
** frame using the single line characters in the colour specified.
*/
VOID EXPORTFUNC MDADrawSHorizBar(int iSX, int iDX, int iY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

	/* Draw the basic line. */
     MDADrawHorizLine(iSX, iDX, iY, S_HORZBAR, cColour);
     
     /* Now match the edges. */
     MDADrawChar(iSX, iY, S_SIDELEFT,  cColour);
     MDADrawChar(iDX, iY, S_SIDERIGHT, cColour);
}

/*****************************************************************************
** Draw a horizontal bar from (sx,y) to (dx,y) that matches the edge of a
** frame using the double line characters in the colour specified.
*/
VOID EXPORTFUNC MDADrawDHorizBar(int iSX, int iDX, int iY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

	/* Draw the basic line. */
     MDADrawHorizLine(iSX, iDX, iY, D_HORZBAR, cColour);
     
     /* Now match the edges. */
     MDADrawChar(iSX, iY, D_SIDELEFT,  cColour);
     MDADrawChar(iDX, iY, D_SIDERIGHT, cColour);
}

/*****************************************************************************
** Draw a vertical bar from (x,sy) to (x,dy) that matches the edge of a
** frame using the single line characters in the colour specified.
*/
VOID EXPORTFUNC MDADrawSVertBar(int iX, int iSY, int iDY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

	/* Draw the basic line. */
     MDADrawVertLine(iX, iSY, iDY, S_VERTBAR, cColour);
     
     /* Now match the edges. */
     MDADrawChar(iX, iSY, S_TOPMID, cColour);
     MDADrawChar(iX, iDY, S_BOTMID, cColour);
}

/*****************************************************************************
** Draw a vertical bar from (x,sy) to (x,dy) that matches the edge of a
** frame using the double line characters in the colour specified.
*/
VOID EXPORTFUNC MDADrawDVertBar(int iX, int iSY, int iDY, BYTE cColour)
{
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

	/* Draw the basic line. */
     MDADrawVertLine(iX, iSY, iDY, D_VERTBAR, cColour);
     
     /* Now match the edges. */
     MDADrawChar(iX, iSY, D_TOPMID, cColour);
     MDADrawChar(iX, iDY, D_BOTMID, cColour);
}
