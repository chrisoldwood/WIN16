/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LIST.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CList class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef LIST_HPP
#define LIST_HPP

/******************************************************************************
** 
** This is an item in the CList.
**
*******************************************************************************
*/

typedef WCLSTRUCT tagListItem
{
	struct tagListItem*	pNext;
	void*				pItem;
} ListItem;

/******************************************************************************
** 
** This is a singly-linked list class.
**
*******************************************************************************
*/

WCLCLASS CList
{
public:
	//
	// Constructors/Destructor.
	//
	CList(void);
	~CList(void);

	//
	// Methods.
	//
	int Length(void) const;
	void Add(void* pItem);
	void Insert(void* pItem, void* pPrevItem);
	void Remove(void* pItem);
	
protected:
	//
	// Members.
	//
	ListItem*	m_pListHead;

	//
	// Friends.
	//
	friend class CListEnum;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //LIST_HPP
