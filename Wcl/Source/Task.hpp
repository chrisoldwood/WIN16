/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TASK.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CTask class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TASK_HPP
#define TASK_HPP

/******************************************************************************
** 
** This class is the base class for all Window based threads.
**
*******************************************************************************
*/

WCLCLASS CTask
{
public:
	//
	// Constructors/Destructor.
	//
	CTask(void);
	~CTask(void);

	//
	// Member access.
	//
	void Module(CModule* pModule);
	CModule* Module(void) const;
	void CmdLine(LPCSTR lpszCmdLine);
	void CmdShow(int iCmdShow);
	const CString& Title(void) const;
	CFrameWnd* FrameWnd(void) const;

	//
	// Initialisation and termination.
	//
	virtual	bool Initialise(void);
	virtual	bool Terminate(void);

    //
    // Message boxes.
    // For use when no window is available.
    //
	void Alert(const char* pszMsg, ...) const;
	int  Query(const char* pszMsg, ...) const;
	int  QueryEx(const char* pszMsg, ...) const;
	void Notify(const char* pszMsg, ...) const;

	//
	// Message handling.
	//
	int MessageLoop(void) const;
	void AddMsgFilter(CWnd* pWnd);
	void DelMsgFilter(CWnd* pWnd);
	
	//
	// Others.
	//
	void Busy(bool bBusy);
	void Yield(void) const;

	//
	// Access to the app object.
	//
	static CTask* This(void);

protected:
	//
	// Members.
	//
	CModule*	m_pModule;
	CString		m_strTitle;
	LPCSTR		m_lpszCmdLine;
	int			m_iCmdShow;
	CFrameWnd*	m_pAppWnd;
#ifdef WIN16
	CCtl3d		m_Ctl3d;
#endif
	CList		m_MsgFilters;

private:
	//
	// Not needed by the derived class.
	//
	int		m_iBusyCount;
	HCURSOR	m_hOldCursor;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CTask::Module(CModule* pModule)
{
	m_pModule = pModule;
}

inline CModule* CTask::Module(void) const
{
	return m_pModule;
}

inline void CTask::CmdLine(LPCSTR lpszCmdLine)
{
	m_lpszCmdLine = lpszCmdLine;
}

inline void CTask::CmdShow(int iCmdShow)
{
	m_iCmdShow = iCmdShow;
}

inline const CString& CTask::Title(void) const
{
	return m_strTitle;
}

inline CFrameWnd* CTask::FrameWnd(void) const
{
	return m_pAppWnd;
}

#endif //TASK_HPP
