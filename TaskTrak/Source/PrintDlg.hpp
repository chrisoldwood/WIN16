/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRINTDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CPrintDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRINTDLG_HPP
#define PRINTDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user prints.
**
*******************************************************************************
*/

APPCLASS CPrintDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CPrintDlg(CWnd* pParent);
	
	//
	// Members.
	//
	Grouping	m_eGrouping;
	CDate		m_FromDate;
	CDate		m_ToDate;

protected:
	//
	// Members.
	//
	CLabel			m_txtPrinter;
	CLabel			m_txtPort;
	CComboBox		m_cbGrouping;
	CComboBox		m_cbPeriod;
	CDateEditBox	m_ebFromDate;
	CDateEditBox	m_ebToDate;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnSelect(void);
	void OnPeriodChange(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //PRINTDLG_HPP
