/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LABEL.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CLabel class methods.
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

CLabel::CLabel(void)
{
	m_wiStyle.pszClassName = "STATIC";
	m_wiStyle.dwStyle     |= SS_SIMPLE;
}

/******************************************************************************
** Methods:		Text()
**
** Description:	Get the text from the control as a string.
**
** Parameters:	None.
**
** Returns:		The string.
**
*******************************************************************************
*/

CString CLabel::Text(void) const
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

/******************************************************************************
** Methods:		Long()
**				ULong()
**				Double()
**
** Description:	These functions are used to set and get different types of
**				value from an EditBox.
**
** Parameters:	Value		The value to set the controls text to.
**
** Returns:		The value (for a get) or nothing (for a set).
**
*******************************************************************************
*/

/*
void CLabel::Value(int iValue, bool bSigned = TRUE) const
{
}

uint CLabel::Value(bool bSigned = TRUE) const
{
}

void CLabel::Value(long lValue, bool bSigned) const
{
	char szValue[20];
	
	// Convert depending on type.
	if (bSigned)
		wsprintf(szValue, "%ld", lValue);
	else
		wsprintf(szValue, "%lu", (ulong)lValue);
	
	SetDlgItemText(m_hWnd, iCtlID, szValue);
}

ulong CLabel::Value(bool bSigned) const
{
	char 	szValue[20];
	char**	ppChar = NULL;
	ulong 	lValue;

	// First get as text.
	GetDlgItemText(m_hWnd, iCtlID, szValue, sizeof(szValue));

	// Now convert depending on sign.
	if (bSigned)
		lValue = strtol(szValue, ppChar, 10);
	else
		lValue = strtoul(szValue, ppChar, 10);

	// Check for error.
	if (*ppChar)
	{
		*lpbValid = FALSE;
		return 0L;
	}
		
	// Conversion okay.
	*lpbValid = TRUE;
	
	return lValue;
}

void CLabel::Double(double dValue) const
{
	char szValue[20];
	
	sprintf(szValue, "%f", dValue);
	Title(m_hWnd, szValue);
}

double CLabel::Value(void) const
{
	char	szValue[20];
	char**	ppChar = NULL;
	double 	dValue;

	// First get as text.
	Title(m_hWnd, iCtlID, szValue, sizeof(szValue));

	// Now convert.
	dValue = strtod(szValue, ppChar);

	// Check for error.
	if (*ppChar)
	{
		*lpbValid = FALSE;
		return 0L;
	}
		
	// Conversion okay.
	*lpbValid = TRUE;
	
	return dValue;
}
*/
