/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPIC.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTopic class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise members..
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTopic::CTopic(void)
{
	m_strName        = "";
	m_strContextName = "";
	m_strKeywords    = "";
	m_strText        = "";
	m_bModified      = FALSE;
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

CTopic::~CTopic(void)
{
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a topic from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTopic::Read(CFile& rFile)
{
	if (!m_strName.Read(rFile))
		return FALSE;

	if (!m_strContextName.Read(rFile))
		return FALSE;

	if (!m_strKeywords.Read(rFile))
		return FALSE;

	if (!m_strText.Read(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a topic to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTopic::Write(CFile& rFile)
{
	if (!m_strName.Write(rFile))
		return FALSE;

	if (!m_strContextName.Write(rFile))
		return FALSE;

	if (!m_strKeywords.Write(rFile))
		return FALSE;

	if (!m_strText.Write(rFile))
		return FALSE;

	// Reset dirty flag.
	m_bModified = FALSE;

	return TRUE;
}
