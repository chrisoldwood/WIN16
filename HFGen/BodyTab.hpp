/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BODYTAB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CBodyTab class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef BODYTAB_HPP
#define BODYTAB_HPP

/******************************************************************************
** 
** This is the tab page used for the body text project settings.
**
*******************************************************************************
*/

APPCLASS CBodyTab : public CTabPage
{
public:
	//
	// Constructors/Destructor.
	//
	CBodyTab();
	
	//
	// Members.
	//
	int	m_iLineSpacing;
	int	m_iParaSpacing;
	int	m_iLeftMargin;
	int	m_iRightMargin;

protected:
	//
	// Members.
	//
	CEditBox	m_ebLineSpacing;
	CEditBox	m_ebParaSpacing;
	CEditBox	m_ebLeftMargin;
	CEditBox	m_ebRightMargin;
	
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

#endif //BODYTAB_HPP
