/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MENU.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CMenu class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Destructor
**
** Description:	Free resource if not done automatically.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CMenu::~CMenu(void)
{
	// Only destroy if not already. 
	// e.g. by the parent window.
	if (IsMenu(m_hMenu))
		DestroyMenu(m_hMenu);
}

/******************************************************************************
** Method:		LoadRsc()
**
** Description:	Loads a menu from the resource file.
**
** Parameters:	iID		The resource ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMenu::LoadRsc(uint iID)
{
	ASSERT(m_hMenu == NULL);

	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);
	
	// Load the resource.
	m_hMenu = pApp->Module()->LoadMenu(iID);
}

/******************************************************************************
** Method:		EnableCmd()
**				DisableCmd()
**
** Description:	Enable or disable a menu command.
**
** Parameters:	iCmdID		The command ID.
**				bEnable		Flag to enable or disable.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMenu::EnableCmd(uint iCmdID, bool bEnable)
{
	if (bEnable)
		EnableMenuItem(m_hMenu, iCmdID, MF_BYCOMMAND | MF_ENABLED);
	else
		EnableMenuItem(m_hMenu, iCmdID, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
}

void CMenu::DisableCmd(uint iCmdID, bool bDisable)
{
	EnableCmd(iCmdID, !bDisable);
}
