/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPWND.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAppWnd class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "aboutdlg.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CAppWnd::CAppWnd(void)
{
	// Define the command table.
	static CmdMsg Cmds[] = {	ID_FILE_EXIT,	(CmdMsgFn)OnFileExit,
								ID_HELP_ABOUT,	(CmdMsgFn)OnHelpAbout,
						 		0,				(CmdMsgFn)0           };
	
	CmdMsgTable(Cmds);
}

/******************************************************************************
** Method:		Destructor.
**
** Description:	Free up any resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CAppWnd::~CAppWnd(void)
{
}

/******************************************************************************
** Method:		OnFileExit()
**
** Description:	Terminate the app.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileExit(void)
{
	Close();
}

/******************************************************************************
** Method:		OnHelpAbout()
**
** Description:	Show the about dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnHelpAbout(void)
{
	CAboutDlg	Dlg(this);
	
	Dlg.RunModal();
}
