/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ADDTPDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAddTopicDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef ADDTPDLG_HPP
#define ADDTPDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user adds a new topic.
**
*******************************************************************************
*/

APPCLASS CAddTopicDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CAddTopicDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CString	m_strName;
	CString	m_strContextName;
	CString	m_strKeywords;

protected:
	//
	// Members.
	//
	CEditBox	m_ebName;
	CEditBox	m_ebContextName;
	CEditBox	m_ebKeywords;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnChangeName(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //ADDTPDLG_HPP
