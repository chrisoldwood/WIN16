/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSENUM.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CSessionEnum class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SESSENUM_HPP
#define SESSENUM_HPP

/******************************************************************************
** 
** This is the enumerator for the session list.
**
*******************************************************************************
*/

class CSessionEnum : public CListEnum
{
public:
	//
	// Constructors/Destructor.
	//
	CSessionEnum(const CSessionList& List);
	CSessionEnum(const CSessionList& List, const CDateTime dtStart, const CDateTime dtEnd);

	//
	// Methods.
	//
	CSession* Next(void);
	
protected:
	//
	// Members.
	//
	CDateTime	m_dtStart;
	CDateTime	m_dtEnd;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //SESSENUM_HPP
