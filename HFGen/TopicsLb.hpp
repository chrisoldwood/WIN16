/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TOPICSLB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTopicsListBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TOPICSLB_HPP
#define TOPICSLB_HPP

/******************************************************************************
** 
** This is a list box used to display the list of topics.
**
*******************************************************************************
*/

class CTopicsListBox : public CListBox
{
public:
	//
	// Constructors/Destructor.
	//
	CTopicsListBox(void);
	~CTopicsListBox(void);
	
	//
	// Methods.
	//
	void Refresh(void) const;
	CTopic* CurrentTopic(void) const;

protected:
	//
	// Members.
	//

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

inline CTopic* CTopicsListBox::CurrentTopic(void) const
{
#if defined(M_I86MM)
	return (CTopic*)(WORD) ItemData(Current());
#elif defined(M_I86LM)
	return (CTopic*) ItemData(Current());
#else
	return (CTopic*) ItemData(Current());
#endif
}

#endif //TOPICSLB_HPP
