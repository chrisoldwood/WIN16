/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICLST.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTopicList class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOPICLST_HPP
#define TOPICLST_HPP

/******************************************************************************
** 
** This is the class used to hold the collection of topcs within the document.
**
*******************************************************************************
*/

class CTopicList : public CList
{
public:
	//
	// Constructors/Destructor.
	//
	CTopicList(void);
	~CTopicList(void);

	//
	// Methods.
	//
	void Add(CTopic* pTopic);
	void Remove(CTopic* pTopic);
	CTopic* Find(const char* pszName) const;

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

#endif //TOPICLST_HPP
