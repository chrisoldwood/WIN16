/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MODULE.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CModule class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default Constructor
**
** Description:	Resets its members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CModule::CModule(void)
{
	m_hInstance = NULL;
}

/******************************************************************************
** Method:		Deconstructor
**
** Description:	Check reasources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CModule::~CModule(void)
{
}

/******************************************************************************
** Method:		FindResource()
**
** Description:	Attempts to locate the specified resource.
**
** Parameters:	iID 		The ID of the resource
**				lpszType	The resource type.
**
** Returns:		TRUE		On success.
**				FALSE		On Failure.
**
*******************************************************************************
*/

bool CModule::FindResource(uint iID, LPCSTR lpszType) const
{
	ASSERT(lpszType);
	
	if (::FindResource(m_hInstance, MAKEINTRESOURCE(iID), lpszType))
		return TRUE;
		
	return FALSE;
}

/******************************************************************************
** Method:		LoadAccel()
**
** Description:	Loads a keyboard accelerator table.
**
** Parameters:	iID 		The ID of the resource
**
** Returns:		HANDLE		The handle to the table.
**				NULL		On failure.
**
*******************************************************************************
*/

HACCEL CModule::LoadAccel(uint iID) const
{
	// Try and load it.
	HACCEL	hAccel = ::LoadAccelerators(m_hInstance, MAKEINTRESOURCE(iID));
	
#ifdef _DEBUG
	// Okay?
	if (!hAccel)
	{
		TRACE1("LoadAccel() failed for: %d\n", iID);
		ASSERT(FALSE);
	}
#endif

	return hAccel;
}

/******************************************************************************
** Method:		LoadBitmap()
**
** Description:	Loads a device dependant bitmap.
**
** Parameters:	iID 		The ID of the resource
**
** Returns:		HANDLE		The handle to the bitmap.
**				NULL		On failure.
**
*******************************************************************************
*/

HBITMAP CModule::LoadBitmap(uint iID) const
{
	// Try and load it.
	HBITMAP	hBitmap = ::LoadBitmap(m_hInstance, MAKEINTRESOURCE(iID));
	
#ifdef _DEBUG
	// Okay?
	if (!hBitmap)
	{
		TRACE1("LoadBitmap() failed for: %d\n", iID);
		ASSERT(FALSE);
	}
#endif

	return hBitmap;
}

/******************************************************************************
** Method:		LoadCursor()
**
** Description:	Loads a cursor.
**
** Parameters:	iID 		The ID of the resource
**
** Returns:		HANDLE		The handle to the cursor.
**				NULL		On failure.
**
*******************************************************************************
*/

HCURSOR CModule::LoadCursor(uint iID) const
{
	// Try and load it.
	HCURSOR	hCursor = ::LoadCursor(m_hInstance, MAKEINTRESOURCE(iID));
	
#ifdef _DEBUG
	// Okay?
	if (!hCursor)
	{
		TRACE1("LoadCursor() failed for: %d\n", iID);
		ASSERT(FALSE);
	}
#endif

	return hCursor;
}

/******************************************************************************
** Method:		LoadStdCursor()
**
** Description:	Loads one of the standard Windows cursors.
**
** Parameters:	lID			The resource ID from MAKEINTRESOURCE().
**
** Returns:		HANDLE		The handle to the cursor.
**				NULL		On failure.
**
*******************************************************************************
*/

HCURSOR CModule::LoadStdCursor(LPCSTR lID) const
{
	ASSERT(lID);

	// Try and load it.
	HCURSOR	hCursor = ::LoadCursor(NULL, lID);
	
#ifdef _DEBUG
	// Okay?
	if (!hCursor)
	{
		TRACE1("LoadStdCursor() failed for: %ld\n", lID);
		ASSERT(FALSE);
	}
#endif

	return hCursor;
}

/******************************************************************************
** Method:		LoadIcon()
**
** Description:	Loads an icon.
**
** Parameters:	iID 		The ID of the resource
**
** Returns:		HANDLE		The handle to the icon.
**				NULL		On failure.
**
*******************************************************************************
*/

HICON CModule::LoadIcon(uint iID) const
{
	// Try and load it.
	HICON	hIcon = ::LoadIcon(m_hInstance, MAKEINTRESOURCE(iID));
	
#ifdef _DEBUG
	// Okay?
	if (!hIcon)
	{
		TRACE1("LoadIcon() failed for: %d\n", iID);
		ASSERT(FALSE);
	}
#endif

	return hIcon;
}

/******************************************************************************
** Method:		LoadMenu()
**
** Description:	Loads a menu.
**
** Parameters:	iID 		The ID of the resource
**
** Returns:		HANDLE		The handle to the menu.
**				NULL		On failure.
**
*******************************************************************************
*/

HMENU CModule::LoadMenu(uint iID) const
{
	// Try and load it.
	HMENU	hMenu = ::LoadMenu(m_hInstance, MAKEINTRESOURCE(iID));
	
#ifdef _DEBUG
	// Okay?
	if (!hMenu)
	{
		TRACE1("LoadMenu() failed for: %d\n", iID);
		ASSERT(FALSE);
	}
#endif

	return hMenu;
}

/******************************************************************************
** Method:		StringLength()
**
** Description:	Finds the length of a resource string. If the string does not
**				exist it returns a value that can hold the string ID.
**
** Parameters:	iID			The resource ID.
**
** Returns:		The string length.
**
*******************************************************************************
*/

uint CModule::StringLength(uint iID) const
{
	char szTemp[128];

	// Try and load into temp buffer.
	int iLength = ::LoadString(m_hInstance, iID, szTemp, 128);

	// Exists?
	if (!iLength)
		iLength = 15;

	return iLength;
}

/******************************************************************************
** Method:		LoadString()
**
** Description:	Loads a string into the specfied buffer. If the string does not
**				exist it returns the ID of the resource.
**
** Parameters:	iID			The resource ID.
**				pszBuffer	The return buffer.
**				iSize		The size of the buffer.
**
** Returns:		A pointer to the return buffer.
**
*******************************************************************************
*/

const char* CModule::LoadString(uint iID, char* pszBuffer, uint iSize) const
{
	ASSERT(pszBuffer);
	ASSERT(iSize);

	// Try and load it.
	bool	bLoaded = ::LoadString(m_hInstance, iID, pszBuffer, iSize);
	
	// Okay?
	if (!bLoaded)
	{
		TRACE1("LoadString() failed for: %u\n", iID);
		
		// Create dummy string from ID.
		wsprintf((LPSTR)pszBuffer, (LPCSTR)"#%u", iID);
	}

	return pszBuffer;
}

/******************************************************************************
** Method:		Path()
**
** Description:	Gets the full pathname of the module.
**
** Parameters:	None.
**
** Returns:		The path.
**
*******************************************************************************
*/

CPath& CModule::Path(void)
{
	GetModuleFileName(m_hInstance, m_Path.Buffer(), m_Path.BufferSize());
	
	return m_Path;
}

/******************************************************************************
** Method:		Load()
**
** Description:	Loads the module.
**
** Parameters:	None.
**
** Returns:		TRUE on success.
**				FALSE on failure.
**
*******************************************************************************
*/

bool CModule::Load(void)
{
	m_hInstance = LoadLibrary(m_Path);

#ifdef WIN16
	if (m_hInstance < HINSTANCE_ERROR)
#else
	if (!m_hInstance)
#endif
	{
		m_hInstance = NULL;
		return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		Free()
**
** Description:	Unload the module.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CModule::Free(void)
{
	if (m_hInstance)
	{
		FreeLibrary(m_hInstance);
		m_hInstance = NULL;
	}
}
