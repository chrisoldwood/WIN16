/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSNLB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CSessionListBox class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdio.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSessionListBox::CSessionListBox(void)
{
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSessionListBox::~CSessionListBox(void)
{
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Initialise the control with the list of sessions.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CSessionListBox::OnCreate(void)
{
	// Fill listbox.
	Refresh();
	
	// Select 1st item, if one.
	if (App.SessionList().Length())
		Select(0);
}

/******************************************************************************
** Method:		Refresh()
**
** Description:	Refresh the list of sessions.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CSessionListBox::Refresh(void) const
{
	// Save current selection.
	int iSel = Current();

	// Empty listbox.
	Reset();

	CSessionEnum	Enum(App.SessionList());
	CSession*		pSession;
	char			szSession[50];
	
	// For all sessions within the period.
	while((pSession = Enum.Next()) != NULL)
	{
		const char*	pszStartDate = pSession->Start().Date();
		const char*	pszStartTime = pSession->Start().Time();
		const char*	pszEndTime   = pSession->Finish().Time();
		const char* pszTask      = pSession->Task();
	
		// Convert to a string and add.
		sprintf(szSession, "%s  %s  %s  %s", pszStartDate, pszStartTime,
											pszEndTime, pszTask);
		int iIdx = Add(szSession);
		
		ASSERT(iIdx != LB_ERR);
		
		// Add session as item data.
#ifdef WIN16
		ItemData(iIdx, (LPARAM)(WORD)pSession);
#else
		ItemData(iIdx, (LPARAM)pSession);
#endif
    }
    
    // Was current selection?
    if (iSel != LB_ERR)
    	Select(iSel);
    else
    	Select(0);
}
