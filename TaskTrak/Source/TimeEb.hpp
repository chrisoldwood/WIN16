/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TIMEEB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTimeEditBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TIMEEB_HPP
#define TIMEEB_HPP

/******************************************************************************
** 
** This is an edit box used to display a time.
**
*******************************************************************************
*/

class CTimeEditBox : public CEditBox
{
public:
	//
	// Constructors/Destructor.
	//
	CTimeEditBox(void);
	~CTimeEditBox(void);
	
	//
	// Methods.
	//

protected:
	//
	// Members.
	//

	//
	// Message processors.
	//
	virtual void OnCreate(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //TIMEEB_HPP
