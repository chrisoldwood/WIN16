/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		POPUPWND.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CPopupWnd class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Fill in the default window class and inital display settings'
**				structures.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPopupWnd::CPopupWnd(void)
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Fill in default WNDCLASS members.
	m_wcClass.style         = CS_HREDRAW | CS_VREDRAW;
	m_wcClass.lpfnWndProc   = DefWindowProc;
	m_wcClass.cbClsExtra    = 0;
	m_wcClass.cbWndExtra    = 0;
	m_wcClass.hInstance     = pApp->Module()->Handle();
	m_wcClass.hIcon         = NULL;
	m_wcClass.hCursor       = pApp->Module()->LoadStdCursor(IDC_ARROW);
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	m_wcClass.lpszMenuName  = NULL;
	m_wcClass.lpszClassName = NULL;

	// Fill in default WNDINIT members.
	m_wiStyle.dwExStyle     = 0;
	m_wiStyle.pszClassName  = NULL;
	m_wiStyle.pszTitle      = NULL;
	m_wiStyle.dwStyle       = 0;
	m_wiStyle.rcPos.Set(CW_USEDEFAULT, 0, 0, 0);
	m_wiStyle.hParent       = NULL;
	m_wiStyle.hMenu         = NULL;
	m_wiStyle.lpCreation    = NULL;
}

/******************************************************************************
** Method:		RegisterClass()
**
** Description:	Registers the "window class" of a CPopupWnd derived window. It
**				checks first to see if the class is registered so that it can
**				be called by any instance of the object.
**
** Parameters:	None.
**
** Returns:		TRUE			On Success.
**				FALSE			On Failure.
**
*******************************************************************************
*/

bool CPopupWnd::RegisterClass(void)
{
	WNDCLASS	wcPrev;
	
	ASSERT(m_wcClass.lpfnWndProc);
	ASSERT(m_wcClass.hInstance);
	ASSERT(m_wcClass.hbrBackground);
	ASSERT(m_wcClass.lpszClassName);

	// Is already registered?
	if (GetClassInfo(m_wcClass.hInstance, m_wcClass.lpszClassName, &wcPrev))
		return TRUE;
	
	// Do it.
	if (::RegisterClass((LPWNDCLASS)&m_wcClass))
		return TRUE;
		
	ASSERT(FALSE);
	
	return FALSE;
}

/******************************************************************************
** Method:		Create()
**
** Description:	Register the window class then create it.
**
** Parameters:	None.
**
** Returns:		TRUE		On Success.
**				FALSE		On Failure.
**
*******************************************************************************
*/

bool CPopupWnd::Create(void)
{
	// Try and register the class.
	if (!RegisterClass())
		return FALSE;

	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	ASSERT(m_hWnd == NULL);
	ASSERT(m_wiStyle.pszClassName);
	
	// Now create it.
	m_hWnd = CreateWindowEx(m_wiStyle.dwExStyle,
							m_wiStyle.pszClassName,
							m_wiStyle.pszTitle,
							m_wiStyle.dwStyle,
							m_wiStyle.rcPos.left,
							m_wiStyle.rcPos.top,
							m_wiStyle.rcPos.Width(),
							m_wiStyle.rcPos.Height(),
							m_wiStyle.hParent,
							m_wiStyle.hMenu,
							pApp->Module()->Handle(),
							m_wiStyle.lpCreation );

	ASSERT(m_hWnd);
	
	// Setup Window/Object mapping.
	Map(m_hWnd, this);
	
	// Change WndProc to our multi purpose one.
	WindowProc(PopupWndProc);

	// Initialise.
	OnCreate();
	
	return TRUE;
}

/******************************************************************************
** Function:	PopupWndProc()
**
** Description:	This is the real CPopupWnd based window message procedure. It
**				works out which object belongs to the window handle and passes
**				the message straight onto that object for processing.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message
**
*******************************************************************************
*/

LRESULT WINDOWPROC PopupWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	CPopupWnd* pWnd;
	
	// Get the window object.
	pWnd = (CPopupWnd*) CWnd::FromHandle(hWnd);
	ASSERT(pWnd);
	
	// Call real message handler.
	pWnd->WndProc(hWnd, iMsg, wParam, lParam);

	return pWnd->m_lMsgResult;
}

/******************************************************************************
** Method:		WndProc()
**
** Description:	This is the base implementation of a CPopupWnd window message
**				handler. It handles all messages common to all popup windows.
**				This is a virtual function and is overriden by derived clases
**				to farm out more specific messages, but should always be called
**				by derived clases to get the default processing.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CPopupWnd::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Decode message.
	switch(iMsg)
	{
        // Left button pressed.
		case WM_LBUTTONDOWN:
			OnLeftButtonDown(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;

        // Left button released.
		case WM_LBUTTONUP:
			OnLeftButtonUp(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;
		
        // Left button double clicked.
		case WM_LBUTTONDBLCLK:
			OnLeftButtonDblClick(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;

        // Right button pressed.
		case WM_RBUTTONDOWN:
			OnRightButtonDown(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;

        // Right button released.
		case WM_RBUTTONUP:
			OnRightButtonUp(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;
		
        // Right button double clicked.
		case WM_RBUTTONDBLCLK:
			OnRightButtonDblClick(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;
		
		// Mouse moved.
		case WM_MOUSEMOVE:
			OnMouseMove(CPoint(LOWORD(lParam), HIWORD(lParam)), wParam);
			break;
		
		// Key pressed.
		case WM_KEYDOWN:
			OnKeyDown((WORD)wParam, lParam);
			break;
		
		// Key released.
		case WM_KEYUP:
			OnKeyUp((WORD)wParam, lParam);
			break;

		// Translated WM_KEYDOWN/UP.
		case WM_CHAR:
			OnChar((WORD)wParam, lParam);
			break;

		// Window being destroyed.
		case WM_DESTROY:
			// Call base class first.
			CMsgWnd::WndProc(hWnd, iMsg, wParam, lParam);
			
			// Set WndProc to defualt.
			WindowProc(m_wcClass.lpfnWndProc);
			
			// Delete object mapping.
			UnMap(hWnd);
			break;
		
		// Call the default handler.
		default:
			return CMsgWnd::WndProc(hWnd, iMsg, wParam, lParam);
	}
	
	m_bMsgHandled = TRUE;
	m_lMsgResult  = 0;

	return 0;
}

/******************************************************************************
** Method:		DefaultWndProc()
**
** Description:	This is the handler for all non-handled messages. It calls
**				DefWindowProc().
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CPopupWnd::DefaultWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	m_bMsgHandled = TRUE;
	m_lMsgResult  = DefWindowProc(hWnd, iMsg, wParam, lParam);

	return 0;
}

/******************************************************************************
** Methods:		OnLeftButtonDown()
**				OnLeftButtonUp()
**				OnLeftButtonDblClick()
**				OnRightButtonDown()
**				OnRightButtonUp()
**				OnRightButtonDblClick()
**				OnMouseMove()
**
** Description:	Mouse state messages. By default all do nothing.
**
** Parameters:	ptCursor	Mouse position.
**				iKeyFlags	State of control keys.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPopupWnd::OnLeftButtonDown(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnLeftButtonUp(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnLeftButtonDblClick(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnRightButtonDown(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnRightButtonUp(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnRightButtonDblClick(const CPoint& ptCursor, uint iKeyFlags)
{
}

void CPopupWnd::OnMouseMove(const CPoint& ptCursor, uint iKeyFlags)
{
}

/******************************************************************************
** Methods:		OnKeyDown()
**				OnKeyUp()
**				OnChar()
**
** Description:	Keyboard state messages. By default all do nothing.
**
** Parameters:	wKey		The keys' vitual keycode.
**				dwFlags		Key state information.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPopupWnd::OnKeyDown(WORD wKey, DWORD dwFlags)
{
}

void CPopupWnd::OnKeyUp(WORD wKey, DWORD dwFlags)
{
}

void CPopupWnd::OnChar(WORD wKey, DWORD dwFlags)
{
}
