/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HEADRTAB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CHeaderTab class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HEADRTAB_HPP
#define HEADRTAB_HPP

/******************************************************************************
** 
** This is the tab page used for the header project settings.
**
*******************************************************************************
*/

APPCLASS CHeaderTab : public CTabPage
{
public:
	//
	// Constructors/Destructor.
	//
	CHeaderTab();
	
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

#endif //HEADRTAB_HPP
