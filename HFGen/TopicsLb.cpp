/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICSLB.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTopicsListBox class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdio.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTopicsListBox::CTopicsListBox(void)
{
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

CTopicsListBox::~CTopicsListBox(void)
{
}

/******************************************************************************
** Method:		Refresh()
**
** Description:	Refresh the list of topics.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicsListBox::Refresh(void) const
{
	// Save current selection.
	int iSel = Current();

	// Empty listbox.
	Reset();

	CTopicEnum	Enum(App.Doc()->TopicList());
	CTopic*		pTopic;
	
	// For all topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		int iIdx = Add(pTopic->Name());
		ASSERT(iIdx != LB_ERR);
		
		// Add session as item data.
#ifdef WIN16
		ItemData(iIdx, (LPARAM)(WORD)pTopic);
#else
		ItemData(iIdx, (LPARAM)pTopic);
#endif
    }
    
    // Was current selection?
    if (iSel != LB_ERR)
    	Select(iSel);
    else
    	Select(0);
}
