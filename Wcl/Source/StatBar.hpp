/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		STATBAR.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CStatusBar class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef STATBAR_HPP
#define STATBAR_HPP

/******************************************************************************
** 
** This is a child window that acts as a placeholder for other child windows
** that display information about the application. By defualt it knows about a
** hint window and a progress bar.
**
*******************************************************************************
*/

WCLCLASS CStatusBar : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CStatusBar(const CWnd& rParent);
	~CStatusBar(void);
	bool Create(void);

	//
	// Access to child windows.
	//
	CHintBar* HintBar(void);
//	CProgBar* ProgBar(void);

protected:
	//
	// Members.
	//
	CSize		m_Size;
	CWnd*		m_pActive;
	CHintBar*	m_pHintBar;
//	CProgBar*	m_pProgBar;

	//
	// Internal methods.
	//
	void ActivateWnd(CWnd* pWnd);
	
	//
	// Message processors.
	//
	virtual void OnPaint(CDC& rDC);
	virtual void OnResize(int iFlag, const CSize& rNewSize);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CHintBar* CStatusBar::HintBar(void)
{
	ActivateWnd(m_pHintBar);
	return m_pHintBar;
}

#endif //STATBAR_HPP
