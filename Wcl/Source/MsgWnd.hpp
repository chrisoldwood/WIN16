/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MSGWND.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CMsgWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MSGWND_HPP
#define MSGWND_HPP

/******************************************************************************
** 
** This is a Wnd derived class that provides a base class for all message
** based windows. It provides the defualt handlers for all messages common to
** all windows.
**
*******************************************************************************
*/

WCLCLASS CMsgWnd : public CWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CMsgWnd(void);

	//
	// Scroll bar methods.
	//
	int HorzScrollPos(int iPos, bool bRepaint = TRUE);
	int VertScrollPos(int iPos, bool bRepaint = TRUE);
	int HorzScrollPos(void);
	int VertScrollPos(void);
	void HorzScrollRange(int iMin, int iMax, bool bRepaint = TRUE);
	void VertScrollRange(int iMin, int iMax, bool bRepaint = TRUE);
	
	//
	// Control methods.
	//
	void MapCtl(uint iID, CMsgWnd* pWnd);
	void UnMapCtl(uint iID);
	CMsgWnd* CtlFromID(uint iID);

protected:
	/******************************************************************************
	** 
	** An entry in the command message table.
	**
	*******************************************************************************
	*/
	
	typedef void (CMsgWnd::*CmdMsgFn)(void);
	
	typedef struct tagCmdMsg
	{
		uint		iCmdID;
		CmdMsgFn	lpfnCmdFn;
	} CmdMsg;
	
	/******************************************************************************
	** 
	** An entry in the control message table.
	**
	*******************************************************************************
	*/

	typedef void (CMsgWnd::*CtlMsgFn)(void);
	
	typedef struct tagCtlMsg
	{
		uint		iCtlID;
		uint		iCtlMsg;
		CtlMsgFn	lpfnCtlFn;
	} CtlMsg;
	
	//
	// Members.
	//
	bool		m_bMsgHandled;
	LRESULT		m_lMsgResult;
	CmdMsg*		m_pCmdMsgTable;
	CtlMsg*		m_pCtlMsgTable;
	CHashTable	m_CtlTable;
	
	//
	// Member setting.
	//
	void CmdMsgTable(CmdMsg* pCmdMsgTable);
	void CtlMsgTable(CtlMsg* pCtlMsgTable);
	
	//
	// General message handlers.
	//
	virtual	LRESULT WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT DefaultWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) = 0;

	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual void OnActivate(bool bActivating);
	virtual	void OnPaint(CDC& rDC);
	virtual void OnResize(int iFlag, const CSize& NewSize);
	virtual void OnTimer(uint iTimerID);
	virtual	void OnShow(bool bShowing);
	virtual void OnDestroy(void);
	virtual void OnHorizScroll(uint iCode, uint iPos);
	virtual void OnVertScroll(uint iCode, uint iPos);
	virtual void OnCmdMsg(uint iID);
	virtual void OnCtlMsg(uint iID, uint iMsg, HWND hControl);
	virtual void OnDrawItem(uint iID, uint iAction, uint iState, CDC& rDC, const CRect& rcItem);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline int CMsgWnd::HorzScrollPos(int iPos, bool bRepaint)
{
	return ::SetScrollPos(m_hWnd, SB_HORZ, iPos, bRepaint);
}

inline int CMsgWnd::VertScrollPos(int iPos, bool bRepaint)
{
	return ::SetScrollPos(m_hWnd, SB_VERT, iPos, bRepaint);
}

inline int CMsgWnd::HorzScrollPos(void)
{
	return ::GetScrollPos(m_hWnd, SB_HORZ);
}

inline int CMsgWnd::VertScrollPos(void)
{
	return ::GetScrollPos(m_hWnd, SB_VERT);
}

inline void CMsgWnd::HorzScrollRange(int iMin, int iMax, bool bRepaint)
{
	::SetScrollRange(m_hWnd, SB_HORZ, iMin, iMax, bRepaint);
}

inline void CMsgWnd::VertScrollRange(int iMin, int iMax, bool bRepaint)
{
	::SetScrollRange(m_hWnd, SB_VERT, iMin, iMax, bRepaint);
}

inline void CMsgWnd::CmdMsgTable(CmdMsg* pCmdMsgTable)
{
	m_pCmdMsgTable = pCmdMsgTable;
}

inline void CMsgWnd::CtlMsgTable(CtlMsg* pCtlMsgTable)
{
	m_pCtlMsgTable = pCtlMsgTable;
}

inline void CMsgWnd::MapCtl(uint iID, CMsgWnd* pWnd)
{
#ifdef M_I86MM
	m_CtlTable.Add(iID, (DWORD)(WORD)pWnd);
#else
	m_CtlTable.Add(iID, (DWORD)pWnd);
#endif
}

inline void CMsgWnd::UnMapCtl(uint iID)
{
	m_CtlTable.Delete(iID);
}

inline CMsgWnd* CMsgWnd::CtlFromID(uint iID)
{
#ifdef M_I86MM
	return (CMsgWnd*)(WORD) m_CtlTable.Find(iID);
#else
	return (CMsgWnd*) m_CtlTable.Find(iID);
#endif
}

#endif //MSGWND_HPP
