/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRSESDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CPruneSessionsDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "prsesdlg.hpp"
#include <limits.h>

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

CPruneSessionsDlg::CPruneSessionsDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_PRUNE_SESSIONS_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_ALL, 	&m_rbAll,
						IDC_BEFORE, &m_rbBefore,
						IDC_DATE, 	&m_ebDate,
				 		0,			0			};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_ALL, 	BN_CLICKED,		(CtlMsgFn)OnAll,
								IDC_BEFORE,	BN_CLICKED,		(CtlMsgFn)OnBefore,
								0, 			0,				0					};
	
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

void CPruneSessionsDlg::OnCreate(void)
{
	// Initialise date and time fields.
	m_Date.Set();
	m_ebDate.Text(m_Date);

	// Initalise prune selection.
	m_rbAll.Select(TRUE);
	m_rbBefore.Select(FALSE);
	OnAll();
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

bool CPruneSessionsDlg::OnOk(void)
{
	// Clock in now?
	if (m_rbAll.IsSelected())
	{
		CDate	Date;

		// Create date as max.
		Date  += ULONG_MAX;
		m_Date = Date;
	}
	else
	{
		// Get date from edit box.
		if (!m_Date.Set(m_ebDate.Text()))
		{
			Alert("Date is invalid.");
			return FALSE;
		}
	}

	return TRUE;
}

/******************************************************************************
** Method:		OnAll()
**
** Description:	Disable the date field.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPruneSessionsDlg::OnAll(void)
{
	m_ebDate.Disable();
}

/******************************************************************************
** Method:		OnBefore()
**
** Description:	Enable the date field.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPruneSessionsDlg::OnBefore(void)
{
	m_ebDate.Enable();
}
