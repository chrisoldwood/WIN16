/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DLGFRAME.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CDlgFrame class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DLGFRAME_HPP
#define DLGFRAME_HPP

/******************************************************************************
** 
** This is a frame window derived class used in applications that have a dialog
** as their main window.
**
*******************************************************************************
*/

WCLCLASS CDlgFrame : public CFrameWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CDlgFrame(void);
	virtual	~CDlgFrame(void);

	//
	// Member setting.
	//
	void Dialog(CDialog* pDialog);

protected:
	//
	// Members.
	//
	CDialog* m_pAppDlg;		// App window dialog.
	
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

#endif //DLGFRAME_HPP
