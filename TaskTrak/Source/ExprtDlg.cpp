/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EXPRTDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CExportDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "exprtdlg.hpp"
#include <limits.h>

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

CExportDlg::CExportDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_EXPORT_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_FILENAME,	&m_ebFileName,
						IDC_GROUPING, 	&m_cbGrouping,
						IDC_PERIOD,		&m_cbPeriod,
						IDC_FROM_DATE,	&m_ebFromDate,
						IDC_TO_DATE, 	&m_ebToDate,
				 		0,				0				};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_BROWSE,	BN_CLICKED,		(CtlMsgFn)OnBrowse,
								IDC_PERIOD,	CBN_SELCHANGE,	(CtlMsgFn)OnPeriodChange,
								0, 			0,				0							};
	
	CtlMsgTable(CtlMsgs);
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

void CExportDlg::OnCreate(void)
{
	// Initialise filename.
	m_strFileName = App.DefaultFile();
	m_ebFileName.Text(m_strFileName);

	// Fill grouping list.
	m_cbGrouping.Add("None");
	m_cbGrouping.Add("By Week");
	m_cbGrouping.Add("By Month");
	m_cbGrouping.Add("By Task");

	// Select default.
	m_cbGrouping.Select(App.DefaultGrouping());
	
	// Fill period list.
	m_cbPeriod.Add("All");
	m_cbPeriod.Add("This Week");
	m_cbPeriod.Add("This Month");
	m_cbPeriod.Add("Last Week");
	m_cbPeriod.Add("Last Month");
	m_cbPeriod.Add("Custom...");
	
	// Select default.
	m_cbPeriod.Select(App.DefaultPeriod());

	// Initialise date fields.
	OnPeriodChange();
}

/******************************************************************************
** Method:		OnOk()
**
** Description:	Check if the user can okay the dialog.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CExportDlg::OnOk(void)
{
	// Get period selection.
	Period ePeriod = (Period) m_cbPeriod.Current();

	// Custom period?
	if (ePeriod == Custom)
	{
		// Get from date from edit box.
		if (!m_FromDate.Set(m_ebFromDate.Text()))
		{
			Alert("'From' date is invalid.");
			return FALSE;
		}

		// Get to date from edit box.
		if (!m_ToDate.Set(m_ebToDate.Text()))
		{
			Alert("'To' date is invalid.");
			return FALSE;
		}

		// Check from date is before to date.
		if (m_FromDate > m_ToDate)
		{
			Alert("'From' date must be before 'To' date.");
			return FALSE;
		}
	}

	// Get grouping selection.
	m_eGrouping = (Grouping) m_cbGrouping.Current();

	// Get filename from edit control.
	m_strFileName = m_ebFileName.Text();

	// Save prefs.
	App.DefaultFile(m_strFileName);
	App.DefaultGrouping(m_eGrouping);
	App.DefaultPeriod(ePeriod);
	
	return TRUE;
}

/******************************************************************************
** Method:		OnBrowse()
**
** Description:	Show the file dialog to select a file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CExportDlg::OnBrowse(void)
{
	// File extensions.
	static char szExts[] = {	"Text Files (*.TXT)\0*.TXT\0"
								"All Files (*.*)\0*.*\0"
								"\0\0"							};

	// Select a filename.
	if (m_strFileName.Select(this, OF_WRITE, szExts, "TXT"))
	{
		// Update the dialog.
		m_ebFileName.Text(m_strFileName);
	}
}
/******************************************************************************
** Method:		OnPeriodChange()
**
** Description:	Update the from and to date controls' states.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CExportDlg::OnPeriodChange(void)
{
	// Get current selection.
	int i = m_cbPeriod.Current();
	ASSERT(i != CB_ERR);

	// Convert selelction to date range.
	App.PeriodToDates((Period)i, m_FromDate, m_ToDate);
	
	// Update date fields.
	m_ebFromDate.Text(m_FromDate);
	m_ebToDate.Text(m_ToDate);

	// Custom period?
	if (i == Custom)
	{
		// Enable date fields.
		m_ebFromDate.Enable();
		m_ebToDate.Enable();
	}
	else
	{
		// Disable date fields.
		m_ebFromDate.Disable();
		m_ebToDate.Disable();
	}
}
