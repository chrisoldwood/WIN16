/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICEB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTopicEditBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOPICEB_HPP
#define TOPICEB_HPP

/******************************************************************************
** 
** This is an edit box used to display the topic text.
**
*******************************************************************************
*/

class CTopicEditBox : public CEditBox
{
public:
	//
	// Constructors/Destructor.
	//
	CTopicEditBox(void);
	~CTopicEditBox(void);
	
	//
	// Methods.
	//
	void Topic(CTopic* pTopic);
	void Modified(void);
	void Commit(void);

protected:
	//
	// Members.
	//
	CTopic*		m_pTopic;			// The topic being edited.
	bool		m_bModified;		// Dirty flag for text view.

	//
	// Message processors.
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //TOPICEB_HPP
