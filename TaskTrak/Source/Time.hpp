/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TIME.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTime class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TIME_HPP
#define TIME_HPP

/******************************************************************************
** 
** This class represents the time of day. The time is stored as the number of
** minutes since midnight.
**
*******************************************************************************
*/

class CTime
{
public:
	//
	// Constructors/Destructor.
	//
	CTime(void);
	CTime(int iHrs, int iMins);
	~CTime(void);

	//
	// Member access.
	//
	void Get(int& rHrs, int& rMins) const;
	operator const char*() const;
	ulong InMins(void) const;

	//
	// Member setting.
	//
	void Set(void);
	bool Set(int iHrs, int iMins);
	bool Set(const char* pszTime);

	//
	// Comparison.
	//
	bool operator ==(const CTime& rPost) const;
	bool operator !=(const CTime& rPost) const;
	bool operator  <(const CTime& rPost) const;
	bool operator  >(const CTime& rPost) const;
	bool operator >=(const CTime& rPost) const;

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

protected:
	//
	// Members.
	//
	uint32	m_lTime;
	char	m_szTime[10];
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CTime::CTime(int iHrs, int iMins)
{
	bool bOkay = Set(iHrs, iMins);
	ASSERT(bOkay);
}

inline ulong CTime::InMins(void) const
{
	return m_lTime;
}

inline bool CTime::operator ==(const CTime& rPost) const
{
	return (m_lTime == rPost.m_lTime);
}

inline bool CTime::operator !=(const CTime& rPost) const
{
	return (m_lTime != rPost.m_lTime);
}

inline bool CTime::operator <(const CTime& rPost) const
{
	return (m_lTime < rPost.m_lTime);
}

inline bool CTime::operator >(const CTime& rPost) const
{
	return (m_lTime > rPost.m_lTime);
}

inline bool CTime::operator >=(const CTime& rPost) const
{
	return (m_lTime >= rPost.m_lTime);
}

#endif //TIME_HPP
