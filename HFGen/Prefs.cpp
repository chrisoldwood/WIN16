/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PREFS.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CPrefs class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrefs::CPrefs(void)
{
	m_bModified = FALSE;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrefs::~CPrefs(void)
{
}

/******************************************************************************
** Method:		Load()
**
** Description:	Load the settings from the .ini file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

bool CPrefs::Load(void)
{
	m_IniFile.ReadString("Compiler", "Path", "", m_CompilerPath.Buffer(), MAX_PATH);

	// Reset dirty flag.
	m_bModified = FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Save()
**
** Description:	Save the settings to the .ini file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

bool CPrefs::Save(void)
{
	// Any changes?
	if (m_bModified)
	{
		m_IniFile.WriteString("Compiler", "Path", m_CompilerPath);
	}

	// Reset dirty flag.
	m_bModified = FALSE;

	return TRUE;
}
