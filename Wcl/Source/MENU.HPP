/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MENU.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CMenu class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MENU_HPP
#define MENU_HPP

/******************************************************************************
** 
** This encapsulates a Windows popup menu.
**
*******************************************************************************
*/

WCLCLASS CMenu
{
public:
	//
	// Constructors/Destructor.
	//
	CMenu(void);
	CMenu(HMENU hMenu);
	~CMenu(void);
	
	//
	// Member access.
	//
	HMENU Handle(void) const;

	//
	// Member setting.
	//
	void LoadRsc(uint iID);

	//
	// Item state.
	//
	void EnableCmd(uint iCmdID, bool bEnable = TRUE);
	void DisableCmd(uint iCmdID, bool bDisable = TRUE);
	
protected:
	//
	// Members.
	//
	HMENU	m_hMenu;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CMenu::CMenu(void)
{
	m_hMenu = NULL;
}

inline CMenu::CMenu(HMENU hMenu)
{
	m_hMenu = hMenu;
}

inline HMENU CMenu::Handle(void) const
{
	return m_hMenu;
}

#endif //MENU_HPP
