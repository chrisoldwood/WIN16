/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPVIEW.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAppView class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings.
**
** Parameters:	rParent		The views' parent window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CAppView::CAppView(const CWnd& rParent) : CGfxView(rParent)
{
	// Initialise view settings.
	MapMode(MM_TEXT);
	Size(CSize(200, 200));
	LineScrollSize(10);
	PageScrollSize(50);
}

/******************************************************************************
** Method:		OnViewPaint()
**
** Description:	Paint the window contents.
**
** Parameters:	rDC		The device to use.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnViewPaint(CDC& rDC)
{
	CRect	rcBox(0, 0, 200, 200);
	
	rDC.Rectangle(rcBox);
	rDC.Line(0, 0, 200, 200);
	rDC.Line(0, 200, 200, 0);
}
