/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSION.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CSession class definition.
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

CSession::CSession(void)
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

CSession::~CSession(void)
{
}

/******************************************************************************
** Method:		Length()
**
** Description:	Get the length of the session in minutes.
**
** Parameters:	None.
**
** Returns:		The length or 0 if the start time is later then finish time.
**
*******************************************************************************
*/

ulong CSession::Length(void) const
{
	// Start later than finish?
	if (m_dtStart > m_dtFinish)
		return 0;

	// Return difference.
	return (m_dtFinish.InMins() - m_dtStart.InMins());
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a session from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CSession::Read(CFile& rFile)
{
	if (!m_dtStart.Read(rFile))
		return FALSE;

	if (!m_dtFinish.Read(rFile))
		return FALSE;

	if (!m_strTask.Read(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a session to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CSession::Write(CFile& rFile)
{
	if (!m_dtStart.Write(rFile))
		return FALSE;

	if (!m_dtFinish.Write(rFile))
		return FALSE;

	if (!m_strTask.Write(rFile))
		return FALSE;

	return TRUE;
}
