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
#include "clkindlg.hpp"
#include "clkotdlg.hpp"
#include "swtskdlg.hpp"
#include "edtsndlg.hpp"
#include "prsesdlg.hpp"
#include "prtskdlg.hpp"
#include "exprtdlg.hpp"
#include "printdlg.hpp"

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
	static CmdMsg Cmds[] = {	ID_FILE_EXPORT,				(CmdMsgFn) OnExport,
								ID_FILE_PRINT,				(CmdMsgFn) OnPrint,
								ID_FILE_PRINT_SETUP,		(CmdMsgFn) OnPrintSetup,
								ID_FILE_EXIT,				(CmdMsgFn) OnExit,
								ID_SESSION_CLOCK_IN,		(CmdMsgFn) OnClockIn,
								ID_SESSION_SWITCH_TASKS,	(CmdMsgFn) OnSwitchTasks,
								ID_SESSION_CLOCK_OUT,		(CmdMsgFn) OnClockOut,
								ID_SESSION_EDIT,			(CmdMsgFn) OnEditSessions,
								ID_PRUNE_SESSIONS,			(CmdMsgFn) OnPruneSessions,
								ID_PRUNE_TASKS,				(CmdMsgFn) OnPruneTasks,
								ID_HELP_CONTENTS,			(CmdMsgFn) OnContents,
								ID_HELP_ABOUT,				(CmdMsgFn) OnAbout,
						 		0,							(CmdMsgFn) 0 };
	
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
	EnableCmd(ID_FILE_EXPORT);
	EnableCmd(ID_FILE_PRINT);

	// Get current status.
	bool bClockedIn = App.ClockedIn();

	// Dependencies on state.
	EnableCmd(ID_SESSION_CLOCK_IN, !bClockedIn);
	EnableCmd(ID_SESSION_CLOCK_OUT, bClockedIn);
	EnableCmd(ID_SESSION_SWITCH_TASKS, bClockedIn);
}

/******************************************************************************
** Method:		OnExport()
**
** Description:	Show the export dialog and export to a file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnExport(void)
{
	CExportDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		// Report status.
		m_pStatusBar->HintBar()->Hint("Exporting...");

		App.Busy(TRUE);

		// Setup the file to export to.
		CFileExport Device(Dlg.m_strFileName);
		
		// Do the export.
		App.ExportData(Device, Dlg.m_eGrouping, Dlg.m_FromDate, Dlg.m_ToDate);

		App.Busy(FALSE);

		// Report status.
		m_pStatusBar->HintBar()->Hint("Export completed");
	}
}

/******************************************************************************
** Method:		OnPrint()
**
** Description:	Show the print dialog and export to a printer.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnPrint(void)
{
	CPrintDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		// Report status.
		m_pStatusBar->HintBar()->Hint("Printing...");

		App.Busy(TRUE);

		// Setup the printer to print to.
		CPrintExport Device(App.Printer());
		
		// Do the export.
		App.ExportData(Device, Dlg.m_eGrouping, Dlg.m_FromDate, Dlg.m_ToDate);

		App.Busy(FALSE);

		// Report status.
		m_pStatusBar->HintBar()->Hint("Printing completed");
	}
}

/******************************************************************************
** Method:		OnPrintSetup()
**
** Description:	Select a new printer using the standard dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnPrintSetup(void)
{
	App.Printer().Select(this);
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

void CAppWnd::OnExit(void)
{
	Close();
}

/******************************************************************************
** Method:		OnClockIn()
**
** Description:	Show the clock in dialog and clock in if accepted.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnClockIn(void)
{
	CClockInDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		App.ClockIn(CDateTime(Dlg.m_Date, Dlg.m_Time), Dlg.m_strTask);
		AppDlg()->Update();
	}
}

/******************************************************************************
** Method:		OnSwitchTasks()
**
** Description:	Show the switch tasks dialog and switch tasks if accepted.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnSwitchTasks(void)
{
	CSwitchTasksDlg	Dlg(this);
	CDateTime		dtCurrent;
	
	if (Dlg.RunModal() == IDOK)
	{
		dtCurrent.Set();
	
		App.ClockOut(dtCurrent, Dlg.m_strPrevTask);
		App.ClockIn(dtCurrent, Dlg.m_strNextTask);
		AppDlg()->Update();
	}
}

/******************************************************************************
** Method:		OnClockOut()
**
** Description:	Show the clock out dialog and clock out if accepted.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnClockOut(void)
{
	CClockOutDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		App.ClockOut(CDateTime(Dlg.m_Date, Dlg.m_Time), Dlg.m_strTask);
		AppDlg()->Update();
	}
}

/******************************************************************************
** Method:		OnEditSessions()
**
** Description:	Show the edit sessions dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnEditSessions(void)
{
	CEditSessionDlg	Dlg(this);
	
	Dlg.RunModal();
	AppDlg()->Update();
}

/******************************************************************************
** Method:		OnPruneSessions()
**
** Description:	Show the prune sessions dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnPruneSessions(void)
{
	CPruneSessionsDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		CDateTime	dtStart;
		CDateTime	dtEnd;

		// Setup enum limits.
		dtEnd.Date(Dlg.m_Date);
		
		CSessionList&	SessionList = App.SessionList();
		CSessionEnum	Enum(SessionList, dtStart, dtEnd);
		CSession*		pCurrSession = Enum.Next();
		CSession*		pNextSession = NULL;
		
		// For all sessions within the period.
		while(pCurrSession)
		{
			// Get next session first.
			pNextSession = Enum.Next();
			
			// Delete it.
			SessionList.Remove(pCurrSession);
			delete pCurrSession;
			
			// Move on.
			pCurrSession = pNextSession;
		}

		// Update dirty flag.
		App.Modified();
	
		AppDlg()->Update();
	}
}

/******************************************************************************
** Method:		OnPruneTasks()
**
** Description:	Show the prune tasks dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnPruneTasks(void)
{
	CPruneTasksDlg	Dlg(this);
	
	if (Dlg.RunModal() == IDOK)
	{
		CTaskList&		rAppTaskList = App.TaskList();
		CTaskListEnum	Enum(Dlg.m_TaskList);
		CString*		pString;
		
		// For all tasks.
		while((pString = Enum.Next()) != NULL)
			rAppTaskList.Remove(*pString);
		
		// Update dirty flag.
		App.Modified();
	}
}

/******************************************************************************
** Method:		OnContents()
**
** Description:	Show the helptext.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnContents(void)
{
	Notify("No help available yet");
}

/******************************************************************************
** Method:		OnAbout()
**
** Description:	Show the about dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppWnd::OnAbout(void)
{
	CAboutDlg	Dlg(this);
	
	Dlg.RunModal();
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
	// Data changed?
	if (!App.IsModified())
		return TRUE;

	App.Busy(TRUE);

	// Do the save.
	if (App.SaveData())
		return TRUE;

	App.Busy(FALSE);

	return FALSE;
}
