/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICENM.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTopicEnum class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOPICENM_HPP
#define TOPICENM_HPP

/******************************************************************************
** 
** This is a type-safe class for enumerating a topic collection.
**
*******************************************************************************
*/

class CTopicEnum : public CListEnum
{
public:
	//
	// Constructors/Destructor.
	//
	CTopicEnum(const CTopicList& rList);
	~CTopicEnum(void);
	
	//
	// Methods.
	//
	CTopic* Next(void);
	
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

inline CTopic* CTopicEnum::Next(void)
{
	return (CTopic*) CListEnum::Next();
}

#endif //TOPICENM_HPP
