/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		INIFILE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CIniFile class declaration
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef INIFILE_HPP
#define INIFILE_HPP

/******************************************************************************
** 
** This class encapsulates the behaviour of accessing a Windows .INI file.
**
*******************************************************************************
*/

WCLCLASS CIniFile
{
public:
	//
	// Constructors/Destructor.
	//
	
	//
	// Member access.
	//
	CPath& Path(void);

	//
	// File access.
	//
	void ReadString(const char* pszSection, const char* pszEntry, const char* pszDefault, 
						char* pszValue, uint iBufSize) const;
	void WriteString(const char* pszSection, const char* pszEntry, const char* pszValue);
	int  ReadInt(const char* pszSection, const char* pszEntry, int iDefault) const;
	void WriteInt(const char* pszSection, const char* pszEntry, int iValue);
	long ReadLong(const char* pszSection, const char* pszEntry, long lDefault) const;
	void WriteLong(const char* pszSection, const char* pszEntry, long lValue);
	bool ReadBool(const char* pszSection, const char* pszEntry, bool bDefault) const;
	void WriteBool(const char* pszSection, const char* pszEntry, bool bValue);
	// ReadReal
	// WriteReal
	// ReadHex
	// WriteHex
	
protected:
	//
	// Members.
	//
	CPath	m_Path;
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CPath& CIniFile::Path(void)
{
	return m_Path;
}

#endif //INIFILE_HPP
