/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CHECKBOX.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CCheckBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

/******************************************************************************
** 
** This is a checkbox control.
**
*******************************************************************************
*/

WCLCLASS CCheckBox : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CCheckBox(void);

	//
	// Standard methods.
	//
	void Check(bool bCheck = TRUE) const;
	bool IsChecked(void) const;

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

inline void CCheckBox::Check(bool bCheck) const
{
	SendMessage(BM_SETCHECK, bCheck, 0);
}

inline bool CCheckBox::IsChecked(void) const
{
	return (bool)SendMessage(BM_GETCHECK, 0, 0);
}

#endif //CHECKBOX_HPP
