/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APP.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CApp class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "appwnd.hpp"

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

// "The" application object.
CApp App;

// The toolbar cmd table.
static uint aiCmds[] = {	ID_FILE_NEW,
							ID_FILE_OPEN,
							ID_FILE_SAVE,
							ID_SPACE,
							ID_EDIT_CUT,
							ID_EDIT_COPY,
							ID_EDIT_PASTE,
							ID_SPACE,
							ID_TOPIC_ADD,
							ID_TOPIC_EDIT,
							ID_TOPIC_DELETE,
							ID_SPACE,
							ID_PROJECT_BUILD,
							ID_PROJECT_TEST,
							0				};

/******************************************************************************
** Method:		Constructor
**
** Description:	Default constructor.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CApp::CApp(void)
{
}

/******************************************************************************
** Method:		Deconstructor
**
** Description:	Cleanup.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CApp::~CApp(void)
{
}


/******************************************************************************
** Method:		Initialise()
**
** Description:	This is the main initalisation routine for the application. It
**				is where the main window should be created and any other app
**				specific initialistion is done. This is the default for a
**				dialog based main window.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure
**
*******************************************************************************
*/

bool CApp::Initialise(void)
{
	// Initialise base classes.
	if (!CTask::Initialise())
		return FALSE;

	CPath	IniFile;
	
	// Create .ini file path.
	IniFile.Dir(CPath::AppDir);
	IniFile += "HFGEN.INI";
	m_Prefs.Path(IniFile);

	// Load settings.
	m_Prefs.Load();

	// Create main window.
	m_pAppWnd = new CAppWnd;
	if (!m_pAppWnd->Create())
		return FALSE;
	
	// Create toolbar.
	CToolBar* pToolBar = new CToolBar(*m_pAppWnd);
	if (!pToolBar->Create())
		return FALSE;

	// Set the toolbar commands.
	if (!pToolBar->Cmds(aiCmds))
		return FALSE;

	// Create info line.
	CStatusBar* pStatusBar = new CStatusBar(*m_pAppWnd);
	if (!pStatusBar->Create())
		return FALSE;

	// Link to main window.
	m_pAppWnd->ToolBar(pToolBar);
	m_pAppWnd->StatusBar(pStatusBar);
	
	// Show it.
	m_pAppWnd->Show(m_iCmdShow);
	AppWnd()->UpdateCmds();

	//Success
	return TRUE;
}

/******************************************************************************
** Method:		Terminate()
**
** Description:	This is the main termination routine for the application. All
**				application specific cleaning up should be done here.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure
**
*******************************************************************************
*/

bool CApp::Terminate(void)
{
	// Save settings.
	m_Prefs.Save();

	// Free up main window.
	if (m_pAppWnd)
		delete m_pAppWnd;

	// Cleanup base classes.
	return CTask::Terminate();
}
