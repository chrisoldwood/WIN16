/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PROJDLG.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CProjectDlg class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PROJDLG_HPP
#define PROJDLG_HPP

// Tab control pages.
#include "genrltab.hpp"
#include "headrtab.hpp"
#include "bodytab.hpp"

/******************************************************************************
** 
** This dialog is used when the user changes the settings for the project.
**
*******************************************************************************
*/

APPCLASS CProjectDlg : public CDialog
{
public:
	//
	// Constructors/Destructor.
	//
	CProjectDlg(CWnd* pParent);
	
	//
	// Members.
	//
	CGeneralTab	m_tabGeneral;
	CHeaderTab	m_tabHeader;
	CBodyTab	m_tabBody;

protected:
	//
	// Members.
	//
	CTabCtrl	m_tcSettings;
	
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

#endif //PROJDLG_HPP
