/*****************************************************************************
** (C) Chris Wood 1995.
**
** IODLG.C - File I/O status dialog.
**
******************************************************************************
*/

#include "af.h"
#include "apputils.h"
#include "rscutils.h"
#include "resource.h"

/**** Global vars. **********************************************************/
HWND hIODlg;							/* This dialogs handle. */
char szDlgTitle[40];					/* Dialog title. */

extern HINSTANCE hAppInst;              	/* Application instance. */
extern char szTitle[];					/* Aplication title. */
extern char szMailDir[];					/* Working directory. */
extern char szServer[];					/* Default server. */
extern char szPostmaster[];				/* Postmaster. */

/**** Prototypes. ***********************************************************/
DIALOGPROC FileIODialogProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

/*****************************************************************************
** Create the dialog.
*/
VOID FAR CreateFileIODlg(VOID)
{ 
	char szVersion[40];
	
	/* Load version string. */
	LoadRscString(IDS_VERSION, szVersion, 40);
	
	/* Create the title. */
	wsprintf(szDlgTitle, "%s V%s", (LPSTR) szTitle, (LPSTR) szVersion);
	
	/* Create the dialog. */
	hIODlg = CreateDialog(hAppInst, "FILE_IO_DIALOG", NULL, (DLGPROC) FileIODialogProc);
	ASSERT(IsValidWnd(hIODlg));
}

/*****************************************************************************
** Set the dialogs file name field.
*/
VOID FAR SetFileName(LPSTR lpszFileName)
{
	ASSERT(IsValidPtr(lpszFileName));
	ASSERT(IsValidWnd(hIODlg));

	SetDlgItemText(hIODlg, IDC_FILENAME, lpszFileName);
}

/*****************************************************************************
** Set the dialogs user name field.
*/
VOID FAR SetUserName(LPSTR lpszUserName)
{
	ASSERT(IsValidPtr(lpszUserName));
	ASSERT(IsValidWnd(hIODlg));

	SetDlgItemText(hIODlg, IDC_USERNAME, lpszUserName);
}

/*****************************************************************************
** Destroy the dialog.
*/
VOID FAR DestroyFileIODlg(VOID)
{
	DestroyWindow(hIODlg);
	hIODlg = NULL;
}

/*******************************************************************************
** File IO dialog message handler.
**/
DIALOGPROC FileIODialogProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
     /* Decode message. */
     switch (iMsg)
     {
		/* Initialisation. */
		case WM_INITDIALOG:
			CentreWindow(hDlg);
			
			/* Set the title. */
			SetWindowText(hDlg, szDlgTitle);
			
			/* Set the defualt labels. */
			SetDlgItemText(hDlg, IDC_SERVERNAME, szServer);
			SetDlgItemText(hDlg, IDC_SOURCEDIR,  szMailDir);
			SetDlgItemText(hDlg, IDC_POSTMASTER, szPostmaster);
			
			/* Blank the fields. */
			SetDlgItemText(hDlg, IDC_FILENAME, "");
			SetDlgItemText(hDlg, IDC_USERNAME, "");
			return TRUE;
			
          /* Safe. */
          default:
     		break;
     }

	/* All others. */
     return FALSE;
}
