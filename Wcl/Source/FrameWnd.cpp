/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FRAMEWND.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CFrameWnd class methods.
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

CFrameWnd::CFrameWnd(void)
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Load strings for class name and title.
	m_strClassName.LoadRsc(IDS_FRAME_WND);
	m_strTitle.LoadRsc(IDS_APP_TITLE);

	// Override any WNDCLASS members.
	m_wcClass.hIcon         = pApp->Module()->LoadIcon(ID_APP_ICON);
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_BTNSHADOW + 1);
	m_wcClass.lpszClassName = m_strClassName;

	// Override WNDINIT members.
	m_wiStyle.pszClassName  = m_strClassName;
	m_wiStyle.pszTitle      = m_strTitle;
	m_wiStyle.dwStyle       = WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN;
	m_wiStyle.hParent       = HWND_DESKTOP;


	// Check for accelerator table.
	if (pApp->Module()->FindResource(ID_APP_ACCEL, RT_ACCELERATOR))
	{
		m_Accel.LoadRsc(ID_APP_ACCEL);
	}

	// Check for menu.
	if (pApp->Module()->FindResource(ID_APP_MENU, RT_MENU))
	{
		m_Menu.LoadRsc(ID_APP_MENU);
		m_wiStyle.hMenu = m_Menu.Handle();
	}
	else
	{
		m_wiStyle.hMenu = NULL;
	}

	// Reset members.
	m_pToolBar    = NULL;
	m_pStatusBar  = NULL;
//	m_pActiveDlg  = NULL;
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

CFrameWnd::~CFrameWnd(void)
{
	// Destroy toolbar?
	if (m_pToolBar)
		delete m_pToolBar;

	// Destroy info line?
	if (m_pStatusBar)
		delete m_pStatusBar;
}

/******************************************************************************
** Method:		ProcessMsg()
**
** Description:	Process the message if necessary.
**
** Parameters:	pMsg	The message.
**
** Returns:		TRUE if processed.
**				FALSE if not.
**
*******************************************************************************
*/

bool CFrameWnd::ProcessMsg(MSG* pMsg)
{
	return m_Accel.Translate(m_hWnd, pMsg);
}

/******************************************************************************
** Method:		WndProc()
**
** Description:	This is the window procedure that performs message processing
**				that is specific to a main window.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CFrameWnd::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Decode message.
	switch(iMsg)
	{
		// App is being activated.	
		case WM_ACTIVATEAPP:
			OnActivateApp(wParam);
			break;
		
		// Menu item selected.
		case WM_MENUSELECT:
#ifdef WIN16
			OnSelectMenu(LOWORD(lParam), wParam, (HMENU)wParam);
#else
			OnSelectMenu(HIWORD(wParam), LOWORD(wParam), (HMENU)lParam);
#endif
			break;

		// An application has realized its palette.
//		case WM_PALETTECHANGED:
			// If not us fall through to WM_QUERYNEWPALETTE.
//			if ((HWND) wParam == hWnd)
//				break;

		// Ask if the application wants to realize its palette.
//		case WM_QUERYNEWPALETTE:
//			{
//			CScreenDC	DC;
//			return OnRealizePalette(DC);
//			}
			
		// Can Windows terminate?
		case WM_QUERYENDSESSION:
			if (OnQueryClose())
				break;
			else
				return 0;

		// Application requesting termination.
		case WM_CLOSE:
			if (OnQueryClose())
				Destroy();
			break;

		// Call the default handler.
		default:
			return CPopupWnd::WndProc(hWnd, iMsg, wParam, lParam);
	}

	m_bMsgHandled = TRUE;
	m_lMsgResult  = 0;

	return 0;
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

void CFrameWnd::OnResize(int iFlag, const CSize& rNewSize)
{
	// Only when our window is changed.
	if ( (iFlag == SIZE_RESTORED) || (iFlag == SIZE_MAXIMIZED) )
	{
		// Resize toolbar.
		if (m_pToolBar)
		{
			// Get current pos.
			CRect rcToolBar = m_pToolBar->ClientRect();
			
			// Calc new pos and move.
			CRect rcNewPos(0, 0, rNewSize.cx, rcToolBar.Size().cy);
			m_pToolBar->Move(rcNewPos);
		}
		
		// Resize Status bar.
		if (m_pStatusBar)
		{
			// Get current pos.
			CRect rcStatusBar = m_pStatusBar->ClientRect();

			// Calc new pos and move.
			CRect rcNewPos(0, rNewSize.cy - rcStatusBar.Size().cy, 
								rNewSize.cx, rNewSize.cy);
			m_pStatusBar->Move(rcNewPos);
		}
	}
}

/******************************************************************************
** Method:		OnSelectMenu()
**
** Description:	Decode the menu item being shown and display a hint for it. The
**				strings IDs are the same as the item IDs, except for popup
**				menus where they are a multiple of 25; in which case it looks
**				as the first item to determine the hint ID.
**
** Parameters:	iFlags		The menu ite flags.
**				iItemID		The menu ID.
**				hMenu		The menu handle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::OnSelectMenu(uint iFlags, uint iItemID, HMENU hMenu)
{
	char* pszHint = "";

	// Is a popup?
	if (iFlags & MF_POPUP)
	{
		// Menu item selected?
		if (iFlags == 0xFFFF)
		{
			pszHint = "";
		}
		else if (iFlags & MF_SYSMENU)
		{
			pszHint = "System menu";
		}
		else // Popup menu
		{
#ifdef WIN32
			hMenu = GetSubMenu(hMenu, iItemID);
#endif

			OnShowMenuPopupHint(hMenu);
			return;
		}
	}
	else // Menu item
	{
		// Is a separator
		if (iFlags & MF_SEPARATOR)
		{
			pszHint = "";
		}
		else // Menu item.
		{
			OnShowMenuItemHint(iItemID);
			return;
		}
	}
		
	// Show menu hint.
	if (m_pStatusBar)
		m_pStatusBar->HintBar()->Hint(pszHint);
}

/******************************************************************************
** Method:		OnShowMenuItemHint()
**
** Description:	Display a hint for the selected menu item. This method is
**				virtual and can be overriden, by defualt it loads the hint from
**				resource file and displays it.
**
** Parameters:	iItemID		The menu ID or handle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::OnShowMenuItemHint(uint iItemID)
{
	CString strHint;
	
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	strHint.LoadRsc(iItemID);

	// Show hint.
	if (m_pStatusBar)
		m_pStatusBar->HintBar()->Hint(strHint);
}

/******************************************************************************
** Method:		OnShowMenuPopupHint()
**
** Description:	Display a hint for the selected popup menu. This method is
**				virtual and can be overriden, by defualt it loads the hint from
**				resource file and displays it. It looks at the first item in
**				the submenu and uses modulo 25 to find the hint for it.
**
** Parameters:	hMenu		The menu handle
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::OnShowMenuPopupHint(HMENU hMenu)
{
	// Get ID of first item in menu.
	int iFirstID = GetMenuItemID(hMenu, 0);
    
    // Is a first item?
    if (iFirstID != -1)
    {
		CString strHint;
		
		// Get application object.
		CTask* pApp = CTask::This();
		ASSERT(pApp);
	
		// Calculate menu hint and load.
		// The hint is always a multiple of 100.
		int iHintID = iFirstID - (iFirstID % 10);

		strHint.LoadRsc(iHintID);

		// Show hint.
		if (m_pStatusBar)
			m_pStatusBar->HintBar()->Hint(strHint);
	}
	else
	{
		// Show dummy hint.
		if (m_pStatusBar)
			m_pStatusBar->HintBar()->Hint("");
	}
}

/******************************************************************************
** Method:		OnQueryClose()
**
** Description:	Ask if the main window can close.
**
** Parameters:	None.
**
** Returns:		TRUE	If it can.
**				FALSE	If it cannot.
**
*******************************************************************************
*/

bool CFrameWnd::OnQueryClose(void)
{
	return TRUE;
}

/******************************************************************************
** Method:		OnDestroy()
**
** Description:	The main window is being destroyed so terminate the app.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::OnDestroy(void)
{
	PostQuitMessage(0);
}

/******************************************************************************
** Method:		OnRealizePalette()
**
** Description:	The application is being asked to realize it's palette. This
**				may be because it now has the focus, or another app has already
**				realized it's own. By default do nothing.
**
** Parameters:	rDC		A screen device.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

bool CFrameWnd::OnRealizePalette(CDC& rDC)
{
	return FALSE;
}

/******************************************************************************
** Method:		EnableCmd()
**				DisableCmd()
**
** Description:	Enable or disable a command. This will change the state of a
**				menu item and toolbar control if appropriate.
**
** Parameters:	iCmdID		The command ID.
**				bEnable		Flag to enable or disable.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::EnableCmd(uint iCmdID, bool bEnable)
{
	m_Menu.EnableCmd(iCmdID, bEnable);
	
	if (m_pToolBar)
		m_pToolBar->EnableCmd(iCmdID, bEnable);
}

void CFrameWnd::DisableCmd(uint iCmdID, bool bDisable)
{
	m_Menu.DisableCmd(iCmdID, bDisable);

	if (m_pToolBar)
		m_pToolBar->DisableCmd(iCmdID, bDisable);
}

/******************************************************************************
** Method:		ClientRect()
**
** Description:	Get the position of the client area, accounting for the DIL
**				and toolbars etc.
**
** Parameters:	None.
**
** Returns:		The rect.
**
*******************************************************************************
*/

CRect CFrameWnd::ClientRect(void) const
{
	CRect rcClient;

	// Get the maximum size.
	::GetClientRect(m_hWnd, &rcClient);

	// Has a visible toolbar.
	if ( (m_pToolBar) && (m_pToolBar->IsVisible()) )
	{
		// Get current pos.
		CRect rcToolBar = m_pToolBar->ClientRect();
			
		// Adjust client rect.
		rcClient.top += rcToolBar.Height();
	}

	// Has a visible info line.
	if ( (m_pStatusBar) && (m_pStatusBar->IsVisible()) )
	{
		// Get current pos.
		CRect rcStatusBar = m_pStatusBar->ClientRect();

		// Adjust client rect.
		rcClient.bottom -= rcStatusBar.Height();
	}
	
	return rcClient;
}

/******************************************************************************
** Method:		OnActivateApp()
**
** Description:	The application is about to be activated or de-activated.
**
** Parameters:	bActivating		Being activated?
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFrameWnd::OnActivateApp(bool bActivating)
{
}
