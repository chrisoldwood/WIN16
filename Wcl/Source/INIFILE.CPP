/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		INIFILE.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CIniFile class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <stdlib.h>

/******************************************************************************
** Method:		ReadString()
**				WriteString()
**				ReadInt()
**				WriteInt()
**				ReadLong()
**				WriteLong()
**				ReadBool()
**				WriteBool()
**
** Description:	Methods to read and write specific data types to and from the
**				.ini file.
**
** Parameters:	pszSection		The [..] section heading.
**				pszEntry		The ?= entry name.
**				Default			The default value.
**
** Returns:		Depends on method.
**
*******************************************************************************
*/

void CIniFile::ReadString(const char* pszSection, const char* pszEntry, 
						const char* pszDefault, char* pszValue, uint iBufSize) const
{
	ASSERT(pszSection);
	ASSERT(pszEntry);
	ASSERT(pszDefault);
	ASSERT(pszValue);
	ASSERT(iBufSize);
	
	GetPrivateProfileString(pszSection, pszEntry, pszDefault, pszValue,
							iBufSize, m_Path);
}
						
void CIniFile::WriteString(const char* pszSection, const char* pszEntry, const char* pszValue)
{
	ASSERT(pszSection);
	ASSERT(pszEntry);
	ASSERT(pszValue);
	
	WritePrivateProfileString(pszSection, pszEntry, pszValue, m_Path);
}
						
int CIniFile::ReadInt(const char* pszSection, const char* pszEntry, int iDefault) const
{
	ASSERT(pszSection);
	ASSERT(pszEntry);

	return GetPrivateProfileInt(pszSection, pszEntry, iDefault, m_Path);
}
						
void CIniFile::WriteInt(const char* pszSection, const char* pszEntry, int iValue)
{
	ASSERT(pszSection);
	ASSERT(pszEntry);
	
	char szValue[10];
	
	// Convert to string and write.
	wsprintf(szValue, "%d", iValue);
	WritePrivateProfileString(pszSection, pszEntry, szValue, m_Path);
}
						
long CIniFile::ReadLong(const char* pszSection, const char* pszEntry, long lDefault) const
{
	ASSERT(pszSection);
	ASSERT(pszEntry);

	char szValue[20];

	// Read as a string.
	GetPrivateProfileString(pszSection, pszEntry, "", szValue, 
								sizeof(szValue), m_Path);
	
	// Read anything?
	if (szValue[0] == '\0')
		return lDefault;
		
	// Convert to value and return
	return strtol(szValue, NULL, 10);
}
						
void CIniFile::WriteLong(const char* pszSection, const char* pszEntry, long lValue)
{
	ASSERT(pszSection);
	ASSERT(pszEntry);

	char szValue[20];
	
	// Convert to string and write.
	wsprintf(szValue, "%ld", lValue);
	WritePrivateProfileString(pszSection, pszEntry, szValue, m_Path);
}
						
bool CIniFile::ReadBool(const char* pszSection, const char* pszEntry, bool bDefault) const
{
	ASSERT(pszSection);
	ASSERT(pszEntry);

	char szValue[10];

	// Read as a string.
	GetPrivateProfileString(pszSection, pszEntry, "", szValue, 
								sizeof(szValue), m_Path);

	// Read anything?
	if (szValue[0] == '\0')
		return bDefault;
		
	// Check first character.
	if (szValue[0] == 'T')
		return TRUE;
		
	return FALSE;
}
						
void CIniFile::WriteBool(const char* pszSection, const char* pszEntry, bool bValue)
{
	ASSERT(pszSection);
	ASSERT(pszEntry);

	if (bValue)
		WritePrivateProfileString(pszSection, pszEntry, "TRUE", m_Path);
	else
		WritePrivateProfileString(pszSection, pszEntry, "FALSE", m_Path);
}
