/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ADDTPDLG.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAddTopicDlg class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include "addtpdlg.hpp"

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

CAddTopicDlg::CAddTopicDlg(CWnd* pParent)
{
	ASSERT(pParent);

	// Initialise INIT structure.
	m_diInit.lpszTemplate = MAKEINTRESOURCE(IDD_ADD_TOPIC);
	m_diInit.hParent      = pParent->Handle();

	// Define the control table.
	Control Ctrls[] = {	IDC_NAME,			&m_ebName,
						IDC_CONTEXT_NAME,	&m_ebContextName,
						IDC_KEYWORDS,		&m_ebKeywords,
				 		0,					0				};
	
	CtrlTable(Ctrls);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_NAME,	EN_CHANGE,	(CtlMsgFn)OnChangeName,
								0, 			0,			0						};
	
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

void CAddTopicDlg::OnCreate(void)
{
	// Initialise members.
	m_strName        = "";
	m_strContextName = "";
	m_strKeywords    = "";
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

bool CAddTopicDlg::OnOk(void)
{
	// Get details.
	m_strName        = m_ebName.Text();
	m_strContextName = m_ebContextName.Text();
	m_strKeywords    = m_ebKeywords.Text();

	// Valid name?
	if (m_strName == "")
	{
		Alert("You must specify a topic name.");
		return FALSE;
	}

	// Valid context name?
	if (m_strContextName == "")
	{
		Alert("You must specify a context name.");
		return FALSE;
	}

	CTopicEnum	Enum(App.Doc()->TopicList());
	CTopic*		pTopic;
	
	// For all topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		// Topic name in use?
		if (m_strName == pTopic->Name())
		{
			Alert("The topic name must be unique.");
			return FALSE;
		}

		// Context name in use?
		if (m_strContextName == pTopic->ContextName())
		{
			Alert("The context name must be unique.");
			return FALSE;
		}
	}

	return TRUE;
}

/******************************************************************************
** Method:		OnChangeName()
**
** Description:	Fill in the defaults for the other properties using the new
**				name.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAddTopicDlg::OnChangeName(void)
{
	// Get the name.
	m_strName = m_ebName.Text();

	// Set keywords field.
	m_ebKeywords.Text(m_strName);
	
	// Create the context field.
	m_strContextName = m_ebName.Text();
	char *pszField   = m_strContextName.Buffer();
	
	// Replace spaces with underscores.
	while (*pszField)
	{
		if (*pszField == ' ')
			*pszField = '_';
			
		pszField++;
	}
	
	// And set it.
	m_ebContextName.Text(m_strContextName);
}
