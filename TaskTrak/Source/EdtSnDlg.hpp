/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EDTSNDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CEditSessionDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef EDTSNDLG_HPP
#define EDTSNDLG_HPP

/******************************************************************************
** 
** This dialog is used to add, modify and delete sessions.
**
*******************************************************************************
*/

APPCLASS CEditSessionDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CEditSessionDlg(CWnd* pParent);
	
	//
	// Members.
	//

protected:
	//
	// Members.
	//
	CSessionListBox	m_lbSessions;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);

	//
	// Control message processors.
	//
	void OnAdd(void);
	void OnModify(void);
	void OnDelete(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //EDTSNDLG_HPP
