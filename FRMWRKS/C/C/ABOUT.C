/*****************************************************************************
** (C) Chris Wood 1995.
**
** ABOUT.C - Display the program about box.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"
#include "winutils.h"

/**** Defines & Global variables. *******************************************/
extern HWND         hAppWnd;            /* Main window. */
extern HINSTANCE    hAppInst;           /* Application instance. */

/**** Internal Prototypes. **************************************************/
DIALOGPROC AboutDlg(HWND, UINT, WPARAM, LPARAM);

/*******************************************************************************
** Show the About Box dialog.
**/
VOID FAR ShowAboutBox(VOID)
{
     DialogBox(hAppInst, "ABOUT_APP", hAppWnd, AboutDlg);
}

/*******************************************************************************
** Handle the About Box dialog.
**/
DIALOGPROC AboutDlg(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
     /* Decode message. */
     switch(iMsg)
     {
		case WM_INITDIALOG:
               /* Initialise Dialog. */
               CentreWindow(hDlg);
			return(TRUE);

		case WM_COMMAND:	
			switch(wParam) 
			{
                    case IDOK:
                    case IDCANCEL:
                         EndDialog(hDlg, TRUE);
                         return(TRUE);

		          default:
			          break;
               }
               break;
               
		default:
			break;
	}

	return FALSE;
}
