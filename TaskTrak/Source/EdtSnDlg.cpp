/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EDTSNDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CEditSessionDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "edtsndlg.hpp"
#include "addsndlg.hpp"
#include "modsndlg.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings.
**
** Parameters:	pParent		The dialogs' parent window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CEditSessionDlg::CEditSessionDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_EDIT_SESSIONS_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_SESSIONS,	&m_lbSessions,
				 		0,				0				};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_ADD, 		BN_CLICKED,		(CtlMsgFn)OnAdd,
								IDC_MODIFY,		BN_CLICKED,		(CtlMsgFn)OnModify,
								IDC_DELETE,		BN_CLICKED,		(CtlMsgFn)OnDelete,
								IDC_SESSIONS,	LBN_DBLCLK,		(CtlMsgFn)OnModify,
								0, 				0,				0					};
	
	CtlMsgTable(CtlMsgs);
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Initialise the dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CEditSessionDlg::OnCreate(void)
{
	// Session list empty?
    if (!App.SessionList().Length())
    {
    	// Disable delete and modify buttons.
    	DisableCtl(IDC_DELETE);
    	DisableCtl(IDC_MODIFY);
    }
}

/******************************************************************************
** Method:		OnAdd()
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CEditSessionDlg::OnAdd(void)
{
	CAddSessionDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		CDateTime	dtIn(Dlg.m_InDate, Dlg.m_InTime);
		CDateTime	dtOut(Dlg.m_OutDate, Dlg.m_OutTime);
		CSession*	pNewSession;
		
		// Create a new session.
		pNewSession = new CSession;
		ASSERT(pNewSession);
	
		// Initialise.
		pNewSession->Start(dtIn, Dlg.m_strTask);
		pNewSession->Finish(dtOut, Dlg.m_strTask);
	
		// Add task to list if set.
		if (Dlg.m_strTask != "")
			App.TaskList().Add(Dlg.m_strTask);
	
		// Add to list.
		App.SessionList().Add(pNewSession);
		
		// Refresh session list.
		m_lbSessions.Refresh();

    	// Enable delete and modify buttons.
    	EnableCtl(IDC_DELETE);
    	EnableCtl(IDC_MODIFY);
		
		// Update dirty flag.
		App.Modified();
	}
}

/******************************************************************************
** Method:		OnModify()
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CEditSessionDlg::OnModify(void)
{
	CModifySessionDlg	Dlg(this);

	// Get selected session.
	CSession* pSession = m_lbSessions.CurrSession();
	ASSERT(pSession);
	
	// Initialise dialog.
	Dlg.m_InDate = pSession->Start().Date();
	Dlg.m_InTime = pSession->Start().Time();

	Dlg.m_OutDate = pSession->Finish().Date();
	Dlg.m_OutTime = pSession->Finish().Time();
	
	Dlg.m_strTask = pSession->Task();
	
	// Show it.
	if (Dlg.RunModal() == IDOK)
	{
		CDateTime	dtIn(Dlg.m_InDate, Dlg.m_InTime);
		CDateTime	dtOut(Dlg.m_OutDate, Dlg.m_OutTime);
		
		// Update session details.
		pSession->Start(dtIn, Dlg.m_strTask);
		pSession->Finish(dtOut, Dlg.m_strTask);
	
		// Add task to list if set.
		if (Dlg.m_strTask != "")
			App.TaskList().Add(Dlg.m_strTask);
	
		// Refresh session list.
		m_lbSessions.Refresh();

		// Update dirty flag.
		App.Modified();
	}
}

/******************************************************************************
** Method:		OnDelete()
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CEditSessionDlg::OnDelete(void)
{
	// Get current selection.
	int iIdx = m_lbSessions.Current();
	ASSERT(iIdx != LB_ERR);

	// Get selected session.
	CSession* pSession = m_lbSessions.CurrSession();
	ASSERT(pSession);

	// Delete session.
	App.SessionList().Remove(pSession);
	delete pSession;
	
	// Update listbox.
	m_lbSessions.Delete(iIdx);

	// Change listbox selection.
	int iNumItems = App.SessionList().Length();
	
    if (iNumItems)
    {
    	// Select next item
    	if (iIdx == iNumItems)
    		m_lbSessions.Select(iIdx-1);
    	else
    		m_lbSessions.Select(iIdx);
    }
    else
    {
    	// Disable delete and modify buttons.
    	DisableCtl(IDC_DELETE);
    	DisableCtl(IDC_MODIFY);
    }
    
	// Update dirty flag.
	App.Modified();
}
