/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATETIME.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CDateTime class definition.
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

CDateTime::CDateTime(void)
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

CDateTime::~CDateTime(void)
{
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the date & time as it is now.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDateTime::Set(void)
{
	m_Date.Set();
	m_Time.Set();
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the date & time from the ASCII strings passed in.
**
** Parameters:	pszDate		The date in a string formatted as DD/MM/YYYY.
**				pszTime		The time in a string formatted as HH:MM.
**
** Returns:		TRUE if valid.
**				FALSE if not.
**
*******************************************************************************
*/

bool CDateTime::Set(const char* pszDate, const char* pszTime)
{
	if (!m_Date.Set(pszDate))
		return FALSE;

	if (!m_Time.Set(pszTime))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a date-time from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CDateTime::Read(CFile& rFile)
{
	if (!m_Date.Read(rFile))
		return FALSE;

	if (!m_Time.Read(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a date-time to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CDateTime::Write(CFile& rFile)
{
	if (!m_Date.Write(rFile))
		return FALSE;

	if (!m_Time.Write(rFile))
		return FALSE;

	return TRUE;
}
