/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LISTENUM.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CListEnum class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef LISTENUM_HPP
#define LISTENUM_HPP

/******************************************************************************
** 
** This is a simple enumerator for the CList class.
**
*******************************************************************************
*/

WCLCLASS CListEnum
{
public:
	//
	// Constructors/Destructor.
	//
	CListEnum(const CList& List);

	//
	// Methods.
	//
	void* Next(void);
	
protected:
	//
	// Members.
	//
	ListItem*	m_pCurrItem;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //LISTENUM_HPP
