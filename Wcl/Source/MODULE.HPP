/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MODULE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CModule class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MODULE_HPP
#define MODULE_HPP

/******************************************************************************
** 
** Class that defines the behaviour of an application component such as the
** .exe or .dll. It provides methods to load resources.
**
*******************************************************************************
*/

WCLCLASS CModule
{
public:
	//
	// Constructors/Destructor.
	//
	CModule(void);
	~CModule(void);

	bool Load(void);
	void Free(void);
	
	//
	// Member access.
	//
	void Handle(HINSTANCE hInst);
	HINSTANCE Handle(void) const;
	CPath& Path(void);

	//
	// Resource methods.
	//
	bool FindResource(uint iID, LPCSTR lpszType) const;
	HACCEL LoadAccel(uint iID) const;
	HBITMAP LoadBitmap(uint iID) const;
	HCURSOR LoadCursor(uint iID) const;
	HCURSOR LoadStdCursor(LPCSTR lpszName) const;
	HICON LoadIcon(uint iID) const;
	HMENU LoadMenu(uint iID) const;
	uint StringLength(uint iID) const;
	const char* LoadString(uint iID, char* pszBuffer, uint iSize) const;

protected:
	//
	// Members
	//
	HINSTANCE	m_hInstance;
	CPath		m_Path;
};

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

extern CModule	Module;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CModule::Handle(HINSTANCE hInst)
{
	m_hInstance = hInst;
}

inline HINSTANCE CModule::Handle(void) const
{
	return m_hInstance;
}

#endif //MODULE_HPP
