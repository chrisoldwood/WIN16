/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HASHTBLE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHashTable class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HASHTBLE_HPP
#define HASHTBLE_HPP

/******************************************************************************
**
** A general purpose hash-table class.
**
*******************************************************************************
*/

WCLCLASS CHashTable
{
public:
	//
	// Constructors/Destructor.
	//
	CHashTable(void);
	CHashTable(uint iSize);

	//
	// Member access.
	//
	void Size(uint iSize);

	void  Add(ulong lKey, ulong lItem);
	ulong Find(ulong lKey);
	void  Delete(ulong lKey);

protected:
	/******************************************************************************
	**
	** An item in the hash table.
	**
	*******************************************************************************
	*/
	
	typedef struct tagHashItem
	{
		ulong			m_lKey;
		ulong			m_lItem;
		tagHashItem*	m_pNext;
	} HashItem;

	//
	// Members.
	//
	HashItem**	m_pTable;
	uint		m_iSize;
	uint		m_iNumItems;

	//
	// Internal methods.
	//
	void Alloc(void);
	void Free(void);
	uint Hash(ulong lKey);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline uint CHashTable::Hash(ulong lKey)
{
	return (uint) (lKey % m_iSize);
}

inline void CHashTable::Size(uint iSize)
{
	m_iSize = iSize;
}

#endif //HASHTBLE_HPP
