/*****************************************************************************
** (C) Chris Wood 1995.
**
** MAINWND.CPP - Application window class functions.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"
#include "mainwnd.hpp"
#include "debug.h"
#include "appinst.hpp"
#include "resource.h"

/**** Internal Prototypes. **************************************************/
WINDOWPROC AppWndProc(HWND, UINT, WPARAM, LPARAM);

/**** External Prototypes. **************************************************/
extern APPINST AppInst;
               
/*****************************************************************************
** Application window class constructor.
*/
MAINWND::MAINWND(HINSTANCE hInst) : BASEWND("AppWindow")
{
	// Override registration defaults.
	RegArgs.lpfnWndProc = AppWndProc;
	RegArgs.hInstance   = hInst;
	RegArgs.hIcon       = AppInst.LoadRscIcon("AppIcon");
	                              
	// Override creation defaults.
	CreateArgs.dwStyle    = WS_OVERLAPPEDWINDOW;
	CreateArgs.lpszTitle  = AppInst.LoadRscString(IDS_APPNAME);
	CreateArgs.hMenu      = AppInst.LoadRscMenu("AppMenu");
       
	// Set application name from window title.
	lpszAppName = CreateArgs.lpszTitle;
		
	// Register and create the window.
	Create();
}

/*****************************************************************************
** Display a message box.
*/
MAINWND::MsgBox(LPSTR lpszMsg, UINT iStyle)
{ 
	return MessageBox(hWnd, lpszMsg, lpszAppName, iStyle); 
}

/*******************************************************************************
** Application window message handler.
**/
WINDOWPROC AppWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{                   
     // Decode message.
     switch (iMsg)
     {
          case WM_CREATE:
               break;

          case WM_COMMAND:
          	{
          		switch(wParam)
          		{
          			case IDM_EXIT:
          				PostMessage(hWnd, WM_CLOSE, 0, 0L);
          				break;
          			
          			default:
          				break;
          		}
          	}
               break;

          case WM_PAINT:
          	{
			PAINTSTRUCT	ps;
          	
		     BeginPaint(hWnd, &ps);
               EndPaint(hWnd, &ps);
               }
               break;

          case WM_CLOSE:
               // Clean up.
               DestroyWindow(hWnd);
               break;
               
          case WM_DESTROY:
               // Send exit message.
               PostQuitMessage(0);
               break;
                              
          default:
               return DefWindowProc(hWnd, iMsg, wParam, lParam);
     }

     return FALSE;
}
