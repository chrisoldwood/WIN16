/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSENUM.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CSessionEnum class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <limits.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	Construct an enumerator for the whole of the list.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSessionEnum::CSessionEnum(const CSessionList& List) : CListEnum(List)
{
	CDate	Date;
	
	// Set start and end days.
	Date += 0;
	m_dtStart.Date(Date);

	Date += ULONG_MAX;
	m_dtEnd.Date(Date);
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Construct an enumerator for the part of the list that falls
**				between the two dates.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CSessionEnum::CSessionEnum(const CSessionList& List, const CDateTime dtStart,
									const CDateTime dtEnd) : CListEnum(List)
{
	// Copy start and end dates.
	m_dtStart = dtStart;
	m_dtEnd   = dtEnd;
}

/******************************************************************************
** Method:		Next()
**
** Description:	Returns the next session in the enumeration.
**
** Parameters:	None.
**
** Returns:		The session or NULL.
**
*******************************************************************************
*/

CSession* CSessionEnum::Next(void)
{
	// Get next session.
	CSession*	pSession = (CSession*) CListEnum::Next();

	// Skip sessions not in limits.
	while ( (pSession) 
		 && ( (pSession->Start() <  m_dtStart) 
		   || (pSession->Start() >= m_dtEnd) ) )
	{
		pSession = (CSession*) CListEnum::Next();
	}
	
	return pSession;
}
