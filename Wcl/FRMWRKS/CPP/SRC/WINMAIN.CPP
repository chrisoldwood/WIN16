/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINMAIN.CPP - Application entry point.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"
#include "appinst.hpp"
#include "mainwnd.hpp"

/**** Defines & Global variables. *******************************************/
MAINWND   *AppWnd;                 // Main window.
APPINST 	AppInst;                 // Application instance.

/****************************************************************************
** Application entry point. All window class registration, initialisation of
** CTL3D and creation of the main window.
*/
int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	BOOL		bOkay;			// Initilised okay?
     MSG  	msg;                // Windows messages.
	
	// Setup this instance.
	bOkay = AppInst.Initialise(hInstance, hPrevInstance, lpszCmdLine);
	if (!bOkay)
		return FALSE;
	        
	// Try to install CTL3D.
	AppInst.InitCtl3d();
	     
     // Create the application window and show.
 	AppWnd = new MAINWND(hInstance);
	AppWnd->Centre();
	AppWnd->Show(iCmdShow);

     // Do the usual stuff!
     while(GetMessage(&msg, NULL, 0, 0))
     {
	     TranslateMessage(&msg);
          DispatchMessage(&msg);
     }

	// Delete the application window.
	delete AppWnd;

	// Remove CTL3D.
	AppInst.TermCtl3d();
	
     // Exit.
     return msg.wParam;
}
