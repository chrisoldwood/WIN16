/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CTL3D.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CCtl3d class methods.
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

CCtl3d::CCtl3d(void)
{
	m_lpfnCtl3dRegister     = NULL;
	m_lpfnCtl3dAutoSubclass = NULL;
	m_lpfnCtl3dUnregister   = NULL;
}

/******************************************************************************
** Method:		Load()
**
** Description:	Loads the module and gets the main function entry points.
**
** Parameters:	None.
**
** Returns:		TRUE on success.
**				FALSE on failure.
**
*******************************************************************************
*/

bool CCtl3d::Load(void)
{
	// Load the DLL.
	if (!CModule::Load())
		return FALSE;

	// Get function pointers.
	m_lpfnCtl3dRegister     = (LPFNCTL3DREGISTER)     GetProcAddress(m_hInstance, "Ctl3dRegister");
	m_lpfnCtl3dAutoSubclass = (LPFNCTL3DAUTOSUBCLASS) GetProcAddress(m_hInstance, "Ctl3dAutoSubclass");
	m_lpfnCtl3dUnregister   = (LPFNCTL3DUNREGISTER)   GetProcAddress(m_hInstance, "Ctl3dUnregister");
	
	ASSERT(m_lpfnCtl3dRegister);
	ASSERT(m_lpfnCtl3dAutoSubclass);
	ASSERT(m_lpfnCtl3dUnregister);
	
	return TRUE;
}
