/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CLKOTDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CClockOutDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef CLKOTDLG_HPP
#define CLKOTDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user clocks out.
**
*******************************************************************************
*/

APPCLASS CClockOutDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CClockOutDlg(CWnd* pParent);
	
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

#endif //CLKOTDLG_HPP
