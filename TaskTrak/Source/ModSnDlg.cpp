/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MODSNDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CModifySessionDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
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

CModifySessionDlg::CModifySessionDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_MODIFY_SESSION_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_IN_DATE, 	&m_ebInDate,
						IDC_IN_TIME, 	&m_ebInTime,
						IDC_OUT_DATE, 	&m_ebOutDate,
						IDC_OUT_TIME, 	&m_ebOutTime,
						IDC_TASK,		&m_cbTask,
				 		0,				0			};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_IN_DATE,	EN_UPDATE,	(CtlMsgFn)OnEditInDate,
								0, 				0,			0						};
	
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

void CModifySessionDlg::OnCreate(void)
{
	// Initialise date and time fields.
	m_ebInDate.Text(m_InDate);
	m_ebInTime.Text(m_InTime);

	m_ebOutDate.Text(m_OutDate);
	m_ebOutTime.Text(m_OutTime);

	// Initialise task.
	if (m_strTask != "")
	{
		int iItem = m_cbTask.FindExact(m_strTask);
		ASSERT(iItem != CB_ERR);
			
		m_cbTask.Select(iItem);
	}
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

bool CModifySessionDlg::OnOk(void)
{
	// Get date from edit box.
	if (!m_InDate.Set(m_ebInDate.Text()))
	{
		Alert("Date is invalid.");
		return FALSE;
	}

	// Get time from edit box.
	if (!m_InTime.Set(m_ebInTime.Text()))
	{
		Alert("Time is invalid.");
		return FALSE;
	}

	// Get date from edit box.
	if (!m_OutDate.Set(m_ebOutDate.Text()))
	{
		Alert("Date is invalid.");
		return FALSE;
	}

	// Get time from edit box.
	if (!m_OutTime.Set(m_ebOutTime.Text()))
	{
		Alert("Time is invalid.");
		return FALSE;
	}

	CDateTime	ClockIn(m_InDate, m_InTime);
	CDateTime	ClockOut(m_OutDate, m_OutTime);
	
	// Check clock out time.
	if (ClockOut < ClockIn)
	{
		Alert("You cannot clock out ealier than\nyou clocked in.");
		return FALSE;
	}

	// Get task.
	m_strTask = m_cbTask.Text();

	return TRUE;
}

/******************************************************************************
** Method:		OnEditInDate()
**
** Description:	Copy the newly edited in date to the out date edit box.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CModifySessionDlg::OnEditInDate(void)
{
	m_ebOutDate.Text(m_ebInDate.Text());
}
