/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPVIEW.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CAppView class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

// Size of splitter bar.
#define SPLITTER_WIDTH	5

// Child control IDs.
#define IDC_TOPICS		100
#define IDC_TEXT		101

/******************************************************************************
** Method:		Default constructor.
**
** Description:	Override any default settings.
**
** Parameters:	rParent		The views' parent window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CAppView::CAppView(const CWnd& rParent) : CView(rParent)
{
	// Override WNDCLASS members.
//	m_wcClass.hCursor = App.Module()->LoadCursor(IDC_SPLITTER);

	// Define control messages table.
	static CtlMsg CtlMsgs[] = {	IDC_TOPICS,	LBN_SELCHANGE,	(CtlMsgFn)OnSelectTopic,
								IDC_TEXT,	EN_CHANGE,		(CtlMsgFn)OnChangeText,
								0, 			0,				0							};
	
	CtlMsgTable(CtlMsgs);

	// Initialise members.
	m_pDoc       = NULL;
	m_iBarOffset = 100;
}

/******************************************************************************
** Method:		OnCreate()
**
** Description:	Create the child windows for the topic list and topic text.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnCreate(void)
{
	bool bOkay;
	
	// Create the topics listbox.
	bOkay = m_lbTopics.Create(this, IDC_TOPICS, CRect(0, 0, 10, 10));
	ASSERT(bOkay);
	
	// Create the topic text edit box.
	bOkay = m_ebText.Create(this, IDC_TEXT, CRect(0, 0, 10, 10));
	ASSERT(bOkay);
}

/******************************************************************************
** Method:		OnResize()
**
** Description:	Resize the topic and topic text windows to fit the new view
**				window size.
**
** Parameters:	iFlag		The resize type.
**				NewSize		The new size of the window.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnResize(int iFlag, const CSize& NewSize)
{
	CRect rcNewSize;
	
	// Resize the topics listbox
	rcNewSize.Set(0, 0, m_iBarOffset, NewSize.cy);
	m_lbTopics.Move(rcNewSize);
	
	// Resize the topic text edit box.
	rcNewSize.Set(m_iBarOffset+SPLITTER_WIDTH, 0, NewSize.cx, NewSize.cy);
	m_ebText.Move(rcNewSize);
}

/******************************************************************************
** Method:		OnPaint()
**
** Description:	Paint the splitter bar.
**
** Parameters:	rDC		The device to draw on.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnPaint(CDC& rDC)
{
	// Calculate splitter bar dimensions.
	CRect rcClient = ClientRect();
	CRect rcBar(m_iBarOffset, 0, m_iBarOffset+SPLITTER_WIDTH-1, rcClient.bottom);
	
	// Draw background.
	rDC.Brush(GetSysColor(COLOR_BTNFACE));
	rDC.PatBlt(rcBar);
	
	// Draw left/right borders.
	rDC.Pen(BLACK_PEN);
	rDC.Line(rcBar.left,  0, rcBar.left,  rcBar.bottom);
	rDC.Line(rcBar.right, 0, rcBar.right, rcBar.bottom);
	
	// Draw 3D effects.
	rDC.Pen(GetSysColor(COLOR_BTNHIGHLIGHT));
	rDC.Line(rcBar.left+1,  0, rcBar.left+1,  rcBar.bottom);
	rDC.Pen(GetSysColor(COLOR_BTNSHADOW));
	rDC.Line(rcBar.right-1, 0, rcBar.right-1, rcBar.bottom);
}

/******************************************************************************
** Method:		Update()
**
** Description:	Update all elements of the view.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::Update(void)
{
	m_lbTopics.Refresh();
	OnSelectTopic();
}

/******************************************************************************
** Method:		OnSelectTopic()
**
** Description:	Select a new topic to edit.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnSelectTopic(void)
{
	// Get selected topic.
	CTopic*	pTopic = m_lbTopics.CurrentTopic();
	
	// Update the edit control.
	m_ebText.Topic(pTopic);
}

/******************************************************************************
** Method:		OnChangeText()
**
** Description:	Notify the topic text control of changes to the text.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::OnChangeText(void)
{
	// Notify the control of the change.
	m_ebText.Modified();
}

/******************************************************************************
** Method:		Commit()
**
** Description:	Commit any changes back to the document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CAppView::Commit(void)
{
	m_ebText.Commit();
}
