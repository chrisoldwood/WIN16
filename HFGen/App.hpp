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
	CHelpDoc* Doc(void);
	void Doc(CHelpDoc* pDoc);
	CPrefs& Prefs(void);
	
protected:
	//
	// Members
	//
	CHelpDoc*	m_pDoc;		// The current document.
	CPrefs		m_Prefs;	// Application settings.
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

inline CHelpDoc* CApp::Doc(void)
{
	return m_pDoc;
}

inline void CApp::Doc(CHelpDoc* pDoc)
{
	m_pDoc = pDoc;
}

inline CPrefs& CApp::Prefs(void)
{
	return m_Prefs;
}

#endif CAPP_HPP
