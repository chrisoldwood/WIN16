/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPIC.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTopic class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOPIC_HPP
#define TOPIC_HPP

/******************************************************************************
** 
** This is a single topic within the document.
**
*******************************************************************************
*/

class CTopic
{
public:
	//
	// Constructors/Destructor.
	//
	CTopic(void);
	~CTopic(void);

	//
	// Member access.
	//
	const char* Name(void) const;
	const char* ContextName(void) const;
	const char* Keywords(void) const;
	const char* Text(void) const;
	bool Modified(void) const;
	
	void Name(const char* pszName);
	void ContextName(const char* pszContextName);
	void Keywords(const char* pszKeywords);
	void Text(const char* pszText);

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);
	
protected:
	//
	// Members.
	//
	CString	m_strName;			// The topic name.
	CString	m_strContextName;	// The hyperlink name.
	CString	m_strKeywords;		// The list of keywords.
	CString	m_strText;			// The topic text.
	bool	m_bModified;		// Dirty flag.
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline const char* CTopic::Name(void) const
{
	return m_strName;
}

inline const char* CTopic::ContextName(void) const
{
	return m_strContextName;
}

inline const char* CTopic::Keywords(void) const
{
	return m_strKeywords;
}

inline const char* CTopic::Text(void) const
{
	return m_strText;
}

inline bool CTopic::Modified(void) const
{
	return m_bModified;
}

inline void CTopic::Name(const char* pszName)
{
	m_strName   = pszName;
	m_bModified = TRUE;
}

inline void CTopic::ContextName(const char* pszContextName)
{
	m_strContextName = pszContextName;
	m_bModified      = TRUE;
}

inline void CTopic::Keywords(const char* pszKeywords)
{
	m_strKeywords = pszKeywords;
	m_bModified   = TRUE;
}

inline void CTopic::Text(const char* pszText)
{
	m_strText   = pszText;
	m_bModified = TRUE;
}

#endif //TOPIC_HPP
