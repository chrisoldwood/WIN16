/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PATH.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CPath class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PATH_HPP
#define PATH_HPP

// For the dialog.
class CWnd;

/******************************************************************************
**
** File name and path constants.
**
*******************************************************************************
*/

#define FILE_NAME_LEN	8		// Length of files' name.
#define FILE_EXT_LEN	3		// Length of files' extension.
#define MAX_FILENAME	12		// Maximum length of full filename.

#ifdef WIN16
#define MAX_PATH		128		// Maximim length of path (inc. filename).
#endif

#define OF_SELECT		0x0004	// Used with Select() to set the open filename
								// title to Select instead of Open or Save As.

/******************************************************************************
** 
** A path is a string derived class that is used to manipulate filenames and
** directory paths.
**
*******************************************************************************
*/

WCLCLASS CPath : public CString
{
public:
	//
	// Common path root directories.
	//
	enum RootDirs
	{
		CurrentDir,		// Current working directory.
		AppDir,			// App directory.
		WindowsDir,		// Windows directory.
		SystemDir,		// Windows system directory.
		TempDir			// Temporary directory.
	};

	//
	// Constructors/Destructor.
	//
	CPath(void);
    CPath(RootDirs eRootDir);
    CPath(const char* pszPath);
	CPath(const CPath& pathSrc);
    
	//
	// Attributes.
	//
    bool Exists(void) const;
    bool ReadOnly(void) const;

	//
	// Directory.
	//
	void Dir(RootDirs eRootDir);
	void Dir(const char* pszDir);
	CPath Dir(void) const;

	//
	// Filename.
	//
	void StripFileName(void);
	void StripExtension(void);
	CPath FileName(void) const;
	CPath FileTitle(void) const;
	void Extension(const char* pszExt);
	bool Select(const CWnd* pParent, int iMode, const char* pszExts,
				const char* pszDefExt, const char* pszDir = NULL);

	//
	// Operators.
	//
	CPath& operator=(const CString& rSrc);
#ifdef M_I86MM
	// Medium memory model only.
	const CPath& operator=(const char* pszBuffer);
#endif
	const CPath& operator=(LPCSTR lpszBuffer);
	
	void operator+=(const char* pszPath);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CPath::CPath(const char* pszPath)
{
	Copy(pszPath);
}

inline CPath::CPath(const CPath& pathSrc)
{
	Copy(pathSrc.m_pszBuffer);
}

inline CPath& CPath::operator=(const CString& rSrc)
{
	Copy(rSrc.m_pszBuffer);
	return *this;
}

//
// Only for Medium memory model.
//
#ifdef M_I86MM

inline const CPath& CPath::operator=(const char* pszBuffer)
{
	ASSERT(pszBuffer);

	Copy(pszBuffer);
	return *this;
}

#endif //M_I86MM

inline const CPath& CPath::operator=(LPCSTR lpszBuffer)
{
	ASSERT(lpszBuffer);

	Copy(lpszBuffer);
	return *this;
}

#endif //PATH_HPP
