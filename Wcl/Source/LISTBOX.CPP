/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LISTBOX.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CListBox class methods.
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

CListBox::CListBox(void)
{
	m_wiStyle.pszClassName = "LISTBOX";
	m_wiStyle.dwStyle     |= LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT | LBS_NOTIFY;
	m_wiStyle.dwStyle     |= LBS_SORT | WS_VSCROLL;
}

/******************************************************************************
** Method:		Text()
**
** Description:	Get the string for the specified item.
**
** Parameters:	iPos	The item.
**
** Returns:		The string.
**
*******************************************************************************
*/

CString CListBox::Text(int iPos) const
{
	CString	strText;

	// Allocate space.
	strText.BufferSize(TextLength(iPos));

	SendMessage(LB_GETTEXT, iPos, (LPARAM)(LPCSTR) strText);

	return strText;
}
