/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICLST.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTopicList class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

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

CTopicList::CTopicList(void)
{
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	Delete the members in the list.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTopicList::~CTopicList(void)
{
	CTopicEnum	Enum(*this);
	CTopic*		pTopic;
	
	// Free all topics.
	while((pTopic = Enum.Next()) != NULL)
		delete pTopic;
}

/******************************************************************************
** Method:		Add()
**
** Description:	Add a topic to the list.
**
** Parameters:	pTopic	The topic.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicList::Add(CTopic* pTopic)
{
	ASSERT(pTopic);
	CList::Add((void*)pTopic);
}

/******************************************************************************
** Method:		Remove()
**
** Description:	Remove the item from the list.
**
** Parameters:	pTopic	The topic.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTopicList::Remove(CTopic* pTopic)
{
	ASSERT(pTopic);
	CList::Remove((void*)pTopic);
}

/******************************************************************************
** Method:		Find()
**
** Description:	Finds a topic in the list.
**
** Parameters:	pszName		The name of the topic.
**
** Returns:		The topic if found or NULL.
**
*******************************************************************************
*/

CTopic* CTopicList::Find(const char* pszName) const
{
	CTopicEnum	Enum(*this);
	CTopic*		pTopic;
	
	// For all topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		// Match?
//		if (*pString == pszTask)
//			return pString;
	}

	return NULL;
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read the list from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTopicList::Read(CFile& rFile)
{
	CTopic*	pTopic;
	int16 	iCount;
	
	// Read count.
	if (!rFile.Read(iCount))
		return FALSE;

	// Read topics.
	while(iCount--)
	{
		pTopic = new CTopic;
		ASSERT(pTopic);

		if (!pTopic->Read(rFile))
			return FALSE;

		CList::Add(pTopic);
	}

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write the list to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTopicList::Write(CFile& rFile)
{
	CTopicEnum	Enum(*this);
	CTopic*		pTopic;
	int16		iCount = (int16) Length();
	
	// Write count.
	if (!rFile.Write(iCount))
		return FALSE;
	
	// Write topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		if (!pTopic->Write(rFile))
			return FALSE;
	}
	
	return TRUE;
}
