/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPWND.C - Application window.
**
******************************************************************************
*/

#include "af.h"
#include "winutils.h"
#include "menursc.h"
#include "strngrsc.h"

/**** Defs. *****************************************************************/

/**** Global Vars. **********************************************************/
HWND		hAppWnd;						/* Application window. */
HMENU	hMenu;						/* Current menu. */

extern HINSTANCE hAppInst;              	/* Application instance. */
extern BYTE szTitle[];					/* Application title. */

/**** Prototypes. ***********************************************************/
WINDOWPROC MainWindowProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

extern VOID FAR ShowAboutBox(VOID);
extern VOID ClearOutput32(VOID);
extern VOID StopRscCheck(VOID);

/*****************************************************************************
** Register the main window class.
*/
BOOL FAR RegisterAppWnd(VOID)
{    
	WNDCLASS	WndClass;
	
	/* Setup window class parameters. */
	WndClass.style         = CS_VREDRAW | CS_HREDRAW;
	WndClass.lpfnWndProc   = (WNDPROC) MainWindowProc;
	WndClass.cbClsExtra    = 0;
	WndClass.cbWndExtra    = 0;
	WndClass.hInstance     = hAppInst;
	WndClass.hIcon         = LoadRscIcon((LPSTR) "AppIcon");
	WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName  = NULL;
	WndClass.lpszClassName = LoadTmpRscString(IDS_PRGWNDCLASS);

	return RegisterClass(&WndClass);
}

/*****************************************************************************
** Create the application window.
*/
VOID FAR CreateAppWnd(VOID)
{
	/* Get menu. */
	hMenu = LoadRscMenu("AppMenu");

	/* Create the window. */
	hAppWnd = CreateWindow(LoadTmpRscString(IDS_PRGWNDCLASS),
						(LPSTR) szTitle,
						WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
						CW_USEDEFAULT, CW_USEDEFAULT,
						//CW_USEDEFAULT, CW_USEDEFAULT,
                              50, 50,
						NULL,
						hMenu,
						hAppInst,
						NULL);

	AssertEx(IsValidWnd(hAppWnd), "CreateWindow()");
     CentreWindow(hAppWnd);
}

/*****************************************************************************
** Clean up any application window leftovers. 
*/
VOID FAR CleanUpAppWnd(VOID)
{
	/* Destroy menus. */
	if (IsMenu(hMenu))
		DestroyMenu(hMenu);
}

/*****************************************************************************
** Check if we can exit. 
*/
BOOL FAR QueryExit(VOID)
{
     return TRUE;
}

/*******************************************************************************
** Application window message handler.
**/
WINDOWPROC MainWindowProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
     /* Decode message. */
     switch (iMsg)
     {
     	/* A menu command. */
     	case WM_COMMAND:
     		{     
     			/* Decode command. */
     			switch(LOWORD(wParam))
     			{
					/* Close the application. */
     				case IDM_EXIT:
     					PostMessage(hWnd, WM_CLOSE, 0, 0L);
     					return FALSE;

                         /* Show the about box. */
					case IDM_ABOUT:
						ShowAboutBox();
						return FALSE;

     				default:
						break;
     			}
     		}
     		break;

     	/* Exit. */
     	case WM_CLOSE:
               StopRscCheck();
     		DestroyWindow(hWnd);
     		return FALSE;

          /* Exit procedure. */
          case WM_DESTROY:  
			/* Send WM_QUIT. */
               PostQuitMessage(0);
               return FALSE;
                              
          /* Safe. */
          default:
     		break;
     }

     return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
