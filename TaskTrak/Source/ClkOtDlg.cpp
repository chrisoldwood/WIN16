/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CLKOTDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CClockOutDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "clkotdlg.hpp"

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

CClockOutDlg::CClockOutDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_CLOCK_OUT_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_NOW, 	&m_rbNow,
						IDC_ON_AT, 	&m_rbOnAt,
						IDC_DATE, 	&m_ebDate,
						IDC_TIME, 	&m_ebTime,
						IDC_TASK,	&m_cbTask,
				 		0,			0			};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_NOW, 	BN_CLICKED,	(CtlMsgFn)OnNow,
								IDC_ON_AT,	BN_CLICKED,	(CtlMsgFn)OnOnAt,
								0, 			0,			0					};
	
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

void CClockOutDlg::OnCreate(void)
{
	// Initialise date and time fields.
	m_Date.Set();
	m_Time.Set();
	m_ebDate.Text(m_Date);
	m_ebTime.Text(m_Time);

	// Initalise clock out selection.
	m_rbNow.Select(TRUE);
	m_rbOnAt.Select(FALSE);
	OnNow();

	// Initialise task.
	m_strTask = "";
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

bool CClockOutDlg::OnOk(void)
{
	// Clock out now?
	if (m_rbNow.IsSelected())
	{
		// Get date and time now.
		m_Date.Set();
		m_Time.Set();
	}
	else
	{
		// Get date from edit box.
		if (!m_Date.Set(m_ebDate.Text()))
		{
			Alert("Date is invalid.");
			return FALSE;
		}

		// Get time from edit box.
		if (!m_Time.Set(m_ebTime.Text()))
		{
			Alert("Time is invalid.");
			return FALSE;
		}
	}

	CDateTime	ClockIn = App.CurrentSession()->Start();
	CDateTime	ClockOut(m_Date, m_Time);
	
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
** Method:		OnNow()
**
** Description:	Disable the date and time fields.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CClockOutDlg::OnNow(void)
{
	m_ebDate.Disable();
	m_ebTime.Disable();
}

/******************************************************************************
** Method:		OnAt()
**
** Description:	Enable the date and time fields.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CClockOutDlg::OnOnAt(void)
{
	m_ebDate.Enable();
	m_ebTime.Enable();
}
