/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ACCEL.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CAccel class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		LoadRsc()
**
** Description:	Loads an accelerator table from the resource file.
**
** Parameters:	iID		The resource ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAccel::LoadRsc(uint iID)
{
	ASSERT(m_hAccel == NULL);

	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);
	
	// Load the resource.
	m_hAccel = pApp->Module()->LoadAccel(iID);
}

/******************************************************************************
** Method:		Translate()
**
** Description:	Attempts to translate an accelerator keystroke.
**
** Parameters:	hWnd	The message window destination.
**				pMsg	The message.
**
** Returns:		TRUE if processed.
**				FALSE if not.
**
*******************************************************************************
*/

bool CAccel::Translate(HWND hWnd, MSG* pMsg)
{
	// Table loaded?
	if (m_hAccel)
	{
		// Attempt to translate it.
		if (TranslateAccelerator(hWnd, m_hAccel, pMsg))
			return TRUE;
	}
	
	return FALSE;
}
