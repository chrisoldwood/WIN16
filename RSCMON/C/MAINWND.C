/*****************************************************************************
** (C) Chris Wood 1995.
**
** MAINWND.C - Application window functions.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"

/**** Defines & Global variables. *******************************************/
BYTE   szAppWndClass[] = "AppWindow";   /* Main window class name. */
HWND   hAppWnd;                         /* Main window. */

extern HINSTANCE hAppInst;              /* Application insatnce. */

/**** Internal Prototypes. **************************************************/
WINDOWPROC AppWndProc(HWND, UINT, WPARAM, LPARAM);

/*******************************************************************************
** Register the main window class and create the main window.
** The main window is a multiple of fixed system font characters in width and
** height. This also allocates the memory for the window text buffers.
**/
VOID FAR CreateAppWindow(VOID)
{
     WNDCLASS   MainClass;         /* Application window class. */

     /* Set up the class. */
     MainClass.style         = CS_VREDRAW | CS_HREDRAW;
     MainClass.lpfnWndProc   = (WNDPROC) AppWndProc;
     MainClass.cbClsExtra    = 0;
     MainClass.cbWndExtra    = 0;
     MainClass.hInstance     = hAppInst;
     MainClass.hIcon         = LoadIcon(hAppInst, (LPSTR) "AppIcon");
     MainClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
     MainClass.hbrBackground = GetStockObject(WHITE_BRUSH);
     MainClass.lpszMenuName  = NULL;
     MainClass.lpszClassName = (LPSTR) szAppWndClass;

     /* Register it. */
     RegisterClass(&MainClass);

     /* Create the window. */
     hAppWnd = CreateWindow((LPSTR) szAppWndClass, 
                            (LPSTR) "Resource Monitor", 
                            WS_OVERLAPPED | WS_SYSMENU,
			             CW_USEDEFAULT, CW_USEDEFAULT, 
                            CW_USEDEFAULT, CW_USEDEFAULT,
					   NULL, 
                            NULL,
                            hAppInst, 
                            NULL);
}

/*******************************************************************************
** Application window message handler.
** We only expect to have one of these so they explicitly reference the AppWnd
** object.
**/
WINDOWPROC AppWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{                   
     /* Decode message. */
     switch (iMsg)
     {
		/* Request to exit. */
          case WM_CLOSE:
               DestroyWindow(hAppWnd);
               break;

          /* System menu commands. */
		case WM_SYSCOMMAND:
			switch (wParam & 0xFFF0)
			{         
				/* Only allow window to be iconified. */
				case SC_RESTORE:
				case SC_MAXIMIZE:
					break;
					
				default:
               		return DefWindowProc(hWnd, iMsg, wParam, lParam);
			}
			break;
			               
          /* We are exiting. */
          case WM_DESTROY:
               PostQuitMessage(0);
               break;
           
          /* Don't care! */
          default:
               return DefWindowProc(hWnd, iMsg, wParam, lParam);
     }

     return FALSE;
}
