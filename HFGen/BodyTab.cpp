/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BODYTAB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CBodyTab class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "bodytab.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CBodyTab::CBodyTab()
{
	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_BODY_TAB);
	m_diInit.hParent      = NULL;

	// Define the control table.
	Control Ctrls[] = {	IDC_LINE_SPACING,	&m_ebLineSpacing,
						IDC_PARA_SPACING,	&m_ebParaSpacing,
						IDC_LEFT_MARGIN,	&m_ebLeftMargin,
						IDC_RIGHT_MARGIN,	&m_ebRightMargin,
				 		0,					0				};
	
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

void CBodyTab::OnCreate(void)
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

bool CBodyTab::OnOk(void)
{
	return TRUE;
}
