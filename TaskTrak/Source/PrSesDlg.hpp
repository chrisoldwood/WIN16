/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRSESDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CPruneSessionsDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRSESDLG_HPP
#define PRSESDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user prunes sessions.
**
*******************************************************************************
*/

APPCLASS CPruneSessionsDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CPruneSessionsDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CDate		m_Date;

protected:
	//
	// Members.
	//
	CRadioBtn		m_rbAll;
	CRadioBtn		m_rbBefore;
	CDateEditBox	m_ebDate;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnAll(void);
	void OnBefore(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //PRSESDLG_HPP
