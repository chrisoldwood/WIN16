/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOOLBAR.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CToolBar class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOOLBAR_HPP
#define TOOLBAR_HPP

// A space between buttons.
#define ID_SPACE	(uint)-1

/******************************************************************************
** 
** This is a child window that acts as a placeholder for buttons that sits
** along the top of the main window.
**
*******************************************************************************
*/

WCLCLASS CToolBar : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CToolBar(const CWnd& rParent);
	~CToolBar(void);

	//
	// Command methods.
	//		
	bool Cmds(uint* pCmdTable);

	void EnableCmd(uint iCmdID, bool bEnable = TRUE);
	void DisableCmd(uint iCmdID, bool bDisable = TRUE);

	//
	// Message handling.
	//		
	virtual bool FilterMessage(MSG* pMsg);

protected:
	/******************************************************************************
	** 
	** A button on the toolbar.
	**
	*******************************************************************************
	*/

	typedef struct tagCmdBtn
	{
		uint		iCmdID;
		CBmpButton*	pButton;
	} CmdBtn;

	//
	// Members.
	//
	CSize		m_Size;
	uint		m_iNumCmds;
    CmdBtn*		m_pBtnTable;
    CBitmap		m_BmpEnabled;
    CBitmap		m_BmpDisabled;

	//
	// Internal methods.
	//
	void CreateBitmaps(void);
	void ShowHint(const CWnd* pWnd) const;
	
	//
	// Message processors.
	//
	virtual void OnPaint(CDC& rDC);
	virtual void OnResize(int iFlag, const CSize& rNewSize);
	virtual void OnCtlMsg(uint iID, uint iMsg, HWND hControl);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CToolBar::DisableCmd(uint iCmdID, bool bDisable)
{
	EnableCmd(iCmdID, !bDisable);
}

#endif //TOOLBAR_HPP
