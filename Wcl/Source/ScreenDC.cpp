/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SCREENDC.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CScreenDC class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default Constructor.
**
** Description:	Creates a device for the display.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CScreenDC::CScreenDC(void)
{
	m_hWnd     = NULL;
	m_hDC      = GetDC(m_hWnd);
	m_iState   = SaveState();
	m_bRelease = TRUE;
	
	ASSERT(m_hDC);
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Creates a device for a window.
**
** Parameters:	pWindow		The window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CScreenDC::CScreenDC(const CWnd* pWnd)
{
	m_hWnd     = pWnd->Handle();
	m_hDC      = GetDC(m_hWnd);
	m_iState   = SaveState();
	m_bRelease = TRUE;

	ASSERT(m_hDC);
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Creates a device from a PAINTSTRUCT. This is used in reponse
**				to a WM_PAINT message. BeginPaint ia called in the message
**				handler before constructing this. EndPaint is also called
**				in the message handler after use.
**
** Parameters:	psPaint		The filled in WM_PAINT paint structure.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CScreenDC::CScreenDC(PAINTSTRUCT& psPaint)
{
	m_hWnd     = NULL;
	m_hDC      = psPaint.hdc;
	m_iState   = SaveState();
	m_bRelease = FALSE;

	ASSERT(m_hDC);
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Creates a device from another HDC.
**
** Parameters:	hDC		The existing DC.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CScreenDC::CScreenDC(HDC hDC)
{
	m_hWnd     = NULL;
	m_hDC      = hDC;
	m_iState   = SaveState();
	m_bRelease = FALSE;

	ASSERT(m_hDC);
}

/******************************************************************************
** Method:		Destructor
**
** Description:	Cleans up the DC before freeing.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CScreenDC::~CScreenDC(void)
{
	// First delete any selected resources.
	Cleanup();

	// Restore DC to inital settings.
	RestoreState(m_iState);
	
	// Free up DC.
	if (m_bRelease)
		ReleaseDC(m_hWnd, m_hDC);
}

/******************************************************************************
** Method:		Type()
**
** Description:	Returns the actual type of the device. This is used when you
**				need to know the actual device type to perform different
**				drawing actions and you only have a Device.
**
** Parameters:	None.
**
** Returns:		The device enumerated type.
**
*******************************************************************************
*/

CDC::Device CScreenDC::Type(void) const
{
	return Screen;
}
