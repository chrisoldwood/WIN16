/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPWND.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAppWnd class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPWND_HPP
#define APPWND_HPP

/******************************************************************************
**
** This is the the applications' real main window.
**
*******************************************************************************
*/

APPCLASS CAppWnd : public CSDIFrame
{
public:
	//
	// Constructors/Destructor.
	//
	CAppWnd(void);
	~CAppWnd(void);

protected:
	//
	// Members.
	//
	
	//
	// Message processors.
	//
	void OnFileExit(void);
	void OnHelpAbout(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //APPWND_HPP
