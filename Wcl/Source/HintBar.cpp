/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HINTBAR.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CHintBar class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings for the window class and style.
**
** Parameters:	rParent		The windows parent.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHintBar::CHintBar(const CWnd& rParent)
{
	// Load string for class name.
	m_strClassName.LoadRsc(IDS_HINTBAR_WND);

	// Override any WNDCLASS members.
	m_wcClass.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1);
	m_wcClass.lpszClassName = m_strClassName;

	// Override WNDINIT members.
	m_wiStyle.pszClassName  = m_strClassName;
	m_wiStyle.dwStyle       = WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE;
	m_wiStyle.rcPos.Set(0, 0, 0, 0);
	m_wiStyle.hParent       = rParent.Handle();
	m_wiStyle.hMenu         = (HMENU) IDS_HINTBAR_WND;
	
	// Clear hint.
	m_szHint[0] = '\0';
}

/******************************************************************************
** Method:		Hint()
**
** Description:	Set the current hint and display it if changed.
**
** Parameters:	pszHint		The hint.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHintBar::Hint(const char* pszHint)
{
	ASSERT(pszHint);

	// Hint different?
	if (lstrcmp(pszHint, (LPCSTR)m_szHint) == 0)
		return;
		
	// Yes, Save it and redraw the window.
	lstrcpy((LPSTR)m_szHint, pszHint);
	RePaintAll();
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Paints the hint window 3D border and hint.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHintBar::OnPaint(CDC& rDC)
{
	// Get the window dimensions.
	CSize Dims = ClientRect().Size();

	// Draw the border.
	CRect rcBorder(CPoint(0,0), Dims);
	rDC.DrawRecess(rcBorder);
	
	// Draw the hint.
	rDC.TextColour(GetSysColor(COLOR_BTNTEXT));
	rDC.BkMode(TRANSPARENT);
	rDC.Font(SYSTEM_FONT);
	rDC.TextOut(2, 0, (const char*)m_szHint);
}
