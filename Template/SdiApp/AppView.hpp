/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPVIEW.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAppView class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPVIEW_HPP
#define APPVIEW_HPP

/******************************************************************************
** 
** This is the applications view window.
**
*******************************************************************************
*/

APPCLASS CAppView : public CGfxView
{
public:
	//
	// Constructors/Destructor.
	//
	CAppView(const CWnd& rParent);
	
protected:
	//
	// Members.
	//
	
	//
	// Message processors.
	//
	virtual void OnViewPaint(CDC& rDC);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //APPVIEW_HPP
