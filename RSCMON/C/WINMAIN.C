/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINMAIN.C - Application entry & exit point.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"
#include "mdalib.h"

/**** Defines & Global variables. *******************************************/
HINSTANCE hAppInst;                          /* Application instance. */

extern HWND hAppWnd;					/* Application window. */

/**** Internal Prototypes. **************************************************/

/**** External Prototypes. **************************************************/
extern VOID FAR CreateAppWindow(VOID);

/****************************************************************************
** Application entry point. 
** Initialisation of CTL3D and creation of the main window.
*/
int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, WORD nCmdShow)
{
     MSG  	msg;                /* Windows messages. */
     
     /* Check for previous instance. */
     if (hPrevInstance)
     {
     	/* Bring the previous instance to the front. */
		GetInstanceData(hPrevInstance, (BYTE *) &hAppWnd, 2);
		if (GetWindowLong(hAppWnd, GWL_STYLE) & WS_ICONIC)
		{
			/* If it is an icon restore it. */
			SendMessage(hAppWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
		}
		SetFocus(hAppWnd);
		  
          /* Only allow one instance for now. */
		return FALSE;     
     }

     /* Copy this instance and command line to globals. */
     hAppInst = hInstance;

     /* Create the application window and show. */
     CreateAppWindow();
     ShowWindow(hAppWnd, SW_SHOWMINIMIZED);

	/* Turn on the MDA display and clear. */
	MDAAutoMonitor();

	/* Show copyright. */
	MDADrawLftString(2, 21, (LPSTR) "MDA Library & Resource Monitor (C) Chris Wood 1994/5", NORMAL);
     /* Do the usual stuff! */
     while(GetMessage(&msg, NULL, 0, 0))
     {
	     TranslateMessage(&msg);
          DispatchMessage(&msg);
     }
     
     /* Exit. */
     return msg.wParam;
}
