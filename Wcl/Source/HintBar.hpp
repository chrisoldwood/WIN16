/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HINTBAR.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHintBar class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HINTBAR_HPP
#define HINTBAR_HPP

/******************************************************************************
** 
** This is a child window of InfoLine that is used to display hints about
** operations, such as when moving over menu items.
**
*******************************************************************************
*/

WCLCLASS CHintBar : public CPopupWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CHintBar(const CWnd& rParent);

	//
	// Member setting.
	//
	void Hint(const char* pszHint);
	
protected:
	//
	// Members.
	//
	char	m_szHint[128];
	
	//
	// Message processors.
	//
	virtual	void OnPaint(CDC& rDC);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //HINTBAR_HPP
