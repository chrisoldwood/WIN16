/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SWTSKDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CSwitchTasksDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SWTSKDLG_HPP
#define SWTSKDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user switches tasks.
**
*******************************************************************************
*/

APPCLASS CSwitchTasksDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CSwitchTasksDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CString		m_strPrevTask;
	CString		m_strNextTask;

protected:
	//
	// Members.
	//
	CTaskCombo	m_cbPrevTask;
	CTaskCombo	m_cbNextTask;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //SWTSKDLG_HPP
