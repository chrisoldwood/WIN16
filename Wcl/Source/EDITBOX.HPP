/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EDITBOX.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CEditBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef EDITBOX_HPP
#define EDITBOX_HPP

/******************************************************************************
** 
** This is an editbox control.
**
*******************************************************************************
*/

WCLCLASS CEditBox : public CLabel
{
public:
	//
	// Constructors/Destructor.
	//
	CEditBox(void);

	//
	// Standard methods.
	//
	void TextLimit(int iLimit) const;
	void ReadOnly(bool bReadOnly = TRUE) const;
	void Select(int iFirstChar = 0, int iLastChar = -1) const;

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

inline void CEditBox::TextLimit(int iLimit) const
{
	SendMessage(EM_LIMITTEXT, iLimit, 0L);
}

inline void CEditBox::ReadOnly(bool bReadOnly) const
{
	SendMessage(EM_SETREADONLY, bReadOnly, 0L);
}

inline void	CEditBox::Select(int iFirstChar, int iLastChar) const
{
	SendMessage(EM_SETSEL, 0, MAKELONG(iFirstChar, iLastChar));
}

#endif //EDITBOX_HPP
