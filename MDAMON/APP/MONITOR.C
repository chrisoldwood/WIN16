/*****************************************************************************
**
** MONITOR.C - Monochrome test application. 
** (C) Chris Wood 1994.
** cwood@gst-soft.demon.co.uk
**
** 31/03/94 Add on/off button.
** 30/03/94 Display memory usage and system resources. 
**
******************************************************************************
*/

#include <windows.h>
#include <toolhelp.h>
#include "monocode.h"

/**** Prototypes for this module. *******************************************/
long FAR PASCAL MainWndProc(HWND, WORD, WORD, LONG);
VOID NEAR DrawBorder(VOID);
VOID NEAR SetupMeters(VOID);
VOID NEAR UpdateMeters(VOID);
VOID NEAR RedrawMeter(int, int, int, int);
VOID NEAR SwitchTimer(VOID);

/**** Defines & Global variables. *******************************************/
#define TRUE   1
#define FALSE  0

#define ONOFFBUTTON 20

char szAppName[]  = "Debug Monitor";    /* Application title. */
char szAppClass[] = "Monitor_App";      /* Application class. */
char	szIconName[] = "MonitorIcon";      /* Icon resource name. */

HWND      hMainWnd;                     /* Handle to Application window. */
HWND      hOnOffWnd;                    /* Handle to on-off button. */
HANDLE    hInst;                        /* Application instance. */
MEMMANINFO     mmiStruct;               /* Memory manager structure. */

long lMaxLinear;                        /* Max. pages of linear space. */
long lMaxPages;                         /* Max. pages of real RAM, i think! */
int  iActual;                           /* Amount of real RAM free. */
int  iVirtual;                          /* Amount of virtual memory free. */
int  iFragged;                          /* Memory fragmentation,  yeah sure! */
int  iGdi;                              /* GDI resources. */
int  iSystem;                           /* System resources. */
int  iUser;                             /* User resources. */
int  iTimer = 200;                      /* Windows timer ID. */
BOOL bTimerOn = FALSE;                  /* Is the timer running? */

/*
******************************************************************************
** Main Windows functions.
******************************************************************************
*/

/****************************************************************************
** Application entry point.
*/
int PASCAL WinMain ( HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdLine, WORD nCmdShow)
{
     MSG       msg;
     WNDCLASS  wndclass;
     RECT      rcClient;
     WORD      wResult;

     if (hPrevInstance)
     {
          /* Bring the previous instance to the front. */
		GetInstanceData(hPrevInstance, (NPSTR) &hMainWnd, 2);
		if (GetWindowLong(hMainWnd, GWL_STYLE) & WS_ICONIC)
		{
			/* If it is an icon restore it. */
			SendMessage(hMainWnd, WM_SYSCOMMAND, SC_RESTORE, 0);
		}

		SetFocus(hMainWnd);
		return FALSE;     
     }
     else
     {
          wResult = InitMono();
          if (wResult == ERR_NOMONO)
          {
               MessageBox(NULL, "ERROR: No mono adapter found.", szAppName, 
                              MB_OK | MB_ICONEXCLAMATION);
               return FALSE;
          }
          else if (wResult == ERR_BADADDRESS)
          {
               MessageBox(NULL, "ERROR: Cannot get mono adapter address.", szAppName, 
                              MB_OK | MB_ICONEXCLAMATION);
               return FALSE;
          }
          
          /* Register the application class. */
          wndclass.style         = CS_VREDRAW | CS_HREDRAW;
          wndclass.lpfnWndProc   = (WNDPROC) MainWndProc;
          wndclass.cbClsExtra    = 0;
          wndclass.cbWndExtra    = 0;
          wndclass.hInstance     = hInstance;
          wndclass.hIcon         = LoadIcon(hInstance, szIconName);
          wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
          wndclass.hbrBackground = GetStockObject(WHITE_BRUSH);
          wndclass.lpszMenuName  = NULL;
          wndclass.lpszClassName = szAppClass;

          if (!RegisterClass (&wndclass))
               return FALSE;
     }
               
     /* Create the application window. */
     hInst = hInstance;
     hMainWnd = CreateWindow(szAppClass, szAppName, 
          WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN,
          CW_USEDEFAULT, CW_USEDEFAULT, 150, 60, NULL, NULL, hInstance, NULL);

     GetClientRect(hMainWnd, (LPRECT) &rcClient);
     hOnOffWnd = CreateWindow ("BUTTON", "TURN OFF",  WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE,
          0, 0, rcClient.right - rcClient.left, rcClient.bottom - rcClient.top, 
          hMainWnd, ONOFFBUTTON, hInstance, NULL);
          
     /* Realize the application windows.*/     
     ShowWindow(hMainWnd, SW_MINIMIZE);
     ShowWindow(hOnOffWnd, SW_SHOW);

     /* Do the usual stuff! */
     while (GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
     }

     return msg.wParam;
}

/****************************************************************************
** Bog standard Windows message handler.
*/
long FAR PASCAL MainWndProc ( HWND hWnd, WORD iMessage, WORD wParam, LONG lParam )
{
	PAINTSTRUCT	ps;
     HDC            hDC;

     switch (iMessage)
     {
	     case WM_CREATE:
               /* Set the display up. */
               DrawBorder();
               SetupMeters();
               
               /* Start the ball rolling. */
               bTimerOn = SetTimer(hWnd, iTimer, 500, NULL);               
			break;

	     case WM_COMMAND:
			if ( (wParam == ONOFFBUTTON) && (HIWORD(lParam) == BN_CLICKED) )
                    SwitchTimer();
			break;

     	case WM_PAINT:
               hDC = BeginPaint(hWnd, &ps);
               EndPaint(hWnd, &ps);
               break;

          case WM_TIMER:
               UpdateMeters();
               break;
               
        	case WM_DESTROY:
               /* Clean up windows resources and mono display. */
               if (bTimerOn)
                    KillTimer(hWnd, iTimer);
               ClearMono();
         		PostQuitMessage (0);
    	     	break;

          default:
               return DefWindowProc (hWnd, iMessage, wParam, lParam);
     }

     return 0L;
}

/****************************************************************************
** Draw the mono display window borders.
*/
VOID NEAR DrawBorder(VOID)
{
     /* Draw the window edges and dividers. */
     PlotFrame(0, 0, 79, 24, DUAL, WHITE);
     HorizLine(0, 79, 4, D_HORBAR, WHITE);
     HorizLine(0, 79, 14, D_HORBAR, WHITE);

     /* Join up the windows correctly. */     
     PlotChar(0,4,D_SIDELEFT, WHITE);
     PlotChar(79,4,D_SIDERIGHT, WHITE);
     PlotChar(0,14,D_SIDELEFT, WHITE);
     PlotChar(79,14,D_SIDERIGHT, WHITE);

     /* Show the window titles. */
     HorizString(16, 0, (LPSTR) " MEMORY ", WHITE);
     HorizString(55, 0, (LPSTR) " RESOURCES ", WHITE);
     HorizString(28, 4, (LPSTR) " TRACE & DEBUG MESSAGES ", WHITE);
     HorizString(27, 14, (LPSTR) " WARNING & ERROR MESSAGES ", WHITE);
}

/****************************************************************************
** Setup the usage meters with initial values.
*/
VOID NEAR SetupMeters()
{
     int  iOffset;
     BYTE szValue[10];

     /*
     ** The memory usage display.
     */
     
     /* Draw the memory meter titles. */
     HorizString(1, 1, (LPSTR) " ACTUAL:", WHITE);
     HorizString(1, 2, (LPSTR) "VIRTUAL:", WHITE);
     HorizString(1, 3, (LPSTR) "FRAGGED:", WHITE);

     /* Draw the basic graphical meter. */
     HorizLine(9, 34, 1, HALFBLOCK, GREY);
     HorizLine(9, 34, 2, HALFBLOCK, GREY);
     HorizLine(9, 34, 3, HALFBLOCK, GREY);

     /* Get some static memory sizes. */
     mmiStruct.dwSize = sizeof(MEMMANINFO);
     MemManInfo(&mmiStruct);
     lMaxLinear = mmiStruct.dwTotalLinearSpace;
     lMaxPages  = mmiStruct.dwTotalPages;               

     /* Amount of actual memory. Well sort of! */
     iActual = (int) ((((long) lMaxPages - (long) mmiStruct.dwFreePages) * (long) 100) / (long) lMaxPages); 
     if (iActual > 100)
          iActual = 100;
     wsprintf((LPSTR) szValue, "%3d%%", iActual);
     HorizString(35, 1, (LPSTR) szValue, WHITE);

     /* Amount of actual & swap space. */
     iVirtual = (int) ((((long) lMaxLinear - (long) mmiStruct.dwFreeLinearSpace) * (long) 100) / (long) lMaxLinear);   
     wsprintf((LPSTR) szValue, "%3d%%", iVirtual);
     HorizString(35, 2, (LPSTR) szValue, WHITE);

     /* Memory fragmentation. Not really! */
     iFragged = (int) (((long) mmiStruct.dwMaxPagesAvailable * (long) 100) / (long) mmiStruct.dwFreeLinearSpace);
     iFragged = 100 - iFragged;
     wsprintf((LPSTR) szValue, "%3d%%", iFragged);
     HorizString(35, 3, (LPSTR) szValue, WHITE);

     /* Show the values on the graphical display. */
     iOffset = (25 * iActual) / 100;
     HorizLine( 9, 9 + iOffset, 1, HALFBLOCK, WHITE);
     iOffset = (25 * iVirtual) / 100;
     HorizLine( 9, 9 + iOffset, 2, HALFBLOCK, WHITE);
     iOffset = (25 * iFragged) / 100;
     HorizLine( 9, 9 + iOffset, 3, HALFBLOCK, WHITE);

     /*
     ** The resource usage display. 
     */
     
     /* Draw the resource meter titles. */
     HorizString(41, 1, (LPSTR) "   GDI:", WHITE);
     HorizString(41, 2, (LPSTR) "SYSTEM:", WHITE);
     HorizString(41, 3, (LPSTR) "  USER:", WHITE);

     /* Draw the basic graphical meter. */
     HorizLine(48, 74, 1, HALFBLOCK, GREY);
     HorizLine(48, 74, 2, HALFBLOCK, GREY);
     HorizLine(48, 74, 3, HALFBLOCK, GREY);

     /* Get the initial resource readings. */
     iGdi    = GetFreeSystemResources(GFSR_GDIRESOURCES);
     iSystem = GetFreeSystemResources(GFSR_SYSTEMRESOURCES);
     iUser   = GetFreeSystemResources(GFSR_USERRESOURCES);

     /* Show the actual values. */
     wsprintf((LPSTR) szValue, "%3d%%", iGdi);
     HorizString(75, 1, (LPSTR) szValue, WHITE);
     wsprintf((LPSTR) szValue, "%3d%%", iSystem);
     HorizString(75, 2, (LPSTR) szValue, WHITE);
     wsprintf((LPSTR) szValue, "%3d%%", iUser);
     HorizString(75, 3, (LPSTR) szValue, WHITE);

     /* Show the values on the graphical display. */
     iOffset = (26 * iGdi) / 100;
     HorizLine(48, 48 + iOffset, 1, HALFBLOCK, WHITE);
     iOffset = (26 * iSystem) / 100;
     HorizLine(48, 48 + iOffset, 2, HALFBLOCK, WHITE);
     iOffset = (26 * iUser) / 100;
     HorizLine(48, 48 + iOffset, 3, HALFBLOCK, WHITE);
}

/****************************************************************************
** Update the meters, only if they have changed.
*/
VOID NEAR UpdateMeters()
{
     int  iTmp;

     /* Get the current memory stats. */
     MemManInfo(&mmiStruct);

     /* Amount of actual RAM used. */
     iTmp = (int) ((((long) lMaxPages - (long) mmiStruct.dwFreePages) * (long) 100) / (long) lMaxPages);
     if (iTmp > 100)
          iTmp = 100;
     if (iTmp != iActual)
     {
          /* Value has changed. */
          iActual = iTmp;
          RedrawMeter(9, 34, 1, iActual);
     }

     /* Amount of virtual memory used. */
     iTmp = (int) ((((long) lMaxLinear - (long) mmiStruct.dwFreeLinearSpace) * (long) 100) / (long) lMaxLinear);   
     if (iTmp != iVirtual)
     {
          iVirtual = iTmp;
          RedrawMeter(9, 34, 2, iVirtual);
     }

     /* Memory fragmentation. */
     iTmp = (int) (((long) mmiStruct.dwMaxPagesAvailable * (long) 100) / (long) mmiStruct.dwFreeLinearSpace);
     iTmp = 100 - iTmp;
     if (iTmp != iFragged)
     {
          iFragged = iTmp;
          RedrawMeter(9, 34, 3, iFragged);
     }

     /* GDI Resources. */
     iTmp = GetFreeSystemResources(GFSR_GDIRESOURCES);
     if (iTmp != iGdi)
     {
          iGdi = iTmp;
          RedrawMeter(48, 74, 1, iGdi);
     }

     /* System Resources. */     
     iTmp = GetFreeSystemResources(GFSR_SYSTEMRESOURCES);
     if (iTmp != iSystem)
     {
          iSystem = iTmp;
          RedrawMeter(48, 74, 2, iSystem);
     }
     
     /* User resources. */     
     iTmp = GetFreeSystemResources(GFSR_USERRESOURCES);
     if (iTmp != iUser)
     {
          iUser = iTmp;
          RedrawMeter(48, 74, 3, iUser);
     }
}

/****************************************************************************
** Redraw the graphical display and value for a meter.
*/
VOID NEAR RedrawMeter(int iSX, int iDX, int iY, int iValue)
{
     BYTE szValue[10];
     int  iOffset;
    
     wsprintf((LPSTR) szValue, "%3d%%", iValue);
     HorizString(iDX + 1, iY, (LPSTR) szValue, WHITE);
     HorizLine(iSX, iDX, iY, HALFBLOCK, GREY);
     iOffset = ((iDX - iSX) * iValue) / 100;
     HorizLine(iSX, iSX + iOffset, iY, HALFBLOCK, WHITE);
}

/****************************************************************************
** Turn the meter update timer on or off and change the button text. The mono
** display is also cleared or fully redraw.
*/
VOID NEAR SwitchTimer()
{
     if(bTimerOn)
     {
          bTimerOn = FALSE;
          KillTimer(hMainWnd, iTimer);
          SetWindowText(hOnOffWnd, (LPSTR) "TURN ON");
          ClearMono();
     }
     else
     {
          bTimerOn = SetTimer(hMainWnd, iTimer, 500, NULL);
          SetWindowText(hOnOffWnd, (LPSTR) "TURN OFF");
          DrawBorder();
          SetupMeters();
     }
}