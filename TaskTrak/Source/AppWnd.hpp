/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPWND.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAppWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPWND_HPP
#define APPWND_HPP

/******************************************************************************
**
** This is the the applications' real main window.
**
*******************************************************************************
*/

APPCLASS CAppWnd : public CDlgFrame
{
public:
	//
	// Constructors/Destructor.
	//
	CAppWnd(void);
	~CAppWnd(void);

	//
	// Methods.
	//
	void UpdateCmds(void);

	//
	// Member access.
	//
	CAppDlg* AppDlg(void);

protected:
	//
	// Members.
	//

	//
	// Message processors.
	//
	virtual bool OnQueryClose(void);

	void OnExport(void);
	void OnPrint(void);
	void OnPrintSetup(void);
	void OnExit(void);

	void OnClockIn(void);
	void OnSwitchTasks(void);
	void OnClockOut(void);
	void OnEditSessions(void);

	void OnPruneSessions(void);
	void OnPruneTasks(void);

	void OnContents(void);
	void OnAbout(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CAppDlg* CAppWnd::AppDlg(void)
{
	return (CAppDlg*) m_pAppDlg;
}

#endif //APPWND_HPP
