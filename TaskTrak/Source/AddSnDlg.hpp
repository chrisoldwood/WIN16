/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ADDSNDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAddSessionDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef ADDSNDLG_HPP
#define ADDSNDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user adds a new session.
**
*******************************************************************************
*/

APPCLASS CAddSessionDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CAddSessionDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CDate		m_InDate;
	CTime		m_InTime;
	CDate		m_OutDate;
	CTime		m_OutTime;
	CString		m_strTask;

protected:
	//
	// Members.
	//
	CDateEditBox	m_ebInDate;
	CTimeEditBox	m_ebInTime;
	CDateEditBox	m_ebOutDate;
	CTimeEditBox	m_ebOutTime;
	CTaskCombo		m_cbTask;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnEditInDate(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //ADDSNDLG_HPP
