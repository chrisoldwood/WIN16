/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		RADIOBTN.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CRadioBtn class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef RADIOBTN_HPP
#define RADIOBTN_HPP

/******************************************************************************
** 
** This is a radio button control.
**
*******************************************************************************
*/

WCLCLASS CRadioBtn : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CRadioBtn(void);

	//
	// Standard methods.
	//
	void Select(bool bSelect = TRUE) const;
	bool IsSelected(void) const;

protected:
	//
	// Members.
	//
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CRadioBtn::Select(bool bSelect) const
{
	SendMessage(BM_SETCHECK, bSelect, 0);
}

inline bool CRadioBtn::IsSelected(void) const
{
	return (bool)SendMessage(BM_GETCHECK, 0, 0);
}

#endif //RADIOBTN_HPP
