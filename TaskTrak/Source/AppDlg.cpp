/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAppDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

#define TIMER_ID	10
#define TIMEOUT 	1000

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings.
**
** Parameters:	pParent		The dialogs' parent window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CAppDlg::CAppDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_MAIN_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_CURRENT_DATE,	&m_txtCurrDate,
						IDC_CURRENT_TIME,	&m_txtCurrTime,
						IDC_SESSION_DATE,	&m_txtSessionDate,
						IDC_SESSION_TIME,	&m_txtSessionTime,
						IDC_SESSION_LEN,	&m_txtSessionLen,
						IDC_SESSION_TASK,	&m_txtSessionTask,
						IDC_TOTAL_TODAY,	&m_txtTotalToday,
						IDC_TOTAL_WEEK,		&m_txtTotalWeek,
						IDC_TOTAL_MONTH,	&m_txtTotalMonth,
						IDC_TOTAL_TOTAL,	&m_txtTotalTotal,
						0,					0           		};
	
	CtrlTable(Ctrls);
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Initialise the dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppDlg::OnCreate(void)
{
	// Start the clock timer.
	StartTimer(TIMER_ID, TIMEOUT);

	// Get the current time.
	m_dtCurrent.Set();
}

/******************************************************************************
** Method:		OnDestroy()
**
** Description:	Clean up any resources.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppDlg::OnDestroy(void)
{
	// Stop the clock timer.
	StopTimer(TIMER_ID);
}

/******************************************************************************
** Method:		OnTimer()
**
** Description:	Checks the clock and updates the display if the time has
**				changed.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppDlg::OnTimer(uint iTimerID)
{
	CDateTime	dtCurrent;
	
	// Get the current time.
	dtCurrent.Set();
	
	// Changed?
	if (m_dtCurrent != dtCurrent)
	{
		// Save current and update.
		m_dtCurrent = dtCurrent;
		Update();
	}
}

/******************************************************************************
** Method:		Update()
**
** Description:	Updates the info displayed on the dialog.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppDlg::Update(void)
{
	ulong lCurrLen = 0;

	// Update current date and time.
	m_txtCurrDate.Text(m_dtCurrent.Date());
	m_txtCurrTime.Text(m_dtCurrent.Time());
	
	// Update current session, if one.
	if (App.ClockedIn())
	{
		// Create a copy of the current session.
		CSession m_CurrSession(*App.CurrentSession());
		
		// Set to finish now.
		m_CurrSession.Finish(m_dtCurrent, App.CurrentSession()->Task());
		
		// Update fields.
		m_txtSessionDate.Text(m_CurrSession.Start().Date());
		m_txtSessionTime.Text(m_CurrSession.Start().Time());
		m_txtSessionTask.Text(m_CurrSession.Task());

		lCurrLen = m_CurrSession.Length();
		m_txtSessionLen.Text(App.MinsToStr(lCurrLen));
	}
	else
	{
		// Blank out fields.
		m_txtSessionDate.Text("");
		m_txtSessionTime.Text("");
		m_txtSessionLen.Text("");
		m_txtSessionTask.Text("");
	}
	
	// Update totals.
	m_txtTotalToday.Text(App.MinsToStr(App.TotalForDay(m_dtCurrent.Date())));
	m_txtTotalWeek.Text(App.MinsToStr(App.TotalForWeek(m_dtCurrent.Date())));
	m_txtTotalMonth.Text(App.MinsToStr(App.TotalForMonth(m_dtCurrent.Date())));
	m_txtTotalTotal.Text(App.MinsToStr(App.TotalOverall()));
}
