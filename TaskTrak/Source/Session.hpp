/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSION.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CSession class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SESSION_HPP
#define SESSION_HPP

/******************************************************************************
** 
** This class represents a period of time spent on a task.
**
*******************************************************************************
*/

class CSession
{
public:
	//
	// Constructors/Destructor.
	//
	CSession(void);
	~CSession(void);

	//
	// Member access.
	//
	const CDateTime& Start(void) const;
	const CDateTime& Finish(void) const;
	const CString&   Task(void) const;
	ulong Length(void) const;

	//
	// Member setting.
	//
	void Start(const CDateTime& dtStart, const char* pszTask);
	void Finish(const CDateTime& dtFinish, const char* pszTask);
	
	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

protected:
	//
	// Members.
	//
	CDateTime	m_dtStart;
	CDateTime	m_dtFinish;
	CString		m_strTask;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline const CDateTime& CSession::Start(void) const
{
	return m_dtStart;
}

inline const CDateTime& CSession::Finish(void) const
{
	return m_dtFinish;
}

inline const CString& CSession::Task(void) const
{
	return m_strTask;
}

inline void CSession::Start(const CDateTime& dtStart, const char* pszTask)
{
	m_dtStart = dtStart;
	m_strTask = pszTask;
}

inline void CSession::Finish(const CDateTime& dtFinish, const char* pszTask)
{
	m_dtFinish = dtFinish;
	m_strTask  = pszTask;
}

#endif //SESSION_HPP
