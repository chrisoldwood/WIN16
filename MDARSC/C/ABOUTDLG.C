/*****************************************************************************
** (C) Chris Wood 1995.
**
** ABOUTDLG.C - Show and handle the about dialog.
**
******************************************************************************
*/

#include "af.h"
#include "winutils.h"
#include "resource.h"

/**** Global Vars. **********************************************************/
extern HINSTANCE hAppInst;				/* Application instance. */
extern HWND hAppWnd;					/* Application window. */

/**** Prototypes. ***********************************************************/
DIALOGPROC AboutDialogProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

/*****************************************************************************
** Show the about box dialog.
*/
VOID FAR ShowAboutBox(VOID)
{ 
	DialogBox(hAppInst, "ABOUT_DIALOG", hAppWnd, (DLGPROC) AboutDialogProc);
}

/*******************************************************************************
** About box dialog message handler.
**/
DIALOGPROC AboutDialogProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
     /* Decode message. */
     switch (iMsg)
     {
		/* Initialisation. */
		case WM_INITDIALOG:
			CentreWindow(hDlg);
			return TRUE;
			
		/* Command. */
		case WM_COMMAND:
			/* Decode command. */
			switch(wParam)
			{
				/* OK button pressed. */
				case IDOK:
				case IDCANCEL:
					EndDialog(hDlg, TRUE);
					return TRUE;
					
				/* Safe. */
				default:
					break;
			}
			return TRUE;
			
          /* Safe. */
          default:
     		break;
     }

	/* All others. */
     return FALSE;
}
