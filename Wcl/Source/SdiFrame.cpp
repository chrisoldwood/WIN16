/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SDIFRAME.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CSDIFrame class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSDIFrame::CSDIFrame(void)
{
	// Reset members.
	m_pView = NULL;
}

/******************************************************************************
** Method:		Destructor.
**
** Description:	Free up any child windows and resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSDIFrame::~CSDIFrame(void)
{
}

/******************************************************************************
** Method:		SetView()
**
** Description:	Set the frame windows' view and resize to fit.
**
** Parameters:	pView		A pointer to the view window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CSDIFrame::View(CView* pView)
{
	// New view?
	if (pView)
	{
	    //
		// Resize the view to fit the area
		// between the toolbar and infoline.
		//
		CRect rcClient = ClientRect();
		pView->Move(rcClient);
	}
	
	// Save new setting.
	m_pView = pView;
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	The window has been resized. This resizes the toolbar and info
**				line to match the new settings.
**
** Parameters:	iFlag		The resize method.
**				rNewSize	The new window dimensions.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CSDIFrame::OnResize(int iFlag, const CSize& rNewSize)
{
	// Only when our window has changed.
	if ( (iFlag == SIZE_RESTORED) || (iFlag == SIZE_MAXIMIZED) )
	{
		// Do toolbar and infoline first.
		CFrameWnd::OnResize(iFlag, rNewSize);
		
		// Have a view?
		if (m_pView)
		{
		    //
			// Resize the view to fit the area
			// between the toolbar and infoline.
			//
			CRect rcClient = ClientRect();
			m_pView->Move(rcClient);
		}
	}
}
