/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TIME.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTime class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdlib.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise the members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTime::CTime(void)
{
	m_lTime = 0;
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

CTime::~CTime(void)
{
}

/******************************************************************************
** Method:		Get()
**
** Description:	Gets the time.
**
** Parameters:	rHrs, rMins		The return parameters.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTime::Get(int& rHrs, int& rMins) const
{
	rHrs  = (int) (m_lTime / 60);
	rMins = (int) (m_lTime % 60);
}

/******************************************************************************
** Operator:	const char*
**
** Description:	Convert the time to a string.
**
** Parameters:	None.
**
** Returns:		A string.
**
*******************************************************************************
*/

CTime::operator const char*() const
{
	int iHrs, iMins;
	
	Get(iHrs, iMins);
	
	wsprintf((char*)m_szTime, "%02d:%02d", iHrs, iMins);
	
	return m_szTime;
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the time as it is now. This uses the a BIOS call to read
**				the PC's clock.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

#pragma optimize("", off)

void CTime::Set(void)
{
#ifdef WIN16

	uint8 	iHrs, iMins;
	
	// Call DOS to get time.
	__asm
	{
		; Get time.
		mov	ah, 2Ch
		int	21h
		
		; Copy to stack variables.
		mov	iHrs, ch
		mov	iMins, cl
	}
	
	Set(iHrs, iMins);

#else

	SYSTEMTIME	Time;

	GetSystemTime(&Time);

	Set(Time.wHour, Time.wMinute);

#endif
}

#pragma optimize("", on)

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the time given the discrete parameters.
**
** Parameters:	iHrs, iMins		The time.
**
** Returns:		TRUE if valid.
**				FALSE if not.
**
*******************************************************************************
*/

bool CTime::Set(int iHrs, int iMins)
{
	// Validate time.
	if ( (iHrs < 0) || (iHrs > 23) )
		return FALSE;

	if ( (iMins < 0) || (iMins > 59) )
		return FALSE;

	// Set.
	m_lTime = (iHrs * 60) + iMins;
	
	return TRUE;
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the time from the ASCII string passed in.
**
** Parameters:	pszTime		The time in a string formatted as HH:MM.
**
** Returns:		TRUE if valid.
**				FALSE if not.
**
*******************************************************************************
*/

bool CTime::Set(const char* pszTime)
{
	char	szTime[10];
	
	// Copy to tmp buffer.
	strncpy(szTime, pszTime, 5);
	szTime[5] = '\0';
	
	// Break up string.
	char*	pszHours = strtok(szTime, ":");
	char*	pszMins  = strtok(NULL,   ":");

	// Convert to numbers.
	int	iHrs  = atoi(pszHours);
	int iMins = atoi(pszMins);
	
	return Set(iHrs, iMins);
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a time from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTime::Read(CFile& rFile)
{
	if (!rFile.Read(m_lTime))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a time to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTime::Write(CFile& rFile)
{
	if (!rFile.Write(m_lTime))
		return FALSE;

	return TRUE;
}
