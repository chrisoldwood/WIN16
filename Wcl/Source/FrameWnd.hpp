/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FRAMEWND.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CFrameWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef FRAMEWND_HPP
#define FRAMEWND_HPP

/******************************************************************************
** 
** This is the base class for the main application window. It contains the menu
** and caption etc. It can also support a DIL and toolbar. This is where all
** the basic command processing is done.
**
*******************************************************************************
*/

WCLCLASS CFrameWnd : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CFrameWnd(void);
	virtual	~CFrameWnd(void);

	//
	// Member access.
	//
	CToolBar* ToolBar(void) const;
	CStatusBar* StatusBar(void) const;

	//
	// Member setting.
	//
	void ToolBar(CToolBar* pToolBar);
	void StatusBar(CStatusBar* pStatusBar);
	void ActiveDlg(CDialog* pDialog);

	//
	// Attributes.
	//
	virtual	CRect ClientRect(void) const;

	//
	// Command handling.
	//
	void EnableCmd(uint iCmdID, bool bEnable = TRUE);
	void DisableCmd(uint iCmdID, bool bDisable = TRUE);

	//
	// Message handling.
	//
	bool ProcessMsg(MSG* pMsg);

protected:
	//
	// Members.
	//
	CAccel		m_Accel;		// Accelerator table.
	CMenu		m_Menu;			// Main menu.
	CToolBar*	m_pToolBar;		// Toolbar, if one.
	CStatusBar*	m_pStatusBar;	// Status Bar, if one.
	CDialog*	m_pActiveDlg;	// The active modeless dialog, if one.
	
	//
	// Message processors (Overriden from the base class).
	//
	virtual	LRESULT	WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual void OnResize(int iFlag, const CSize& rNewSize);
	virtual void OnDestroy(void);

	//
	// Message processors (Specific to this class).
	//
	virtual bool OnQueryClose(void);
	virtual bool OnRealizePalette(CDC& rDC);
			void OnSelectMenu(uint iFlags, uint iItemID, HMENU hMenu);
	virtual void OnShowMenuItemHint(uint iItemID);
	virtual void OnShowMenuPopupHint(HMENU hMenu);
	virtual void OnActivateApp(bool bActivating);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CToolBar* CFrameWnd::ToolBar(void) const
{
	return m_pToolBar;
}

inline CStatusBar* CFrameWnd::StatusBar(void) const
{
	return m_pStatusBar;
}

inline void CFrameWnd::ToolBar(CToolBar* pToolBar)
{
	m_pToolBar = pToolBar;
}

inline void CFrameWnd::StatusBar(CStatusBar* pStatusBar)
{
	m_pStatusBar = pStatusBar;
}

inline void CFrameWnd::ActiveDlg(CDialog* pDialog)
{
	m_pActiveDlg = pDialog;
}

#endif //FRAMEWND_HPP
