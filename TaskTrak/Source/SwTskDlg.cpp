/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SWTSKDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CSwitchTasksDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "swtskdlg.hpp"

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

CSwitchTasksDlg::CSwitchTasksDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_SWITCH_TASKS_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_PREV_TASK,	&m_cbPrevTask,
						IDC_NEXT_TASK,	&m_cbNextTask,
				 		0,			0				};
	
	CtrlTable(Ctrls);
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

void CSwitchTasksDlg::OnCreate(void)
{
	// Initialise tasks.
	m_strPrevTask = "";
	m_strNextTask = "";
}

/******************************************************************************
** Method:		OnOk()
**
** Description:	Check if the user can okay the dialog.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CSwitchTasksDlg::OnOk(void)
{
	// Get tasks.
	m_strPrevTask = m_cbPrevTask.Text();
	m_strNextTask = m_cbNextTask.Text();

	return TRUE;
}
