/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICEB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTopicEditBox class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdio.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTopicEditBox::CTopicEditBox(void)
{
	m_pTopic        = NULL;
	m_bModified     = FALSE;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTopicEditBox::~CTopicEditBox(void)
{
}

/******************************************************************************
** Method:		Topic()
**
** Description:	Change the topic that the user is editing.
**
** Parameters:	pTopic		The new topic.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicEditBox::Topic(CTopic* pTopic)
{
	// Commit changes to current topic.
	Commit();

	// Display new topic.
	m_pTopic = pTopic;
	Text(m_pTopic->Text());
}

/******************************************************************************
** Method:		Modified()
**
** Description:	Set the dirty flag on the topic.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicEditBox::Modified(void)
{
	m_bModified = TRUE;
}

/******************************************************************************
** Method:		Commit()
**
** Description:	Commit any changes in the edit box back to the topic.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicEditBox::Commit(void)
{
	// Displaying a topic and modified?
	if ( (m_pTopic) && (m_bModified) )
	{
		// Copy text back to topic.
		CString strText = Text();
		m_pTopic->Text(strText);
	}

	// Reset dirty flag.
	m_bModified = FALSE;
}
