/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRTSKDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CPruneTasksDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRTSKDLG_HPP
#define PRTSKDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user prunes tasks.
**
*******************************************************************************
*/

APPCLASS CPruneTasksDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CPruneTasksDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CTaskList	m_TaskList;

protected:
	//
	// Members.
	//
	CListBox	m_lbTasks;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //PRTSKDLG_HPP
