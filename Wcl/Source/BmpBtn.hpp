/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BMPBTN.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CBmpButton class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef BMPBTN_HPP
#define BMPBTN_HPP

/******************************************************************************
** 
** This is a bitmap based button control.
**
*******************************************************************************
*/

WCLCLASS CBmpButton : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CBmpButton(void);

	//
	// Member access.
	//
	void Bitmap(CBitmap* pBmpEnabled, CBitmap* pBmpDisabled, const CPoint& ptOrigin);

protected:
	//
	// Members.
	//
	CBitmap*	m_pBmpEnabled;
	CBitmap*	m_pBmpDisabled;
	CPoint		m_ptOrigin;

	//
	// Message processors.
	//
	virtual void OnDrawItem(uint iID, uint iAction, uint iState, CDC& rDC, const CRect& rcItem);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CBmpButton::Bitmap(CBitmap* pBmpEnabled, CBitmap* pBmpDisabled, const CPoint& ptOrigin)
{
	m_pBmpEnabled  = pBmpEnabled;
	m_pBmpDisabled = pBmpDisabled;
	m_ptOrigin     = ptOrigin;
}

#endif //BMPBTN_HPP
