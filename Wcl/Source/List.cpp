/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LIST.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CList class definition.
**
*******************************************************************************
*/

#include "wcl.hpp"

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

CList::CList(void)
{
	// Initialise members.
	m_pListHead = NULL;
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

CList::~CList(void)
{
	ListItem*	pItem = m_pListHead;
	ListItem*	pNextItem;

	// For all items.
	while(pItem)
	{
		// Free list item.
		pNextItem = pItem->pNext;
		delete pItem;
		pItem = pNextItem;
	}
}

/******************************************************************************
** Method:		Length()
**
** Description:	Get the number of items in the list.
**
** Parameters:	None.
**
** Returns:		The count.
**
*******************************************************************************
*/

int CList::Length(void) const
{
	int 		iCount = 0;
	ListItem*	pItem = m_pListHead;
	
	// For all items.
	while(pItem)
	{
		iCount++;
		pItem = pItem->pNext;
	}
	
	return iCount;
}

/******************************************************************************
** Method:		Add()
**
** Description:	Add an item to the head of the list.
**
** Parameters:	pItem	The new item.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CList::Add(void* pItem)
{
	// Allocate a new list item.
	ListItem* pNewItem = new ListItem;
	if (!pNewItem)
	{
		ASSERT(FALSE);
		return;
	}

	// Initialise list item.
	pNewItem->pItem = pItem;

	// Add to the head of the list.
	pNewItem->pNext = m_pListHead;
	m_pListHead     = pNewItem;
}

/******************************************************************************
** Method:		Insert()
**
** Description:	Insert an item into the list after the item specified.
**
** Parameters:	pItem		The new item.
**				pPrevItem	The predecessor to the new item.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CList::Insert(void* pItem, void* pPrevItem)
{
	/* Insert at head? */
	if (!pPrevItem)
	{
		Add(pItem);
		return;
	}

	// Get list head.
	ListItem*	pCurr = m_pListHead;
	
	// Find previous item.
	while( (pCurr) && (pCurr->pItem != pPrevItem) )
		pCurr = pCurr->pNext;
		
	ASSERT(pCurr);
	
	// Allocate a new list item.
	ListItem* pNewItem = new ListItem;
	if (!pNewItem)
	{
		ASSERT(FALSE);
		return;
	}

	// Initialise list item.
	pNewItem->pItem = pItem;

	// Add to the list.
	pNewItem->pNext = pCurr->pNext;
	pCurr->pNext    = pNewItem;
}

/******************************************************************************
** Method:		Remove()
**
** Description:	Remove an item from the list.
**
** Parameters:	pItem	The item to remove.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CList::Remove(void* pItem)
{
	// Get list head.
	ListItem*	pCurr = m_pListHead;
	
	// Walk the list.
	while(pCurr)
	{
		// Found it?
		if (pCurr->pItem == pItem)
			break;
		
		// And on...
		pCurr = pCurr->pNext;
	}

	// Found?
	if (!pCurr)
	{
		ASSERT(FALSE);
		return;
	}

	// Is list head?
	if (pCurr == m_pListHead)
	{
		// New list head.
		m_pListHead = pCurr->pNext;
	}
	else
	{
		// Get list head.
		ListItem*	pPrev = m_pListHead;
		
		// Find previous item.
		while (pPrev->pNext != pCurr)
			pPrev = pPrev->pNext;
			
		// Remove from list.
		pPrev->pNext = pCurr->pNext;
	}

	// Delete item.
	delete pCurr;
}
