/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BITMAP.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CBitmap class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		LoadRsc()
**
** Description:	Loads a bitmap from the resource file.
**
** Parameters:	iID		The resource ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CBitmap::LoadRsc(uint iID)
{
	ASSERT(m_hBitmap == NULL);

	// Get application object.
	CTask* pApp = CTask::This();
	ASSERT(pApp);
	
	// Load the resource.
	m_hBitmap = pApp->Module()->LoadBitmap(iID);
	
	// Get attributes.
	BITMAP	bmBitmap;
	GetObject(m_hBitmap, sizeof(BITMAP), &bmBitmap);

	// Set members.
	m_Size.cx = bmBitmap.bmWidth;
	m_Size.cy = bmBitmap.bmHeight;
}

/******************************************************************************
** Method:		Create()
**
** Description:	Creates a bitmap of the specified dimensions.
**
** Parameters:	rSize			The bitmap size.
**				iBitsPerPixel	The bitmap depth.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CBitmap::Create(const CSize& rSize, int iBitsPerPixel)
{
	m_hBitmap = CreateBitmap(rSize.cx, rSize.cy, 1, iBitsPerPixel, NULL);
	m_Size    = rSize;
	
	ASSERT(m_hBitmap);
}

/******************************************************************************
** Method:		Create()
**
** Description:	Creates a bitmap compatible with the specifed device.
**
** Parameters:	rSize	The bitmap size.
**				rDC		The dc to be compatible with.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CBitmap::Create(const CSize& rSize, const CDC& rDC)
{
	m_hBitmap = CreateCompatibleBitmap(rDC.Handle(), rSize.cx, rSize.cy);
	m_Size    = rSize;
	
	ASSERT(m_hBitmap);
}
