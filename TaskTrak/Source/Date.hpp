/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATE.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CDate class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DATE_HPP
#define DATE_HPP

/******************************************************************************
** 
** This class represents a date. It is stored as the number of days since 1st
** January 1990.
**
*******************************************************************************
*/

class CDate
{
public:
	//
	// Constructors/Destructor.
	//
	CDate(void);
	~CDate(void);

	//
	// Member access.
	//
	void Get(int& rDate, int& rMonth, int& rYear) const;
	operator const char*() const;
	ulong InDays(void) const;
	uint DayOfWeek(void) const;
	uint DaysInMonth(void) const;
	const char* DayOfWeekStr(void) const;

	//
	// Member setting.
	//
	void Set(void);
	bool Set(int iDate, int iMonth, int iYear);
	bool Set(const char* pszDate);

	//
	// Comparison.
	//
	bool operator ==(const CDate& rPost) const;
	bool operator !=(const CDate& rPost) const;
	bool operator  <(const CDate& rPost) const;
	bool operator  >(const CDate& rPost) const;
	
	//
	// Other operators.
	//
	void operator +=(ulong lDays);
	void operator -=(ulong lDays);

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

protected:
	//
	// Members.
	//
	uint32	m_lDate;
	char	m_szDate[20];
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline ulong CDate::InDays(void) const
{
	return m_lDate;
}

inline uint CDate::DayOfWeek(void) const
{
	return (uint) ((m_lDate - 1) % 7);
}

inline bool CDate::operator ==(const CDate& rPost) const
{
	return (m_lDate == rPost.m_lDate);
}

inline bool CDate::operator !=(const CDate& rPost) const
{
	return (m_lDate != rPost.m_lDate);
}

inline bool CDate::operator <(const CDate& rPost) const
{
	return (m_lDate < rPost.m_lDate);
}

inline bool CDate::operator >(const CDate& rPost) const
{
	return (m_lDate > rPost.m_lDate);
}

inline void CDate::operator +=(ulong lDays)
{
	m_lDate += lDays;
}

inline void CDate::operator -=(ulong lDays)
{
	m_lDate -= lDays;
}

#endif //DATE_HPP
