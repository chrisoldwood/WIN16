/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		GENRLTAB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CGeneralTab class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "genrltab.hpp"

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

CGeneralTab::CGeneralTab()
{
	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_GENERAL_TAB);
	m_diInit.hParent      = NULL;

	// Define the control table.
	Control Ctrls[] = {	IDC_TITLE,		&m_ebTitle,
						IDC_COPYRIGHT,	&m_ebCopyright,
						IDC_COMPRESS,	&m_cbCompress,
				 		0,				0				};
	
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

void CGeneralTab::OnCreate(void)
{
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);
	
	// Initialise controls.
	m_ebTitle.Text(pDoc->Title());
	m_ebCopyright.Text(pDoc->Copyright());
	m_cbCompress.Check(pDoc->Compress());
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

bool CGeneralTab::OnOk(void)
{
	// Retrieve details.
	m_strTitle     = m_ebTitle.Text();
	m_strCopyright = m_ebCopyright.Text();
	m_bCompress    = m_cbCompress.IsChecked();
	
	return TRUE;
}
