/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DATEEB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CDateEditBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DATEEB_HPP
#define DATEEB_HPP

/******************************************************************************
** 
** This is an edit box used to display a date.
**
*******************************************************************************
*/

class CDateEditBox : public CEditBox
{
public:
	//
	// Constructors/Destructor.
	//
	CDateEditBox(void);
	~CDateEditBox(void);
	
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

#endif //DATEEB_HPP
