/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MSGWND.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CMsgWnd class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Initialise members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CMsgWnd::CMsgWnd(void)
{
	m_pCmdMsgTable = NULL;
	m_pCtlMsgTable = NULL;
	
	m_CtlTable.Size(1);
}

/******************************************************************************
** Method:		WndProc()
**
** Description:	This is the base implementation of a CMsgWnd window message
**				handler. It handles all messages common to all popup windows.
**				This is a virtual function and is overriden by derived clases
**				to farm out more specific messages, but should always be called
**				by derived clases to get the default processing.
**				
** Parameters:	Standard window procedure parameters.
**
** Returns:		LRESULT based on the message.
**
*******************************************************************************
*/

LRESULT CMsgWnd::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// Decode message.
	switch(iMsg)
	{
		// Child control message.
		case WM_COMMAND:
#ifdef WIN16
			if (LOWORD(lParam) == NULL)
				OnCmdMsg(wParam);
			else
				OnCtlMsg(wParam, HIWORD(lParam), (HWND)LOWORD(lParam));
#else //WIN32
			if (lParam == NULL)
				OnCmdMsg(LOWORD(wParam));
			else
				OnCtlMsg(LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
#endif
			break;
		
		// Window needs redrawing.	
		case WM_PAINT:
			PAINTSTRUCT psPaint;
			BeginPaint(hWnd, &psPaint);
			{

			// Construct a device and call the paint method.
			CScreenDC	DC(psPaint);
			OnPaint(DC);

			}
			EndPaint(hWnd, &psPaint);
			break;

		// Window resized.
		case WM_SIZE:
			{
			CSize NewSize(LOWORD(lParam), HIWORD(lParam));
			OnResize(wParam, NewSize);
			}
			break;

		// Window is being enabled or disabled.
		case WM_ENABLE:
			//OnEnable((bool)wParam);
			break;
        
		// Timer gone off.
		case WM_TIMER:
			OnTimer(wParam);
			break;

		// Horizontal scrollbar changed.
		case WM_HSCROLL:
			OnHorizScroll(wParam, LOWORD(lParam));
			break;

		// Vertical scrollbar changed.
		case WM_VSCROLL:
			OnVertScroll(wParam, LOWORD(lParam));
			break;

		// Window being shown.
		case WM_SHOWWINDOW:
			OnShow(wParam);
			break;

		// A control needs painting.
		case WM_DRAWITEM:
			{
			DRAWITEMSTRUCT FAR* lpInfo = (DRAWITEMSTRUCT FAR*) lParam;
			
			// Get control object.
			CMsgWnd* pWnd = CtlFromID(lpInfo->CtlID);
			ASSERT(pWnd);
			
			// Construct a paint DC.
			CScreenDC	dcPaint(lpInfo->hDC);
			CRect		rcItem(&lpInfo->rcItem);
			
			pWnd->OnDrawItem(lpInfo->itemID, lpInfo->itemAction, lpInfo->itemState,
								dcPaint, rcItem);
			}
			break;
		
		// Window being destroyed.
		case WM_DESTROY:
			OnDestroy();
			break;
		
		// Call the default handler.
		default:
			return DefaultWndProc(hWnd, iMsg, wParam, lParam);
	}
	
	m_bMsgHandled = TRUE;
	m_lMsgResult  = 0;

	return 0;
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	The window has just been created.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnCreate(void)
{
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Window needs repainting. By default do nothing.
**
** Parameters:	rDC		The device to paint on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnPaint(CDC& rDC)
{
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	Window has been resized. By default do nothing.
**
** Parameters:	iFlag		The resize method.
**				rNewSize	The new window dimensions.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnResize(int iFlag, const CSize& rNewSize)
{
}

/******************************************************************************
** Method:		OnTimer()
**
** Description:	A timer has gone off. By default do nothing.
**
** Parameters:	iTimerID	The timers' ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnTimer(uint iTimerID)
{
}

/******************************************************************************
** Method:		OnShow()
**
** Description:	The window is about to be shown. By default do nothing.
**
** Parameters:	bShowing	Being shown?
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnShow(bool bShowing)
{
}

/******************************************************************************
** Method:		OnDestroy()
**
** Description:	The window is being destroyed. By default do nothing.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnDestroy(void)
{
}

/******************************************************************************
** Methods:		OnHorizScroll()
**				OnVertScroll()
**
** Description:	User has moved a scroll bar.
**
** Parameters:	iCode		How the scroll bar was moved.
**				iPos		Position of scroll bar for SB_THUMB*.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnHorizScroll(uint iCode, uint iPos)
{
}

void CMsgWnd::OnVertScroll(uint iCode, uint iPos)
{
}

/******************************************************************************
** Method:		OnCmdMsg()
**
** Description:	Execute the command.
**
** Parameters:	iID		Menu ID.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnCmdMsg(uint iID)
{
	CmdMsg* pCmdMsg = m_pCmdMsgTable;
	
	// Find command callback function.
	while( (pCmdMsg) && (pCmdMsg->iCmdID) )
	{
		// Match?
		if (pCmdMsg->iCmdID == iID)
		{
			// Execute it.
			(this->*pCmdMsg->lpfnCmdFn)();
			break;
	    }
	    
	    pCmdMsg++;
	}
}

/******************************************************************************
** Methods:		OnCtlMsg()
**
** Description:	A message has been sent by a child control.
**
** Parameters:	iID			Child control ID.
**				iMsg		Control message.
**				hControl	Handle of control window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnCtlMsg(uint iID, uint iMsg, HWND hControl)
{
	CtlMsg* pCtlMsg = m_pCtlMsgTable;
	
	// Find control callback function.
	while( (pCtlMsg) && (pCtlMsg->iCtlID) )
	{
		// Match?
		if ( (pCtlMsg->iCtlID == iID) && (pCtlMsg->iCtlMsg == iMsg) )
		{
			// Execute it.
			(this->*pCtlMsg->lpfnCtlFn)();
			break;
	    }
	    
	    pCtlMsg++;
	}
}

/******************************************************************************
** Method:		OnActivate()
**
** Description:	The window is about to be activated or de-activated.
**
** Parameters:	bActivating		Being activated?
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnActivate(bool bActivating)
{
}

/******************************************************************************
** Method:		OnDrawItem()
**
** Description:	Draw an item of the control.
**
** Parameters:	See DRAWITEMSTRUCT.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMsgWnd::OnDrawItem(uint iID, uint iAction, uint iState, CDC& rDC,
							const CRect& rcItem)
{
	TRACE1("ID: %u\n", iID);
	
	if (iAction & ODA_DRAWENTIRE)
		TRACE("ODA Draw entire\n");

	if (iAction & ODA_FOCUS)
		TRACE("ODA Draw focus\n");

	if (iAction & ODA_SELECT)
		TRACE("ODA Draw select\n");

	if (iState & ODS_CHECKED)
		TRACE("ODS is checked\n");

	if (iState & ODS_DISABLED)
		TRACE("ODS is disabled\n");

	if (iState & ODS_FOCUS)
		TRACE("ODS has focus\n");

	if (iState & ODS_GRAYED)
		TRACE("ODS is grayed\n");

	if (iState & ODS_SELECTED)
		TRACE("ODS is selected\n");

	TRACE4("Pos: (%d, %d)(%d,%d)\n", rcItem.left, rcItem.top, rcItem.right, rcItem.bottom);
	TRACE("\n");
}
