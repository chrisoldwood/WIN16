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

	//
	// Methods.
	//
	void UpdateCmds(void);
	void UpdateTitle(void);

protected:
	//
	// Members.
	//
	
	//
	// Message processors.
	//
	virtual bool OnQueryClose(void);

	void OnFileNew(void);
	void OnFileOpen(void);
	void OnFileSave(void);
	void OnFileSaveAs(void);
	void OnFileExport(void);
	void OnFileExit(void);
	void OnEditCut(void);
	void OnEditCopy(void);
	void OnEditPaste(void);
	void OnTopicAdd(void);
	void OnTopicEdit(void);
	void OnTopicDelete(void);
	void OnProjectSettings(void);
	void OnProjectBuild(void);
	void OnProjectTest(void);
	void OnOptionsCompiler(void);
	void OnHelpAbout(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //APPWND_HPP
