/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WND.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CWnd class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <stdio.h>
#include <stdarg.h>
#include "hashtble.hpp"

// MessageBox() message buffer.
static char	szMsg[256];

/******************************************************************************
**
** Local variables.
**
*******************************************************************************
*/

// Window objects hash table.
CHashTable WndTable(1);

/******************************************************************************
** Method:		Map()
**
** Description:	Sets up a mapping between a window handle and the objects'
**				pointer.
**
** Parameters:	hWnd		The objects' window handle.
**				pWindow		A pointer to the object.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CWnd::Map(HWND hWnd, CWnd* pWindow)
{
#ifdef M_I86MM
	WndTable.Add((DWORD)(LPVOID)hWnd, (DWORD)(WORD)pWindow);
#else
	WndTable.Add((DWORD)(LPVOID)hWnd, (DWORD)pWindow);
#endif
}

/******************************************************************************
** Method:		UnMap()
**
** Description:	Removes the mapping between a window handle and the objects'
**				pointer.
**
** Parameters:	hWnd	The handle of the objects' window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CWnd::UnMap(HWND hWnd)
{
	WndTable.Delete((DWORD)(LPVOID)hWnd);
}

/******************************************************************************
** Method:		FromHandle()
**
** Description:	Get a pointer to the window object that owns the specified
**				window handle.
**
** Parameters:	hWnd	The handle of the objects' window
**
** Returns:		A pointer to the object.
**
*******************************************************************************
*/

CWnd* CWnd::FromHandle(HWND hWnd)
{

#ifdef M_I86MM
	return (CWnd*)(WORD) WndTable.Find((DWORD)(LPVOID)hWnd);
#else
	return (CWnd*) WndTable.Find((DWORD)(LPVOID)hWnd);
#endif
}

/******************************************************************************
** Method:		WindowRect()
**
** Description:	Get the rect describing the window border.
**
** Parameters:	None.
**
** Returns:		The rect.
**
*******************************************************************************
*/

CRect CWnd::WindowRect(void) const
{
	CRect rcWnd;

	::GetWindowRect(m_hWnd, &rcWnd);

	return rcWnd;
}

/******************************************************************************
** Method:		ClientRect()
**
** Description:	Get the position of the client area of the window, for child
**				windows the top-left corner will always be 0,0. This is
**				virtual and should be overriden by frame windows to account for
**				toolbars etc.
**
** Parameters:	None.
**
** Returns:		The rect.
**
*******************************************************************************
*/

CRect CWnd::ClientRect(void) const
{
	CRect rcClient;

	::GetClientRect(m_hWnd, (LPRECT) &rcClient);

	return rcClient;
}

/******************************************************************************
** Method:		Centre()
**
** Description:	Centre the window on its parent.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CWnd::Centre(void)
{
	HWND	hParent;
	CRect	rcThis;
	CSize	dmThis;
	CRect	rcParent;
	CPoint	ptOrigin;

	// Get parent, use desktop, if none.
	hParent = GetParent(m_hWnd);
	if (!hParent)
		hParent = GetDesktopWindow();
		
	// Get the window dimensions.
	::GetWindowRect(hParent, (LPRECT)&rcParent);
	rcThis = WindowRect();
	dmThis = rcThis.Size();
	
	// Calculate new origin.
	ptOrigin.x = ((rcParent.Width()  - dmThis.cx) / 2 ) + rcParent.left;
	ptOrigin.y = ((rcParent.Height() - dmThis.cy) / 2 ) + rcParent.top;
	
	// Move it
	Move(CRect(ptOrigin, dmThis));
}

/******************************************************************************
** Methods:		Alert()
**				Notify()
**				Query()
**				QueryEx()
**
** Description:	Displays a message box linked to the window.
**				QueryEx() is used for Yes/No/Cancel style message boxes.
**
** Parameters:	pszMsg			The message format.
**				...				Variable number of arguments.
**
** Returns:		Result from MessageBox() if appropriate.
**
*******************************************************************************
*/

void CWnd::Alert(const char* pszMsg, ...) const
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	MessageBox(m_hWnd, (LPCSTR)szMsg, pApp->Title(), MB_OK | MB_ICONSTOP);
}

void CWnd::Notify(const char* pszMsg, ...) const
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	MessageBox(m_hWnd, (LPCSTR)szMsg, pApp->Title(), MB_OK | MB_ICONINFORMATION);
}

int CWnd::Query(const char* pszMsg, ...) const
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	return MessageBox(m_hWnd, (LPCSTR)szMsg, pApp->Title(), MB_YESNO | MB_ICONQUESTION);
}

int CWnd::QueryEx(const char* pszMsg, ...) const
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	return MessageBox(m_hWnd, (LPCSTR)szMsg, pApp->Title(), MB_YESNOCANCEL | MB_ICONQUESTION);
}

/******************************************************************************
** Method:		FilterMessage()
**
** Description:	Callback to process a message before it is translated and
**				dispatched by the main message loop.
**
** Parameters:	pMsg	The message.
**
** Returns:		TRUE	if processed.
**				FALSE	if not.
**
*******************************************************************************
*/

bool CWnd::FilterMessage(MSG* pMsg)
{
	return FALSE;
}

/******************************************************************************
** Methods:		Title()
**
** Description:	Get the title of the window as a string.
**
** Parameters:	None.
**
** Returns:		The string.
**
*******************************************************************************
*/

CString CWnd::Title(void) const
{
	CString	strText;
	int		iLen;

	// Get string length.
	iLen = 	(int)SendMessage(WM_GETTEXTLENGTH, 0, 0L);

	// Allocate space.
	strText.BufferSize(iLen);

	// Fetch string.
	SendMessage(WM_GETTEXT, iLen+1, (LPARAM)(LPCSTR) strText);

	return strText;
}
