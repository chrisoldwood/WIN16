/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TASKLIST.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CTaskList class definition.
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

CTaskList::CTaskList(void)
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

CTaskList::~CTaskList(void)
{
	CTaskListEnum	Enum(*this);
	CString*		pString;
	
	// Free all tasks.
	while((pString = Enum.Next()) != NULL)
		delete pString;
}

/******************************************************************************
** Method:		Add()
**
** Description:	Add a task to the list if not already in it.
**
** Parameters:	pszTask		The task.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTaskList::Add(const char* pszTask)
{
	// String already in list?.
	CString* pString = Find(pszTask);
	if (pString)
		return;

	// Make a copy.
	pString = new CString(pszTask);
	ASSERT(pString);

	// And add it.
	CList::Add((void*)pString);
}

/******************************************************************************
** Method:		Remove()
**
** Description:	Remove the task from the list.
**
** Parameters:	pszTask		The task.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTaskList::Remove(const char* pszTask)
{
	// Find the string.
	CString* pString = Find(pszTask);
	ASSERT(pString);

	// And delete.
	CList::Remove((void*)pString);
	delete pString;
}

/******************************************************************************
** Method:		Find()
**
** Description:	Finds a task in the list.
**
** Parameters:	pszTask		The task.
**
** Returns:		The string if found or NULL.
**
*******************************************************************************
*/

CString* CTaskList::Find(const char* pszTask) const
{
	CTaskListEnum	Enum(*this);
	CString*		pString;
	
	// For all tasks.
	while((pString = Enum.Next()) != NULL)
	{
		// Match?
		if (*pString == pszTask)
			return pString;
	}

	return NULL;
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a task list from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTaskList::Read(CFile& rFile)
{
	CString*	pTask;
	int16 		iCount;
	
	// Read count.
	if (!rFile.Read(iCount))
		return FALSE;

	// Read tasks.
	while(iCount--)
	{
		pTask = new CString;
		ASSERT(pTask);

		if (!pTask->Read(rFile))
			return FALSE;

		CList::Add(pTask);
	}

	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a task list to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CTaskList::Write(CFile& rFile)
{
	CTaskListEnum	Enum(*this);
	CString*		pTask;
	int16			iCount = (int16) Length();
	
	// Write count.
	if (!rFile.Write(iCount))
		return FALSE;
	
	// Write tasks.
	while((pTask = Enum.Next()) != NULL)
	{
		if (!pTask->Write(rFile))
			return FALSE;
	}
	
	return TRUE;
}
