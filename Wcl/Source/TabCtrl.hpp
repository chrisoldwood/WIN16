/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TABCTRL.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CTabCtrl class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TABCTRL_HPP
#define TABCTRL_HPP

/******************************************************************************
** 
** This structure is used to define the tab pages which the control will use.
**
*******************************************************************************
*/

typedef struct tagTabCtrlPage
{
	CTabPage*	pPage;			// Pointer to the dialog.
	const char*	pszTitle;		// Page title.
} TabCtrlPage;

/******************************************************************************
** 
** This class is used to create a tab control.
**
*******************************************************************************
*/

WCLCLASS CTabCtrl : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CTabCtrl(void);
	~CTabCtrl(void);

	static bool Register(void);
	void Pages(TabCtrlPage* pPageTable);
	
protected:
	/******************************************************************************
	** 
	** A tab page in the page table.
	**
	*******************************************************************************
	*/
	
	typedef struct tagTabPage
	{
		CTabPage*	pPage;			// Pointer to the dialog.
		CString		strTitle;		// Page title.
		int			iTitleWidth;	// Width of title.
	} TabPage;

	//
	// Members.
	//
	CRect		m_rcArea;			// Control dimensions.
	TabPage*	m_pPageTable;		// Table of pages.
	int			m_iNumPages;		// Number of pages.
	int			m_iTitleHeight;		// Page title height.
	int			m_iTabHeight;		// Height of tab.
	int			m_iActivePage;		// Page currently being shown.
	HFONT		m_hTabFont;			// Font used for tabs.

	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual void OnPaint(CDC& rDC);
	virtual void OnLeftButtonUp(const CPoint& ptCursor, uint iKeyFlags);

	//
	// Internal methods.
	//
	CRect TabPos(int iTabNum) const;
	void DrawTab(CDC& rDC, int iTabNum, bool bActive) const;
	void ActivatePage(int iPageNum);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //TABCTRL_HPP
