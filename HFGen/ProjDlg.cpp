/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PROJDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CProjectDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "projdlg.hpp"

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

CProjectDlg::CProjectDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_PROJECT_SETTINGS);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_SETTINGS,	&m_tcSettings,
				 		0,				0				};
	
	CtrlTable(Ctrls);

	// Define the tab page table.
	TabCtrlPage PageTable[] = {	&m_tabGeneral,	"General",
								&m_tabHeader,	"Heading",
								&m_tabBody,		"Body Text",
								NULL,			NULL	};
								
	m_tcSettings.Pages(PageTable);
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

void CProjectDlg::OnCreate(void)
{
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

bool CProjectDlg::OnOk(void)
{
	return TRUE;
}
