/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		GFXVIEW.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CGfxView class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef GFXVIEW_HPP
#define GFXVIEW_HPP

/******************************************************************************
** 
** This is a view derived class used to create a logical drawing area.
**
*******************************************************************************
*/

WCLCLASS CGfxView : public CView
{
public:
	//
	// Constructors/Destructor.
	//
	CGfxView(const CWnd& rParent);

	//
	// View mapping setup.
	//
    void MapMode(int iMode);
	void MapMode(const CSize& rDeviceUnits, const CSize& rLogicalUnits);
	void Size(const CSize& rExtents);
	void LineScrollSize(int iSize);
	void PageScrollSize(int iSize);

protected:
	//
	// Members.
	//
	int		m_iMapMode;			// Mapping mode.
	CSize	m_dmDeviceUnits;	// MM_ANISOTROPIC device units per...
	CSize	m_dmLogicalUnits;	// ..logical unit.
	CSize	m_dmLogExtents;		// Extents, in logical units.
	CPoint	m_ptWndOrigin;		// View origin.
	CSize	m_dmWndSize;		// Window size.
    int		m_iLineSize;		// Scrollbar line up/down size.
    int		m_iPageSize;		// Scrollbar page up/down size.
    
	//
	// Internal methods.
	//
	int LogicalXToDeviceX(int iX);
	int LogicalYToDeviceY(int iY);
	
	//
	// Message processors (Overriden from the base class).
	//
	virtual	void OnPaint(CDC& rDC);
	virtual void OnResize(int iFlag, const CSize& NewSize);
	virtual void OnHorizScroll(uint iCode, uint iPos);
	virtual void OnVertScroll(uint iCode, uint iPos);

	//
	// View based message processors.
	//
	virtual void OnViewPaint(CDC& rDC);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CGfxView::LineScrollSize(int iSize)
{
	m_iLineSize = iSize;
}

inline void CGfxView::PageScrollSize(int iSize)
{
	m_iPageSize = iSize;
}

#endif //GFXVIEW_HPP
