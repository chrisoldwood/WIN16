/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APP.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAPP class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APP_HPP
#define APP_HPP

/******************************************************************************
** 
** Type to define the ordering used when exporting.
**
*******************************************************************************
*/

typedef enum tagGrouping
{
	Ungrouped,
	ByWeek,
	ByMonth,
	ByTask
} Grouping;

/******************************************************************************
** 
** Type to define the period used when exporting.
**
*******************************************************************************
*/

typedef enum tagPeriod
{
	All,
	ThisWeek,
	ThisMonth,
	LastWeek,
	LastMonth,
	Custom
} Period;

/******************************************************************************
** 
** This is "the" application class.
**
*******************************************************************************
*/

APPCLASS CApp : public CTask
{
public:
	//
	// Constructors/Destructor.
	//
	CApp(void);
	~CApp(void);

	//
	// Initialisation and termination.
	// These are virtual in the base class and must be overriden.
	//
	bool Initialise(void);
	bool Terminate(void);

	//
	// Member access
	//
	CAppWnd* AppWnd(void) const;
	bool ClockedIn(void) const;
	CTaskList& TaskList(void);
	const CString& LastTask(void) const;
	CSessionList& SessionList(void);
	const CSession* CurrentSession(void) const;
	bool IsModified(void) const;
	void Modified(void);
	CPrinterDC& Printer(void);
	const char* DefaultFile(void) const;
	Grouping DefaultGrouping(void) const;
	Period DefaultPeriod(void) const;

	//
	// Member setting.
	//
	void DefaultFile(const char* pszPath);
	void DefaultGrouping(Grouping eGrouping);
	void DefaultPeriod(Period ePeriod);
	
	//
	// Session status.
	//
	void ClockIn(const CDateTime& dtIn, const CString& strTask);
	void ClockOut(const CDateTime& dtOut, const CString& strTask);
	ulong TotalForPeriod(const CDateTime& dtStart, const CDateTime& dtEnd) const;
	ulong TotalForDay(const CDate& rDate) const;
	ulong TotalForWeek(const CDate& rDate) const;
	ulong TotalForMonth(const CDate& rDate) const;
	ulong TotalOverall(void) const;

	//
	// Serialisation.
	//
	bool LoadData(void);
	bool SaveData(void);
	void ExportData(CExport& rDevice, Grouping eGrouping, const CDate& rFromDate, const CDate& rToDate) const;
	void ReportFileError(CFile::Error eErr, const CPath& rPath) const;

	//
	// Misc methods.
	//
	const char* MinsToStr(ulong lMins);
	void PeriodToDates(Period ePeriod, CDate& rFromDate, CDate& rToDate) const;
	
protected:
	//
	// Members
	//
	CSessionList	m_SessionList;
	CTaskList		m_TaskList;
	int16			m_bClockedIn;
	CSession*		m_pCurrSession;
	CString			m_strLastTask;
	char			m_szMins[20];
	bool			m_bModified;
	CPrinterDC		m_Printer;
	
	//
	// Preferences.
	//
	CIniFile		m_IniFile;
	char			m_szDefFile[MAX_PATH];
	Grouping		m_eDefGrouping;
	Period			m_eDefPeriod;

	//
	// Internal methods.
	//
	bool ReadData(CFile& rFile);
	bool WriteData(CFile& rFile);

	bool ExportUngrouped(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom, const CDateTime& dtTo) const;
	bool ExportByWeek(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom, const CDateTime& dtTo) const;
	bool ExportByMonth(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom, const CDateTime& dtTo) const;
	bool ExportByTask(CExport& rDevice, ulong& rlTotal, const CDateTime& dtFrom, const CDateTime& dtTo) const;
	bool ExportDay(CExport& rDevice, const CDate& rDate, ulong& rlTotal) const;
	bool ExportSession(CExport& rDevice, CSession* pSession) const;

	void LoadDefaults(void);
	void SaveDefaults(void);
};

// The current file version.
#define APP_FILE_VERSION	10

// The data filename.
#define	APP_FILE_NAME		"TASKTRAK.DAT"

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

extern CApp App;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CAppWnd* CApp::AppWnd(void) const
{
	return (CAppWnd*) m_pAppWnd;
}

inline bool CApp::ClockedIn(void) const
{
	return m_bClockedIn;
}

inline CTaskList& CApp::TaskList(void)
{
	return m_TaskList;
}

inline const CString& CApp::LastTask(void) const
{
	return m_strLastTask;
}

inline CSessionList& CApp::SessionList(void)
{
	return m_SessionList;
}

inline const CSession* CApp::CurrentSession(void) const
{
	ASSERT(m_pCurrSession);

	return m_pCurrSession;
}

inline const char* CApp::MinsToStr(ulong lMins)
{
	wsprintf(m_szMins, "%ld h %02ld m", (lMins / 60), (lMins % 60));
	return m_szMins;
}

inline bool CApp::IsModified(void) const
{
	return m_bModified;
}

inline void CApp::Modified(void)
{
	m_bModified = TRUE;
}

inline CPrinterDC& CApp::Printer(void)
{
	return m_Printer;
}

inline const char* CApp::DefaultFile(void) const
{
	return m_szDefFile;
}

inline Grouping CApp::DefaultGrouping(void) const
{
	return m_eDefGrouping;
}

inline Period CApp::DefaultPeriod(void) const
{
	return m_eDefPeriod;
}

inline void CApp::DefaultFile(const char* pszPath)
{
	ASSERT(pszPath);

	strcpy(m_szDefFile, pszPath);
}

inline void CApp::DefaultGrouping(Grouping eGrouping)
{
	m_eDefGrouping = eGrouping;
}

inline void CApp::DefaultPeriod(Period ePeriod)
{
	m_eDefPeriod = ePeriod;
}

#endif //APP_HPP
