/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CLKINDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CClockInDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef CLKINDLG_HPP
#define CLKINDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user clocks in.
**
*******************************************************************************
*/

APPCLASS CClockInDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CClockInDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CDate		m_Date;
	CTime		m_Time;
	CString		m_strTask;

protected:
	//
	// Members.
	//
	CRadioBtn		m_rbNow;
	CRadioBtn		m_rbOnAt;
	CDateEditBox	m_ebDate;
	CTimeEditBox	m_ebTime;
	CTaskCombo		m_cbTask;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnNow(void);
	void OnOnAt(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //CLKINDLG_HPP
