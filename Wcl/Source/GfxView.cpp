/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		GFXVIEW.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CGfxView class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	rParent		The windows parent.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CGfxView::CGfxView(const CWnd& rParent) : CView(rParent)
{
 	// Override WNDINIT members.
	m_wiStyle.dwStyle |= WS_VSCROLL | WS_HSCROLL;

 	// Make whole view visible.
	m_iMapMode = MM_TEXT;
	m_dmLogExtents.Set(1, 1);
	m_ptWndOrigin.Set(0, 0);
	m_dmWndSize.Set(1, 1);

	// Default scrolling values.
    m_iLineSize = 10;
    m_iPageSize = 50;
}

/******************************************************************************
** Method:		MapMode()
**
** Description:	Set the mapping mode to one of the pre-defined types, this only
**				supports MM_TEXT at the moment.
**
** Parameters:	iMode	The mapping mode.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::MapMode(int iMode)
{
	ASSERT(iMode == MM_TEXT);

	m_iMapMode = iMode;
}

/******************************************************************************
** Method:		MapMode()
**
** Description:	Set the mapping mode to an Anisotropic one.
**
** Parameters:	rDeviceUnits	These two parameters specify the ratios between
**				rLogicalUnits	pixels and logical units for both X & Y axis.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::MapMode(const CSize& rDeviceUnits, const CSize& rLogicalUnits)
{
	m_iMapMode       = MM_ANISOTROPIC;
	m_dmDeviceUnits  = rDeviceUnits;
	m_dmLogicalUnits = rLogicalUnits;
}

/******************************************************************************
** Method:		Size()
**
** Description:	Set the size of the view in logical units.
**
** Parameters:	rExtents	The logical size of the window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::Size(const CSize& rExtents)
{
	m_dmLogExtents = rExtents;
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Setup the device for painting, i.e. setup the mapping mode
**				then call the logical paint handler.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::OnPaint(CDC& rDC)
{
	//
	// Setup mapping mode.
	//
	if (m_iMapMode == MM_ANISOTROPIC)
	{
		// Its a custom mode.
		rDC.MapMode(MM_ANISOTROPIC);
		rDC.MapMode(m_dmDeviceUnits, m_dmLogicalUnits);
	}
	else
	{
		// Its a pre-defined one.
		rDC.MapMode(m_iMapMode);
	}
	
	// Adjust the origin.
	rDC.ViewportOrigin(-m_ptWndOrigin.x, -m_ptWndOrigin.y);
	
	// Call the real paint handler.
	OnViewPaint(rDC);
}

/******************************************************************************
** Method:		LogicalXToDeviceX()
**
** Description:	Convert a logical X value into a device X value.
**
** Parameters:	iX		The logical value.
**
** Returns:		The device value.
**
*******************************************************************************
*/

int CGfxView::LogicalXToDeviceX(int iX)
{
	// Already in pixels?
	if (m_iMapMode == MM_TEXT)
		return iX;
	
	return (iX / m_dmLogicalUnits.cx) * m_dmDeviceUnits.cx;
}

/******************************************************************************
** Method:		LogicalYToDeviceY()
**
** Description:	Convert a logical Y value into a device Y value.
**
** Parameters:	iY		The logical value.
**
** Returns:		The device value.
**
*******************************************************************************
*/

int CGfxView::LogicalYToDeviceY(int iY)
{
	// Already in pixels?
	if (m_iMapMode == MM_TEXT)
		return iY;
	
	return (iY / m_dmLogicalUnits.cy) * m_dmDeviceUnits.cy;
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	Window has been resized. Update the scroll bars.
**				NB: This method can be called recursively if a call to
**				SetScrollRange() causes an scrollbar to appear or disappear.
**				The worst case if 3 levels of recursion, where a resize causes
**				a scrollbar to become (in)visible, which in turn causes the
**				other scrollbar to become (in)visible.
**
** Parameters:	iFlag		The resize method.
**				rNewSize	The new window dimensions.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::OnResize(int iFlag, const CSize& rNewSize)
{
	CSize dmClient = rNewSize;

	// Get the dimensions of the view in pixels.
	int iRealWidth  = LogicalXToDeviceX(m_dmLogExtents.cx);
	int iRealHeight = LogicalYToDeviceY(m_dmLogExtents.cy);

	// Need a horizontal scrollbar?
	if (dmClient.cx >= iRealWidth)
	{
		// Update viewport.
		m_ptWndOrigin.x = 0;

		// Hide the scrollbar.
		HorzScrollRange(0, 0);
    }
    else
    {
    	int iMax = iRealWidth - dmClient.cx;
    	
    	// Clip position to max.
    	if (m_ptWndOrigin.x > iMax)
			m_ptWndOrigin.x = iMax;

    	// Setup scrollbar
    	HorzScrollPos(m_ptWndOrigin.x, FALSE);
    	HorzScrollRange(0, iMax);
    }

	// Update rect in case we've recursed.
	CRect rcClient = ClientRect();
	dmClient = rcClient.Size();
	    
	// Need a vertical scrollbar?
	if (dmClient.cy >= iRealHeight)
	{
		// Update viewport.
		m_ptWndOrigin.y = 0;

		// Hide the scrollbar.
		VertScrollRange(0, 0);
    }
    else
    {
    	int iMax = iRealHeight - dmClient.cy;
    	
    	// Clip position to max.
    	if (m_ptWndOrigin.y > iMax)
			m_ptWndOrigin.y = iMax;

    	// Setup scrollbar
    	VertScrollPos(m_ptWndOrigin.y, FALSE);
    	VertScrollRange(0, iMax);
    }

	// Update rect in case we've recursed and 
	// remeber the window size.
	rcClient = ClientRect();
	m_dmWndSize = rcClient.Size();
}

/******************************************************************************
** Methods:		OnHorizScroll()
**
** Description:	User has moved the horizontal scroll bar.
**
** Parameters:	iCode		How the scroll bar was moved.
**				iPos		Position of scroll bar for SB_THUMB*.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::OnHorizScroll(uint iCode, uint iPos)
{
	// Ignore SB_ENDSCROLL
	if (iCode == SB_ENDSCROLL)
		return;
	
	// Get current value.
	int iCurrPos = HorzScrollPos();
	
	// Calculate position max.
	int iMax = LogicalXToDeviceX(m_dmLogExtents.cx) - m_dmWndSize.cx;
	
	// Scroll how?
	switch(iCode)
	{
		case SB_TOP:
			iCurrPos = 0;
			break;
			
		case SB_BOTTOM:
			iCurrPos = iMax;
			break;
		
		case SB_LINEUP:
			iCurrPos -= LogicalXToDeviceX(m_iLineSize);
			break;
			
		case SB_LINEDOWN:
			iCurrPos += LogicalXToDeviceX(m_iLineSize);
			break;
			
		case SB_PAGEUP:
			iCurrPos -= LogicalXToDeviceX(m_iPageSize);
			break;
			
		case SB_PAGEDOWN:
			iCurrPos += LogicalXToDeviceX(m_iPageSize);
			break;
			
	    case SB_THUMBTRACK:
	    	iCurrPos = iPos;
	    	break;

	    case SB_THUMBPOSITION:
	    case SB_ENDSCROLL:
	    default:
	    	// Do nothing.
	    	break;
	}

	// Clip position.
	if (iCurrPos < 0)		iCurrPos = 0;
	if (iCurrPos > iMax)	iCurrPos = iMax;
	
	// Any change?
	if (m_ptWndOrigin.x != iCurrPos)
	{
		// Set new position.
		m_ptWndOrigin.x = iCurrPos;
		HorzScrollPos(m_ptWndOrigin.x);
		RePaintAll();
	}
}

/******************************************************************************
** Methods:		OnVertScroll()
**
** Description:	User has moved the vertical scroll bar.
**
** Parameters:	iCode		How the scroll bar was moved.
**				iPos		Position of scroll bar for SB_THUMB*.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::OnVertScroll(uint iCode, uint iPos)
{
	// Ignore SB_ENDSCROLL
	if (iCode == SB_ENDSCROLL)
		return;
	
	// Get current value.
	int iCurrPos = VertScrollPos();
	
	// Calculate position max.
	int iMax = LogicalYToDeviceY(m_dmLogExtents.cy) - m_dmWndSize.cy;
	
	// Scroll how?
	switch(iCode)
	{
		case SB_TOP:
			iCurrPos = 0;
			break;
			
		case SB_BOTTOM:
			iCurrPos = iMax;
			break;
		
		case SB_LINEUP:
			iCurrPos -= LogicalYToDeviceY(m_iLineSize);
			break;
			
		case SB_LINEDOWN:
			iCurrPos += LogicalYToDeviceY(m_iLineSize);
			break;
			
		case SB_PAGEUP:
			iCurrPos -= LogicalYToDeviceY(m_iPageSize);
			break;
			
		case SB_PAGEDOWN:
			iCurrPos += LogicalYToDeviceY(m_iPageSize);
			break;
			
	    case SB_THUMBTRACK:
	    	iCurrPos = iPos;
	    	break;

	    case SB_THUMBPOSITION:
	    case SB_ENDSCROLL:
	    default:
	    	// Do nothing.
	    	break;
	}

	// Clip position.
	if (iCurrPos < 0)		iCurrPos = 0;
	if (iCurrPos > iMax)	iCurrPos = iMax;
	
	// Any change?
	if (m_ptWndOrigin.y != iCurrPos)
	{
		// Set new position.
		m_ptWndOrigin.y = iCurrPos;
		VertScrollPos(iCurrPos);
		RePaintAll();
	}
}

/******************************************************************************
** Method:		OnViewPaint()
**
** Description:	The logical paint method
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CGfxView::OnViewPaint(CDC& rDC)
{
}
