/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		GENRLTAB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CGeneralTab class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef GENRLTAB_HPP
#define GENRLTAB_HPP

/******************************************************************************
** 
** This is the tab page used for the general project settings.
**
*******************************************************************************
*/

APPCLASS CGeneralTab : public CTabPage
{
public:
	//
	// Constructors/Destructor.
	//
	CGeneralTab();
	
	//
	// Members.
	//
	CString	m_strTitle;
	CString	m_strCopyright;
	bool	m_bCompress;

protected:
	//
	// Members.
	//
	CEditBox	m_ebTitle;
	CEditBox	m_ebCopyright;
	CCheckBox	m_cbCompress;
	
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

#endif //GENRLTAB_HPP
