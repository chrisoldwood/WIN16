/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATE.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CDate class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdlib.h>

/******************************************************************************
**
** Local variables.
**
*******************************************************************************
*/

// Array of months in days.
static int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static char* Days[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

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

CDate::CDate(void)
{
	m_lDate = 0;
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

CDate::~CDate(void)
{
}

/******************************************************************************
** Method:		Get()
**
** Description:	Gets the date.
**
** Parameters:	rDate, rMonth, rYear	The return parameters.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDate::Get(int& rDate, int& rMonth, int& rYear) const
{
	ulong	lDays = 0;
	int		iDaysInMonth;
	
	rYear = 1990;
	
	// Find year.
	while ((lDays + 365) < m_lDate)
	{
		rYear++;
		
		// Leap Year?
		if ((rYear % 4) == 0)
			lDays += 366;
		else
			lDays += 365;
	}
	
	rMonth       = 1;
	iDaysInMonth = Months[rMonth-1];
	
	// Find month.
	while ((lDays + iDaysInMonth) < m_lDate)
	{
		rMonth++;

		lDays += iDaysInMonth;
		iDaysInMonth = Months[rMonth-1];
		
		// Febuary & leap year?
		if ( (rMonth == 2) && ((rYear % 4) == 0) )
			iDaysInMonth++;
	}
	
	// Find date.
	rDate = (int) (m_lDate - lDays);
}

/******************************************************************************
** Operator:	const char*
**
** Description:	Convert the date to a string.
**
** Parameters:	None.
**
** Returns:		A string.
**
*******************************************************************************
*/

CDate::operator const char*() const
{
	int	iDate, iMonth, iYear;
	
	Get(iDate, iMonth, iYear);
	
	wsprintf((char*)m_szDate, "%02d/%02d/%02d", iDate, iMonth, iYear);
	
	return m_szDate;
}

/******************************************************************************
** Method:		DaysInMonth()
**
** Description:	Get the number of days in the month.
**
** Parameters:	None.
**
** Returns:		The number of days in the month.
**
*******************************************************************************
*/

uint CDate::DaysInMonth(void) const
{
	int	iDate, iMonth, iYear;
	int iDays;
	
	Get(iDate, iMonth, iYear);
	
	// Get days in month.
	iDays = Months[iMonth-1];
	
	// Adjust for leap year if February?
	if ( (iMonth == 2) && ((iYear % 4) == 0) )
		iDays++;
		
	return iDays;
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the date as it is now. This uses the a BIOS call to read
**				the PC's clock.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

#pragma optimize("", off)

void CDate::Set(void)
{
#ifdef WIN16	

	uint8 	iDate, iMonth;
	uint16	iYear;

	// Call DOS to get date.
	__asm
	{
		; Get date.
		mov	ah, 2Ah
		int	21h
		
		; Copy to stack variables.
		mov	iDate, dl
		mov	iMonth, dh
		mov	iYear, cx
	}

	Set(iDate, iMonth, iYear);

#else

	SYSTEMTIME	Date;

	GetSystemTime(&Date);

	Set(Date.wDay, Date.wMonth, Date.wYear);

#endif
}

#pragma optimize("", on)

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the date given the discrete parameters.
**
** Parameters:	iDate, iMonth, iYear	The date.
**
** Returns:		TRUE if valid.
**				FALSE if not.
**
*******************************************************************************
*/

bool CDate::Set(int iDate, int iMonth, int iYear)
{
	int i;

	// Validate date.
	if ( (iYear < 1990) || (iYear > 3000) )
		return FALSE;

	if ( (iMonth < 1) || (iMonth > 12) )
		return FALSE;
	
	if ( (iDate < 1) || (iDate > 31) )
		return FALSE;

	// Start with whole years.
	m_lDate = (uint32)(iYear - 1990) * 365;
	
	// Adjust for leap years.
	for (i = 1990; i < iYear; i++)
	{
		// Leap year?
		if ((i % 4) == 0)
			m_lDate++;
	}

	// For all whole months.
	for (i = 1; i < iMonth; i++)
	{
		// Add in days in month.
		m_lDate += Months[i-1];
		
		// February and leap year?
		if ( (iMonth == 2) && ((iYear % 4) == 0) )
			m_lDate++;
	}

	// Add in days.
	m_lDate += iDate;
	
	return TRUE;
}

/******************************************************************************
** Method:		Set()
**
** Description:	Sets the date from the ASCII string passed in.
**
** Parameters:	pszDate		The date in a string formatted as DD/MM/YYYY.
**
** Returns:		TRUE if valid.
**				FALSE if not.
**
*******************************************************************************
*/

bool CDate::Set(const char* pszDate)
{
	char	szDate[20];
	
	// Copy to tmp buffer.
	strncpy(szDate, pszDate, 10);
	szDate[10] = '\0';
	
	// Break up string.
	char*	pszDay   = strtok(szDate, "/");
	char*	pszMonth = strtok(NULL,   "/");
	char*	pszYear  = strtok(NULL,   "/");

	// Convert to numbers.
	int	iDate  = atoi(pszDay);
	int iMonth = atoi(pszMonth);
	int iYear  = atoi(pszYear);
	
	return Set(iDate, iMonth, iYear);
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a date from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CDate::Read(CFile& rFile)
{
	if (!rFile.Read(m_lDate))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a date to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CDate::Write(CFile& rFile)
{
	if (!rFile.Write(m_lDate))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		DayOfWeekStr()
**
** Description:	Get the day of the week as a string.
**
** Parameters:	None.
**
** Returns:		The string.
**
*******************************************************************************
*/

const char* CDate::DayOfWeekStr(void) const
{
	return Days[DayOfWeek()];
}
