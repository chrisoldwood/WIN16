/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		COMBOBOX.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CComboBox class methods.
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

CComboBox::CComboBox(void)
{
	m_wiStyle.pszClassName = "COMBOBOX";
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

CString CComboBox::Text(int iPos) const
{
	CString	strText;

	// Allocate space for string.
	strText.BufferSize(TextLength(iPos));

	// Get string.
	SendMessage(CB_GETLBTEXT, iPos, (LPARAM)(LPCSTR) strText);

	return strText;
}

/******************************************************************************
** Method:		Text()
**
** Description:	Get the string for edit box part of the control.
**
** Parameters:	None.
**
** Returns:		The string.
**
*******************************************************************************
*/

CString CComboBox::Text(void) const
{
	CString	strText;
	int		iLen;

	// Get string length.
	iLen = TextLength();

	// Allocate space.
	strText.BufferSize(iLen);

	// Fetch string.
	SendMessage(WM_GETTEXT, iLen+1, (LPARAM)(LPCSTR) strText);

	return strText;
}
