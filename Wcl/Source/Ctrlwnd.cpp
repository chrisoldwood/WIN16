/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CTRLWND.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CCtrlWnd class methods.
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

CCtrlWnd::CCtrlWnd(void)
{
	// Fill in default WNDINIT members.
	m_wiStyle.dwStyle = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;

	// Initialise members.	
	m_iID     = 0;
	m_pParent = NULL;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Cleanup resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CCtrlWnd::~CCtrlWnd(void)
{
	ASSERT(m_iID);

	// Delete object mapping.
	UnMap(m_hWnd);

	// Remove from parent control table.
	m_pParent->UnMapCtl(m_iID);
}

/******************************************************************************
** Method:		Create()
**
** Description:	Create the control window.
**
** Parameters:	pParent		The parent window.
**				iID			The control ID.
**				rcPos		The window position.
**
** Returns:		TRUE		On Success.
**				FALSE		On Failure.
**
*******************************************************************************
*/

bool CCtrlWnd::Create(CMsgWnd* pParent, uint iID, const CRect& rcPos)
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	ASSERT(pParent);
	ASSERT(m_hWnd == NULL);
	ASSERT(m_wiStyle.pszClassName);
	
	// Now create it.
	m_hWnd = CreateWindowEx(m_wiStyle.dwExStyle,
							m_wiStyle.pszClassName,
							m_wiStyle.pszTitle,
							m_wiStyle.dwStyle,
							rcPos.left,
							rcPos.top,
							rcPos.Width(),
							rcPos.Height(),
							pParent->Handle(),
							(HMENU)iID,
							pApp->Module()->Handle(),
							m_wiStyle.lpCreation);

	ASSERT(m_hWnd);

	// Save members.
	m_iID     = iID;
	m_pParent = pParent;

	// Setup Window/Object mapping.
	Map(m_hWnd, this);

	// Add to parent control table.
	pParent->MapCtl(iID, this);

	// Initialise.
	OnCreate();

	return TRUE;
}

/******************************************************************************
** Method:		Attach()
**
** Description:	Attach the object to the given control.
**
** Parameters:	iID			The control ID.
**				hWnd		The control window handle.
**				pParent		The parent window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CCtrlWnd::Attach(uint iID, HWND hWnd, CMsgWnd* pParent)
{
	// Initialise members.
	m_iID     = iID;
	m_hWnd    = hWnd;
	m_pParent = pParent;

	// Setup Window/Object mapping.
	Map(m_hWnd, this);
	
	// Add to parent control table.
	pParent->MapCtl(m_iID, this);

	// Initialise.
	OnCreate();
}

/******************************************************************************
** Function:	SubWndProc()
**
** Description:	This is a controls' replacemnt WndProc for a sublassed control.
**				It calls the SubWndProc virtual function to do any real work.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message
**
*******************************************************************************
*/

LRESULT WINDOWPROC SubWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	CCtrlWnd* pWnd;
	
	// Get the window object.
	pWnd = (CCtrlWnd*) CWnd::FromHandle(hWnd);
	ASSERT(pWnd);
	
	// Call the virtual message handler.
	return pWnd->SubWndProc(hWnd, iMsg, wParam, lParam);
}

/******************************************************************************
** Method:		SubWndProc()
**
** Description:	This is the base implementation of sublassed controls' window
**				proc. By defualt it does nothing but call the real handler.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CCtrlWnd::SubWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Decode message.
	switch(iMsg)
	{
		// Window being destroyed.
		case WM_DESTROY:
			// Unsubclass the window.
			UnSubClass();
			break;

		// Call the default handler.
		default:
			break;
	}

	// Call the controls' real handler.
	return ::CallWindowProc(m_pOldWndProc, hWnd, iMsg, wParam, lParam);
}

/******************************************************************************
** Method:		SubClass()
**
** Description:	Subclass the control by replacing its window procedure with a
**				new one.
**				
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CCtrlWnd::SubClass(void)
{
	// Setup Window/Object mapping.
	Map(m_hWnd, this);

	m_pOldWndProc = WindowProc(::SubWndProc);
}

/******************************************************************************
** Method:		UnSubClass()
**
** Description:	Unsubclass the control by replacing the window proc with its
**				original one.
**				
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CCtrlWnd::UnSubClass(void)
{
	// Delete object mapping.
	UnMap(m_hWnd);

	WindowProc(m_pOldWndProc);
}

/******************************************************************************
** Method:		Register()
**
** Description:	Register a dummy class to be used for custom controls.
**				
** Parameters:	pszClassName	The name of the class to register.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CCtrlWnd::Register(const char* pszClassName)
{
	WNDCLASS	wcClass;
	
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Fill in class structure.
	wcClass.style         = CS_HREDRAW | CS_VREDRAW;
	wcClass.lpfnWndProc   = DefWindowProc;
	wcClass.cbClsExtra    = 0;
	wcClass.cbWndExtra    = 0;
	wcClass.hInstance     = pApp->Module()->Handle();
	wcClass.hIcon         = NULL;
	wcClass.hCursor       = pApp->Module()->LoadStdCursor(IDC_ARROW);
	wcClass.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wcClass.lpszMenuName  = NULL;
	wcClass.lpszClassName = pszClassName;
	
	// Register.
	return ::RegisterClass(&wcClass);
}
