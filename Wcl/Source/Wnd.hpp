/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WND.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef WND_HPP
#define WND_HPP

/******************************************************************************
** 
** This is the base class from which all window classes are derived. It
** encapsulates the window handles and provides all the standard methods that
** work on an HWND. It also provides static functions that map objects and
** HWNDs to each other.
**
*******************************************************************************
*/

WCLCLASS CWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CWnd(void);
	CWnd(HWND hWnd);
	virtual ~CWnd(void);

    //
    // Member access.
    //
    HWND Handle(void) const;
    void Handle(HWND hWnd);
	operator HWND();

    //
    // State.
    //
    bool Close(void);
    bool Destroy(void);
    bool Show(int iStyle = SW_SHOW);
	void Hide(void);
    bool IsVisible(void) const;
    void Enable(bool bEnable = TRUE);
    void Disable(bool bDisable = TRUE);
    bool IsEnabled(void);
	void Centre(void);
	void Title(const char* lpszTitle);
	CString Title(void) const;

	//
	// Dimensions.
	//
	void Move(const CRect& rNewPos, bool bRepaint = TRUE);
	CRect WindowRect(void) const;
	virtual	CRect ClientRect(void) const;

    //
    // Window data.
    //
    WNDPROC	WindowProc(WNDPROC lpfnWndProc);
    
    //
    // Message handling.
    //
    LRESULT	SendMessage(UINT iMsg, WPARAM wParam = 0, LPARAM lParam = 0L) const;
    bool PostMessage(UINT iMsg, WPARAM wParam = 0, LPARAM lParam = 0L) const;
    bool PostCommand(uint iCmd) const;
    void RePaint(const CRect& rArea, bool bErase = TRUE);
    void RePaintAll(bool bErase = TRUE);
	uint StartTimer(uint iTimerID, uint iTimeout);
	void StopTimer(uint iTimerID);
	virtual bool FilterMessage(MSG* pMsg);
    
    //
    // Message boxes.
    //
	void Alert(const char* pszMsg, ...) const;
	int  Query(const char* pszMsg, ...) const;
	int  QueryEx(const char* pszMsg, ...) const;
	void Notify(const char* pszMsg, ...) const;
    
	//
	// These are used to manage the mappings between a CWnd object and its 
	// handle.
	//
	static void Map(HWND hWnd, CWnd* pWindow);
	static void UnMap(HWND hWnd);
	static CWnd* FromHandle(HWND hWnd);

protected:
	//
	// Members.
	//
	HWND	m_hWnd;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CWnd::CWnd(void)
{
	m_hWnd = NULL;
}

inline CWnd::CWnd(HWND hWnd)
{
	ASSERT(hWnd);
	
	m_hWnd = hWnd;
}

inline CWnd::~CWnd(void)
{
}

inline HWND CWnd::Handle() const
{
	return m_hWnd;
}

inline void CWnd::Handle(HWND hWnd)
{
	ASSERT(hWnd);
	
	m_hWnd = hWnd;
}

inline CWnd::operator HWND()
{
	ASSERT(m_hWnd);

	return m_hWnd;
}

inline bool CWnd::Close(void)
{
	return PostMessage(WM_CLOSE);
}

inline bool CWnd::Destroy(void)
{
	return ::DestroyWindow(m_hWnd);
}

inline bool CWnd::Show(int iStyle)
{
	return ::ShowWindow(m_hWnd, iStyle);
}

inline void CWnd::Hide(void)
{
	::ShowWindow(m_hWnd, SW_HIDE);
}

inline bool CWnd::IsVisible(void) const
{
	return ::IsWindowVisible(m_hWnd);
}

inline void CWnd::Enable(bool bEnable)
{
	::EnableWindow(m_hWnd, bEnable);
}

inline void CWnd::Disable(bool bDisable)
{
	::EnableWindow(m_hWnd, !bDisable);
}

inline bool CWnd::IsEnabled(void)
{
	return ::IsWindowEnabled(m_hWnd);
}

inline void CWnd::Title(const char* pszTitle)
{
	ASSERT(pszTitle);

	::SetWindowText(m_hWnd, pszTitle);
}

inline void CWnd::Move(const CRect& rNewPos, bool bRepaint)
{
	::MoveWindow(m_hWnd, rNewPos.left, rNewPos.top, rNewPos.Width(), rNewPos.Height(), bRepaint);
}

inline WNDPROC CWnd::WindowProc(WNDPROC lpfnWndProc)
{
	return (WNDPROC) ::SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)lpfnWndProc);
}

inline LRESULT CWnd::SendMessage(UINT iMsg, WPARAM wParam, LPARAM lParam) const
{
	return ::SendMessage(m_hWnd, iMsg, wParam, lParam);
}

inline bool CWnd::PostMessage(UINT iMsg, WPARAM wParam, LPARAM lParam) const
{
	return ::PostMessage(m_hWnd, iMsg, wParam, lParam);
}

inline bool CWnd::PostCommand(uint iCmd) const
{
	return ::PostMessage(m_hWnd, WM_COMMAND, iCmd, 0L);
}

inline void CWnd::RePaint(const CRect& rArea, bool bErase)
{
	::InvalidateRect(m_hWnd, (LPRECT)&rArea, bErase);
	::UpdateWindow(m_hWnd);
}

inline void CWnd::RePaintAll(bool bErase)
{
	::InvalidateRect(m_hWnd, NULL, bErase);
	::UpdateWindow(m_hWnd);
}

inline uint CWnd::StartTimer(uint iTimerID, uint iTimeout)
{
	return ::SetTimer(m_hWnd, iTimerID, iTimeout, NULL);
}

inline void CWnd::StopTimer(uint iTimerID)
{
	::KillTimer(m_hWnd, iTimerID);
}

#endif //WND_HPP
