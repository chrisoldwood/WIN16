/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDASTRNG.C - MDA Library string drawing functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdadefs.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Draw a string left justified at (x,y) in the colour specified.
*/
VOID EXPORTFUNC MDADrawLftString(int iX, int iY, LPSTR lpString, BYTE cColour)
{
     LPSTR     lpDisplay;
     
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Calculate the screen address. */
     lpDisplay = lpMDA + ((iY * MDA_WIDTH * 2) + (iX * 2));
         
     /* Loop for each character. */
     while(*lpString)
     {    
     	/* Store the character. */
          *lpDisplay++ = *lpString++;
          
          /* OR in the foreground colour. */
          *lpDisplay++ = (*lpDisplay & 0xF0) | cColour;
     }     
}

/*****************************************************************************
** Draw a string right justified onto (x,y) in the colour specified.
*/
VOID EXPORTFUNC MDADrawRgtString(int iX, int iY, LPSTR lpString, BYTE cColour)
{
     LPSTR     lpDisplay;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;
	
	/* Find start position of string. */
     iX -= lstrlen(lpString) - 1;    

     /* Calculate the screen address. */
     lpDisplay = lpMDA + ((iY * MDA_WIDTH * 2) + (iX * 2));

     /* Loop for each character. */
     while(*lpString)
     {    
     	/* Store the character. */
          *lpDisplay++ = *lpString++;
          
          /* OR in the foreground colour. */
          *lpDisplay++ = (*lpDisplay & 0xF0) | cColour;
     }     
}

/*****************************************************************************
** Centre a string on the line iY in the colour specified.
*/
VOID EXPORTFUNC MDADrawCtrString(int iY, LPSTR lpString, BYTE cColour)
{
     LPSTR     lpDisplay;
     int       iX;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;
	
	/* Find start position of string. */
     iX = (MDA_WIDTH - lstrlen(lpString)) >> 1;    

     /* Calculate the screen address. */
     lpDisplay = lpMDA + ((iY * MDA_WIDTH * 2) + (iX * 2));

     /* Loop for each character. */
     while(*lpString)
     {    
     	/* Store the character. */
          *lpDisplay++ = *lpString++;
          
          /* OR in the foreground colour. */
          *lpDisplay++ = (*lpDisplay & 0xF0) | cColour;
     }     
}
