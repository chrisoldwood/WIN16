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
#include "addtpdlg.hpp"
#include "compdlg.hpp"
#include "projdlg.hpp"

// File extensions.
static char szHFExts[] = {	"HelpFiles (*.HF)\0*.HF\0"
							"All Files (*.*)\0*.*\0"
							"\0\0"						};

static char szRTFExts[] = {	"RTF Files (*.RTF)\0*.RTF\0"
							"All Files (*.*)\0*.*\0"
							"\0\0"						};

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
	static CmdMsg Cmds[] = {	ID_FILE_NEW,			(CmdMsgFn)OnFileNew,
								ID_FILE_OPEN,			(CmdMsgFn)OnFileOpen,
								ID_FILE_SAVE,			(CmdMsgFn)OnFileSave,
								ID_FILE_SAVE_AS,		(CmdMsgFn)OnFileSaveAs,
								ID_FILE_EXPORT,			(CmdMsgFn)OnFileExport,
								ID_FILE_EXIT,			(CmdMsgFn)OnFileExit,
								ID_EDIT_CUT,			(CmdMsgFn)OnEditCut,
								ID_EDIT_COPY,			(CmdMsgFn)OnEditCopy,
								ID_EDIT_PASTE,			(CmdMsgFn)OnEditPaste,
								ID_TOPIC_ADD,			(CmdMsgFn)OnTopicAdd,
								ID_TOPIC_EDIT,			(CmdMsgFn)OnTopicEdit,
								ID_TOPIC_DELETE,		(CmdMsgFn)OnTopicDelete,
								ID_PROJECT_SETTINGS,	(CmdMsgFn)OnProjectSettings,
								ID_PROJECT_BUILD,		(CmdMsgFn)OnProjectBuild,
								ID_PROJECT_TEST,		(CmdMsgFn)OnProjectTest,
								ID_OPTIONS_COMPILER,	(CmdMsgFn)OnOptionsCompiler,
								ID_HELP_ABOUT,			(CmdMsgFn)OnHelpAbout,
						 		0,						(CmdMsgFn)0           	};
	
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
** Method:		OnFileNew()
**
** Description:	Create a new blank document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileNew(void)
{
	// Close current document.
	OnQueryClose();

	// Create the document.
	CHelpDoc* pDoc = new CHelpDoc;
	if (!pDoc)
	{
		Alert("Not enough memory to create a new document");
		return;
	}

	// Create a view for the document.
	CAppView* pView = new CAppView(*this);
	if (!pView)
	{
		Alert("Not enough memory to create a document view");
		delete pDoc;
		return;
	}

	// Create the view window.
	if (!pView->Create())
	{
		Alert("Failed to create a document view");
		delete pDoc;
		delete pView;
		return;
	}

	// Setup App/Doc/View Links.
	App.Doc(pDoc);
	pDoc->View(pView);
	pView->Doc(pDoc);
	pView->Update();

	// Assign view to frame window.
	View(pView);
	
	// Update menu/toolbar.
	UpdateCmds();
	UpdateTitle();
}

/******************************************************************************
** Method:		OnFileOpen()
**
** Description:	Open a new document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileOpen(void)
{
	// Close current document.
	OnQueryClose();

	CPath	DocPath;

	// Get the filename
	if (!DocPath.Select(this, OF_READ, szHFExts, "HF"))
		return;

	// Create a new document.
	CHelpDoc* pDoc = new CHelpDoc(DocPath);
	if (!pDoc)
	{
		Alert("Not enough memory to create a new document");
		return;
	}

	// Report status.
	App.Busy(TRUE);
	m_pStatusBar->HintBar()->Hint("Opening...");
	
	// And load.
	if (!pDoc->Load())
	{
		delete pDoc;
		return;
	}

	// Report status.
	App.Busy(FALSE);
	m_pStatusBar->HintBar()->Hint("");

	// Create a view for the document.
	CAppView* pView = new CAppView(*this);
	if (!pView)
	{
		Alert("Not enough memory to create a document view");
		delete pDoc;
		return;
	}

	// Create the view window.
	if (!pView->Create())
	{
		Alert("Failed to create a document view");
		delete pDoc;
		delete pView;
		return;
	}

	// Setup App/Doc/View Links.
	App.Doc(pDoc);
	pDoc->View(pView);
	pView->Doc(pDoc);
	pView->Update();

	// Assign view to frame window.
	View(pView);
	
	// Update menu/toolbar.
	UpdateCmds();
	UpdateTitle();
}

/******************************************************************************
** Method:		OnFileSave()
**
** Description:	Save the document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileSave(void)
{
	// Get the document.
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);
	
	// Have a filename?
	if (pDoc->Untitled())
	{
		// Do a "Save As".
		OnFileSaveAs();
		return;
	}

	// Commit changes.
	m_pView->Commit();

	// Report status.
	App.Busy(TRUE);
	m_pStatusBar->HintBar()->Hint("Saving...");
	
	// Save the document.
	pDoc->Save();

	// Report status.
	App.Busy(FALSE);
	m_pStatusBar->HintBar()->Hint("Save completed");

	UpdateTitle();
}

/******************************************************************************
** Method:		OnFileSaveAs()
**
** Description:	Save the document to a different filename.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileSaveAs(void)
{
	CPath	DocPath;

	// Get the filename
	if (!DocPath.Select(this, OF_WRITE, szHFExts, "HF"))
		return;

	// File exists?
	if (DocPath.Exists())
	{
		// Notify user.
		if (Query("The following file already exists:\n\n"
					"%s\n\nDo you wish to overwrite it?",
					(const char *) DocPath) == IDNO)
		return;
	}

	// Get the doucment.
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);

	// Commit changes.
	m_pView->Commit();

	// Report status.
	App.Busy(TRUE);
	m_pStatusBar->HintBar()->Hint("Saving...");
	
	// Set the filename and save.
	pDoc->Path(DocPath);
	pDoc->Save();

	// Report status.
	App.Busy(FALSE);
	m_pStatusBar->HintBar()->Hint("Save completed");

	UpdateTitle();
}

/******************************************************************************
** Method:		OnExport()
**
** Description:	Export the helpfile to an .RTF file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnFileExport(void)
{
	CPath	DocPath;

	// Get the filename
	if (!DocPath.Select(this, OF_WRITE, szRTFExts, "RTF"))
		return;

	// File exists?
	if (DocPath.Exists())
	{
		// Notify user.
		if (Query("The following file already exists:\n\n"
					"%s\n\nDo you wish to overwrite it?",
					(const char *) DocPath) == IDNO)
		return;
	}

	// Get the doucment.
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);

	// Commit changes.
	m_pView->Commit();
	
	// Report status.
	App.Busy(TRUE);
	m_pStatusBar->HintBar()->Hint("Exporting...");
	
	// Export the documet.
	pDoc->WriteRTF(DocPath);

	// Report status.
	App.Busy(FALSE);
	m_pStatusBar->HintBar()->Hint("Export completed");
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

void CAppWnd::OnEditCut(void)
{
}

void CAppWnd::OnEditCopy(void)
{
}

void CAppWnd::OnEditPaste(void)
{
}

/******************************************************************************
** Method:		OnTopicAdd()
**
** Description:	Add a new topic to the document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnTopicAdd(void)
{
	CAddTopicDlg	Dlg(this);
	
	// Show the dialog.
	if (Dlg.RunModal() == IDOK)
	{
		// Allocate a new topic.
		CTopic* pTopic = new CTopic;
		if (!pTopic)
		{
			Alert("Not enough memory to create a new topic");
			return;
		}
		
		// Fill in details.
		pTopic->Name(Dlg.m_strName);
		pTopic->ContextName(Dlg.m_strContextName);
		pTopic->Keywords(Dlg.m_strKeywords);
		
		// Add to the doc.
		App.Doc()->TopicList().Add(pTopic);
		
		// Refresh the view.
		m_pView->Update();
	}
}

void CAppWnd::OnTopicEdit(void)
{
}

void CAppWnd::OnTopicDelete(void)
{
}

/******************************************************************************
** Method:		OnProjectSettings()
**
** Description:	Show the project settings dialog and update the document
**				properties.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnProjectSettings(void)
{
	CProjectDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
	}
}

/******************************************************************************
** Method:		OnProjectBuild()
**
** Description:	Export the document and run the compiler on it.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnProjectBuild(void)
{
	// Check compiler path.
	const CPath& strCompiler = App.Prefs().CompilerPath();
	if ( (strCompiler == "") || (!strCompiler.Exists()) )
	{
		Alert("You must set a valid path\nfor the help compiler first");
		OnOptionsCompiler();
		return;
	}

	// Get the document.
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);

	// Commit view changes.
	m_pView->Commit();
	
	// Have a filename?
	if (pDoc->Untitled())
	{
		// Force a save.
		Alert("You must save the project first");
		OnFileSaveAs();
		
		// Save cancelled?
		if (pDoc->Untitled())
			return;
	}

	// Report status.
	App.Busy(TRUE);
	m_pStatusBar->HintBar()->Hint("Building...");
	
	// Get document filename.
	CPath strFileName = pDoc->Path();
	
	// Write .HPJ project file.
	strFileName.Extension("HPJ");
	if (!pDoc->WriteHPJ(strFileName))
		return;
	
	// Write .RTF project text.
	strFileName.Extension("RTF");
	if (!pDoc->WriteRTF(strFileName))
		return;

	// Write .BAT build file.
	strFileName.Extension("BAT");
	if (!pDoc->WriteBAT(strFileName))
		return;

	// Run the build file.
	WinExec(strFileName, SW_SHOW);

	// Report status.
	App.Busy(FALSE);
	m_pStatusBar->HintBar()->Hint("Build completed");
}

/******************************************************************************
** Method:		OnProjectTest()
**
** Description:	Run the helpfile if it exists.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnProjectTest(void)
{
	// Get the document.
	CHelpDoc* pDoc = App.Doc();
	ASSERT(pDoc);
	
	// Have a filename?
	if (pDoc->Untitled())
	{
		Alert("You must build the project first");
		return;
	}

	// Create the target filename.
	CPath strFileName = pDoc->Path();
	strFileName.Extension("HLP");
	
	// Check it exists.
	if (!strFileName.Exists())
	{
		Alert("The target file does not exist:\n\n%s\n\nHave you built it?",
				(const char*) strFileName);
		return;
	}

	// Build up the winhelp command line.
	CString	strCmdLine("WinHelp.exe ");
	strCmdLine += strFileName;
	
	// Launch the help file.
	WinExec(strCmdLine, SW_SHOW);
}

/******************************************************************************
** Method:		OnOptionsCompiler()
**
** Description:	Show the compiler settings dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnOptionsCompiler(void)
{
	CCompilerDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		App.Prefs().CompilerPath(Dlg.m_strFileName);
	}
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

/******************************************************************************
** Method:		UpdateCmds().
**
** Description:	Update the menu and toolbar comands.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::UpdateCmds(void)
{
	// Always available.
	EnableCmd(ID_FILE_NEW);
	EnableCmd(ID_FILE_OPEN);
	EnableCmd(ID_FILE_EXIT);
	EnableCmd(ID_OPTIONS_COMPILER);
	EnableCmd(ID_HELP_ABOUT);
	
	// Have a doc?
	if (App.Doc())
	{
		EnableCmd(ID_FILE_SAVE);
		EnableCmd(ID_FILE_SAVE_AS);
		EnableCmd(ID_FILE_EXPORT);
		EnableCmd(ID_TOPIC_ADD);
		EnableCmd(ID_PROJECT_SETTINGS);
		EnableCmd(ID_PROJECT_BUILD);
		EnableCmd(ID_PROJECT_TEST);
	}
	else
	{
		DisableCmd(ID_FILE_SAVE);
		DisableCmd(ID_FILE_SAVE_AS);
		DisableCmd(ID_FILE_EXPORT);
		DisableCmd(ID_TOPIC_ADD);
		DisableCmd(ID_PROJECT_SETTINGS);
		DisableCmd(ID_PROJECT_BUILD);
		DisableCmd(ID_PROJECT_TEST);
	}

	// Not implemented yet.
	DisableCmd(ID_TOPIC_EDIT);
	DisableCmd(ID_TOPIC_DELETE);
	DisableCmd(ID_EDIT_CUT);
	DisableCmd(ID_EDIT_COPY);
	DisableCmd(ID_EDIT_PASTE);
}

/******************************************************************************
** Method:		OnQueryClose()
**
** Description:	Save the data, if modified.
**
** Parameters:	None.
**
** Returns:		TRUE	If it can.
**				FALSE	If it cannot.
**
*******************************************************************************
*/

bool CAppWnd::OnQueryClose(void)
{
	// Get view window and doc.
	CView*		pView = View();
	CHelpDoc*	pDoc = App.Doc();
	
	// Doc modified?
	if ( (pDoc) && (pDoc->Modified()) )
	{
		// Check to save changes.
		int iRes = QueryEx("Would you like to save the changes?");
		
		if (iRes == IDCANCEL)
			return FALSE;

		if (iRes == IDYES)
			OnFileSave();
	}
	
	// View open?
	if (pView)
	{
		// Unlink from frame.
		View(NULL);

		// Destroy view.
		pView->Destroy();
		delete pView;
	}
	
	// Doc open?
	if (pDoc)
	{
		// Unlink from app.
		App.Doc(NULL);

		// Destroy doc.
		pDoc->View(NULL);
		delete pDoc;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		UpdateTitle()
**
** Description:	Update the windows title to show the current document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::UpdateTitle(void)
{
	CString	strTitle;
	
	// Get app name.
	strTitle.LoadRsc(IDS_APP_TITLE);
	
	// Document open?
	CHelpDoc* pDoc = App.Doc();
	if (pDoc)
	{
		// Append file title.
		strTitle += " [";
		strTitle += pDoc->Path().FileTitle();
		strTitle += "]";
	}
	
	Title(strTitle);
}
