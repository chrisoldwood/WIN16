/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TIMEEB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTimeEditBox class definition.
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

CTimeEditBox::CTimeEditBox(void)
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

CTimeEditBox::~CTimeEditBox(void)
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

void CTimeEditBox::OnCreate(void)
{
	// Limit to just ??:??
	TextLimit(5);
}
