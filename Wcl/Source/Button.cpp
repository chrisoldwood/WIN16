/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BUTTON.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CButton class methods.
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

CButton::CButton(void)
{
	m_wiStyle.pszClassName = "BUTTON";
	m_wiStyle.dwStyle     |= BS_PUSHBUTTON;
}
