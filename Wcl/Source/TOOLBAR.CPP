/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOOLBAR.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CToolBar class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

// Width and height of a button.
#define	BUTTON_SIZE		24
#define BORDER_SIZE		3

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

CToolBar::CToolBar(const CWnd& rParent)
{
	// Load string for class name.
	m_strClassName.LoadRsc(IDS_TOOLBAR_WND);

	// Override any WNDCLASS members.
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
	m_wcClass.lpszClassName = m_strClassName;

	// Override WNDINIT members.
	m_wiStyle.pszClassName  = m_strClassName;
	m_wiStyle.dwStyle       = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	m_wiStyle.rcPos.Set(0, 0, 50, BUTTON_SIZE + (BORDER_SIZE*2) + 2);
	m_wiStyle.hParent       = rParent.Handle();
	m_wiStyle.hMenu         = (HMENU) IDS_TOOLBAR_WND;
	
	// Initialise size.
	m_Size = m_wiStyle.rcPos.Size();

	// Initialise other members.
	m_iNumCmds  = 0;
    m_pBtnTable = NULL;
    
    // Create the button bitmaps.
    CreateBitmaps();
    
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

    // Add itself to message filters.
    pApp->AddMsgFilter(this);
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Free up child windows.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CToolBar::~CToolBar()
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

    // Remove itself from message filters.
    pApp->DelMsgFilter(this);

	// Button table allocated?
	if (m_pBtnTable)
	{
		// For all cmd buttons.
		for (uint i = 0; i < m_iNumCmds; i++)
		{
			// Is a button?
			if (m_pBtnTable[i].pButton)
				delete m_pBtnTable[i].pButton;
		}
		
		delete m_pBtnTable;
	}
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Paints the toolbar background.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::OnPaint(CDC& rDC)
{
	rDC.Pen(GetSysColor(COLOR_BTNSHADOW));
	rDC.Line(0, m_Size.cy-1, m_Size.cx, m_Size.cy-1);
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	Window resized - save the new window dimensions.
**
** Parameters:	iFlag		The resize method.
**				rNewSize	The new window dimensions.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::OnResize(int iFlag, const CSize& rNewSize)
{
	// Update members.
	m_Size = rNewSize;
}

/******************************************************************************
** Method:		Cmds()
**
** Description:	Create the toolbar buttons using the table of commands given.
**
** Parameters:	pCmdTable	An array of cmd ids that represents the toolbar
**							buttons. IDC_STATIC is used as a spacer and 0 is
**							used to mark the end of the array.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CToolBar::Cmds(uint* pCmdTable)
{
	int		i = 0;
	CPoint	ptOrigin(BUTTON_SIZE/2, BORDER_SIZE);
	CSize	dmSize(BUTTON_SIZE, BUTTON_SIZE);
	CPoint	ptBmpOrigin(0,0);

	ASSERT(pCmdTable);
	
	// How big is array?
	while(pCmdTable[m_iNumCmds] != 0)
		m_iNumCmds++;
	
	// Allocate table.
	m_pBtnTable = new CmdBtn[m_iNumCmds];
	if (!m_pBtnTable)
		return FALSE;
	
	// For all commands.
	while(pCmdTable[i] != 0)
	{
		// Spacer?
		if (pCmdTable[i] == ID_SPACE)
		{
			m_pBtnTable[i].iCmdID  = ID_SPACE;
			m_pBtnTable[i].pButton = NULL;

			ptOrigin.x += BUTTON_SIZE/2;
		}
		// Command
		else
		{
			// Allocate a button.
			CBmpButton* pButton = new CBmpButton;
			if (!pButton)
				return FALSE;
			
			CRect	rcPos(ptOrigin, dmSize);
			
			// Create it.
			if (!pButton->Create(this, pCmdTable[i], rcPos))
				return FALSE;
			
			// Setup button.
			pButton->Bitmap(&m_BmpEnabled, &m_BmpDisabled, ptBmpOrigin);
			
			// Save in the table.
			m_pBtnTable[i].iCmdID  = pCmdTable[i];
			m_pBtnTable[i].pButton = pButton;

			// Advance origins.
			ptBmpOrigin.x += BUTTON_SIZE;
			ptOrigin.x    += BUTTON_SIZE-1;
		}
		
		// Move to next.
		i++;
	}
	
	return TRUE;
}

/******************************************************************************
** Methods:		OnCtlMsg()
**
** Description:	Convert all BN_CLICKED messages into WM_COMMAND messages and
**				forward to the frame window.
**
** Parameters:	iID			Child control ID.
**				iMsg		Control message.
**				hControl	Handle of control window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::OnCtlMsg(uint iID, uint iMsg, HWND hControl)
{
	// Forward to frame window.
	if (iMsg == BN_CLICKED)
		::PostMessage(GetParent(m_hWnd), WM_COMMAND, iID, 0L);
}

/******************************************************************************
** Methods:		EnableCmd()
**
** Description:	Enable or disable a toolbar command button.
**
** Parameters:	iCmdID		The button.
**				bEnable		The new state.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::EnableCmd(uint iCmdID, bool bEnable)
{
	// Button table allocated?
	if (m_pBtnTable)
	{
		// Find command button.
		for (uint i = 0; i < m_iNumCmds; i++)
		{
			// Is command?
			if (m_pBtnTable[i].iCmdID == iCmdID)
				m_pBtnTable[i].pButton->Enable(bEnable);
		}
	}
}

/******************************************************************************
** Methods:		CreateBitmaps()
**
** Description:	Create the toolbar button bitmaps for the enabled and disabled
**				states.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::CreateBitmaps(void)
{
	CBitmap	bmpButtons;
	CBitmap	bmpMask;
	CBitmap	bmpMask2;
	
    // Load the button bitmap.
    bmpButtons.LoadRsc(ID_APP_TOOLBAR);

	// Get dimensions.
	CSize BmpSize = bmpButtons.Size();
	
	// Setup DCs.
	CScreenDC	ScnDC;
	CMemDC		ButtonsDC(ScnDC);
	CMemDC		EnabledDC(ScnDC);
	CMemDC		DisabledDC(ScnDC);
	CMemDC		MaskDC(ScnDC);
	CMemDC		Mask2DC(ScnDC);

	// Allocate the final bitmaps.
	m_BmpEnabled.Create(BmpSize, ScnDC);
	m_BmpDisabled.Create(BmpSize, ScnDC);

	// Allocate the temp bitmaps.
	bmpMask.Create(BmpSize);
	bmpMask2.Create(BmpSize);
	
	// Select bitmaps into DCs.
	ButtonsDC.Bitmap(bmpButtons);
	EnabledDC.Bitmap(m_BmpEnabled);
	DisabledDC.Bitmap(m_BmpDisabled);
	MaskDC.Bitmap(bmpMask);
	Mask2DC.Bitmap(bmpMask2);

	// Create button background.
	EnabledDC.Brush(GetSysColor(COLOR_BTNFACE));
	EnabledDC.PatBlt(CRect(CPoint(0,0), BmpSize));

	DisabledDC.Brush(GetSysColor(COLOR_BTNFACE));
	DisabledDC.PatBlt(CRect(CPoint(0,0), BmpSize));
	
	// Create general mask.
	ButtonsDC.BkColour(RGB(192,192,192));

	::BitBlt(MaskDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				ButtonsDC.Handle(), 0, 0, SRCCOPY);

	// Create special white mask.
	ButtonsDC.BkColour(RGB(255,255,255));

	::BitBlt(Mask2DC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				ButtonsDC.Handle(), 0, 0, SRCCOPY);

	// Create enabled state
	::BitBlt(EnabledDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				MaskDC.Handle(), 0, 0, SRCAND);

	MaskDC.PatBlt(CRect(CPoint(0,0), BmpSize), DSTINVERT);

	ButtonsDC.BkColour(RGB(255,255,255));

	::BitBlt(ButtonsDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				MaskDC.Handle(), 0, 0, SRCAND);

	::BitBlt(EnabledDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				ButtonsDC.Handle(), 0, 0, SRCPAINT);

	// Create disabled state.

	MaskDC.PatBlt(CRect(CPoint(0,0), BmpSize), DSTINVERT);

	::BitBlt(MaskDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				Mask2DC.Handle(), 0, 0, SRCPAINT);

	DisabledDC.Brush(GetSysColor(COLOR_BTNHIGHLIGHT));

	::BitBlt(DisabledDC.Handle(), 1, 1, BmpSize.cx, BmpSize.cy,
				MaskDC.Handle(), 0, 0, 0x00B8074AL);

	DisabledDC.Brush(GetSysColor(COLOR_BTNSHADOW));

	::BitBlt(DisabledDC.Handle(), 0, 0, BmpSize.cx, BmpSize.cy,
				MaskDC.Handle(), 0, 0, 0x00B8074AL);
}

/******************************************************************************
** Method:		FilterMessage()
**
** Description:	Spy on all messages.
**
** Parameters:	pMsg	The message.
**
** Returns:		TRUE	if processed.
**				FALSE	if not.
**
*******************************************************************************
*/

bool CToolBar::FilterMessage(MSG* pMsg)
{
	// Only interested in mouse moves.
	if (pMsg->message == WM_MOUSEMOVE)
	{
		// Is in the toolbar window?
		if (pMsg->hwnd == m_hWnd)
		{
			// Check for a disabled window.
			HWND hWnd = ChildWindowFromPoint(m_hWnd, MAKEPOINT(pMsg->lParam));

			// Is still toolbar?
			if (hWnd == m_hWnd)
				ShowHint(NULL);
			else
				ShowHint(CWnd::FromHandle(hWnd));
		}
		// or toolbar control?
		else if (GetParent(pMsg->hwnd) == m_hWnd)
		{
			ShowHint(CWnd::FromHandle(pMsg->hwnd));
		}
	}
	
	return FALSE;
}

/******************************************************************************
** Method:		ShowHint()
**
** Description:	Show the status bar hint for the toolbars' control.
**
** Parameters:	pWnd	The window to show the hint for or NULL to remove the
**						hint.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CToolBar::ShowHint(const CWnd* pWnd) const
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// App has main window and status bar?
	if ( (!pApp->FrameWnd()) || (!pApp->FrameWnd()->StatusBar()) )
		return;
		
	// Get the status bar.
	CStatusBar*	pStatusBar = pApp->FrameWnd()->StatusBar();

	// Show a hint?
	if (pWnd)
	{
		// Get control ID.
		CCtrlWnd*	pCtrlWnd = (CCtrlWnd*) pWnd;
		uint 		iID      = pCtrlWnd->ID();
		CString		strHint;
		
		// Show hint.
		strHint.LoadRsc(iID);
		pStatusBar->HintBar()->Hint(strHint);
	}
	else
	{
		// Remove hint.
		pStatusBar->HintBar()->Hint("");
	}
}
