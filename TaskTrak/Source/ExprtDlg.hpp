/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EXPRTDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CExportDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef EXPRTDLG_HPP
#define EXPRTDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user exports data to a file.
**
*******************************************************************************
*/

APPCLASS CExportDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CExportDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CPath		m_strFileName;
	Grouping	m_eGrouping;
	CDate		m_FromDate;
	CDate		m_ToDate;

protected:
	//
	// Members.
	//
	CEditBox		m_ebFileName;
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
	void OnBrowse(void);
	void OnPeriodChange(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //EXPRTDLG_HPP
