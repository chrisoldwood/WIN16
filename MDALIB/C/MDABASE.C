/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDABASE.C - MDA Library basic drawing functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdadefs.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Plot a character at (x,y) in the colour specified.
*/
VOID EXPORTFUNC MDADrawChar(int iX, int iY, BYTE cChar, BYTE cColour)
{
     WORD FAR	*lpDisplay;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;
     
     /* Calculate the screen address. */
     lpDisplay  = (WORD FAR *) (lpMDA + ((iY * MDA_WIDTH * 2) + (iX * 2)));          
     
	/* Mask out character and foreground nybble (NB: LO-HI). */
	*lpDisplay &= 0xF000;
	
     /* OR in character and attribute. */
     *lpDisplay |= (((WORD) cColour) << 8) | (WORD) cChar;
}

/*****************************************************************************
** Draw a horizontal line of using one character from (sx,y) to (dx,y) using
** the colour specified. 
*/
VOID EXPORTFUNC MDADrawHorizLine(int iSX, int iDX, int iY, BYTE cChar, BYTE cColour)
{
     WORD FAR  *lpDisplay;
     int       iLoop;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop. */
     iLoop     = iDX - iSX + 1;
     lpDisplay = (WORD FAR *) (lpMDA + ((iY * MDA_WIDTH * 2) + (iSX * 2)));     
          
     /* Plot the line. */
     while(iLoop--)
     {
		/* Mask out character and foreground nybble. */
		*lpDisplay &= 0xF000;

     	/* OR in character and attribute. */
          *lpDisplay++ |= (((WORD) cColour) << 8) | (WORD) cChar;    
	}
}

/****************************************************************************
** Draw a vertical line of using one character from (x,sy) to (x,dy) using
** the colour specified. 
*/
VOID EXPORTFUNC MDADrawVertLine(int iX, int iSY, int iDY, BYTE cChar, BYTE cColour)
{
     WORD FAR  *lpDisplay;
     int       iLoop;
     
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop. */
     iLoop     = iDY - iSY + 1;    
     lpDisplay = (WORD FAR *) (lpMDA + ((iSY * MDA_WIDTH * 2) + (iX * 2)));     

     /* Plot the line. */
     while(iLoop--)
     {
		/* Mask out character and foreground nybble. */
		*lpDisplay &= 0xF000;

     	/* OR in character and attribute. */
          *lpDisplay |= (((WORD) cColour) << 8) | (WORD) cChar;    
                
          /* Move down a line. */
          lpDisplay += MDA_WIDTH;
     }
}
