/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DLGVIEW.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CDlgView class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DLGVIEW_HPP
#define DLGVIEW_HPP

/******************************************************************************
** 
** This is a view derived class used when a dialog is the basis of the view.
**
*******************************************************************************
*/

WCLCLASS CDlgView : public CView
{
public:
	//
	// Constructors/Destructor.
	//
	CDlgView(const CWnd& rParent);

protected:
	//
	// Members.
	//
	CDialog*	m_pDialog;
    
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

#endif //DLGVIEW_HPP
