/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DLGVIEW.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CDlgView class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	rParent		The windows parent.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDlgView::CDlgView(const CWnd& rParent) : CView(rParent)
{
	// Initialise members.
	m_pDialog = NULL;
}
