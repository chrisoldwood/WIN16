/*****************************************************************************
** (C) Chris Wood 1995.
**
** DBGOUT.C - Debugger code and output.
**
******************************************************************************
*/

#include "af.h"
#include "menursc.h"
#include <string.h>

/**** Defs. *****************************************************************/
#define TIMEOUT          500                 /* Timer interval - 1 sec. */
#define DEBUG_BUF_LEN    2048                /* Debug message buffer length. */

/**** Global Vars. **********************************************************/
UINT      iTimerID;                          /* Application timer. */
CHAR      szDebugMsg[DEBUG_BUF_LEN];         /* Temporary debug string buffer. */

extern HWND	  hAppWnd;			     /* Application window. */
extern HMENU	  hMenu;					/* Current menu. */
extern HINSTANCE hAppInst;              	/* Application instance. */

/**** Prototypes. ***********************************************************/
VOID CALLBACK RscCheckTimerProc(HWND hWnd, UINT uMsg, UINT iID, DWORD dwSysTime);

extern VOID OutputMsg32(LPSTR lpszMsg);
extern VOID ClearOutput32(VOID);

/*****************************************************************************
** Start the monitor
*/
VOID StartRscCheck(VOID)
{
     /* Kick off timer. */
     iTimerID = SetTimer(NULL, 0, TIMEOUT, (TIMERPROC) RscCheckTimerProc);

     /* Hide main window. */
     ShowWindow(hAppWnd, SW_MINIMIZE);
}

/*****************************************************************************
** Stop waiting for the application.
*/
VOID StopRscCheck(VOID)
{
     /* Kill timer. */
     if (iTimerID)
          KillTimer(NULL, iTimerID);
}

/*****************************************************************************
** Timer callback procedure to show resource stats.
*/
VOID CALLBACK RscCheckTimerProc(HWND hWnd, UINT uMsg, UINT iID, DWORD dwSysTime)
{
     MEMORYSTATUS msStats;

     /* Clear the MDA and window. */
     ClearOutput32();

     /* Get memory stats. */
     msStats.dwLength = sizeof(MEMORYSTATUS);
     GlobalMemoryStatus(&msStats);

     OutputMsg32("\n\n");

     /* Show % usage. */
     wsprintf(szDebugMsg, "Current Load:   %d\n", msStats.dwMemoryLoad);
     OutputMsg32(szDebugMsg);

     OutputMsg32("\n");

     /* Show total physical RAM. */
     wsprintf(szDebugMsg, "Total Physical: 0x%08X  (%5d K)\n", msStats.dwTotalPhys, msStats.dwTotalPhys/1024);
     OutputMsg32(szDebugMsg);

     /* Show free physical. */
     wsprintf(szDebugMsg, "Free Physical:  0x%08X  (%5d K)\n", msStats.dwAvailPhys, msStats.dwAvailPhys/1024);
     OutputMsg32(szDebugMsg);

     OutputMsg32("\n");

     /* Show total page file. */
     wsprintf(szDebugMsg, "Total PageFile: 0x%08X  (%5d K)\n", msStats.dwTotalPageFile, msStats.dwTotalPageFile/1024);
     OutputMsg32(szDebugMsg);

     /* Show free page file. */
     wsprintf(szDebugMsg, "Free PageFile:  0x%08X  (%5d K)\n", msStats.dwAvailPageFile, msStats.dwAvailPageFile/1024);
     OutputMsg32(szDebugMsg);

     OutputMsg32("\n");

     /* Show total virtual. */
     wsprintf(szDebugMsg, "Total Virtual:  0x%08X  (%5d K)\n", msStats.dwTotalVirtual, msStats.dwTotalVirtual/1024);
     OutputMsg32(szDebugMsg);

     /* Show free virtual. */
     wsprintf(szDebugMsg, "Free Virtual:   0x%08X  (%5d K)\n", msStats.dwAvailVirtual, msStats.dwAvailVirtual/1024);
     OutputMsg32(szDebugMsg);
}
