/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		STRING.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CString class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef STRING_HPP
#define STRING_HPP

// For I/O.
class CFile;

/******************************************************************************
** 
** This is a simple string manipulation class.
**
*******************************************************************************
*/

WCLCLASS CString
{
public:
	//
	// Constructors/Destructor.
	//
	CString(void);
	CString(uint iID);
	CString(const char* pszBuffer);
	CString(const CString& strSrc);
	~CString(void);

	//
	// Member setting.
	//
	void LoadRsc(uint iID);
	void Free(void);

	//
	// Attributes.
	//
	uint Length(void) const;
	char* Buffer(void);
	uint BufferSize(void) const;
	void BufferSize(uint iSize);

	//
	// Operators.
	//
	const CString& operator=(const CString& strSrc);

#ifdef M_I86MM
	// Medium memory model only.
	const CString& operator=(const char* pszBuffer);
	operator const char*() const;
#endif
	
	const CString& operator=(LPCSTR lpszBuffer);
	operator LPCSTR() const;
	bool operator ==(const char* pszString) const;
	bool operator !=(const char* pszString) const;
	void operator +=(const char* pszString);

	//
	// I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile) const;
	
protected:
	//
	// Members.
	//
	char*	m_pszBuffer;	// Pointer to buffer.
	uint16	m_iSize;		// Size of allocated buffer.

	//
	// Internal methods.
	//
	void Copy(const char FAR* lpszBuffer);
	void Copy(const char FAR* lpszBuffer, uint iChars);

	//
	// Friends.
	//
	friend class CPath;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CString::CString(uint iID)
{
	LoadRsc(iID);
}

inline uint CString::Length(void) const
{
	ASSERT(m_pszBuffer);

	return lstrlen((LPCSTR)m_pszBuffer);
}

inline const CString& CString::operator=(const CString& strSrc)
{
	Copy(strSrc.m_pszBuffer, strSrc.Length());
	return *this;
}

//
// Only for Medium memory model.
//
#ifdef M_I86MM

inline const CString& CString::operator=(const char* pszBuffer)
{
	ASSERT(pszBuffer);

	Copy(pszBuffer, lstrlen(pszBuffer));
	return *this;
}

inline CString::operator const char*() const
{
	ASSERT(m_pszBuffer);
	
	return m_pszBuffer;
}

#endif //M_I86MM

inline const CString& CString::operator=(LPCSTR lpszBuffer)
{
	ASSERT(lpszBuffer);

	Copy(lpszBuffer, lstrlen(lpszBuffer));
	return *this;
}

inline CString::operator LPCSTR() const
{
	ASSERT(m_pszBuffer);
	
	return m_pszBuffer;
}

inline bool CString::operator ==(const char* pszString) const
{
	return (strcmp(m_pszBuffer, pszString) == 0);
}

inline bool CString::operator !=(const char* pszString) const
{
	return (strcmp(m_pszBuffer, pszString) != 0);
}

inline void CString::Copy(const char FAR* lpszBuffer)
{
	Copy(lpszBuffer, lstrlen(lpszBuffer));
}

inline char* CString::Buffer(void)
{
	return m_pszBuffer;
}

inline uint CString::BufferSize(void) const
{
	return m_iSize;
}

#endif //STRING_HPP
