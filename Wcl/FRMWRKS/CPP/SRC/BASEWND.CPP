/*****************************************************************************
** (C) Chris Wood 1995.
**
** BASEWND.CPP - Basic window class functions.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"
#include "basewnd.hpp"
#include "debug.h"

// Instantiate Window registration and creation strctures.
WNDCLASS  BASEWND::RegArgs;
WNDCREATE BASEWND::CreateArgs;

/*****************************************************************************
** Window class constructor. 
** This sets up the the WNDCLASS & WNDCREATE structures with default values.
*/
BASEWND::BASEWND(LPSTR lpszClassName)
{    
	// Reset window handle.                             
	hWnd = NULL;
	                       
	// Setup default window class parameters.
     RegArgs.style         = CS_VREDRAW | CS_HREDRAW;
     RegArgs.lpfnWndProc   = DefWindowProc;
     RegArgs.cbClsExtra    = 0;
     RegArgs.cbWndExtra    = 0;
     RegArgs.hInstance     = NULL;
     RegArgs.hIcon         = NULL;
     RegArgs.hCursor       = LoadCursor(NULL, IDC_ARROW);
     RegArgs.hbrBackground = GetStockObject(WHITE_BRUSH);
     RegArgs.lpszMenuName  = NULL;
     RegArgs.lpszClassName = lpszClassName;

	// Setup default window parameters.
	CreateArgs.lpszTitle    = NULL;
	CreateArgs.dwStyle      = NULL;
	CreateArgs.rcPos.left   = CW_USEDEFAULT;
	CreateArgs.rcPos.top    = CW_USEDEFAULT;
	CreateArgs.rcPos.right  = CW_USEDEFAULT;
	CreateArgs.rcPos.bottom = CW_USEDEFAULT;
	CreateArgs.hMenu        = NULL;
}

/*****************************************************************************
** Window class registration and creation.
*/
BOOL BASEWND::Create(VOID)
{
	WNDCLASS	wcTmp;			// Used when checking existence.
	HWND		hNewWnd;			// New window handle.
	   
	// Check if window class exists, and register.
	if ( !GetClassInfo(RegArgs.hInstance, RegArgs.lpszClassName, &wcTmp)
	  && !GetClassInfo(NULL, RegArgs.lpszClassName, &wcTmp) )
	{
		BOOL bOkay;
		
		bOkay = RegisterClass(&RegArgs);
		AssertEx(bOkay, "RegisterClass()");
	}
	
	// Create the window.
	hNewWnd = CreateWindow(RegArgs.lpszClassName, 
					   CreateArgs.lpszTitle,
					   CreateArgs.dwStyle,
					   CreateArgs.rcPos.left, 
					   CreateArgs.rcPos.top,
					   CreateArgs.rcPos.right, 
					   CreateArgs.rcPos.bottom,
					   NULL, 
					   CreateArgs.hMenu, 
					   RegArgs.hInstance, 
					   NULL);
	hWnd = hNewWnd;
	AssertEx(hNewWnd, "CreateWindow()");
	
	// Return status.
	return (hWnd != NULL);
}

/*****************************************************************************
** Get the windows' handle 
*/
HWND BASEWND::GetHandle(VOID)
{                     
	return hWnd;
}

/*****************************************************************************
** Show/Hide the window.
*/
BOOL BASEWND::Show(int iState)
{                     
	return ShowWindow(hWnd, iState);
}

/******************************************************************************
** Centre the window on the screen.
*/
VOID BASEWND::Centre(VOID)
{
	RECT		rcWindow;           // Window dimensions.
	RECT		rcScreen;           // Screen dimensions.
	POINT     ptOrigin;           // New dialog origin.

     // Get the Screen & Window dimensions.
	GetWindowRect(GetDesktopWindow(), (LPRECT) &rcScreen);
	GetWindowRect(hWnd, (LPRECT) &rcWindow);
	OffsetRect((LPRECT) &rcWindow, -rcWindow.left, -rcWindow.top);

     // Adjust to centre of screen.
	ptOrigin.x = (rcScreen.right - rcWindow.right) / 2;	
	ptOrigin.y = (rcScreen.bottom - rcWindow.bottom) / 2;

     // Move without redrawing.
	MoveWindow(hWnd, ptOrigin.x, ptOrigin.y, rcWindow.right, rcWindow.bottom, FALSE);
}
