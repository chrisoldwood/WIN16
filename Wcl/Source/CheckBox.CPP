/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CHECKBOX.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CCheckBox class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CCheckBox::CCheckBox(void)
{
	m_wiStyle.pszClassName = "BUTTON";
	m_wiStyle.dwStyle     |= BS_AUTOCHECKBOX;
}
