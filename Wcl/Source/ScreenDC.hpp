/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SCREENDC.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CScreenDC class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SCREENDC_HPP
#define SCREENDC_HPP

// Forward declaration.
class CWnd;

/******************************************************************************
** 
** This is a Device derived class that is appropriate for drawing to the
** display such as painting windows.
**
*******************************************************************************
*/

WCLCLASS CScreenDC : public CDC
{
public:
	//
	// Constructors/Destructor.
	//
	CScreenDC(void);
	CScreenDC(const CWnd* pWnd);
	CScreenDC(PAINTSTRUCT& psPaint);
	CScreenDC(HDC hDC);
	~CScreenDC(void);
	
	//
	// Member access.
	//
	virtual	Device Type(void) const;
	
protected:
	//
	// Members.
	//
	HWND	m_hWnd;			// Window handle of windows' device context.
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //SCREENDC_HPP
