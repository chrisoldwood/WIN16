/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APP.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAPP class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APP_HPP
#define APP_HPP

/******************************************************************************
** 
** This is "the" application class.
**
*******************************************************************************
*/

APPCLASS CApp : public CTask
{
public:
	//
	// Constructors/Destructor.
	//
	CApp(void);
	~CApp(void);

	//
	// Initialisation and termination.
	// These are virtual in the base class and must be overriden.
	//
	bool Initialise(void);
	bool Terminate(void);

	//
	// Member access
	//
	CAppWnd* AppWnd(void) const;
};

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

extern CApp App;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CAppWnd* CApp::AppWnd(void) const
{
	return (CAppWnd*) m_pAppWnd;
}

#endif CAPP_HPP
