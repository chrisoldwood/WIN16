/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PATH.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CPath class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <stdlib.h>
#include <io.h>
#include <direct.h>
#include <commdlg.h>

/******************************************************************************
** Method:		Constructor
**
** Description:	Default constructor. Initialise base class.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPath::CPath(void)
{
	BufferSize(MAX_PATH);
	
	// Ensure NUL string.
	m_pszBuffer[0] = '\0';
}

/******************************************************************************
** Method:		Constructor
**
** Description:	Construction with common root path specified.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

inline CPath::CPath(RootDirs eRootDir)
{
	BufferSize(MAX_PATH);

	Dir(eRootDir);
}

/******************************************************************************
** Method:		Exists()
**
** Description:	Determine if the path to a file or directory actually exists.
**
** Parameters:	None.
**
** Returns:		TRUE	If exists.
**				FALSE	If not.
**
*******************************************************************************
*/

bool CPath::Exists(void) const
{
	if (_access(m_pszBuffer, 0) == 0)
		return TRUE;
		
	return FALSE;
}

/******************************************************************************
** Method:		ReadOnly()
**
** Description:	Determine if a file or directory is read-only.
**
** Parameters:	None.
**
** Returns:		TRUE	If exists.
**				FALSE	If not.
**
*******************************************************************************
*/

bool CPath::ReadOnly(void) const
{
	if (_access(m_pszBuffer, 02) == 0)
		return FALSE;
		
	return TRUE;
}

/******************************************************************************
** Method:		Dir()
**
** Description:	Set the paths' directory by using one of the standard ones.
**
** Parameters:	eRootDir	Flag to determine which directory to use.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::Dir(RootDirs eRootDir)
{
	char* pszPath = m_pszBuffer;

	// Source?
	switch(eRootDir)
	{
		// Get the current working directory.
		case CurrentDir:
			{
				_getcwd(m_pszBuffer, m_iSize);
			}
			break;
		
		// Get the applications' directory.
		case AppDir:
			{
				// Get application object.
				CTask* pApp = CTask::This();
				ASSERT(pApp);
				
				Copy(pApp->Module()->Path());
				StripFileName();
			}
			break;
		
		// Get the Windows directory.
		case WindowsDir:
			{
				GetWindowsDirectory(m_pszBuffer, m_iSize);
			}
			break;
			
		// Get the Windows SYSTEM directory.
		case SystemDir:
			{
				GetWindowsDirectory(m_pszBuffer, m_iSize);
				*this += "SYSTEM";
			}
			break;

		// Get the temporary directory.
		case TempDir:
			{
				char* pszTempDir = getenv("TEMP");
				
				// User defined TEMP?
				if (pszTempDir)
				{
					// Use that directory.
					lstrcpy(m_pszBuffer, pszTempDir);
				}
				else
				{
					// Use the Windows directory.
					GetWindowsDirectory(m_pszBuffer, m_iSize);
				}
			}
			break;
			
		default:
			ASSERT(FALSE);
			break;
	}
	
	// Find the end of the path.
	while (*pszPath)
		pszPath++;
	
	// Back to last char.
	pszPath--;
	
	// Trailing slash?
	if (*pszPath == '\\')
	{
		// Remove it.
		*pszPath = '\0';
	}
}

/******************************************************************************
** Method:		Dir()
**
** Description:	Set the paths' directory from a string.
**
** Parameters:	pszDir		The path to use.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::Dir(const char* pszDir)
{
	Copy(pszDir, lstrlen(pszDir));
}

/******************************************************************************
** Method:		Dir()
**
** Description:	Get the directory from the full path. This assumes that the
**				last part of the path name specifies a file and as such only
**				copies the path up to the last entry.
**
** Parameters:	None.
**
** Returns:		The directory as a path.
**
*******************************************************************************
*/

CPath CPath::Dir(void) const
{
	CPath pathDir(m_pszBuffer);
	
	pathDir.StripFileName();

	return pathDir;
}

/******************************************************************************
** Method:		operator+=()
**
** Description:	Append a path to the path.
**
** Parameters:	pszPath		The path.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::operator+=(const char* pszPath)
{
	ASSERT(pszPath);
	
	lstrcat(m_pszBuffer, "\\");
	lstrcat(m_pszBuffer, pszPath);
}

/******************************************************************************
** Method:		StripFileName()
**
** Description:	Strip the filename from the path.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::StripFileName(void)
{
	// Find last backslash.
	char* pcLastSlash = strrchr(m_pszBuffer, '\\');
	
	// Found one?
	if (pcLastSlash)
	{
		// Change to NUL terminator.
		*pcLastSlash = '\0';
	}
	else
	{
		// No directory.
		m_pszBuffer[0] = '\0';
	}
}

/******************************************************************************
** Method:		StripExtension()
**
** Description:	Strip the extension from the filename.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::StripExtension(void)
{
	char* pszPath = m_pszBuffer;

	// Find the end of the path.
	while (*pszPath)
		pszPath++;
		
	// Walk back looking for a .
	while ( (pszPath > m_pszBuffer) && (*pszPath != '\\') )
	{
		// Found it?
		if (*pszPath == '.')
		{
			*pszPath = '\0';
			return;
		}
		
		// Move back 1 char.
		pszPath--;
	}
}

/******************************************************************************
** Method:		FileName()
**
** Description:	Get just the filename from the path.
**
** Parameters:	None.
**
** Returns:		The filename as a path.
**
*******************************************************************************
*/

CPath CPath::FileName(void) const
{
	CPath pathFile;
	
	// Find last backslash.
	char* pcLastSlash = strrchr(m_pszBuffer, '\\');
	
	// Found one?
	if (pcLastSlash)
	{
		// Copy from \ onwards.
		pcLastSlash++;
		pathFile = pcLastSlash;
	}
	else
	{
		// Copy whole buffer.
		pathFile = m_pszBuffer;
	}
	
	return pathFile;
}

/******************************************************************************
** Method:		FileTitle()
**
** Description:	Get just the filename without the path or extension.
**
** Parameters:	None.
**
** Returns:		The file title as a path.
**
*******************************************************************************
*/

CPath CPath::FileTitle(void) const
{
	CPath strTitle = FileName();
	strTitle.StripExtension();

	return strTitle;
}

/******************************************************************************
** Method:		Extension()
**
** Description:	Set the extension of the filename. The extension should not
**				contain the period.
**
** Parameters:	pszExt	The new extension.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPath::Extension(const char* pszExt)
{
	// Remove old extension first.
	StripExtension();
	
	// Apply new extension.
	strcat(m_pszBuffer, ".");
	strcat(m_pszBuffer, pszExt);
}

/******************************************************************************
** Method:		Select()
**
** Description:	Get a filename by using the common file open dialog.
**
** Parameters:	pParent		The dialogs parent.
**				iMode		OF_READ or OF_WRITE.
**				pszExts		File extensions.
**				pszDefExt	Default file extension.
**				pszDir		Initial directory.
**
** Returns:		TRUE	If user pressed OK.
**				FALSE	If user pressed Cancel.
**
*******************************************************************************
*/

bool CPath::Select(const CWnd* pParent, int iMode, const char* pszExts,
					const char* pszDefExt, const char* pszDir)
{
	bool 			bOkay;
	OPENFILENAME	ofnFile;
	char			szFileName[MAX_PATH];

    ASSERT(pParent);
	ASSERT( (iMode == OF_READ) || (iMode == OF_WRITE) || (iMode == OF_SELECT));

	// Initialise filename.
	szFileName[0] = '\0';

    // Fill in structure.
	ofnFile.lStructSize       = sizeof(OPENFILENAME);
	ofnFile.hwndOwner         = pParent->Handle();
	ofnFile.hInstance         = NULL;
	ofnFile.lpstrFilter       = pszExts;
	ofnFile.lpstrCustomFilter = NULL;
	ofnFile.nMaxCustFilter    = NULL;
	ofnFile.nFilterIndex      = NULL;
	ofnFile.lpstrFile         = szFileName;
	ofnFile.nMaxFile          = MAX_PATH;
	ofnFile.lpstrFileTitle    = NULL;
	ofnFile.nMaxFileTitle     = NULL;
	ofnFile.lpstrInitialDir   = pszDir;
	ofnFile.lpstrTitle        = NULL;
	ofnFile.Flags             = OFN_PATHMUSTEXIST;
	ofnFile.nFileOffset       = NULL;
	ofnFile.nFileExtension    = NULL;
	ofnFile.lpstrDefExt       = pszDefExt;
	ofnFile.lCustData         = NULL;
	ofnFile.lpfnHook          = NULL;
	ofnFile.lpTemplateName    = NULL;
	
	// Get the filename.
	if (iMode == OF_READ)
	{
		ofnFile.Flags |= OFN_FILEMUSTEXIST;
		bOkay = GetOpenFileName(&ofnFile);
	}
	else if (iMode == OF_WRITE)
	{
		bOkay = GetSaveFileName(&ofnFile);
	}
	else // OF_SELECT
	{
		ofnFile.lpstrTitle = "Select";
		bOkay = GetOpenFileName(&ofnFile);
	}
	
	// Error or cancel?
	if (!bOkay)
		return FALSE;
		
	// Save filename.
	Copy(szFileName);
	
	return TRUE;
}
