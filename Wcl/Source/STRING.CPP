/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		STRING.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CString class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default Constructor.
**
** Description:	Initialise all members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CString::CString(void)
{
	m_pszBuffer = NULL;
	m_iSize     = 0;
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Makes a copy of the string.
**
** Parameters:	pszBuffer	The source string.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CString::CString(const char* pszBuffer)
{
	m_pszBuffer = NULL;
	m_iSize     = 0;

	Copy(pszBuffer, lstrlen(pszBuffer));
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Makes a copy of the string.
**
** Parameters:	strSrc	The source string.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CString::CString(const CString& strSrc)
{
	m_pszBuffer = NULL;
	m_iSize     = 0;

	Copy(strSrc.m_pszBuffer, strSrc.Length());
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Free resources
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CString::~CString(void)
{
	Free();
}

/******************************************************************************
** Method:		LoadRsc()
**
** Description:	Loads a string from the resource file and copies it to the
**				internal buffer.
**
** Parameters:	iID		The resource ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CString::LoadRsc(uint iID)
{
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Load resource.
	BufferSize(pApp->Module()->StringLength(iID));
	pApp->Module()->LoadString(iID, m_pszBuffer, m_iSize+1);
}

/******************************************************************************
** Method:		BufferSize()
**
** Description:	Ensure enough space is allocated for the string.
**
** Parameters:	iSize
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CString::BufferSize(uint iSize)
{
	// Big enough?
	if (m_iSize >= (iSize+1))
		return;
	
	Free();
	
	// Allocate new buffer.
	m_pszBuffer  = new char[iSize+1];
	
	ASSERT(m_pszBuffer);

	*m_pszBuffer = '\0';
	m_iSize      = (uint16)iSize;
}

/******************************************************************************
** Method:		Copy()
**
** Description:	Allocates space for and copies the string. The parameter is a
**				FAR pointer so that this function can work for either PSTRs
**				or LPSTRs.
**
** Parameters:	lpszBuffer	The source string.
**				iChars		The number of chars to copy.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CString::Copy(const char FAR* lpszBuffer, uint iChars)
{
	ASSERT(lpszBuffer);

	BufferSize(lstrlen(lpszBuffer)+1);

	ASSERT(lstrlen(lpszBuffer) < (int)m_iSize);
	
	// Copy.
	lstrcpy(m_pszBuffer, lpszBuffer);
}

/******************************************************************************
** Method:		Free()
**
** Description:	Free up the memory used by the string. This is used internally
**				to ensure there is no memory used by the library when the
**				memory checking functions are called.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CString::Free(void)
{
	if (m_pszBuffer)
		delete []m_pszBuffer;
	
	m_pszBuffer = NULL;
	m_iSize     = 0;
}

/******************************************************************************
** Method:		Read
**
** Description:	Load the string in from a file. This reads the buffer size,
**				allocates the space and reads the whole string.
**
** Parameters:	rFile	A reference to the file.
**
** Returns:		TRUE  if successful
**				FALSE if not.
**
*******************************************************************************
*/

bool CString::Read(CFile& rFile)
{
	if (!rFile.Read(m_iSize))
		return FALSE;

	BufferSize(m_iSize);
	
	if (!rFile.Read(m_pszBuffer, m_iSize))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Write
**
** Description:	Save the string out to a file. This stores the size of the
**				buffer followed by the buffer.
**
** Parameters:	rFile	A reference to the file.
**
** Returns:		TRUE  if successful
**				FALSE if not.
**
*******************************************************************************
*/

bool CString::Write(CFile& rFile) const
{
	if (!rFile.Write(m_iSize))
		return FALSE;
		
	if (!rFile.Write(m_pszBuffer, m_iSize))
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		Operator +=()
**
** Description:	Concatenate the supplied string onto the existing one. Growing
**				the buffer if necessary.
**
** Parameters:	rFile	A reference to the file.
**
** Returns:		TRUE  if successful
**				FALSE if not.
**
*******************************************************************************
*/

void CString::operator +=(const char* pszString)
{
	ASSERT(m_pszBuffer);
	ASSERT(pszString);

	uint iStrLen = Length();
	uint iParamLen = strlen(pszString);
	
	// Buffer big enough?
	if (m_iSize >= (iStrLen+iParamLen+1))
	{
		// Just append.
		strcat(m_pszBuffer, pszString);
	}
	else
	{
		// Save old string.
		char* pszOldBuffer = m_pszBuffer;
		
		// Allocate a new buffer.
		m_iSize     = (uint16)(iStrLen+iParamLen+1);
		m_pszBuffer = new char[m_iSize];
		ASSERT(m_pszBuffer);
		
		// Copy old string and cat new one.
		strcpy(m_pszBuffer, pszOldBuffer);
		strcat(m_pszBuffer, pszString);
		
		// delete old buffer.
		delete []pszOldBuffer;
	}
}
