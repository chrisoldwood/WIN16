/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINMAIN.C - Application entry point.
**
******************************************************************************
*/

#include "af.h"
#include <ctl3d.h>
#include <direct.h>
#include "winutils.h"
#include "strngrsc.h"

/**** Defs. *****************************************************************/
#define TITLE_LEN		40				/* Length of application name. */

/**** Global Vars. **********************************************************/
HINSTANCE hAppInst;              			/* Application instance. */
HINSTANCE	hPrevInst;					/* Previous instance. */
LPSTR	lpszArgs;						/* Command line. */
HACCEL	hAccel;						/* Keyboard accelerator table. */
BYTE		szTitle[TITLE_LEN];				/* Application title. */

extern HWND	hAppWnd;					/* Application window. */

/**** Prototypes. ***********************************************************/
extern BOOL FAR RegisterAppWnd(VOID);
extern VOID FAR CreateAppWnd(VOID);
extern VOID FAR CleanUpAppWnd(VOID);
extern VOID OutputMsg32(LPSTR lpszMsg);
extern VOID SetTitle32(LPSTR lpszMsg);
extern VOID StartRscCheck(VOID);

/*****************************************************************************
** Application entry point.
*/
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, 
				int iCmdShow)
{
     MSG	msg;                	/* Windows message. */

	/* Setup this instance. */
	hAppInst  = hInstance;
	hPrevInst = hPrevInstance;
	lpszArgs  = lpszCmdLine;

     /* Check for previous instance. */
     if (!hPrevInst)
     {                            
          /* Register window classes. */
		if (!RegisterAppWnd())
			return ERROR;
     }

	/* Get the application title. */
	LoadRscString(IDS_APPNAME, (LPSTR) szTitle, TITLE_LEN);

     /* Display on the MDA. */
     SetTitle32(szTitle);

	/* Get the keyboard accelerator table. */
	hAccel = LoadRscAccelerators("AppKeys");	

	/* Kick in ctl3d. */
	Ctl3dRegister(hAppInst);
	Ctl3dAutoSubclass(hAppInst);
	        
	/* Create the main window. */
	CreateAppWnd();

	/* Show the window and update toolbar. */
	ShowWindow(hAppWnd, iCmdShow);
     StartRscCheck();

     /* Process the windows messages. */
     while(GetMessage(&msg, NULL, 0, 0))
     {    
     	if (!TranslateAccelerator(hAppWnd, hAccel, &msg))
     	{
	     	TranslateMessage(&msg);
          	DispatchMessage(&msg);
          }
     }

	/* Cleanup. */
	Ctl3dUnregister(hAppInst);
     CleanUpAppWnd();
     
     /* Exit. */
     return msg.wParam;
}
