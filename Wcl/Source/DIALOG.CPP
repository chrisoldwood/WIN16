/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DIALOG.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CDialog class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <stdlib.h>
#include <stdio.h>

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Fill in the basic initialisation parameters.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDialog::CDialog(void)
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Initialise INIT structure.
	m_diInit.hInstance    = pApp->Module()->Handle();
	m_diInit.lpszTemplate = NULL;
	m_diInit.hParent      = NULL;

	// Initialise control table.
	m_pCtrlTable = NULL;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Free up resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDialog::~CDialog(void)
{
	// Free control table.
	if (m_pCtrlTable)
		delete[] m_pCtrlTable;
}

/******************************************************************************
** Method:		RunModless()
**
** Description:	Create the dialog as a modeless dialog and display. This method
**				returns straight away as the dialog runs in parallel.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CDialog::RunModeless(void)
{
	// Initalise members.
	m_bModal = FALSE;
	
	ASSERT(m_diInit.lpszTemplate);

	// Create it.
	HWND hWnd = CreateDialogParam(m_diInit.hInstance, m_diInit.lpszTemplate,
									m_diInit.hParent, (DLGPROC)DlgProc, 
#ifdef M_I86MM
									(LPARAM)(WORD)this);
#else // M_I86LM
									(LPARAM)this);
#endif

	// Okay?
	if (!hWnd)
		return FALSE;
		
	return TRUE;
}

/******************************************************************************
** Method:		RunModal()
**
** Description:	Create the dialog as a modal dialog and display. This method
**				does not return until the dialog is closed.
**
** Parameters:	None.
**
** Returns:		IDOK or IDCANCEL	If closed by user.
**				iReturn == -1		On error.
**
*******************************************************************************
*/

int CDialog::RunModal(void)
{
	// Initalise members.
	m_bModal = TRUE;

	ASSERT(m_diInit.lpszTemplate);
	
	// Create it.
	int iReturn = DialogBoxParam(m_diInit.hInstance, m_diInit.lpszTemplate,
									m_diInit.hParent, (DLGPROC)DlgProc, 
#ifdef M_I86MM
									(LPARAM)(WORD)this);
#else // M_I86LM
									(LPARAM)this);
#endif

	ASSERT(iReturn != -1);
    
    // Return 
	return iReturn;
}

/******************************************************************************
** Function:	DialogProc()
**
** Description:	This is the real dialog procedure used for all dialogs. It
**				gets the object associated with the handle and calls the real
**				message processing method.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		bool based on the message.
**
*******************************************************************************
*/

BOOL DIALOGPROC DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	CDialog* pDialog;
	
	// Get the window object.
	pDialog = (CDialog*) CWnd::FromHandle(hWnd);

	// Do we have a mapping?
	if (!pDialog)
	{
		// Time to initialise?
		if (iMsg == WM_INITDIALOG)
		{
			// Get object from LPARAM.
#ifdef M_I86MM
			pDialog = (CDialog*)(WORD)lParam;
#else //M_I86LM
			pDialog = (CDialog*)lParam;
#endif
			// Save handle.
			pDialog->m_hWnd = hWnd;
			
			// Setup Window mapping.
			CWnd::Map(hWnd, pDialog);

			// Centre only if modal.
			if (pDialog->m_bModal)
				pDialog->Centre();
			
			// Initialise child controls.
			pDialog->InitControls();
			
			// Now call initialise method.
			pDialog->OnCreate();
			return TRUE;
		}
		else
		{
			// Ignore it.
			return FALSE;
		}
	}

	// Call real message handler.
	pDialog->WndProc(hWnd, iMsg, wParam, lParam);

	if (pDialog->m_bMsgHandled)
		return TRUE;

	return FALSE;
}

/******************************************************************************
** Method:		DialogProc()
**
** Description:	This is the virtual dialog procedure that processes all the
**				messages and calls the appropriate virtual function. It also
**				does some default processing.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CDialog::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Decode message.
	switch(iMsg)
	{
		// Child control message.
		case WM_COMMAND:
			// Running modal?
			if (m_bModal)
			{
				// Check for termination.
				if ( (wParam == IDOK) && (OnOk()) )
				{
					EndDialog(hWnd, IDOK);
					break;
				}
				else if ( (wParam == IDCANCEL) && (OnCancel()) )
				{
					EndDialog(hWnd, IDCANCEL);
					break;
				}
			}
			return CMsgWnd::WndProc(hWnd, iMsg, wParam, lParam);
		
		// Window being destroyed.
		case WM_DESTROY:
			OnDestroy();
			
			// Delete object mapping.
			UnMap(hWnd);
			break;
		
		// Call the default handler.
		default:
			return CMsgWnd::WndProc(hWnd, iMsg, wParam, lParam);
	}

	m_bMsgHandled = TRUE;
	m_lMsgResult  = 0;

	return 0;
}

/******************************************************************************
** Method:		DefaultWndProc()
**
** Description:	This is the handler for all non-handled messages. It calls
**				DefWindowProc().
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CDialog::DefaultWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Message not processed.
	m_bMsgHandled = FALSE;
	m_lMsgResult  = 0;

	return 0;
}

/******************************************************************************
** Method:		OnOk()
**
** Description:	The OK button was pressed. Ask if the dialog can close.
**
** Parameters:	None.
**
** Returns:		TRUE		If it can close.
**				FALSE		If not.
**
*******************************************************************************
*/

bool CDialog::OnOk(void)
{
	return TRUE;
}

/******************************************************************************
** Method:		OnCancel()
**
** Description:	The Cancel button was pressed. Ask if the dialog can close.
**
** Parameters:	None.
**
** Returns:		TRUE		If it can close.
**				FALSE		If not.
**
*******************************************************************************
*/

bool CDialog::OnCancel(void)
{
	return TRUE;
}

/******************************************************************************
** Method:		CtrlTable()
**
** Description:	Make a copy of the control table and save it.
**
** Parameters:	pCtrlTable	The control table.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDialog::CtrlTable(Control* pCtrlTable)
{
	Control* pCtrl;
	
	ASSERT(pCtrlTable);

	pCtrl = pCtrlTable;
	int	iNumCtrls = 0;

	// Count the number of controls.
	while (pCtrl->iCtrlID)
	{
		iNumCtrls++;
	    pCtrl++;
	}

	// Allocate memory for the copy.
	m_pCtrlTable = new Control[iNumCtrls+1];
	ASSERT(m_pCtrlTable);
	
	pCtrl = pCtrlTable;
	int iIdx  = 0;

	// Copy the table
	while (iIdx < iNumCtrls)
	{
		m_pCtrlTable[iIdx].iCtrlID = pCtrl->iCtrlID;
		m_pCtrlTable[iIdx].pCtrl   = pCtrl->pCtrl;
	    pCtrl++;
	    iIdx++;
	}
	
	// Append table terminator.
	m_pCtrlTable[iIdx].iCtrlID = 0;
	m_pCtrlTable[iIdx].pCtrl   = NULL;
}

/******************************************************************************
** Method:		InitControls()
**
** Description:	Enumerate the control table and setup their ID and window
**				handles.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDialog::InitControls(void)
{
	Control* pCtrl = m_pCtrlTable;
	
	// For all controls.
	while( (pCtrl) && (pCtrl->iCtrlID) )
	{
		uint iID = pCtrl->iCtrlID;
		
	    // Attach object to window.
	    pCtrl->pCtrl->Attach(iID, CtlHandle(iID), this);
	    
	    pCtrl++;
	}
}
