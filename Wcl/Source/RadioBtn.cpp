/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		RADIOBTN.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CRadioBtn class methods.
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

CRadioBtn::CRadioBtn(void)
{
	m_wiStyle.pszClassName = "BUTTON";
	m_wiStyle.dwStyle     |= BS_AUTORADIOBUTTON;
}
