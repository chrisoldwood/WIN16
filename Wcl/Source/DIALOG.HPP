/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DIALOG.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CDialog class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DIALOG_HPP
#define DIALOG_HPP

/******************************************************************************
** 
** This structure contains all the information used to create a dialog using
** either DialogBox() or CreateDialog().
**
*******************************************************************************
*/

typedef WCLSTRUCT tagDlgInit
{
	HINSTANCE	hInstance;		// Instance handle.
	LPCSTR		lpszTemplate;	// CDialog template name.
	HWND		hParent;		// Parent window.
} DLGINIT;

/******************************************************************************
** 
** This is the base class from which all modal and modeless	dialogs are
** derived. The diaog can be run modal or modeless depending on the method
** used.
**
*******************************************************************************
*/

WCLCLASS CDialog : public CMsgWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CDialog(void);
	~CDialog(void);
	void Parent(const CWnd& rParent);
	
	//
	// Creation methods.
	//
	bool RunModeless(void);
	int RunModal(void);

	//
	// Control attributes.
	//
	HWND CtlHandle(int iCtlID) const;
	void EnableCtl(int iCtlID, bool bEnable = TRUE) const;
	void DisableCtl(int iCtlID, bool bDisable = TRUE) const;

protected:
	/******************************************************************************
	** 
	** An entry in the control table.
	**
	*******************************************************************************
	*/
	
	typedef struct tagControl
	{
		uint		iCtrlID;
		CCtrlWnd*	pCtrl;
	} Control;

	//
	// Members.
	//
	DLGINIT		m_diInit;		// Creation parameters.
	bool		m_bModal;		// Running modal?
	Control*	m_pCtrlTable;	// Table of controls.
	
	//
	// General message handlers.
	//
	virtual	LRESULT WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT DefaultWndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	friend BOOL DIALOGPROC DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

	//
	// Message processors.
	//
	virtual bool OnOk(void);
	virtual bool OnCancel(void);

	//
	// Control methods.
	//
	void CtrlTable(Control* pCtrlTable);
	void InitControls(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CDialog::Parent(const CWnd& rParent)
{
	m_diInit.hParent = rParent.Handle();
}

inline HWND CDialog::CtlHandle(int iCtlID) const
{
	return GetDlgItem(m_hWnd, iCtlID);
}

inline void CDialog::EnableCtl(int iCtlID, bool bEnable) const
{
	EnableWindow(GetDlgItem(m_hWnd, iCtlID), bEnable);
}

inline void CDialog::DisableCtl(int iCtlID, bool bDisable) const
{
	EnableWindow(GetDlgItem(m_hWnd, iCtlID), !bDisable);
}

#endif //DIALOG_HPP
