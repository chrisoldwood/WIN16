/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TABCTRL.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CTabCtrl class definition.
**
*******************************************************************************
*/

#include "wcl.hpp"

// Tab drawing parameters.
#define TITLE_BORDER_CX		5
#define TITLE_BORDER_CY		5
#define TAB_TOP_OFFSET		3
#define TAB_SPACING			1

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise members and find text metrics of default font.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTabCtrl::CTabCtrl(void)
{
	// Initialise members.
	m_pPageTable   = NULL;
	m_iNumPages    = 0;
	m_iActivePage  = -1;

    CScreenDC DC;

	// Create the tabs font.
	m_hTabFont = DC.CreateFont(8, "MS Sans Serif");
    
    // Get the height of the font.
    DC.Font(m_hTabFont);
    CSize FontSize = DC.TextExtents("Ly");

	m_iTitleHeight = FontSize.cy;
	m_iTabHeight   = m_iTitleHeight + (TITLE_BORDER_CY * 2);
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Free up resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTabCtrl::~CTabCtrl(void)
{
	// Free page table.
//	if (m_pPageTable)
//		delete []m_pPageTable;
		
	// Free font.
	DeleteObject(m_hTabFont);
}

/******************************************************************************
** Method:		Register().
**
** Description:	Register a dummy class for the control.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTabCtrl::Register(void)
{
	CString		strClassName;
	WNDCLASS	wcClass;
	
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Get the class name for the resource file.
	strClassName.LoadRsc(IDS_TABCTRL_WND);

	// Fill in class structure.
	wcClass.style         = CS_HREDRAW | CS_VREDRAW;
	wcClass.lpfnWndProc   = DefWindowProc;
	wcClass.cbClsExtra    = 0;
	wcClass.cbWndExtra    = 0;
	wcClass.hInstance     = pApp->Module()->Handle();
	wcClass.hIcon         = NULL;
	wcClass.hCursor       = pApp->Module()->LoadStdCursor(IDC_ARROW);
	wcClass.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
	wcClass.lpszMenuName  = NULL;
	wcClass.lpszClassName = strClassName;
	
	// Register.
	return ::RegisterClass(&wcClass);
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Create the tab pages and align them inside the control.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::OnCreate(void)
{
	// Change WndProc to our multi purpose one.
	WindowProc(PopupWndProc);
	
	// Get window dimensions.
	m_rcArea = ClientRect();
	
	// Calculate tab page position.
	CRect rcPage(2, m_iTabHeight, m_rcArea.right-3, m_rcArea.bottom-3);
	
	// Create the page dialogs.
	for (int i = 0; i < m_iNumPages; i++)
	{
		// Create the page, hide and centre in control.
		m_pPageTable[i].pPage->Parent(*this);
		m_pPageTable[i].pPage->RunModeless();
		m_pPageTable[i].pPage->Show(SW_HIDE);
		m_pPageTable[i].pPage->Move(rcPage);
	}

	//Activate first page, if one.
	if (m_iNumPages)
		ActivatePage(0);
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Paints the tabs and border.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::OnPaint(CDC& rDC)
{
	// Draw outer border.
	rDC.Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
	rDC.Line(0, m_iTabHeight-2, 0,                m_rcArea.bottom-1);
	rDC.Line(0, m_iTabHeight-2, m_rcArea.right-1, m_iTabHeight-2);

	rDC.Pen(GetSysColor(COLOR_BTNFACE));
	rDC.Line(1, m_iTabHeight-1, 1,                m_rcArea.bottom-2);
	rDC.Line(1, m_iTabHeight-1, m_rcArea.right-2, m_iTabHeight-1);

	rDC.Pen(RGB(0,0,0));
	rDC.Line(0,                m_rcArea.bottom-1, m_rcArea.right,   m_rcArea.bottom-1);
	rDC.Line(m_rcArea.right-1, m_iTabHeight-1,    m_rcArea.right-1, m_rcArea.bottom-1);

	rDC.Pen(GetSysColor(COLOR_BTNSHADOW));
	rDC.Line(1,                m_rcArea.bottom-2, m_rcArea.right-1, m_rcArea.bottom-2);
	rDC.Line(m_rcArea.right-2, m_iTabHeight,      m_rcArea.right-2, m_rcArea.bottom-2);
	
	// Draw tabs.
	for (int i=0; i < m_iNumPages; i++)
	{
		if (i == m_iActivePage)
			DrawTab(rDC, i, TRUE);
		else
			DrawTab(rDC, i, FALSE);
	}
}

/******************************************************************************
** Method:		DrawTab()
**
** Description:	Draws a single tab, as either active or inactive.
**
** Parameters:	rDC			The device to paint on.
**				iTabNum		The index of the tab.
**				bActive		Draw active flag.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::DrawTab(CDC& rDC, int iTabNum, bool bActive) const
{
	// Get tab position.
	CRect rcTab = TabPos(iTabNum);
	
	// Draw lower border.
	if (bActive)
	{
		rDC.Pen(GetSysColor(COLOR_BTNFACE));
		rDC.Line(rcTab.left+1, rcTab.bottom-1, rcTab.right, rcTab.bottom-1);
		rDC.Line(rcTab.left+1, rcTab.bottom,   rcTab.right, rcTab.bottom);
	}
	else
	{
		rDC.Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
		rDC.Line(rcTab.left+1, rcTab.bottom-1, rcTab.right, rcTab.bottom-1);
		rDC.Pen(GetSysColor(COLOR_BTNFACE));
		rDC.Line(rcTab.left+1, rcTab.bottom,   rcTab.right, rcTab.bottom);
	}
	
	// Draw edges.
	rDC.Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
	rDC.Line(rcTab.left, rcTab.bottom-1, rcTab.left, rcTab.top+TAB_TOP_OFFSET);
	rDC.Line(rcTab.left, rcTab.top+TAB_TOP_OFFSET, rcTab.left+TAB_TOP_OFFSET, rcTab.top);
	rDC.Line(rcTab.left+TAB_TOP_OFFSET, rcTab.top, rcTab.right-TAB_TOP_OFFSET, rcTab.top);

	rDC.Pen(GetSysColor(COLOR_BTNSHADOW));
	rDC.Line(rcTab.right-TAB_TOP_OFFSET-1, rcTab.top, rcTab.right-1, rcTab.top+TAB_TOP_OFFSET);
	rDC.Line(rcTab.right-1, rcTab.top+TAB_TOP_OFFSET, rcTab.right-1, rcTab.bottom-1);
	rDC.Pen(RGB(0,0,0));
	rDC.Line(rcTab.right-TAB_TOP_OFFSET, rcTab.top, rcTab.right, rcTab.top+TAB_TOP_OFFSET);
	rDC.Line(rcTab.right, rcTab.top+TAB_TOP_OFFSET, rcTab.right, rcTab.bottom-1);
	
	// Draw title.
	rDC.TextColour(GetSysColor(COLOR_BTNTEXT));
	rDC.BkMode(TRANSPARENT);
	rDC.Font(m_hTabFont);
	rDC.TextOut(rcTab.left+TITLE_BORDER_CX, rcTab.top+TITLE_BORDER_CY,
					m_pPageTable[iTabNum].strTitle);
}

/******************************************************************************
** Method:		TabPos()
**
** Description:	Gets the position of the tab relative to the control.
**
** Parameters:	iTabNum		The index of the tab.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CRect CTabCtrl::TabPos(int iTabNum) const
{
	CRect	rcTab;
	
	// Set up top and bottom.
	rcTab.top    = 0;
	rcTab.bottom = m_iTabHeight-1;
	
	// Calculate left and right edges.
	for(int i=0; i < iTabNum; i++)
	{
		rcTab.left += m_pPageTable[i].iTitleWidth + (TITLE_BORDER_CX * 2);
		rcTab.left += TAB_SPACING;
	}
	
	rcTab.right = rcTab.left + m_pPageTable[iTabNum].iTitleWidth + (TITLE_BORDER_CX * 2);
	
	return rcTab;
}

/******************************************************************************
** Method:		Pages()
**
** Description:	Creates a table to store the list of pages in and calculates
**				the width of the tabs.
**
** Parameters:	pPageTable		The list of pages, terminated by a NULL entry.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::Pages(TabCtrlPage* pPageTable)
{
	ASSERT(pPageTable);

	TabCtrlPage* pTabPage = pPageTable;

	// Count the number of pages.
	while (pTabPage->pPage)
	{
		m_iNumPages++;
	    pTabPage++;
	}

	// Allocate memory for the table.
	m_pPageTable = new TabPage[m_iNumPages];
	ASSERT(m_pPageTable);
	
	pTabPage = pPageTable;
	int iIdx  = 0;

    CScreenDC DC;
    DC.Font(m_hTabFont);

	// Copy the table
	while (iIdx < m_iNumPages)
	{
		// Copy the members.
		m_pPageTable[iIdx].pPage       = pTabPage->pPage;
		m_pPageTable[iIdx].strTitle    = pTabPage->pszTitle;

		// Calculate the width of the title.
    	CSize FontSize = DC.TextExtents(pTabPage->pszTitle);
		m_pPageTable[iIdx].iTitleWidth = FontSize.cx;
		
	    pTabPage++;
	    iIdx++;
	}
}

/******************************************************************************
** Method:		ActivatePage()
**
** Description:	Deactivate the current page and activate a new one.
**
** Parameters:	iPageNum	The page to activate.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::ActivatePage(int iPageNum)
{
	CScreenDC	DC(this);

	// Page active?
	if (m_iActivePage >= 0)
	{
		// Hide current one.
		m_pPageTable[m_iActivePage].pPage->Show(SW_HIDE);
		DrawTab(DC, m_iActivePage, FALSE);
	}
	
	// Show new page.
	m_iActivePage = iPageNum;
	m_pPageTable[m_iActivePage].pPage->Show();
	DrawTab(DC, m_iActivePage, TRUE);
}

/******************************************************************************
** Method:		OnLeftButtonUp()
**
** Description:	Check to see if a new tab has been selected and show a new page
**				if it has.
**
** Parameters:	ptCursor	Point where mouse was released.
**				iKeyFlags	Key status.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTabCtrl::OnLeftButtonUp(const CPoint& ptCursor, uint iKeyFlags)
{
	// Find which tab was selected.
	for(int i=0; i < m_iNumPages; i++)
	{
		// Get tab position.
		CRect rcTab = TabPos(i);
		
		// Selected?
		if (ptCursor.InRect(rcTab))
			break;
	}

	// Hit a different tab?
	if ( (i < m_iNumPages) && (i != m_iActivePage) )
		ActivatePage(i);
}
