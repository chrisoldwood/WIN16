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
#include <limits.h>
#include <stdio.h>

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

// "The" application object.
CApp App;

// The toolbar cmd table.
static uint aiCmds[] = {	ID_FILE_EXPORT,
							ID_FILE_PRINT,
							ID_SPACE,
							ID_SESSION_CLOCK_IN,
							ID_SESSION_SWITCH_TASKS,
							ID_SESSION_CLOCK_OUT,
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
	// Initialise members.
	m_bClockedIn   = FALSE;
	m_strLastTask  = "";
	m_pCurrSession = NULL;
	m_bModified    = FALSE;
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

	// Create main dialog
	CDialog* pMainDlg = new CAppDlg(m_pAppWnd);
	if (!pMainDlg->RunModeless())
		return FALSE;
		
	// Link to main window.
	AppWnd()->Dialog(pMainDlg);

	// Show it.
	m_pAppWnd->Centre();
	m_pAppWnd->Show(m_iCmdShow);

	Busy(TRUE);

	// Load the data.
	if (!LoadData())
		m_pAppWnd->Close();

	Busy(FALSE);

	// Create .ini file path.
	m_IniFile.Path().Dir(CPath::AppDir);
	m_IniFile.Path() += "TASKTRAK.INI";

	// Load settings.
	LoadDefaults();
	
	// Update status.
	AppWnd()->UpdateCmds();
	AppWnd()->AppDlg()->Update();

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
	// Free up current session.
	if (m_pCurrSession)
		delete m_pCurrSession;
	
	// Free up main window.
	if (m_pAppWnd)
		delete m_pAppWnd;

	// Save settings.
	SaveDefaults();
	
	// Cleanup base classes.
	return CTask::Terminate();
}

/******************************************************************************
** Method:		ClockIn()
**
** Description:	Add a new session to the session list and update the last task
**				member.
**
** Parameters:	dtIn		The date and time of clocking in.
**				strTask		The task about to be done.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::ClockIn(const CDateTime& dtIn, const CString& strTask)
{
	// Create a new session.
	m_pCurrSession = new CSession;
	ASSERT(m_pCurrSession);

	// Initialise.
	m_pCurrSession->Start(dtIn, strTask);

	// Add task to list if set.
	if (strTask != "")
		m_TaskList.Add(strTask);

	// Update state.
	m_strLastTask = strTask;
	m_bClockedIn  = TRUE;
	m_bModified   = TRUE;

	AppWnd()->UpdateCmds();
}

/******************************************************************************
** Method:		ClockOut()
**
** Description:	Fill in the current session and update the last task member.
**
** Parameters:	dtOut		The date and time of clocking out.
**				strTask		The task just done.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::ClockOut(const CDateTime& dtOut, const CString& strTask)
{
	// Complete session.
	m_pCurrSession->Finish(dtOut, strTask);

	// Add to list.
	m_SessionList.Add(m_pCurrSession);
	
	// Reset current session.
	m_pCurrSession = NULL;

	// Add task to list if set.
	if (strTask != "")
		m_TaskList.Add(strTask);
	
	// Update state.
	m_strLastTask = strTask;
	m_bClockedIn  = FALSE;
	m_bModified   = TRUE;

	AppWnd()->UpdateCmds();
}

/******************************************************************************
** Method:		TotalForPeriod()
**
** Description:	Calculate the total time for those sessions within the
**				period specified.
**
** Parameters:	dtStart		The period start datetime.
**				dtEnd		The period end datetime.
**
** Returns:		The time in minutes.
**
*******************************************************************************
*/

ulong CApp::TotalForPeriod(const CDateTime& dtStart, const CDateTime& dtEnd) const
{
	CSessionEnum	Enum(m_SessionList, dtStart, dtEnd);
	CSession*		pSession;
	ulong			lTotal = 0;
	
	// For all sessions within the period.
	while((pSession = Enum.Next()) != NULL)
		lTotal += pSession->Length();
	
	// Current session in period?
	if ( (m_bClockedIn)
	  && (m_pCurrSession->Start() >= dtStart)
	  && (m_pCurrSession->Start() <  dtEnd) )
	{
		CSession 	CurrSession = *m_pCurrSession;
		CDateTime	dtCurrent;
		
		// Create session based on current time.
		dtCurrent.Set();
		CurrSession.Finish(dtCurrent, "");
		
		lTotal += CurrSession.Length();
	}
	
	return lTotal;
}

/******************************************************************************
** Method:		TotalForDay()
**
** Description:	Calculate the total time for those sessions within the
**				day specified.
**
** Parameters:	rDate	The day required.
**
** Returns:		The time in minutes.
**
*******************************************************************************
*/

ulong CApp::TotalForDay(const CDate& rDate) const
{
	CDateTime	dtStart;
	CDateTime	dtEnd;
	CDate		Date = rDate;

	// Create day limits.
	dtStart.Date(Date);
	Date += 1;
	dtEnd.Date(Date);

	return TotalForPeriod(dtStart, dtEnd);
}

/******************************************************************************
** Method:		TotalForWeek()
**
** Description:	Calculate the total time for those sessions within the
**				week specified.
**
** Parameters:	rDate	A date within the week required.
**
** Returns:		The time in minutes.
**
*******************************************************************************
*/

ulong CApp::TotalForWeek(const CDate& rDate) const
{
	CDateTime	dtStart;
	CDateTime	dtEnd;
	CDate		Date = rDate;
	int			iDay = rDate.DayOfWeek();

	// Create week limits.
	Date -= iDay;
	dtStart.Date(Date);
	Date += 7;
	dtEnd.Date(Date);

	return TotalForPeriod(dtStart, dtEnd);
}

/******************************************************************************
** Method:		TotalForMonth()
**
** Description:	Calculate the total time for those sessions within the
**				month specified.
**
** Parameters:	rDate	A date within the month required.
**
** Returns:		The time in minutes.
**
*******************************************************************************
*/

ulong CApp::TotalForMonth(const CDate& rDate) const
{
	CDateTime	dtStart;
	CDateTime	dtEnd;
	int			iDate, iMonth, iYear;
	int			iNumDays;
	CDate		Date = rDate;
	
	// Get limits.
	rDate.Get(iDate, iMonth, iYear);
	iNumDays = rDate.DaysInMonth();

	// Create month limits.
	Date -= iDate - 1;
	dtStart.Date(Date);
	Date += iNumDays;
	dtEnd.Date(Date);

	return TotalForPeriod(dtStart, dtEnd);
}

/******************************************************************************
** Method:		TotalOverall()
**
** Description:	Calculates the total for all sessions.
**
** Parameters:	None.
**
** Returns:		The time in minutes.
**
*******************************************************************************
*/

ulong CApp::TotalOverall(void) const
{
	CDateTime	dtStart;
	CDateTime	dtEnd;
	CDate		Date;

	// Create limits.
	Date += ULONG_MAX;
	dtEnd.Date(Date);

	return TotalForPeriod(dtStart, dtEnd);
}

/******************************************************************************
** Method:		LoadData()
**
** Description:	Load the applications' data.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::LoadData(void)
{
	CFile	AppFile;
	CPath&	rPath = AppFile.Path();

	// Setup up path.
	rPath.Dir(CPath::AppDir);
	rPath += APP_FILE_NAME;

	// Open file.
	if (!AppFile.Open(OF_READ))
	{
		// File doesn't exist?
		if (!rPath.Exists())
			return TRUE;
			
		ReportFileError(CFile::OpenErr, rPath);
		return FALSE;
	}

	char	szMagic[2];
	uint16	iVersion;

	// Read magic.
	if (!AppFile.Read(szMagic, sizeof(szMagic)))
	{
		ReportFileError(CFile::ReadErr, rPath);
		return FALSE;
	}
	
	// Read version number.
	if (!AppFile.Read(iVersion))
	{
		ReportFileError(CFile::ReadErr, rPath);
		return FALSE;
	}
	
	// Check header.
	if ( (szMagic[0] != 'T') || (szMagic[1] != 'T') )
	{
		ReportFileError(CFile::FormatErr, rPath);
		return FALSE;
	}
	
	// Check version number.
	if (iVersion != APP_FILE_VERSION)
	{
		ReportFileError(CFile::VersionErr, rPath);
		return FALSE;
	}
	
	// Read the actual data.
	if (!ReadData(AppFile))
	{
		ReportFileError(CFile::ReadErr, rPath);
		return FALSE;
	}
		
	// Done.
	AppFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		ReadData()
**
** Description:	Read the actual data from the file.
**
** Parameters:	rFile	The file to read from.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ReadData(CFile& rFile)
{
	// Read current status.
	if (!rFile.Read(m_bClockedIn))
		return FALSE;

	if (m_bClockedIn)
	{
		m_pCurrSession = new CSession;
		ASSERT(m_pCurrSession);

		// Read current session.
		if (!m_pCurrSession->Read(rFile))
			return FALSE;
	}

	// Read last task.
	if (!m_strLastTask.Read(rFile))
		return FALSE;
	
	// Read sessions.
	if (!m_SessionList.Read(rFile))
		return FALSE;

	// Read tasks.
	if (!m_TaskList.Read(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		SaveData()
**
** Description:	Save the applications' data.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::SaveData(void)
{
	CFile	AppFile;
	CPath&	rPath = AppFile.Path();

	// Setup up path.
	rPath.Dir(CPath::AppDir);
	rPath += APP_FILE_NAME;

	// Create file.
	if (!AppFile.Create())
	{
		// File is read-only?
		if (rPath.ReadOnly())
			ReportFileError(CFile::ReadOnlyErr, rPath);
		else
			ReportFileError(CFile::CreateErr, rPath);

		return FALSE;
	}

	char	szMagic[2] = { 'T', 'T' };
	uint16	iVersion   = APP_FILE_VERSION;

	// Write magic.
	if (!AppFile.Write(szMagic, sizeof(szMagic)))
	{
		ReportFileError(CFile::WriteErr, rPath);
		return FALSE;
	}

	// Write version number.
	if (!AppFile.Write(iVersion))
	{
		ReportFileError(CFile::WriteErr, rPath);
		return FALSE;
	}

	// Write the actual data.
	if (!WriteData(AppFile))
	{
		ReportFileError(CFile::WriteErr, rPath);
		return FALSE;
	}

	// Done.
	AppFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		WriteData()
**
** Description:	Write the actual data to the file.
**
** Parameters:	rFile	The file to write to.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::WriteData(CFile& rFile)
{
	// Write current status.
	if (!rFile.Write(m_bClockedIn))
		return FALSE;

	if (m_bClockedIn)
	{
		// Write current session.
		if (!m_pCurrSession->Write(rFile))
			return FALSE;
	}

	// Write last task.
	if (!m_strLastTask.Write(rFile))
		return FALSE;
	
	// Write sessions.
	if (!m_SessionList.Write(rFile))
		return FALSE;

	// Write tasks.
	if (!m_TaskList.Write(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		ReportFileError()
**
** Description:	Report the file error to the user.
**
** Parameters:	eErr	The error.
**				rPath	The files path.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::ReportFileError(CFile::Error eErr, const CPath& rPath) const
{
	char*		pszMsg      = "";
	const char*	pszFileName = rPath;

	// Decode error.
	switch(eErr)
	{
		case CFile::OpenErr:		pszMsg = "Failed to open the file:\n\n%s";		break;
		case CFile::CreateErr:		pszMsg = "Failed to create the file:\n\n%s";	break;
		case CFile::ReadOnlyErr:	pszMsg = "The file is read-only:\n\n%s";		break;
		case CFile::ReadErr:		pszMsg = "Failed to read from file:\n\n%s";		break;
		case CFile::WriteErr:		pszMsg = "Failed to write to file:\n\n%s";		break;
		case CFile::FormatErr:		pszMsg = "Invalid format for the file:\n\n%s";	break;
		case CFile::VersionErr:		pszMsg = "Invalid version of the file:\n\n%s";	break;
		default:					ASSERT(FALSE);									break;
	}
	
	// Show the message.
	AppWnd()->Alert(pszMsg, pszFileName);
}

/******************************************************************************
** Method:		ExportData()
**
** Description:	Export data to a device.
**
** Parameters:	rDevice		The device to export to.
**				eGrouping	The grouping of the data.
**				rFromDate	The starting date.
**				rToDate		The end date.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::ExportData(CExport& rDevice, Grouping eGrouping, const CDate& rFromDate,
						const CDate& rToDate) const
{
    char 		szTotal[100];
	ulong		lTotal = 0;
	bool		bOkay  = FALSE;
	CDateTime	dtFrom, dtTo;

	// Initialise the device.
	if (!rDevice.Init())
		return;

	// Set up limits.
	dtFrom.Date(rFromDate);
	dtTo.Date(rToDate);
	dtTo.Time(CTime(23, 59));

	// Check grouping.
	switch(eGrouping)
	{
		case Ungrouped:
			bOkay = ExportUngrouped(rDevice, lTotal, dtFrom, dtTo);
			break;
			
		case ByWeek:
			bOkay = ExportByWeek(rDevice, lTotal, dtFrom, dtTo);
			break;
			
		case ByMonth:
			bOkay = ExportByMonth(rDevice, lTotal, dtFrom, dtTo);
			break;
			
		case ByTask:
			bOkay = ExportByTask(rDevice, lTotal, dtFrom, dtTo);
			break;
			
		default:
			ASSERT(FALSE);
			break;
	}

	// Exported okay?
	if (bOkay)
	{
		// Output total.
		sprintf(szTotal, "Total For All Sessions: %s", App.MinsToStr(lTotal));
		rDevice.SendText(szTotal);
	}

	// Cleanup the device.
	rDevice.Term();
}

/******************************************************************************
** Method:		ExportUngrouped()
**
** Description:	Export all data ungrouped.
**
** Parameters:	rDevice		The device to export to.
**				rlTotal		The total time.
**				dtFrom		The starting date.
**				dtTo		The end date.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportUngrouped(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom,
							const CDateTime& dtTo) const
{
    CDate			DateDone;
	CSession*		pSession = NULL;
	CSessionEnum	Enum(App.SessionList(), dtFrom, dtTo);
	ulong			lDayTotal = 0;
	
	// Init total.
	rlTotal = 0;

	// For all sessions.
	while((pSession = Enum.Next()) != NULL)
	{
		// New day?
		if (pSession->Start().Date() > DateDone)
		{
			// Export days data.
			if (!ExportDay(rDevice, pSession->Start().Date(), lDayTotal))
				return FALSE;
				
			if (!rDevice.SendLineBreak())
				return FALSE;
			
			DateDone = pSession->Start().Date();
			rlTotal += lDayTotal;
		}
	}

	return TRUE;
}

/******************************************************************************
** Method:		ExportByWeek()
**
** Description:	Export all data ordered by weeks.
**
** Parameters:	rDevice		The device to export to.
**				rlTotal		The total time.
**				dtFrom		The starting date.
**				dtTo		The end date.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportByWeek(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom,
						const CDateTime& dtTo) const
{
	CDateTime		dtStart;
	CDateTime		dtEnd;
	CSession*		pSession = NULL;
	CSessionEnum	Enum(App.SessionList(), dtFrom, dtTo);

	// Init total.
	rlTotal = 0;

	// For all sessions.
	while((pSession = Enum.Next()) != NULL)
	{
		// Skip sessions still in current week.
		if ( (pSession->Start() >= dtStart) && (pSession->Start() < dtEnd) )
			continue;

		CDate	Date = pSession->Start().Date();
		int		iDay = Date.DayOfWeek();
		
		// Create week limits.
		Date -= iDay;
		dtStart.Date(Date);
		Date += 6;
		dtEnd.Date(Date);
		dtEnd.Time(CTime(23, 59));

		// Create enumerator for the week.
		CSessionEnum	LenEnum(App.SessionList(), dtStart, dtEnd);
		CSession*		pLenSession = NULL;
		ulong			lWeekTotal = 0;
		
		// Get total for the week.
		while((pLenSession = LenEnum.Next()) != NULL)
			lWeekTotal += pLenSession->Length();

	    char szHeading[100];
		const char*	pszStartDate = dtStart.Date();
		const char* pszEndDate   = dtEnd.Date();
		const char* pszLen       = App.MinsToStr(lWeekTotal);

		// Output week heading.
		sprintf(szHeading, "Week: %s to %s (Total: %s)", pszStartDate, pszEndDate, pszLen);
		if (!rDevice.SendHeading(szHeading))
			return FALSE;

		// Get date for week start.
		Date = dtStart.Date();
		
		// For all days in the week.
		for(iDay = 0; iDay < 7; iDay++, Date += 1)
		{
			ulong lDayTotal;

			// Export data for the day..
			if (!ExportDay(rDevice, Date, lDayTotal))
				return FALSE;

			// End of day.
			if (!rDevice.SendLineBreak())
				return FALSE;
		}
		
		// End of week.
		if (!rDevice.SendLineBreak())
			return FALSE;
		
		// Update total.
		rlTotal += lWeekTotal;
	}

	return TRUE;
}

/******************************************************************************
** Method:		ExportByMonth()
**
** Description:	Export all data ordered by months.
**
** Parameters:	rDevice		The device to export to.
**				rlTotal		The total time.
**				dtFrom		The starting date.
**				dtTo		The end date.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportByMonth(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom,
							const CDateTime& dtTo) const
{
	CDateTime		dtStart;
	CDateTime		dtEnd;
	CSession*		pSession = NULL;
	CSessionEnum	Enum(App.SessionList(), dtFrom, dtTo);

	// Init total.
	rlTotal = 0;

	// For all sessions.
	while((pSession = Enum.Next()) != NULL)
	{
		// Skip sessions still in current month.
		if ( (pSession->Start() >= dtStart) && (pSession->Start() < dtEnd) )
			continue;

		CDate	Date = pSession->Start().Date();
		int		iDate, iMonth, iYear;
		int 	iNumDays;

		// Create month limits.
		Date.Get(iDate, iMonth, iYear);
		iNumDays = Date.DaysInMonth();
		
		Date -= iDate - 1;
		dtStart.Date(Date);
		Date += iNumDays - 1;
		dtEnd.Date(Date);
		dtEnd.Time(CTime(23, 59));

		// Create enumerator for the month.
		CSessionEnum	LenEnum(App.SessionList(), dtStart, dtEnd);
		CSession*		pLenSession = NULL;
		ulong			lMonthTotal = 0;
		
		// Get total for the month.
		while((pLenSession = LenEnum.Next()) != NULL)
			lMonthTotal += pLenSession->Length();

	    char szHeading[100];
		const char*	pszStartDate = dtStart.Date();
		const char* pszEndDate   = dtEnd.Date();
		const char* pszLen       = App.MinsToStr(lMonthTotal);

		// Output month heading.
		sprintf(szHeading, "Month: %s to %s (Total: %s)", pszStartDate, pszEndDate, pszLen);
		if (!rDevice.SendHeading(szHeading))
			return FALSE;

		// Get date for month start.
		Date = dtStart.Date();
		
		// For all days in the month.
		for(int iDay = 0; iDay < iNumDays; iDay++, Date += 1)
		{
			ulong lDayTotal;

			// Export data for the day..
			if (!ExportDay(rDevice, Date, lDayTotal))
				return FALSE;

			// End of day.
			if (!rDevice.SendLineBreak())
				return FALSE;
		}
		
		// End of week.
		if (!rDevice.SendLineBreak())
			return FALSE;
		
		// Update total.
		rlTotal += lMonthTotal;
	}

	return TRUE;
}

/******************************************************************************
** Method:		ExportByTask()
**
** Description:	Export all data by its task.
**
** Parameters:	rDevice		The device to export to.
**				rlTotal		The total time.
**				dtFrom		The starting date.
**				dtTo		The end date.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportByTask(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom,
						const CDateTime& dtTo) const
{
	CTaskListEnum	TaskEnum(App.TaskList());
	CString*		pString;

	// Initialise total.
	rlTotal = 0;
	
	// For all tasks.
	while((pString = TaskEnum.Next()) != NULL)
	{
		CSession*		pSession = NULL;
		CSessionEnum	LenEnum(App.SessionList(), dtFrom, dtTo);
		ulong			lTotal = 0;
	
		// Get length of all sessions for task.
		while((pSession = LenEnum.Next()) != NULL)
		{
			if (pSession->Task() == *pString)
				lTotal += pSession->Length();
		}
		
		// Update grand total.
		rlTotal +=lTotal;

		CSessionEnum	SessEnum(App.SessionList(), dtFrom, dtTo);
		char			szHeading[256];
		const char*		pszTask = *pString;
		const char*		pszLen  = App.MinsToStr(lTotal);
		
		// Output month heading.
		sprintf(szHeading, "%s (Total: %s)", pszTask, pszLen);
		if (!rDevice.SendHeading(szHeading))
			return FALSE;
		
		// Output all sessions for task.
		while((pSession = SessEnum.Next()) != NULL)
		{
			if (pSession->Task() == *pString)
			{
				char 		szText[100];
				const char* pszDate  = pSession->Start().Date();
				const char*	pszStart = pSession->Start().Time();
				const char*	pszEnd   = pSession->Finish().Time();
				const char* pszLen   = App.MinsToStr(pSession->Length());

				sprintf(szText,"%s from %s to %s for %s", pszDate,
								pszStart, pszEnd, pszLen);
			
				if (!rDevice.SendText(szText))
					return FALSE;
			}
		}

		// End of task.
		if (!rDevice.SendLineBreak())
			return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		ExportDay()
**
** Description:	Export all data for the day to the device.
**
** Parameters:	rDevice		The device to export to.
**				rDate		The date of the day to export.
**				rlTotal		The total time for all sessions on the day.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportDay(CExport& rDevice, const CDate& rDate, ulong& rlTotal) const
{
	CDateTime	dtStart;
	CDateTime	dtEnd;
	CSession*	pSession;

	// Create limits of day.
	dtStart.Date(rDate);
	dtEnd.Date(rDate);
	dtEnd.Time(CTime(23, 59));

	// Create enumerator for the day.
	CSessionEnum	LenEnum(App.SessionList(), dtStart, dtEnd);
	rlTotal = 0;

	// Get length of all sessions on the day.
	while((pSession = LenEnum.Next()) != NULL)
		rlTotal += pSession->Length();
	
	// Create enumerator for the day.
	CSessionEnum	Enum(App.SessionList(), dtStart, dtEnd);
	
	char szText[100];
	const char*	pszDate = rDate;
	const char* pszDay  = rDate.DayOfWeekStr();
	const char* pszLen  = App.MinsToStr(rlTotal);
	
	sprintf(szText, "%s %s (Total: %s)", pszDay, pszDate, pszLen);
	if (!rDevice.SendText(szText))
		return FALSE;

	// Export all sessions on the day.
	while((pSession = Enum.Next()) != NULL)
	{
		if (!ExportSession(rDevice, pSession))
			return FALSE;
	}
		
	return TRUE;
}

/******************************************************************************
** Method:		ExportSession()
**
** Description:	Export a session to the device.
**
** Parameters:	rDevice		The device to export to.
**				pSession	The session to export.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CApp::ExportSession(CExport& rDevice, CSession* pSession) const
{
	char 		szText[100];
	const char*	pszStart = pSession->Start().Time();
	const char*	pszEnd   = pSession->Finish().Time();
	const char* pszTask  = pSession->Task();
	ulong		lLen     = pSession->Length();

	sprintf(szText,"%s to %s for %s on %s", pszStart, pszEnd,
					App.MinsToStr(lLen), pszTask);

	return rDevice.SendText(szText);
}

/******************************************************************************
** Method:		LoadDefaults()
**
** Description:	Load the default settings.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::LoadDefaults(void)
{
	m_IniFile.ReadString("Prefs", "ExportFile", "TaskTrak.txt", m_szDefFile, MAX_PATH);
	m_eDefGrouping = (Grouping)m_IniFile.ReadInt("Prefs", "Grouping", Ungrouped);
	m_eDefPeriod   = (Period)m_IniFile.ReadInt("Prefs", "Period", All);
}

/******************************************************************************
** Method:		SaveDefaults()
**
** Description:	Save the default settings.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::SaveDefaults(void)
{
	m_IniFile.WriteString("Prefs", "ExportFile", m_szDefFile);
	m_IniFile.WriteInt("Prefs", "Grouping", m_eDefGrouping);
	m_IniFile.WriteInt("Prefs", "Period",   m_eDefPeriod);
}

/******************************************************************************
** Method:		PeriodToDates()
**
** Description:	Gets the dates that correspond to the given period.
**
** Parameters:	ePeriod		The period.
**				rFromDate	The returned from date.
**				rToDate		The returned to date.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CApp::PeriodToDates(Period ePeriod, CDate& rFromDate, CDate& rToDate) const
{
	CDate	Today;

	// Get todays date.
	Today.Set();

	// Decode period.
	switch(ePeriod)
	{
		case All:
			{
				// Any sessions?
				if (m_SessionList.Length())
				{
					CSessionEnum	Enum(m_SessionList);
					CSession*		pSession = Enum.Next();
				
					// First session is earliest.
					rFromDate = pSession->Start().Date();
				
					// Find last session.
					while(pSession)
					{
						// Last session is latest date.
						rToDate  = pSession->Start().Date();
						pSession = Enum.Next();
					}
				}
				else
				{
					// Use todays date.
					rFromDate = Today;
					rToDate   = Today;
				}
			}
			break;
		
		case ThisWeek:
			{
				CDate	Date = Today;
				int 	iDay = Today.DayOfWeek();

				// Adjust for week.
				Date     -= iDay;
				rFromDate = Date;
				Date     += 6;
				rToDate   = Date;
			}
			break;
		
		case ThisMonth:
			{
				int		iDate, iMonth, iYear;
				int		iNumDays;
				CDate	Date = Today;
				
				// Get month limits.
				Date.Get(iDate, iMonth, iYear);
				iNumDays = Date.DaysInMonth();
			
				// Create month limits.
				Date     -= iDate - 1;
				rFromDate = Date;
				Date     += iNumDays - 1;
				rToDate   = Date;
			}
			break;
		
		case LastWeek:
			{
				// Go back 7 days.
				CDate Date = Today;
				Date -= 7;
				int	iDay = Today.DayOfWeek();

				// Adjust for week.
				Date     -= iDay;
				rFromDate = Date;
				Date     += 6;
				rToDate   = Date;
			}
			break;
		
		case LastMonth:
			{
				int		iDate, iMonth, iYear;
				int		iNumDays;
				CDate	Date = Today;

				// Move back to previous month.
				Date.Get(iDate, iMonth, iYear);
				Date -= iDate;
				
				// Get month limits.
				Date.Get(iDate, iMonth, iYear);
				iNumDays = Date.DaysInMonth();
			
				// Create month limits.
				Date     -= iDate - 1;
				rFromDate = Date;
				Date     += iNumDays - 1;
				rToDate   = Date;
			}
			break;
		
		case Custom:
			{
				// Use todays date.
				rFromDate = Today;
				rToDate   = Today;
			}
			break;
		
		default:
			ASSERT(FALSE);
			break;
	}
}
