/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		COMPDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CCompilerDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "compdlg.hpp"

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

CCompilerDlg::CCompilerDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_COMPILER_SETTINGS);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_FILENAME,	&m_ebFileName,
				 		0,				0				};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_BROWSE,	BN_CLICKED,		(CtlMsgFn)OnBrowse,
								0, 			0,				0					};
	
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

void CCompilerDlg::OnCreate(void)
{
	// Initialise members.
	m_strFileName = "";
	
	// Initialise controls.
	m_ebFileName.Text(App.Prefs().CompilerPath());
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

bool CCompilerDlg::OnOk(void)
{
	// Get filename.
	m_strFileName = m_ebFileName.Text();

	// Validate filename.
	if ( (m_strFileName == "") || (!m_strFileName.Exists()) )
	{
		Alert("The Help Compiler path is invalid");
		return FALSE;
	}

	return TRUE;
}

/******************************************************************************
** Method:		OnBrowse()
**
** Description:	Show the file selection dialog to get the compiler path.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CCompilerDlg::OnBrowse(void)
{
	// File extensions.
	static char szExts[] = {	"Exe Files (*.EXE)\0*.EXE\0"
								"All Files (*.*)\0*.*\0"
								"\0\0"							};

	// Select a filename.
	if (m_strFileName.Select(this, OF_SELECT, szExts, "EXE"))
	{
		// Update the dialog.
		m_ebFileName.Text(m_strFileName);
	}
}
