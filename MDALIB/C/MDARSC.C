/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDARSC.C - MDA Library resource monitoring functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
int	iMaxGDIRsc, iMinGDIRsc, iCurGDIRsc;	/* Max, Min & Current Free GDI resources. */
int	iMaxSysRsc, iMinSysRsc, iCurSysRsc;	/* Max, Min & Current Free System resources. */
int	iMaxUsrRsc, iMinUsrRsc, iCurUsrRsc;	/* Max, Min & Current Free User resources. */

extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Initialise the resource monitors.
*/
VOID FAR MDAInitRscMonitors(VOID)
{
	BYTE szValue[10];	/* Free resources as a string. */

	/* Draw the GDI resource partition and title. */
	MDADrawCtrString(0, (LPSTR) " GDI Resources ", BRIGHT);

	/* Get GDI resources and set min & max. */
	iCurGDIRsc = GetFreeSystemResources(GFSR_GDIRESOURCES);
	iMaxGDIRsc = iMinGDIRsc = iCurGDIRsc;
	
	/* Convert resource value to string and display. */
	wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurGDIRsc);
	MDADrawCtrString(3, (LPSTR) szValue, NORMAL);
     MDADrawLftString(2, 3, (LPSTR) szValue, NORMAL);
     MDADrawRgtString(MDA_WIDTH-3, 3, (LPSTR) szValue, NORMAL);
     
     /* Draw graph and Min/Max markers. */
     MDADrawHorizGraph(2, 2, 76, iCurGDIRsc, 100);
     MDADrawHGraphMarker(2, 1, 76, iCurGDIRsc, 100, DOWNNUDGE, NORMAL);
     
	/* Draw the System resource partition and title. */
	MDADrawDHorizBar(0, MDA_WIDTH-1, 4, NORMAL);
	MDADrawCtrString(4, (LPSTR) " System Resources ", BRIGHT);

	/* Get GDI resources and set min & max. */
	iCurSysRsc = GetFreeSystemResources(GFSR_SYSTEMRESOURCES);
	iMaxSysRsc = iMinSysRsc = iCurSysRsc;

	/* Convert resource value to string and display. */
	wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurSysRsc);
	MDADrawCtrString(7, (LPSTR) szValue, NORMAL);
     MDADrawLftString(2, 7, (LPSTR) szValue, NORMAL);
     MDADrawRgtString(MDA_WIDTH-3, 7, (LPSTR) szValue, NORMAL);

     /* Draw graph and Min/Max markers. */
     MDADrawHorizGraph(2, 6, 76, iCurSysRsc, 100);
     MDADrawHGraphMarker(2, 5, 76, iCurSysRsc, 100, DOWNNUDGE, NORMAL);

	/* Draw the User resource partition and title. */
	MDADrawDHorizBar(0, MDA_WIDTH-1, 8, NORMAL);
	MDADrawCtrString(8, (LPSTR) " User Resources ", BRIGHT);

	/* Get GDI resources and set min & max. */
	iCurUsrRsc = GetFreeSystemResources(GFSR_USERRESOURCES);
	iMaxUsrRsc = iMinUsrRsc = iCurUsrRsc;

	/* Convert resource value to string and display. */
	wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurUsrRsc);
	MDADrawCtrString(11, (LPSTR) szValue, NORMAL);
     MDADrawLftString(2, 11, (LPSTR) szValue, NORMAL);
     MDADrawRgtString(MDA_WIDTH-3, 11, (LPSTR) szValue, NORMAL);

     /* Draw graph and Min/Max markers. */
     MDADrawHorizGraph(2, 10, 76, iCurUsrRsc, 100);
     MDADrawHGraphMarker(2, 9, 76, iCurUsrRsc, 100, DOWNNUDGE, NORMAL);
}

/*****************************************************************************
** Update the resource monitors.
*/
VOID FAR MDAUpdateRscMonitors(VOID)
{           
	int  iFreeRsc;		/* Current free resources. */
	BYTE szValue[10];	/* Value as a string. */
	
	/* Get current GDI resources. */
	iFreeRsc = GetFreeSystemResources(GFSR_GDIRESOURCES);
	if (iFreeRsc != iCurGDIRsc)
	{                
		/* Update old value. */
		iCurGDIRsc = iFreeRsc;
		wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurGDIRsc);
		MDADrawCtrString(3, (LPSTR) szValue, NORMAL);
		
		/* Update graph. */
     	MDADrawHorizGraph(2, 2, 76, iCurGDIRsc, 100);
		
		/* Check against Min & Max. */
		if (iCurGDIRsc < iMinGDIRsc)
		{   
			/* Remove old min marker. */
			if (iMinGDIRsc != iMaxGDIRsc)
     			MDADrawHGraphMarker(2, 1, 76, iMinGDIRsc, 100, SPACE, NORMAL);
			
			/* Update Min. */
			iMinGDIRsc = iCurGDIRsc;
     		MDADrawLftString(2, 3, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 1, 76, iMinGDIRsc, 100, DOWNNUDGE, NORMAL);
		}
		else if (iCurGDIRsc > iMaxGDIRsc)
		{
			/* Remove old max marker. */
			if (iMinGDIRsc != iMaxGDIRsc)
     			MDADrawHGraphMarker(2, 1, 76, iMaxGDIRsc, 100, SPACE, NORMAL);
			
			/* Update Max. */
			iMaxGDIRsc = iCurGDIRsc;
     		MDADrawRgtString(MDA_WIDTH-3, 3, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 1, 76, iMaxGDIRsc, 100, DOWNNUDGE, NORMAL);
		}
	}

	/* Get current System resources. */
	iFreeRsc = GetFreeSystemResources(GFSR_SYSTEMRESOURCES);
	if (iFreeRsc != iCurSysRsc)
	{
		/* Update old value. */
		iCurSysRsc = iFreeRsc;
		wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurSysRsc);
		MDADrawCtrString(7, (LPSTR) szValue, NORMAL);
		
		/* Update graph. */
     	MDADrawHorizGraph(2, 6, 76, iCurSysRsc, 100);

		/* Check against Min & Max. */
		if (iCurSysRsc < iMinSysRsc)
		{   
			/* Remove old min marker. */
			if (iMinSysRsc != iMaxSysRsc)
     			MDADrawHGraphMarker(2, 5, 76, iMinSysRsc, 100, SPACE, NORMAL);
			
			/* Update Min. */
			iMinSysRsc = iCurSysRsc;
     		MDADrawLftString(2, 7, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 5, 76, iMinSysRsc, 100, DOWNNUDGE, NORMAL);
		}
		else if (iCurSysRsc > iMaxSysRsc)
		{
			/* Remove old min marker. */
			if (iMinSysRsc != iMaxSysRsc)
     			MDADrawHGraphMarker(2, 5, 76, iMaxSysRsc, 100, SPACE, NORMAL);
			
			/* Update Max. */
			iMaxSysRsc = iCurSysRsc;
     		MDADrawRgtString(MDA_WIDTH-3, 7, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 5, 76, iMaxSysRsc, 100, DOWNNUDGE, NORMAL);
		}
	}

	/* Get current User resources. */
	iFreeRsc = GetFreeSystemResources(GFSR_USERRESOURCES);
	if (iFreeRsc != iCurUsrRsc)
	{
		/* Update old value. */
		iCurUsrRsc = iFreeRsc;
		wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iCurUsrRsc);
		MDADrawCtrString(11, (LPSTR) szValue, NORMAL);
		
		/* Update graph. */
     	MDADrawHorizGraph(2, 10, 76, iCurUsrRsc, 100);

		/* Check against Min & Max. */
		if (iCurUsrRsc < iMinUsrRsc)
		{   
			/* Remove old min marker. */
			if (iMinUsrRsc != iMaxUsrRsc)
     			MDADrawHGraphMarker(2, 9, 76, iMinUsrRsc, 100, SPACE, NORMAL);
			
			/* Update Min. */
			iMinUsrRsc = iCurUsrRsc;
     		MDADrawLftString(2, 11, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 9, 76, iMinUsrRsc, 100, DOWNNUDGE, NORMAL);
		}
		else if (iCurUsrRsc > iMaxUsrRsc)
		{
			/* Remove old min marker. */
			if (iMinUsrRsc != iMaxUsrRsc)
     			MDADrawHGraphMarker(2, 9, 76, iMaxUsrRsc, 100, SPACE, NORMAL);
			
			/* Update Max. */
			iMaxUsrRsc = iCurUsrRsc;
     		MDADrawRgtString(MDA_WIDTH-3, 11, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 9, 76, iMaxUsrRsc, 100, DOWNNUDGE, NORMAL);
		}
	}
}
