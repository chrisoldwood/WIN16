/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BMPBTN.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CBmpButton class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CBmpButton::CBmpButton(void)
{
	m_wiStyle.pszClassName = "BUTTON";
	m_wiStyle.dwStyle     |= BS_OWNERDRAW;
	
	// Initialise members.
	m_pBmpEnabled  = NULL;
	m_pBmpDisabled = NULL;
}

/******************************************************************************
** Method:		OnDrawItem()
**
** Description:	Draw the button.
**
** Parameters:	See DRAWITEMSTRUCT.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CBmpButton::OnDrawItem(uint iID, uint iAction, uint iState, CDC& rDC,
							const CRect& rcItem)
{
	CRect rcSrc(m_ptOrigin, rcItem.Size());

	// Repaint or Selection change?
	if ( (iAction & ODA_DRAWENTIRE) || (iAction & ODA_SELECT) )
	{
		CPoint ptDst;
		
		// Button down?
		if (iState & ODS_SELECTED)
		{
			ptDst.x = 1;
			ptDst.y = 1;
		}
		// Button up
		else
		{
			ptDst.x = 0;
			ptDst.y = 0;
		}

		CRect rcDst(ptDst, rcItem.Size());

		// Draw button face.
		if (iState & ODS_DISABLED)
			rDC.BitBlt(*m_pBmpDisabled, rcSrc, rcDst);
		else
			rDC.BitBlt(*m_pBmpEnabled, rcSrc, rcDst);
		
		// Draw button border.
		if (iState & ODS_SELECTED)
			rDC.DrawBtnDownBorder(rcItem);
		else
			rDC.DrawBtnUpBorder(rcItem);
	}
}
