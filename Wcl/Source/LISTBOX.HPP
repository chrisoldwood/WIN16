/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LISTBOX.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CListBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef LISTBOX_HPP
#define LISTBOX_HPP

/******************************************************************************
** 
** This is a listbox control.
**
*******************************************************************************
*/

WCLCLASS CListBox : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CListBox(void);

	//
	// Standard methods.
	//
	void Reset(void) const;
	int Count(void) const;
	int Add(const char* pszText) const;
	int Insert(const char* pszText, int iPos) const;
	int Delete(int iItem) const;
	int Find(const char* pszText, int iFirst = -1) const;
	int FindExact(const char* pszText, int iFirst = -1) const;
	void ItemData(int iItem, LPARAM lData) const;
	LPARAM ItemData(int iItem) const;
	void Select(int iItem) const;
	int Select(const char* pszText, int iFirst = -1) const;
	bool Selected(int iItem) const;
	int Current(void) const;
	int TextLength(int iPos) const;
	int Text(char* pszText, int iPos) const;
	CString Text(int iPos) const;

protected:
	//
	// Members.
	//
	
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CListBox::Reset(void) const
{
	SendMessage(LB_RESETCONTENT, 0, 0L);
}

inline int CListBox::Count(void) const
{
	return (int)SendMessage(LB_GETCOUNT, 0, 0L);
}

inline int CListBox::Add(const char* pszText) const
{
	return (int)SendMessage(LB_ADDSTRING, 0, (LPARAM)(LPCSTR) pszText);
}

inline int CListBox::Insert(const char* pszText, int iPos) const
{
	return (int)SendMessage(LB_INSERTSTRING, iPos, (LPARAM)(LPCSTR) pszText);
}

inline int CListBox::Delete(int iItem) const
{
	return (int)SendMessage(LB_DELETESTRING, iItem, 0L);
}

inline int CListBox::Find(const char* pszText, int iFirst) const
{
	return (int)SendMessage(LB_FINDSTRING, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline int CListBox::FindExact(const char* pszText, int iFirst) const
{
	return (int)SendMessage(LB_FINDSTRINGEXACT, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline void CListBox::ItemData(int iItem, LPARAM lData) const
{
	SendMessage(LB_SETITEMDATA, iItem, lData);
}

inline LPARAM CListBox::ItemData(int iItem) const
{
	return SendMessage(LB_GETITEMDATA, iItem, 0L);
}

inline void CListBox::Select(int iItem) const
{
	SendMessage(LB_SETCURSEL, iItem, 0L);
}

inline int CListBox::Select(const char* pszText, int iFirst) const
{
	return (int)SendMessage(LB_SELECTSTRING, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline bool CListBox::Selected(int iItem) const
{
	return (bool) SendMessage(LB_GETSEL, iItem, 0L);
}

inline int CListBox::Current(void) const
{
	return (int) SendMessage(LB_GETCURSEL, 0, 0L);
}

inline int CListBox::TextLength(int iPos) const
{
	return (int)SendMessage(LB_GETTEXTLEN, iPos, 0L);
}

inline int CListBox::Text(char* pszText, int iPos) const
{
	return (int)SendMessage(LB_GETTEXT, iPos, (LPARAM)(LPCSTR) pszText);
}

#endif //LISTBOX_HPP
