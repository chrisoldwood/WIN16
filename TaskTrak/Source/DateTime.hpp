/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATETIME.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CDateTime class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DATETIME_HPP
#define DATETIME_HPP

/******************************************************************************
** 
** This class represents a date and time.
**
*******************************************************************************
*/

class CDateTime
{
public:
	//
	// Constructors/Destructor.
	//
	CDateTime(void);
	CDateTime(const CDate& rDate, const CTime& rTime);
	~CDateTime(void);
	
	//
	// Member access.
	//
	const CDate& Date(void) const;
	const CTime& Time(void) const;
	ulong InMins(void) const;

	//
	// Member setting.
	//
	void Set(void);
	bool Set(const char* pszDate, const char* pszTime);
	void Date(const CDate& rDate);
	void Time(const CTime& rTime);

	//
	// Comparison.
	//
	bool operator ==(const CDateTime& rPost) const;
	bool operator !=(const CDateTime& rPost) const;
	bool operator  <(const CDateTime& rPost) const;
	bool operator  >(const CDateTime& rPost) const;
	bool operator >=(const CDateTime& rPost) const;

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

protected:
	//
	// Members.
	//
	CDate	m_Date;
	CTime	m_Time;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CDateTime::CDateTime(const CDate& rDate, const CTime& rTime)
{
	m_Date = rDate;
	m_Time = rTime;
}

inline const CDate& CDateTime::Date(void) const
{
	return m_Date;
}

inline const CTime& CDateTime::Time(void) const
{
	return m_Time;
}

inline ulong CDateTime::InMins(void) const
{
	return ( (m_Date.InDays() * 24 * 60) + m_Time.InMins() );
}

inline void CDateTime::Date(const CDate& rDate)
{
	m_Date = rDate;
}

inline void CDateTime::Time(const CTime& rTime)
{
	m_Time = rTime;
}

inline bool CDateTime::operator ==(const CDateTime& rPost) const
{
	return ((m_Date == rPost.m_Date) && (m_Time == rPost.m_Time));
}

inline bool CDateTime::operator !=(const CDateTime& rPost) const
{
	return ((m_Date != rPost.m_Date) || (m_Time != rPost.m_Time));
}

inline bool CDateTime::operator <(const CDateTime& rPost) const
{
	return ( (m_Date  < rPost.m_Date) ||
			((m_Date == rPost.m_Date) && (m_Time < rPost.m_Time)) );
}

inline bool CDateTime::operator >(const CDateTime& rPost) const
{
	return ( (m_Date  > rPost.m_Date) ||
			((m_Date == rPost.m_Date) && (m_Time > rPost.m_Time)) );
}

inline bool CDateTime::operator >=(const CDateTime& rPost) const
{
	return ( (m_Date  > rPost.m_Date) ||
			((m_Date == rPost.m_Date) && (m_Time >= rPost.m_Time)) );
}

#endif //DATETIME_HPP
