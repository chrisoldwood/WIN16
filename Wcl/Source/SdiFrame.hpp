/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SDIFRAME.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CSDIFrame class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SDIFRAME_HPP
#define SDIFRAME_HPP

/******************************************************************************
** 
** This is a frame window derived class used for SDI style apps.
**
*******************************************************************************
*/

WCLCLASS CSDIFrame : public CFrameWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CSDIFrame(void);
	virtual	~CSDIFrame(void);

	//
	// Member access.
	//
	void View(CView* pView);
	CView* View(void);

protected:
	//
	// Members.
	//
	CView*	m_pView;		// Active view.
	
	//
	// Message processors (Overriden from the base class).
	//
	virtual void OnResize(int iFlag, const CSize& NewSize);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CView* CSDIFrame::View(void)
{
	return m_pView;
}

#endif //SDIFRAME_HPP
