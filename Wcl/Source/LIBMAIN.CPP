/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LIBMAIN.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	DLL entry/exit point.
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

//CModule	Module;

/******************************************************************************
** Function: 	LibMain()
**
** Description:	This is the entry point when a DLL is loaded.
**
** Parameters:	hInst		The DLLs instance.
**				wDataSeg	The data segment selector.
**				cbHeapSize	The size of the DLLs heap.
**				lpszCmdLine	Unused.
**
** Returns:		TRUE		If initialised okay.
**				FALSE		On error.
**
*******************************************************************************
*/

extern "C" int CALLBACK LibMain(HINSTANCE hInst, WORD wDataSeg, WORD cbHeapSize, 
						LPSTR lpszCmdLine)
{
	// Initialise the module.
//	Module.Handle(hInst);

    // Success
	return TRUE;
}

/******************************************************************************
** Function: 	_WEP()
**
** Description:	This is the exit point when a DLL is unloaded. It is called by
**				the C-Runtime WEP which does destruction of static C++ objects.
**
** Parameters:	nExitCode	Reason for unloading.
**
** Returns:		TRUE		Always.
**
*******************************************************************************
*/

extern "C" int CALLBACK _WEP(int nExitCode)
{   
	// Success
	return TRUE;
}
