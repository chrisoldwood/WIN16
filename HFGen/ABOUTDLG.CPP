/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ABOUTDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAboutDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "aboutdlg.hpp"

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

CAboutDlg::CAboutDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_ABOUT);
	m_diInit.hParent      = pParent->Handle();
}
