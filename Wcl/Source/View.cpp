/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		VIEW.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CView class methods.
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

CView::CView(const CWnd& rParent)
{
	// Load string for class name.
	m_strClassName.LoadRsc(IDS_VIEW_WND);

	// Override any WNDCLASS members.
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	m_wcClass.lpszClassName = m_strClassName;

	// Override WNDINIT members.
	m_wiStyle.pszClassName  = m_strClassName;
	m_wiStyle.dwStyle       = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	m_wiStyle.rcPos.Set(0, 0, 0, 0);
	m_wiStyle.hParent       = rParent.Handle();
	m_wiStyle.hMenu         = (HMENU) IDS_VIEW_WND;
}

/******************************************************************************
** Method:		Update()
**
** Description:	The view needs updating.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CView::Update(void)
{
}

/******************************************************************************
** Method:		Commit()
**
** Description:	Commit any changes in the view to the underlying object.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CView::Commit(void)
{
}
