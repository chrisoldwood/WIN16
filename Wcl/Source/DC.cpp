/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DC.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CDC class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default Constructor.
**
** Description:	Initialise the members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CDC::CDC(void)
{
	m_hDC      = NULL;
	m_bRelease = FALSE;
	m_iState   = 0;
	
	// The initial ones are never deleted.
	m_bDelOldPen   = FALSE;
	m_bDelOldBrush = FALSE;
}

/******************************************************************************
** Method:		Cleanup().
**
** Description:	Clean up any resources in the device before deletion.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Cleanup(void)
{
	// Currently selected pen needs deleting?
	if (m_bDelOldPen)
	{
		HPEN hOldPen = SelectPen(m_hDC, GetStockPen(BLACK_PEN));
		DeletePen(hOldPen);
	}
	
	// Currently selected brush needs deleting?
	if (m_bDelOldBrush)
	{
		HBRUSH hOldBrush = SelectBrush(m_hDC, GetStockBrush(WHITE_BRUSH));
		DeleteBrush(hOldBrush);
	}
}

/******************************************************************************
** Method:		Pen()
**
** Description:	Create a pen of the desired style and select it into the
**				device. Destroy the old pen if approriate.
**
** Parameters:	crColour	The pen colour.
**				iStyle		The pen style.
**				iWidth		The pen width.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Pen(COLORREF crColour, int iStyle, int iWidth)
{
	// Create the new pen and select it
	HPEN hNewPen = CreatePen(iStyle, iWidth, crColour);
	
	ASSERT(hNewPen);
	
	HPEN hOldPen = SelectPen(m_hDC, hNewPen);
	
	// Delete the old one?
	if (m_bDelOldPen)
		DeletePen(hOldPen);
		
	// The new one needs deleting.
	m_bDelOldPen = TRUE;
}

/******************************************************************************
** Method:		Pen()
**
** Description:	Get a stock pen and select it into the device. Destroy the old
**				pen if approriate.
**
** Parameters:	iObjectID	The stock object ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Pen(int iObjectID)
{
	HPEN hOldPen = SelectPen(m_hDC, GetStockPen(iObjectID));
	
	// Delete the old one?
	if (m_bDelOldPen)
		DeletePen(hOldPen);
		
	// This object doesn't need deleting.
	m_bDelOldPen = FALSE;
}

/******************************************************************************
** Method:		Brush()
**
** Description:	Create a brush of the desired style and select it into the
**				device. Destroy the old brush if approriate.
**
** Parameters:	crColour	The brush colour.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Brush(COLORREF crColour)
{
	// Create the new brush and select it
	HBRUSH hNewBrush = CreateSolidBrush(crColour);
	
	ASSERT(hNewBrush);
	
	HBRUSH hOldBrush = SelectBrush(m_hDC, hNewBrush);
	
	// Delete the old one?
	if (m_bDelOldBrush)
		DeleteBrush(hOldBrush);
		
	// The new one needs deleting.
	m_bDelOldBrush = TRUE;
}

/******************************************************************************
** Method:		Brush()
**
** Description:	Get a stock brush and select it into the device. Destroy the old
**				brush if approriate.
**
** Parameters:	iObjectID	The stock object ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Brush(int iObjectID)
{
	HBRUSH hOldBrush = SelectBrush(m_hDC, GetStockBrush(iObjectID));
	
	// Delete the old one?
	if (m_bDelOldBrush)
		DeleteBrush(hOldBrush);
		
	// This object doesn't need deleting.
	m_bDelOldBrush = FALSE;
}

/******************************************************************************
** Method:		DrawRecess()
**
** Description:	Draw a 3D style recessed border.
**
** Parameters:	rRect	The bounding rectangle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::DrawRecess(const CRect& rRect)
{
	// Draw shadow.
	Pen(GetSysColor(COLOR_BTNSHADOW));
	Move(rRect.left,    rRect.bottom-1);
	Line(rRect.left,    rRect.top);
	Line(rRect.right-1, rRect.top);

	// Draw highlight.
	Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
	Line(rRect.right-1, rRect.bottom-1);
	Line(rRect.left,    rRect.bottom-1);

}

/******************************************************************************
** Method:		DrawExtrusion()
**
** Description:	Draw a 3D style raised border.
**
** Parameters:	rRect	The bounding rectangle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::DrawExtrusion(const CRect& rRect)
{
	// Draw highlight.
	Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
	Move(rRect.left,    rRect.bottom-1);
	Line(rRect.left,    rRect.top);
	Line(rRect.right-1, rRect.top);

	// Draw shadow.
	Pen(GetSysColor(COLOR_BTNSHADOW));
	Line(rRect.right-1, rRect.bottom-1);
	Line(rRect.left,    rRect.bottom-1);
}

/******************************************************************************
** Method:		DrawBtnUpBorder()
**
** Description:	Draw a 3D style border for a button in the up state.
**
** Parameters:	rRect	The bounding rectangle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::DrawBtnUpBorder(const CRect& rRect)
{
	// Draw the surrounding border.
	Pen(RGB(0,0,0));
	Line(rRect.left+1,  rRect.top,      rRect.right-1, rRect.top);
	Line(rRect.left,    rRect.top+1,    rRect.left,    rRect.bottom-1);
	Line(rRect.right-1, rRect.top+1,    rRect.right-1, rRect.bottom-1);
	Line(rRect.left+1,  rRect.bottom-1, rRect.right-1, rRect.bottom-1);

	// Draw the 3D lighting.
	DrawExtrusion(CRect(rRect.left+1, rRect.top+1, rRect.right-1, rRect.bottom-1));
}

/******************************************************************************
** Method:		DrawBtnDownBorder()
**
** Description:	Draw a 3D style border for a button in the down state.
**
** Parameters:	rRect	The bounding rectangle.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::DrawBtnDownBorder(const CRect& rRect)
{
	// Draw the surrounding border.
	Pen(RGB(0,0,0));
	Line(rRect.left+1,  rRect.top,      rRect.right-1, rRect.top);
	Line(rRect.left,    rRect.top+1,    rRect.left,    rRect.bottom-1);
	Line(rRect.right-1, rRect.top+1,    rRect.right-1, rRect.bottom-1);
	Line(rRect.left+1,  rRect.bottom-1, rRect.right-1, rRect.bottom-1);

	// Draw the 3D lighting.
	Pen(GetSysColor(COLOR_BTNSHADOW));
	Line(rRect.left+1, rRect.top+1, rRect.right-1, rRect.top+1);
	Line(rRect.left+1, rRect.top+1, rRect.left+1,  rRect.bottom-1);
}

/******************************************************************************
** Method:		Font()
**
** Description:	Select a pre-created font into the device. Destroy the old font
**				if approriate.
**
** Parameters:	hNewFont	A font created with CreateFont() etc.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Font(HFONT hNewFont)
{
	ASSERT(hNewFont);
	
	SelectFont(m_hDC, hNewFont);
}

/******************************************************************************
** Method:		Font()
**
** Description:	Get a stock font and select it into the device.
**
** Parameters:	iObjectID	The stock object ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::Font(int iObjectID)
{
	SelectFont(m_hDC, GetStockFont(iObjectID));
}

/******************************************************************************
** Method:		TextExtents()
**
** Description:	Get the extents for a piece of text. This uses the currently
**				selected font.
**
** Parameters:	pszText		The text, NULL terminated.
**
** Returns:		The dimensions.
**
*******************************************************************************
*/

CSize CDC::TextExtents(const char* pszText) const
{
	CSize Size;

	GetTextExtentPoint(m_hDC, pszText, lstrlen(pszText), &Size);
	
	return Size;
}

/******************************************************************************
** Method:		MapMode()
**
** Description:	Set the mapping mode to an arbitrary scale. The mapping is made
**				as X device units = X logical units and similarly for the Y
**				axis.
**
** Parameters:	rDeviceUnits	These two parameters specify the ratios between
**				rLogicalUnits	pixels and logical units for both X & Y axis.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::MapMode(const CSize& rDeviceUnits, const CSize& rLogicalUnits)
{
	MapMode(MM_ANISOTROPIC);
	SetWindowExtEx(m_hDC,   rLogicalUnits.cx, rLogicalUnits.cy, NULL);
	SetViewportExtEx(m_hDC, rDeviceUnits.cx,  rDeviceUnits.cy, NULL);
}

/******************************************************************************
** Method:		BitBlt()
**
** Description:	BitBlt the bitmap at the position given.
**
** Parameters:	rBitmap		The bitmap to blt.
**				rcSrc		The source bitmap region.
**				rcDst		The destination device region.
**				dwRop		The ROP code to use.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CDC::BitBlt(const CBitmap& rBitmap, const CRect& rcSrc, const CRect& rcDst,
				DWORD dwRop)
{
	CMemDC	SrcDC(*this);

	// Select bitmap into source dc.
	SrcDC.Bitmap(rBitmap);
	
	// Blt it
	::StretchBlt(m_hDC, rcDst.left, rcDst.top, rcDst.Width(), rcDst.Height(),
				SrcDC.Handle(), rcSrc.left, rcSrc.top, rcSrc.Width(), rcSrc.Height(),
				dwRop);
}

/******************************************************************************
** Method:		CreateFont()
**
** Description:	Creates a font of the given point size and face name for the
**				device.
**
** Parameters:	iPtSize		The font height in points.
**				pszFaceName	The name of the font.
**
** Returns:		The font or NULL.
**
*******************************************************************************
*/

HFONT CDC::CreateFont(int iPtSize, const char* pszFaceName) const
{
	ASSERT(m_hDC);

	// Convert point size to pixels.
	int iHeight = - ((iPtSize * ::GetDeviceCaps(m_hDC, LOGPIXELSY)) / 72);
	
	return ::CreateFont(iHeight, 0, 0, 0, FW_DONTCARE, 0, 0, 0,
							DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
							CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
							DEFAULT_PITCH | FF_DONTCARE, pszFaceName);
}
