/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		POINT.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CPoint class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef POINT_HPP
#define POINT_HPP

// Forward declarations
class CRect;

/******************************************************************************
** 
** This is a class based version of the Windows standard POINT structure.
**
*******************************************************************************
*/

WCLCLASS CPoint : public tagPOINT
{
public:
	//
	// Constructors/Destructor.
	//
	CPoint(void);
	CPoint(int iX, int iY);
	
	//
	// Methods.
	//
	void Set(int iX, int iY);
	bool InRect(const CRect& rcRect) const;
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CPoint::CPoint(void)
{
	Set(0, 0);
}

inline CPoint::CPoint(int iX, int iY)
{
	Set(iX, iY);
}

inline void CPoint::Set(int iX, int iY)
{
	x = iX;
	y = iY;
}

inline bool CPoint::InRect(const CRect& rcRect) const
{
	return PtInRect((LPRECT)&rcRect, *this);
}

#endif //POINT_HPP
