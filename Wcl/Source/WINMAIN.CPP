/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WINMAIN.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Application entry point.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

CModule	Module;

/******************************************************************************
** Function: 	WinMain()
**
** Description:	This is the entry point to the Windows app.
**
** Parameters:	hCurrInst	The current instance.
**				hPrevInst	The previous instance (NULL if none).
**				lpszCmdLine	The command line.
**				iCmdShow	The initial state of the window.
**
** Returns:		TRUE		For a premature exit.
**				FALSE		For a normal exit.
**
*******************************************************************************
*/

extern "C" int PASCAL WinMain(HINSTANCE hCurrInst, HINSTANCE hPrevInst, 
								LPSTR lpszCmdLine, int iCmdShow)
{
	// Initialise the module.
	Module.Handle(hCurrInst);
	
	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);

	// Initialise app task members.
	pApp->Module(&Module);
	pApp->CmdLine(lpszCmdLine);
	pApp->CmdShow(iCmdShow);

	// Register custom controls.
	CTabCtrl::Register();

	// Initialise the app.
	if (!pApp->Initialise())
		PostQuitMessage(0);

	// Run the app.
	int iRetVal = pApp->MessageLoop();

	// App cleanup.
	pApp->Terminate();

	// Return WM_QUIT.wParam
	return iRetVal;
}
