/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LISTENUM.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CListEnum class definition.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	Initialise members.
**
** Parameters:	List	The list.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CListEnum::CListEnum(const CList& List)
{
	m_pCurrItem = List.m_pListHead;
}

/******************************************************************************
** Method:		Next()
**
** Description:	Returns the next item in the list.
**
** Parameters:	None.
**
** Returns:		The next item or NULL.
**
*******************************************************************************
*/

void* CListEnum::Next(void)
{
	// List end?
	if (!m_pCurrItem)
		return NULL;
	
	// Save the current item.
	void* pItem = m_pCurrItem->pItem;
	
	// Move along the list.
	m_pCurrItem = m_pCurrItem->pNext;
	
	return pItem;
}
