/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		STATBAR.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CStatusBar class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

// Width of border around child windows.
#define BORDER_SIZE		3

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	rParent		The windows parent.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CStatusBar::CStatusBar(const CWnd& rParent)
{
    // Get the height of the font.
    CScreenDC DC;
    
    DC.Font(SYSTEM_FONT);
    CSize FontSize = DC.TextExtents("Ly");

	// Load string for class name.
	m_strClassName.LoadRsc(IDS_STATUSBAR_WND);

	// Override any WNDCLASS members.
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
	m_wcClass.lpszClassName = m_strClassName;

	// Override WNDINIT members.
	m_wiStyle.pszClassName  = m_strClassName;
	m_wiStyle.dwStyle       = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	m_wiStyle.rcPos.Set(0, 0, 0, FontSize.cy + (2*BORDER_SIZE) + 3);
	m_wiStyle.hParent       = rParent.Handle();
	m_wiStyle.hMenu         = (HMENU) IDS_STATUSBAR_WND;

	// Initialise size.
	m_Size = m_wiStyle.rcPos.Size();
	
	// Set no active child.
	m_pActive = NULL;

	// Reset children.
	m_pHintBar = NULL;
}

/******************************************************************************
** Method:		Destructor.
**
** Description:	Cleans up the child windows and resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CStatusBar::~CStatusBar(void)
{
	// Hint window?
	if (m_pHintBar)
		delete m_pHintBar;

	// Meter window?
//	if (m_pMeterWnd)
//		delete m_pMeterWnd;
}

/******************************************************************************
** Method:		Create()
**
** Description:	Overloaded creation method that calls the base create method
**				and then constructs the default infoline child windows.
**
** Parameters:	None.
**
** Returns:		TRUE		On Success.
**				FALSE		On Failure.
**
*******************************************************************************
*/

bool CStatusBar::Create(void)
{
	// First create this window.
	if(!CPopupWnd::Create())
		return FALSE;
		
	// Now create the hint window.
	m_pHintBar = new CHintBar(*this);
	if (!m_pHintBar->Create())
		return FALSE;

	// Set active window to be the hint window.
	m_pActive = m_pHintBar;
			
	return TRUE;
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Paints the infoline background.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CStatusBar::OnPaint(CDC& rDC)
{
	rDC.Pen(GetSysColor(COLOR_BTNSHADOW));
	rDC.Line(0, 0, m_Size.cx, 0);
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	Window resized - save the new window dimensions and resize all
**				the info line children.
**
** Parameters:	iFlag		The resize method.
**				rNewSize	The new window dimensions.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CStatusBar::OnResize(int iFlag, const CSize& rNewSize)
{
	// Update members.
	m_Size = rNewSize;
	
	// Calculate the position of all the children.
	CRect rcNewPos(BORDER_SIZE, BORDER_SIZE+1, rNewSize.cx-BORDER_SIZE, 
					rNewSize.cy-BORDER_SIZE);

	ASSERT(m_pHintBar);
	
	// Move the children
	m_pHintBar->Move(rcNewPos);
}

/******************************************************************************
** Method:		ActivateWnd()
**
** Description:	Make the child window the currently visible one. This is used
**				internally to switch between different child windows when a
**				command is issued, such as SetHint().
**
** Parameters:	pWindow		The child window to make visible.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CStatusBar::ActivateWnd(CWnd* pWnd)
{
	ASSERT(pWnd);
	
	// Changed?
	if (m_pActive != pWnd)
	{
		// Is previous?
		if (m_pActive)
			m_pActive->Hide();
			
		m_pActive = (CWnd*) pWnd;
		m_pActive->Show();
	}
}
