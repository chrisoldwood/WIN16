/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		DC.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CDC class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef DC_HPP
#define DC_HPP

/******************************************************************************
** 
** This is an abstract base class from which all DCs are derived. All the
** methods are common to all forms of devices.
**
*******************************************************************************
*/

WCLCLASS CDC
{
public:
	//
	// CDC types
	//
	enum Device
	{
		Screen,			// The current display driver.
		Printer,		// A printer.
		Metafile		// A metafile.
	};

	//
	// Constructors/Destructor.
	//
	CDC(void);
	
	//
	// Member access.
	//
	HDC Handle(void) const;

	//
	// This pure virtual function must be overriden in any derived class
	// so that the outside world can find out what type it really is.
	//
	virtual Device Type(void) const = 0;

	//
	// Attributes.
	//
	int HorzRes(void) const;
	int VertRes(void) const;
	CSize TextExtents(const char* pszText) const;

	//
	// State.
	//
	int SaveState(void);
	bool RestoreState(int iState = -1);
	int BkMode(int iMode);

	//
	// Co-ordinate mapping.
	//
    int MapMode(int iMode);
	void MapMode(const CSize& rDeviceUnits, const CSize& rLogicalUnits);
	void ViewportOrigin(int iX, int iY);
	void ViewportOrigin(const CPoint& rptOrigin);
	void LPtoDP(CPoint* pPoints, int iNumPoints) const;
	void DPtoLP(CPoint* pPoints, int iNumPoints) const;
	
	//
	// Pen style.
	//
	void Pen(COLORREF crColour, int iStyle = PS_SOLID, int iWidth = 0);
	void Pen(int iObjectID);

	//
	// Brush style.
	//
	void Brush(COLORREF crColour);
	void Brush(int iObjectID);
	
	//
	// Line drawing.
	//
	void Move(int iX, int iY);
	void Move(const CPoint& rPoint);
	void Line(int iX, int iY);
	void Line(const CPoint& rPoint);
	void Line(int iSX, int iSY, int iDX, int iDY);
	void Line(const CPoint& rSrcPoint, const CPoint& rDstPoint);

	//
	// Shape drawing.
	//
	void Rectangle(const CRect& rRect);
	void Ellipse(const CRect& rRect);

	//
	// 3D features.
	//
	void DrawRecess(const CRect& rRect);
	void DrawExtrusion(const CRect& rRect);
	void DrawBtnUpBorder(const CRect& rRect);
	void DrawBtnDownBorder(const CRect& rRect);
	
	//
	// Text style.
	//
	HFONT CreateFont(int iPtSize, const char* pszFaceName) const;
	void Font(HFONT hFont);
	void Font(int iObjectID);
    COLORREF TextColour(COLORREF crColour);
    COLORREF BkColour(COLORREF crColour);
    
	//
	// Text drawing.
	//
	void TextOut(int iX, int iY, const char* pszText);
	void TextOut(const CPoint& rptOrigin, const char* pszText);
	
	//
	// Bit blitting.
	//
	void Bitmap(const CBitmap& rBitmap);
	void BitBlt(const CBitmap& rBitmap, const CRect& rcSrc, const CRect& rcDst, DWORD dwRop = SRCCOPY);
	void PatBlt(const CRect& rcDst, DWORD dwRop = PATCOPY);
	
protected:
	//
	// Members.
	//
	HDC		m_hDC;				// CDC context.
	bool	m_bRelease;			// Call ReleaseDC on destruction?
	int		m_iState;			// Initial DC state (From SaveDC).
	bool	m_bDelOldPen;		// Old pen needs deleting?
	bool	m_bDelOldBrush;		// Old brush needs deleting?

	//
	// Internal methods.
	//
	void Cleanup(void);
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline HDC CDC::Handle(void) const
{
	return m_hDC;
}

inline int CDC::HorzRes(void) const
{
	return ::GetDeviceCaps(m_hDC, HORZRES);
}

inline int CDC::VertRes(void) const
{
	return ::GetDeviceCaps(m_hDC, VERTRES);
}

inline int CDC::SaveState(void)
{
	return ::SaveDC(m_hDC);
}

inline bool CDC::RestoreState(int iState)
{
	return ::RestoreDC(m_hDC, iState);
}

inline int CDC::BkMode(int iMode)
{
	return ::SetBkMode(m_hDC, iMode);
}

inline void CDC::Move(int iX, int iY)
{
	::MoveToEx(m_hDC, iX, iY, NULL);
}

inline void CDC::Move(const CPoint& rPoint)
{
	::MoveToEx(m_hDC, rPoint.x, rPoint.y, NULL);
}

inline void CDC::Line(int iX, int iY)
{
	::LineTo(m_hDC, iX, iY);
}

inline void CDC::Line(const CPoint& rPoint)
{
	::LineTo(m_hDC, rPoint.x, rPoint.y);
}

inline void CDC::Line(int iSX, int iSY, int iDX, int iDY)
{
	::MoveToEx(m_hDC, iSX, iSY, NULL);
	::LineTo(m_hDC, iDX, iDY);
}

inline void CDC::Line(const CPoint& rSrcPoint, const CPoint& rDstPoint)
{
	::MoveToEx(m_hDC, rSrcPoint.x, rSrcPoint.y, NULL);
	::LineTo(m_hDC, rDstPoint.x, rDstPoint.y);
}

inline void CDC::TextOut(int iX, int iY, const char* pszText)
{
	::TextOut(m_hDC, iX, iY, (LPCSTR)pszText, lstrlen((LPCSTR)pszText));
}

inline void CDC::TextOut(const CPoint& rptOrigin, const char* pszText)
{
	::TextOut(m_hDC, rptOrigin.x, rptOrigin.y, (LPCSTR)pszText, lstrlen((LPCSTR)pszText));
}

inline int CDC::MapMode(int iMode)
{
	return ::SetMapMode(m_hDC, iMode);
}

inline void CDC::ViewportOrigin(int iX, int iY)
{
	::SetViewportOrgEx(m_hDC, iX, iY, NULL);
}

inline void CDC::ViewportOrigin(const CPoint& rptOrigin)
{
	::SetViewportOrgEx(m_hDC, rptOrigin.x, rptOrigin.y, NULL);
}

inline void CDC::LPtoDP(CPoint* pPoints, int iNumPoints) const
{
	::LPtoDP(m_hDC, (LPPOINT) pPoints, iNumPoints);
}

inline void CDC::DPtoLP(CPoint* pPoints, int iNumPoints) const
{
	::DPtoLP(m_hDC, (LPPOINT) pPoints, iNumPoints);
}

inline void CDC::Rectangle(const CRect& rRect)
{
	::Rectangle(m_hDC, rRect.left, rRect.top, rRect.right, rRect.bottom);
}

inline void CDC::Ellipse(const CRect& rRect)
{
	::Ellipse(m_hDC, rRect.left, rRect.top, rRect.right, rRect.bottom);
}

inline COLORREF CDC::TextColour(COLORREF crColour)
{
	return ::SetTextColor(m_hDC, crColour);
}

inline COLORREF CDC::BkColour(COLORREF crColour)
{
	return ::SetBkColor(m_hDC, crColour);
}

inline void CDC::Bitmap(const CBitmap& rBitmap)
{
	SelectBitmap(m_hDC, rBitmap.Handle());
}

inline void CDC::PatBlt(const CRect& rcDst, DWORD dwRop)
{
	::PatBlt(m_hDC, rcDst.left, rcDst.top, rcDst.Width(), rcDst.Height(), dwRop);
}

#endif //DC_HPP
