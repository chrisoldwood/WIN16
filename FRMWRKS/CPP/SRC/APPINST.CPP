/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPINST.CPP - Application instance class functions.
**
******************************************************************************
*/

#include <windows.h>  
#include <ctl3d.h>
#include "apptypes.h"
#include "debug.h"
#include "appinst.hpp"       
               
/*****************************************************************************
** Initialise the application.
** This stores the application specific data and checks for a previous, which
** if occurs is restored.
*/
BOOL APPINST::Initialise(HINSTANCE hCurr, HINSTANCE hPrev, LPSTR lpszCmdLine)
{    
	// Store instance data.
	hCurrInst = hCurr;
	hPrevInst = hPrev;
	lpszArgs  = lpszCmdLine;

     // Check for previous instance.
     if (hPrevInst)
     {                            
     	HWND	hPrevWnd;					// Previous instance main window.
     	
     	// Bring the previous instance to the front.
		GetInstanceData(hPrevInst, (unsigned char __near *) &hPrevWnd, 2);
		if (GetWindowLong(hPrevWnd, GWL_STYLE) & WS_ICONIC)
		{
			// If it is an icon restore it.
			SendMessage(hPrevWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
		}
		SetFocus(hPrevWnd);
		  
          // Only allow one instance for now.
		return ERROR;     
     }

	// Set up any other data.
	lpszIniFile = "cron.ini";
	
	// Initialisation okay.
	return OKAY;
}

/*****************************************************************************
** Intialise CTL3D, if available.
*/
VOID APPINST::InitCtl3d(VOID)
{
	HINSTANCE hCtl3d;				// Ctl3d exists?
	
     // Check for CTL3D.
     hCtl3d = LoadLibrary("ctl3d.dll");
     if (hCtl3d > 32)
     {
          // Free up the library first.
          FreeLibrary(hCtl3d);
          
          // Intialise CTL3D.
          Ctl3dRegister(hCurrInst);
          Ctl3dAutoSubclass(hCurrInst);

		// Remember.
          bUsingCtl3d = TRUE;
     }
}

/*****************************************************************************
** Terminate CTL3D, if used.
*/
VOID APPINST::TermCtl3d(VOID)
{
     // Check if are used 3d dialogs.
     if (bUsingCtl3d)
     {
       	// Remove 3d dialogs stuff.
	     Ctl3dUnregister(hCurrInst);
     }
}
