/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSLIST.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CSessionList class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SESSLIST_HPP
#define SESSLIST_HPP

/******************************************************************************
** 
** This class is used to hold the list of sessions.
**
*******************************************************************************
*/

class CSessionList : public CList
{
public:
	//
	// Constructors/Destructor.
	//
	CSessionList(void);
	~CSessionList(void);
	
	//
	// Methods.
	//
	void Add(const CSession* pSession);

	//
	// File I/O.
	//
	bool Read(CFile& rFile);
	bool Write(CFile& rFile);

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

#endif //SESSLIST_HPP
