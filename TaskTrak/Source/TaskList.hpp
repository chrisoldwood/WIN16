/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TASKLIST.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTaskList class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TASKLIST_HPP
#define TASKLIST_HPP

/******************************************************************************
** 
** This class is used to hold a list of tasks previously used.
**
*******************************************************************************
*/

class CTaskList : public CList
{
public:
	//
	// Constructors/Destructor.
	//
	CTaskList(void);
	~CTaskList(void);
	
	//
	// Methods.
	//
	void Add(const char* pszTask);
	void Remove(const char* pszTask);

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

protected:
	//
	// Members.
	//

	//
	// Methods.
	//
	CString* Find(const char* pszTask) const;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //TASKLIST_HPP
