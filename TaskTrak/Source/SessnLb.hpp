/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSNLB.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CSessionListBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SESSNLB_HPP
#define SESSNLB_HPP

/******************************************************************************
** 
** This is a list box used to display the list of sessions.
**
*******************************************************************************
*/

class CSessionListBox : public CListBox
{
public:
	//
	// Constructors/Destructor.
	//
	CSessionListBox(void);
	~CSessionListBox(void);
	
	//
	// Methods.
	//
	void Refresh(void) const;
	CSession* CurrSession(void) const;

protected:
	//
	// Members.
	//

	//
	// Message processors.
	//
	virtual void OnCreate(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CSession* CSessionListBox::CurrSession(void) const
{
#if defined(M_I86MM)
	return (CSession*)(WORD) ItemData(Current());
#elif defined(M_I86LM)
	return (CSession*) ItemData(Current());
#else
	return (CSession*) ItemData(Current());
#endif
}

#endif //SESSNLB_HPP
