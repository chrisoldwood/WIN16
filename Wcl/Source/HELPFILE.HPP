/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HELPFILE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHelpFile class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HELPFILE_HPP
#define HELPFILE_HPP

/******************************************************************************
** 
** This class provides a simple wrapper around a Windows Help File.
**
*******************************************************************************
*/

WCLCLASS CHelpFile
{
public:
	//
	// Constructors/Destructor.
	//
	CHelpFile(void);
	
	//
	// Member access.
	//
	CPath& Path(void);

	//
	// Member setting.
	//
    void ParentWindow(const CWnd* pParent);
    
	//
	// Commands.
	//
	void Contents(void);
	void Topic(DWORD dwTopic);
	void Close(void);
	
protected:
	//
	// Members.
	//
	CPath		m_PathName;
	const CWnd*	m_pParent;
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CHelpFile::CHelpFile(void)
{
	m_pParent = NULL;
}

inline CPath& CHelpFile::Path(void)
{
	return m_PathName;
}

inline void CHelpFile::ParentWindow(const CWnd* pParent)
{
	ASSERT(pParent);
	
	m_pParent = pParent;
}

inline void CHelpFile::Contents(void)
{
	ASSERT(m_pParent);
	
	WinHelp(m_pParent->Handle(), m_PathName, HELP_CONTENTS, 0L);
}

inline void CHelpFile::Topic(DWORD dwTopic)
{
	ASSERT(m_pParent);
	
	WinHelp(m_pParent->Handle(), m_PathName, HELP_CONTEXT, dwTopic);
}

inline void CHelpFile::Close(void)
{
	ASSERT(m_pParent);
	
	WinHelp(m_pParent->Handle(), m_PathName, HELP_QUIT, 0L);
}

#endif //HELPFILE_HPP
