/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TSKLSTEN.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTaskListEnum class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TSKLSTEN_HPP
#define TSKLSTEN_HPP

/******************************************************************************
** 
** This is the enumerator for the task list.
**
*******************************************************************************
*/

class CTaskListEnum : public CListEnum
{
public:
	//
	// Constructors/Destructor.
	//
	CTaskListEnum(const CTaskList& List);

	//
	// Methods.
	//
	CString* Next(void);
	
protected:
	//
	// Members.
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CTaskListEnum::CTaskListEnum(const CTaskList& List) : CListEnum(List)
{
}

inline CString* CTaskListEnum::Next(void)
{
	return (CString*) CListEnum::Next();
}

#endif //TSKLSTEN_HPP
