/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DLGFRAME.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CDlgFrame class methods.
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

CDlgFrame::CDlgFrame(void)
{
	// Override WNDINIT members.
	m_wiStyle.dwStyle = WS_OVERLAPPED | WS_CLIPCHILDREN | WS_CAPTION
						| WS_SYSMENU | WS_MINIMIZEBOX;

	// Reset members.
	m_pAppDlg = NULL;
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

CDlgFrame::~CDlgFrame(void)
{
	if (m_pAppDlg)
		delete m_pAppDlg;
}

/******************************************************************************
** Method:		Dialog()
**
** Description:	Set the frame windows' main dialog and resize to fit.
**
** Parameters:	pDialog		The dialog.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDlgFrame::Dialog(CDialog* pDialog)
{
	int iToolBarHt = 0;
	int iStatBarHt = 0;

	ASSERT(pDialog);
	
	// Save member.
	m_pAppDlg = pDialog;

	// Get the current position.
	CRect Pos = WindowRect();
    
	// Get the size of the dialog.
	CSize DlgSize = m_pAppDlg->WindowRect().Size();
	
	// Get the toolbar and info line heights.
	if (m_pToolBar)
		iToolBarHt = m_pToolBar->ClientRect().Size().cy;
    
	if (m_pStatusBar)
		iStatBarHt = m_pStatusBar->ClientRect().Size().cy;
	
	// Calculate the new dimensions.
	CSize NewSize(DlgSize.cx + (2*GetSystemMetrics(SM_CXBORDER)),
				  DlgSize.cy + iToolBarHt + iStatBarHt
				  + GetSystemMetrics(SM_CYCAPTION) + GetSystemMetrics(SM_CYMENU)
				  + (2*GetSystemMetrics(SM_CYBORDER)));

	// Resize it.
	CRect NewPos(Pos.TopLeft(), NewSize);
	Move(NewPos);
	
	// Toolbar?
	if (m_pToolBar)
	{
		// Adjust dialog for toolbar.
		CRect NewPos(CPoint(0, iToolBarHt), DlgSize);
		m_pAppDlg->Move(NewPos);
	}
}
