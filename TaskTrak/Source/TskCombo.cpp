/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TSKCOMBO.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTaskCombo class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

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

CTaskCombo::CTaskCombo(void)
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

CTaskCombo::~CTaskCombo(void)
{
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Initialise the control with the list of previous tasks.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTaskCombo::OnCreate(void)
{
	CTaskListEnum	Enum(App.TaskList());
	CString*		pString;
	
	// Add all tasks.
	while((pString = Enum.Next()) != NULL)
		Add(*pString);
	
	// Select last task, if one
	if (App.LastTask() != "")
	{
		int iItem = FindExact(App.LastTask());
		ASSERT(iItem != CB_ERR);
		
		Select(iItem);
	}
}
