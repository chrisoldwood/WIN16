/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAAPP.C - MDA Library application monitoring functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
#define TIMER_REZ	100			/* Timer resolution - 1/10th second. */

#define RSC_TIMEOUT	20			/* Resource timer resolution. (20 1/10ths) */
#define MEM_TIMEOUT	20			/* Memory timer resolution. (20 1/10ths) */
#define CPU_TIMEOUT 1			/* CPU timer resolution. (1 1/10th) */

UINT	iTimerID=NULL;				/* Monitor timer ID. */
UINT iTimeCount;				/* Time counter. */
int  iCPUPos;					/* CPU monitor marker position. */

extern LPSTR lpMDA;                /* Full address of start of MDA. */
extern BOOL  bOn;                  /* Display output on/off. */

/**** Prototypes. ***********************************************************/
VOID EXPORTFUNC TimerProc(HWND hWnd, UINT iMsg, UINT iTimerID, DWORD dwTime);
VOID NEAR MDAInitCPUMonitor(VOID);
VOID NEAR MDAUpdateCPUMonitor(VOID);

extern VOID FAR MDAInitRscMonitors(VOID);
extern VOID FAR MDAUpdateRscMonitors(VOID);
extern VOID FAR MDAInitMemMonitors(VOID);
extern VOID FAR MDAUpdateMemMonitors(VOID);

/*****************************************************************************
** Start the resources monitors.
*/
VOID EXPORTFUNC MDAAutoMonitor(VOID)
{     
	/* Turn output on. */
	MDAOutput(TRUE);

	/* Clear the whole window. */
	MDAClearRect(0, 0, MDA_WIDTH-1, MDA_HEIGHT-1);

	/* Draw the main window frame. */
	MDADrawDFrame(0, 0, MDA_WIDTH-1, MDA_HEIGHT-1, NORMAL);

	/* Call the monitor init functions. */
	MDAInitRscMonitors();
	MDAInitMemMonitors();
	MDAInitCPUMonitor();

	/* Draw dummy line. */
	MDADrawDHorizBar(0, MDA_WIDTH-1, 16, NORMAL);

	/* Reset time counter. */
	iTimeCount = 0;
	
     /* Kick off the timer. */
	iTimerID = SetTimer(NULL, NULL, TIMER_REZ, (TIMERPROC) TimerProc);
}

/*****************************************************************************
** Handles the timer messages to update the resource monitors.
*/
VOID EXPORTFUNC TimerProc(HWND hWnd, UINT iMsg, UINT iTimerID, DWORD dwTime)
{
	/* Check for resources timeout. */
	if (iTimeCount % RSC_TIMEOUT == 0)
		MDAUpdateRscMonitors();

	/* Check for memory timeout. */
	if (iTimeCount % MEM_TIMEOUT == 0)
		MDAUpdateMemMonitors();

	/* Check for CPU timeout. */
	if (iTimeCount % CPU_TIMEOUT == 0)
		MDAUpdateCPUMonitor();
}

/*****************************************************************************
** Initialise the CPU monitor.
*/
VOID NEAR MDAInitCPUMonitor(VOID)
{
	/* Draw the CPU monitor partition, title and graph. */
	MDADrawDHorizBar(0, MDA_WIDTH-1, 22, NORMAL);
	MDADrawCtrString(22, (LPSTR) " CPU Monitor ", BRIGHT);
     MDADrawHorizLine(1, MDA_WIDTH-2, MDA_HEIGHT-2, HALFBLOCK, NORMAL);

	/* Initialise the CPU marker. */
	iCPUPos = 1;
	MDADrawChar(iCPUPos, MDA_HEIGHT-2, HALFBLOCK, BRIGHT);
}

/*****************************************************************************
** Update the CPU monitor.
*/
VOID NEAR MDAUpdateCPUMonitor(VOID)
{
	/* Undraw the old marker. */
	MDADrawChar(iCPUPos, MDA_HEIGHT-2, HALFBLOCK, NORMAL);
	
	/* Update the position. */
	iCPUPos++;
	if (iCPUPos == (MDA_WIDTH-1))
		iCPUPos = 1;
	
	/* Draw the new marker. */
	MDADrawChar(iCPUPos, MDA_HEIGHT-2, HALFBLOCK, BRIGHT);
}
