/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PREFS.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CPrefs class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PREFS_HPP
#define PREFS_HPP

/******************************************************************************
** 
** This class is used to load and store the application settings.
**
*******************************************************************************
*/

class CPrefs
{
public:
	//
	// Constructors/Destructor.
	//
	CPrefs(void);
	~CPrefs(void);

	//
	// Member access.
	//
	const CPath& CompilerPath(void) const;

	void Path(const CPath& rPath);
	void CompilerPath(const CPath& rPath);

	//
	// Serialisation.
	//
	bool Load(void);
	bool Save(void);
	
protected:
	//
	// Members.
	//
	CIniFile	m_IniFile;			// Storage.
	bool		m_bModified;		// Dirty flag.
	CPath		m_CompilerPath;		// Path to the help compiler.
	
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline const CPath& CPrefs::CompilerPath(void) const
{
	return m_CompilerPath;
}

inline void CPrefs::Path(const CPath& rPath)
{
	m_IniFile.Path() = rPath;
}

inline void CPrefs::CompilerPath(const CPath& rPath)
{
	m_CompilerPath = rPath;
	m_bModified    = TRUE;
}

#endif //PREFS_HPP
