/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAGRAPH.C - MDA Library graph drawing functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Draw a horizontal graph from (x,y) of the specified length using the max
** and current value.
** This assumes that the graph starts at 0.
*/
VOID EXPORTFUNC MDADrawHorizGraph(int iX, int iY, int iLen, int iVal, int iMax)
{    
	int	iValPos;			/* Position of the value. */
	
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;
               
     /* Calculate relative position. */
	iValPos = (int) (((long) iLen * (long) iVal) / (long) iMax);

	/* Draw graph "highlight". */
	if (iValPos != 0)
		MDADrawHorizLine(iX, iX + iValPos - 1, iY, HALFBLOCK, BRIGHT);
	
	/* Draw graph "background". */
	if (iValPos != iLen)
		MDADrawHorizLine(iX + iValPos, iX + iLen - 1, iY, HALFBLOCK, NORMAL);
}

/*****************************************************************************
** Draw a horizontal graph marker defined by a graph from (x,y) of the 
** specified length using the max and current value. The character is the 
** marker to use.
** This assumes that the graph starts at 0.
*/
VOID EXPORTFUNC MDADrawHGraphMarker(int iX, int iY, int iLen, int iVal, int iMax,
							  BYTE cMarker, BYTE cColour)
{    
	int	iValPos;			/* Position of the value. */
	
     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;
               
     /* Calculate relative position. */
	iValPos = (int) (((long) iLen * (long) iVal) / (long) iMax);
	 
	/* Draw marker. */
	MDADrawChar(iX + iValPos, iY, cMarker, cColour);
}
