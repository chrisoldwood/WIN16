/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HASHTBLE.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHashTable class definition.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "hashtble.hpp"

/******************************************************************************
** Method:		Default constructor
**
** Description:	Initialise members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHashTable::CHashTable(void)
{
	m_pTable    = NULL;
	m_iSize     = 0;
	m_iNumItems = 0;
}

/******************************************************************************
** Method:		Constructor
**
** Description:	Construct a hash table of the given size.
**
** Parameters:	iSize	The size of the table.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHashTable::CHashTable(uint iSize)
{
	m_pTable    = NULL;
	m_iSize     = iSize;
	m_iNumItems = 0;
}

/******************************************************************************
** Method:		Alloc()
**
** Description:	Allocate space for the table.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHashTable::Alloc(void)
{
	ASSERT(m_iSize);
	
	// Allocate table.
	m_pTable = new HashItem*[m_iSize];

	// Initialise table.
	for (uint i=0; i < m_iSize; i++)
		m_pTable[i] = NULL;
}

/******************************************************************************
** Method:		Free()
**
** Description:	Destroys the hash table.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHashTable::Free(void)
{
	delete[] m_pTable;
	m_pTable = NULL;
}

/******************************************************************************
** Method:		Add()
**
** Description:	Sets up a mapping between two values. It using chaining to
**				handle collisions.
**
** Parameters:	lKey	The value searches will be made on.
**				lItem	The value the search value maps to.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHashTable::Add(ulong lKey, ulong lItem)
{
	// Table allocated?
	if (!m_iNumItems)
		Alloc();

	// Allocate a new item.
	HashItem*	pNewItem = new HashItem;
	if (!pNewItem)
		return;

	// Fill in members.
	pNewItem->m_lKey  = lKey;
	pNewItem->m_lItem = lItem;

	// Hash source value.
	uint iIndex = Hash(lKey);
	
	// Add to Table.
	pNewItem->m_pNext = m_pTable[iIndex];
	m_pTable[iIndex]  = pNewItem;

	m_iNumItems++;
}

/******************************************************************************
** Method:		Find()
**
** Description:	Find the item that matches the given key.
**
** Parameters:	lKey	The value to search for.
**
** Returns:		The item or 0.
**
*******************************************************************************
*/

ulong CHashTable::Find(ulong lKey)
{
	// Table allocated?
	if (!m_pTable)
		return 0L;

	// Hash source value.
	uint iIndex = Hash(lKey);

	HashItem* pItem = m_pTable[iIndex];

	// Find in collision chain.
	while(pItem)
	{
		// Match?
		if(pItem->m_lKey == lKey)
			return pItem->m_lItem;
			
		pItem = pItem->m_pNext;
	}

	return 0;
}

/******************************************************************************
** Method:		Delete()
**
** Description:	Delete the item that matches the given key.
**
** Parameters:	lKey	The value to search for.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHashTable::Delete(ulong lKey)
{
	// Hash source value.
	uint iIndex = Hash(lKey);

	HashItem* pItem = m_pTable[iIndex];

	// Find in collision chain.
	while(pItem)
	{
		// Match?
		if(pItem->m_lKey == lKey)
		{
			// List head?
			if (m_pTable[iIndex] == pItem)
			{
				m_pTable[iIndex] = pItem->m_pNext;
			}
			else
			{
				HashItem* pPrev = m_pTable[iIndex];

				// Find previous item.
				while(pPrev->m_pNext != pItem)
					pPrev = pPrev->m_pNext;

				// Unlink item.
				pPrev->m_pNext = pItem->m_pNext;
			}

			// Free memory.
			delete pItem;
			m_iNumItems--;

			// Table empty?
			if (!m_iNumItems)
				Free();

			return;
		}

		pItem = pItem->m_pNext;
	}
}
