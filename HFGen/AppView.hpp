/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPVIEW.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CAppView class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPVIEW_HPP
#define APPVIEW_HPP

/******************************************************************************
** 
** This is the applications view window.
**
*******************************************************************************
*/

APPCLASS CAppView : public CView
{
public:
	//
	// Constructors/Destructor.
	//
	CAppView(const CWnd& rParent);
	
	//
	// Member access.
	//
	void Doc(CHelpDoc* pDoc);

	//
	// Methods.
	//
	virtual void Update(void);
	virtual void Commit(void);

protected:
	//
	// Members.
	//
	CHelpDoc*		m_pDoc;			// The document.
	CTopicsListBox	m_lbTopics;		// The list of topics.
	CTopicEditBox	m_ebText;		// The topics' text.
	int				m_iBarOffset;	// X Offset of splitter bar.
	
	//
	// Message processors.
	//
	virtual void OnCreate(void);
	virtual void OnResize(int iFlag, const CSize& NewSize);
	virtual	void OnPaint(CDC& rDC);
	
	//
	// Child message processors.
	//
	void OnSelectTopic(void);
	void OnChangeText(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CAppView::Doc(CHelpDoc* pDoc)
{
	m_pDoc = pDoc;
}

#endif //APPVIEW_HPP
