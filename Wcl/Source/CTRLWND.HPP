/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CTRLWND.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CCtrlWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef CTRLWND_HPP
#define CTRLWND_HPP

/******************************************************************************
** 
** This is the base class for all window child controls.
**
*******************************************************************************
*/

WCLCLASS CCtrlWnd : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CCtrlWnd(void);
	~CCtrlWnd(void);

	virtual bool Create(CMsgWnd* pParent, uint iID, const CRect& rcPos);
	void Attach(uint iID, HWND hWnd, CMsgWnd* pParent);
	static bool Register(const char* pszClassName);

	//
	// Member access.
	//
	uint ID(void) const;
	
protected:
	//
	// Members.
	//
	uint		m_iID;
	CMsgWnd*	m_pParent;
	WNDPROC		m_pOldWndProc;
	
	//
	// Internal methods.
	//
	void SubClass(void);
	void UnSubClass(void);

	//
	// Message handlers.
	//
	friend LRESULT WINDOWPROC SubWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual	LRESULT SubWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline uint CCtrlWnd::ID(void) const
{
	return m_iID;
}

#endif //CTRLWND_HPP
