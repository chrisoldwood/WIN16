/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EDITBOX.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CEditBox class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**				We mask off the lower 16 bits to remove any CLabel style bits.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CEditBox::CEditBox(void)
{
	m_wiStyle.pszClassName = "EDIT";
	m_wiStyle.dwStyle     &= 0xFFFF0000;
	m_wiStyle.dwStyle     |= ES_MULTILINE | ES_AUTOVSCROLL | ES_LEFT | WS_VSCROLL;
}
