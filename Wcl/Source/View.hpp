/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		VIEW.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CView class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef VIEW_HPP
#define VIEW_HPP

/******************************************************************************
** 
** This is the base class for a view window used with SDI and MDI style apps.
**
*******************************************************************************
*/

WCLCLASS CView : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CView(const CWnd& rParent);

	//
	// Methods.
	//
	virtual void Update(void);
	virtual void Commit(void);

protected:
	//
	// Members.
	//
    
	//
	// Internal methods.
	//
	
	//
	// Message processors (Overriden from the base class).
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //VIEW_HPP
