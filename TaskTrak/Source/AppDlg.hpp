/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAppDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPDLG_HPP
#define APPDLG_HPP

/******************************************************************************
** 
** This dialog is the dialog that occupies the frame window.
**
*******************************************************************************
*/

APPCLASS CAppDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CAppDlg(CWnd* pParent);
	
	//
	// Methods.
	//
	void Update(void);

protected:
	//
	// Members.
	//
	CDateTime	m_dtCurrent;
	CLabel		m_txtCurrDate;
	CLabel		m_txtCurrTime;
	CLabel		m_txtSessionDate;
	CLabel		m_txtSessionTime;
	CLabel		m_txtSessionLen;
	CLabel		m_txtSessionTask;
	CLabel		m_txtTotalToday;
	CLabel		m_txtTotalWeek;
	CLabel		m_txtTotalMonth;
	CLabel		m_txtTotalTotal;
		
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual void OnDestroy(void);
	virtual void OnTimer(uint iTimerID);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //APPDLG_HPP
