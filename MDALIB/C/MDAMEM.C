/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAMEM.C - MDA Library memory monitoring functions.
**
******************************************************************************
*/

#include <windows.h>
#include <toolhelp.h>
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
int	iMaxVrtMem, iMinVrtMem, iCurVrtMem;	/* Max, Min & Current free virtual memory. */
int	iVrtPages;						/* Total number of memory pages. */
int	iPageSize;						/* Size of memory page. */

extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/*****************************************************************************
** Initialise the memory monitors.
*/
VOID FAR MDAInitMemMonitors(VOID)
{
	BYTE 	 szValue[10];		/* Free resources as a string. */
	MEMMANINFO mmInfo;			/* Memory manager info. */
	int 		 iMemPc;			/* Memory value as a percent. */
	                                           
	/* Setup and call for memory manager info. */
	mmInfo.dwSize = sizeof(MEMMANINFO);
	MemManInfo((MEMMANINFO FAR *) &mmInfo);
//	iVrtPages = mmInfo.dwTotalLinearSpace;
	iVrtPages = (int) (mmInfo.dwTotalPages + mmInfo.dwSwapFilePages);
	iPageSize = mmInfo.wPageSize;
	
	/* Draw the Virtual memory partition and title. */
	MDADrawDHorizBar(0, MDA_WIDTH-1, 12, NORMAL);
	MDADrawCtrString(12, (LPSTR) " Virtual Memory ", BRIGHT);

	/* Get virtual memory and set min & max. */
//	iCurVrtMem = mmInfo.dwFreeLinearSpace;
//	iCurVrtMem = mmInfo.dwTotalUnlockedPages;
	iCurVrtMem = (int) (GetFreeSpace(NULL) / (DWORD) iPageSize);
	iMaxVrtMem = iMinVrtMem = iCurVrtMem;
	
	/* Convert resource value to string and display. */ 
	iMemPc = (int) (((long) iCurVrtMem * (long) 100) / (long) iVrtPages);
	wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iMemPc);
	MDADrawCtrString(15, (LPSTR) szValue, NORMAL);
     MDADrawLftString(2, 15, (LPSTR) szValue, NORMAL);
     MDADrawRgtString(MDA_WIDTH-3, 15, (LPSTR) szValue, NORMAL);
     
     /* Draw graph and Min/Max markers. */
     MDADrawHorizGraph(2, 14, 76, iCurVrtMem, iVrtPages);
     MDADrawHGraphMarker(2, 13, 76, iCurVrtMem, iVrtPages, DOWNNUDGE, NORMAL);
}

/*****************************************************************************
** Update the memory monitors.
*/
VOID FAR MDAUpdateMemMonitors(VOID)
{         
	int 		 iFreeMem;		/* Latest free memory. */
	BYTE 	 szValue[10];		/* Free resources as a string. */
	MEMMANINFO mmInfo;			/* Memory manager info. */
	int 		 iMemPc;			/* Memory value as a percent. */
	
	/* Setup and call for memory manager info. */
	mmInfo.dwSize = sizeof(MEMMANINFO);
	if (!MemManInfo((MEMMANINFO FAR *) &mmInfo))
		return;

	/* Get current free vitual memory. */
//	iFreeMem = mmInfo.dwFreeLinearSpace;
//	iFreeMem = mmInfo.dwTotalUnlockedPages;
	iFreeMem = (int) (GetFreeSpace(NULL) / (DWORD) iPageSize);

	/* Validate value. */
	if ( (iFreeMem < 0) || (iFreeMem > iVrtPages) )
		return;
		
	/* Check for change. */
	if (iFreeMem != iCurVrtMem)
	{                
		/* Update old value. */
		iCurVrtMem = iFreeMem;
		iMemPc = (int) (((long) iCurVrtMem * (long) 100) / (long) iVrtPages);
		wsprintf((LPSTR) szValue, (LPSTR) "%3d%%", iMemPc);
		MDADrawCtrString(15, (LPSTR) szValue, NORMAL);
		
		/* Update graph. */
     	MDADrawHorizGraph(2, 14, 76, iCurVrtMem, iVrtPages);
		
		/* Check against Min & Max. */
		if (iCurVrtMem < iMinVrtMem)
		{   
			/* Remove old min marker. */
			if (iMinVrtMem != iMaxVrtMem)
     			MDADrawHGraphMarker(2, 13, 76, iMinVrtMem, iVrtPages, SPACE, NORMAL);
			
			/* Update Min. */
			iMinVrtMem = iCurVrtMem;
     		MDADrawLftString(2, 15, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 13, 76, iMinVrtMem, iVrtPages, DOWNNUDGE, NORMAL);
		}
		else if (iCurVrtMem > iMaxVrtMem)
		{
			/* Remove old max marker. */
			if (iMinVrtMem != iMaxVrtMem)
     			MDADrawHGraphMarker(2, 13, 76, iMaxVrtMem, iVrtPages, SPACE, NORMAL);
			
			/* Update Max. */
			iMaxVrtMem = iCurVrtMem;
     		MDADrawRgtString(MDA_WIDTH-3, 15, (LPSTR) szValue, NORMAL);
     		MDADrawHGraphMarker(2, 13, 76, iMaxVrtMem, iVrtPages, DOWNNUDGE, NORMAL);
		}
	}
}
