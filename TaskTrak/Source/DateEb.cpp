/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATEEB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CDateEditBox class definition.
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

CDateEditBox::CDateEditBox(void)
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

CDateEditBox::~CDateEditBox(void)
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

void CDateEditBox::OnCreate(void)
{
	// Limit to just ??/??/????
	TextLimit(10);
}
