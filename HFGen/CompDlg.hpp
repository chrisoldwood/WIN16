/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		COMPDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CCompilerDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef COMPDLG_HPP
#define COMPDLG_HPP

/******************************************************************************
** 
** This dialog is used when the user changes the settings for the help
** compiler.
**
*******************************************************************************
*/

APPCLASS CCompilerDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CCompilerDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CPath	m_strFileName;

protected:
	//
	// Members.
	//
	CEditBox	m_ebFileName;
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual bool OnOk(void);

	//
	// Control message processors.
	//
	void OnBrowse(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //COMPDLG_HPP
