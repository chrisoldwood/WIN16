/*****************************************************************************
** (C) Chris Wood 1995.
**
** MAIN.C - Application entry point and main window handler.
**
******************************************************************************
*/

#include <windows.h>
#include <ctl3d.h>
#include "apptypes.h"

/**** Defines & Global variables. *******************************************/
BYTE      szAppWndClass[] = "AppWindow";     /* Main window class name. */
BYTE      szAppName[] = "AppName";           /* Application name. */
HWND      hAppWnd;                           /* Main window. */
HINSTANCE hAppInst;                          /* Application instance. */

/**** Internal Prototypes. **************************************************/
WINDOWPROC AppWndProc(HWND, UINT, WPARAM, LPARAM);
BOOL NEAR RegisterAppWnd(HINSTANCE);
VOID NEAR ExitApp(VOID);

/**** External Prototypes. **************************************************/
extern VOID FAR ShowAboutBox(VOID);

/****************************************************************************
** Application entry point. All window class registration, initialisation of
** CTL3D and creation of the main window.
*/
int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, WORD nCmdShow)
{
     MSG  msg;                     /* Windows messages. */
     BOOL bUseCtl3d=FALSE;         /* Are we using 3d dialogs? */
     HINSTANCE hCtl3d;             /* Handle to ctl3d libaray. */
     
     /* Check for previous instance. */
     if (hPrevInstance)
     {
     	/* Bring the previous instance to the front. */
		GetInstanceData(hPrevInstance, (NPSTR) &hAppWnd, 2);
		if (GetWindowLong(hAppWnd, GWL_STYLE) & WS_ICONIC)
		{
			/* If it is an icon restore it. */
			SendMessage(hAppWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
		}
		SetFocus(hAppWnd);
		  
          /* Only allow one instance for now. */
		return FALSE;     
     }

     /* Copy this instance to global. */
     hAppInst = hInstance;

     /* Check for CTL3D. */
     hCtl3d = LoadLibrary("ctl3d.dll");
     if (hCtl3d > 32)
     {
          /* Free up the library first. */
          FreeLibrary(hCtl3d);
          
          /* Intialise CTL3D. */
          Ctl3dRegister(hInstance);
          Ctl3dAutoSubclass(hInstance);
          bUseCtl3d = TRUE;
     }
     
     /* Register main window class. */
     if (!RegisterAppWnd(hInstance))
          return FALSE;
     
     /* Create application window. */
     hAppWnd = CreateWindow((LPSTR) szAppWndClass, (LPSTR) szAppName, 
                              WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
			               CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
                              NULL, NULL, hInstance, NULL);

     /* Show main window. */
     ShowWindow(hAppWnd, SW_SHOW);

     /* Do the usual stuff! */
     while(GetMessage(&msg, NULL, 0, 0))
     {
	     TranslateMessage(&msg);
          DispatchMessage(&msg);
     }

     /* Check if we used 3d dialogs. */
     if (bUseCtl3d)
     {
       	/* Remove 3d dialogs stuff. */
	     Ctl3dUnregister(hInstance);
     }
     
     /* Exit. */
     return msg.wParam;
}

/*******************************************************************************
** Main window message handler.
**/
WINDOWPROC AppWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{                   
	PAINTSTRUCT	ps;
	
     /* Decode message.*/
     switch (iMsg)
     {
          case WM_CREATE:
               break;

          case WM_COMMAND:
               break;

          case WM_PAINT:
		     BeginPaint(hWnd, &ps);
               EndPaint(hWnd, &ps);
               break;

          case WM_CLOSE:
               ShowAboutBox();
               /* Clean up. */
               DestroyWindow(hWnd);
               break;
               
          case WM_DESTROY:
               /* Send exit message. */
               PostQuitMessage(0);
               break;
                              
          default:
               return DefWindowProc (hWnd, iMsg, wParam, lParam);
     }

     return FALSE;
}

/*******************************************************************************
** Register the main window class.
**/
BOOL NEAR RegisterAppWnd(HINSTANCE hInstance)
{
     WNDCLASS  MainClass;

     MainClass.style         = CS_VREDRAW | CS_HREDRAW;
     MainClass.lpfnWndProc   = (WNDPROC) AppWndProc;
     MainClass.cbClsExtra    = 0;
     MainClass.cbWndExtra    = 0;
     MainClass.hInstance     = hInstance;
     MainClass.hIcon         = LoadIcon(hInstance, (LPSTR) "AppIcon");
     MainClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
     MainClass.hbrBackground = GetStockObject (WHITE_BRUSH);
     MainClass.lpszMenuName  = NULL;
     MainClass.lpszClassName = (LPSTR) szAppWndClass;

     return RegisterClass(&MainClass);
}

/*******************************************************************************
** Start the close down procedure. 
**/
VOID NEAR ExitApp(VOID)
{
     /* Close the parent window. */
     PostMessage(hAppWnd, WM_CLOSE, 0, 0L);
}
