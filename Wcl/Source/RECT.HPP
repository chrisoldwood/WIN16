/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		RECT.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CRect class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef RECT_HPP
#define RECT_HPP

/******************************************************************************
** 
** This is a class based version of the standard Windows RECT structure.
**
*******************************************************************************
*/

WCLCLASS CRect : public tagRECT
{
public:
	//
	// Constructors/Destructor.
	//
	CRect(void);
	CRect(int iLeft, int iTop, int iRight, int iBottom);
	CRect(const CPoint& TopLeft, const CPoint& BottomRight);
	CRect(const CPoint& TopLeft, const CSize& Size);
	CRect(LPRECT lprcRect);
	
	//
	// Member access.
	//
	CPoint TopLeft(void) const;
	CPoint BottomRight(void) const;
	CPoint BottomLeft(void) const;
	CPoint TopRight(void) const;

	void Set(int iLeft, int iTop, int iRight, int iBottom);

	//
	// Attributes.
	//
	int Width(void) const;
	int Height(void) const;
	CSize Size(void) const;
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CRect::CRect(void)
{
	Set(0, 0, 0, 0);
}

inline CRect::CRect(int iLeft, int iTop, int iRight, int iBottom)
{
	Set(iLeft, iTop, iRight, iBottom);
}

inline CRect::CRect(const CPoint& TopLeft, const CPoint& BottomRight)
{
	Set(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y);
}

inline CRect::CRect(const CPoint& TopLeft, const CSize& Size)
{
	Set(TopLeft.x, TopLeft.y, TopLeft.x + Size.cx, TopLeft.y + Size.cy);
}

inline CRect::CRect(LPRECT lprcRect)
{
	Set(lprcRect->left, lprcRect->top, lprcRect->right, lprcRect->bottom);
}

inline CPoint CRect::TopLeft(void) const
{
	return CPoint(left, top);
}

inline CPoint CRect::BottomRight(void) const
{
	return CPoint(right, bottom);
}

inline CPoint CRect::BottomLeft(void) const
{
	return CPoint(left, bottom);
}

inline CPoint CRect::TopRight(void) const
{
	return CPoint(right, top);
}

inline void CRect::Set(int iLeft, int iTop, int iRight, int iBottom)
{
	left   = iLeft;
	top    = iTop;
	right  = iRight;
	bottom = iBottom;
}

inline int CRect::Width(void) const
{
	return (right - left);
}

inline int CRect::Height(void) const
{
	return (bottom - top);
}

inline CSize CRect::Size(void) const
{
	return CSize(Width(), Height());
}

#endif //RECT_HPP
