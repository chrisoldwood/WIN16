/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		POPUPWND.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CPopupWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef POPUPWND_HPP
#define POPUPWND_HPP

/******************************************************************************
** 
** This structure is a copy of the standard WNDCLASS structure. It is
** duplicated so that it can be marked as EXPORT when building the library as
** a DLL.
**
*******************************************************************************
*/

typedef WCLSTRUCT tagWndReg
{
    uint		style;				// Styles flags.
    WNDPROC		lpfnWndProc;		// Window callback procedure.
    int			cbClsExtra;			// Amount of extra class data.
    int			cbWndExtra;			// Amount of extra window data.
    HINSTANCE	hInstance;			// Classes owner.
    HICON		hIcon;				// Default icon.
    HCURSOR		hCursor;			// Default cursor.
    HBRUSH		hbrBackground;		// Background brush.
    LPCSTR		lpszMenuName;		// Menu resource name.
    LPCSTR		lpszClassName;		// Class name.
} WNDREG;

/******************************************************************************
** 
** This structure contains all the information used to create a window using
** CreateWindowEx().
**
*******************************************************************************
*/

typedef WCLSTRUCT tagWndInit
{
	DWORD		dwExStyle;			// Extended style flags.
	const char*	pszClassName;		// Class name.
	const char*	pszTitle;			// Title.
	DWORD		dwStyle;			// Normal style flags.
	CRect		rcPos;				// Initial position.
	HWND		hParent;			// Parent window.
	HMENU		hMenu;				// Menu handle or child ID.
	void FAR*	lpCreation;			// Window creation params or NULL.
} WNDINIT;

/******************************************************************************
** 
** This is a CMsgWnd derived class that provides defualt handlers for all
** messages common to overlapped and child windows. It is used for all
** non-dialog based windows.
**
*******************************************************************************
*/

WCLCLASS CPopupWnd : public CMsgWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CPopupWnd(void);
	virtual bool Create(void);

protected:
	//
	// Members.
	//
	CString		m_strClassName;			// Class name.
	CString		m_strTitle;				// Initial title.
	WNDREG		m_wcClass;				// Window "class".
	WNDINIT		m_wiStyle;				// Inital style.
	
	//
	// Setup.
	//
	virtual bool RegisterClass(void);

	//
	// General message handlers.
	//
	friend LRESULT WINDOWPROC PopupWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual	LRESULT WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT DefaultWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

	//
	// Message processors.
	//
	virtual void OnLeftButtonDown(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnLeftButtonUp(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnLeftButtonDblClick(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnRightButtonDown(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnRightButtonUp(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnRightButtonDblClick(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnMouseMove(const CPoint& ptCursor, uint iKeyFlags);
	virtual void OnKeyDown(WORD wKey, DWORD dwFlags);
	virtual void OnKeyUp(WORD wKey, DWORD dwFlags);
	virtual void OnChar(WORD wKey, DWORD dwFlags);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //POPUPWND_HPP
