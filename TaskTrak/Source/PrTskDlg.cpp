/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRTSKDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CPruneTasksDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "prtskdlg.hpp"

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

CPruneTasksDlg::CPruneTasksDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_PRUNE_TASKS_DIALOG);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_TASKS, 	&m_lbTasks,
				 		0,			0			};
	
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

void CPruneTasksDlg::OnCreate(void)
{
	CTaskListEnum	Enum(App.TaskList());
	CString*		pString;
	
	// For all tasks.
	while((pString = Enum.Next()) != NULL)
	{
		CSessionEnum	Enum(App.SessionList());
		CSession*		pSession;
		bool			bInUse = FALSE;

		// For all sessions.
		while((pSession = Enum.Next()) != NULL)
        {
        	// Task in use?
        	if (*pString == pSession->Task())
        	{
        		bInUse = TRUE;
        		break;
        	}
        }
        
        // Task in use by current session?
        if ( (App.CurrentSession()) && (*pString == App.CurrentSession()->Task()) )
        	bInUse = TRUE;

        // Task in use as "Last Task"?
        if (*pString == App.LastTask())
        	bInUse = TRUE;
        
		// Add task if not in use?
		if (!bInUse)
			m_lbTasks.Add(*pString);
	}
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

bool CPruneTasksDlg::OnOk(void)
{
	int iNumTasks = m_lbTasks.Count();

	// For all tasks.
	for (int i = 0; i < iNumTasks; i++)
	{
		// Add to list if selected.
		if (m_lbTasks.Selected(i))
			m_TaskList.Add(m_lbTasks.Text(i));
	}
	
	return TRUE;
}
