/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		COMBOBOX.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CComboBox class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP

/******************************************************************************
** 
** This is a combobox control.
**
*******************************************************************************
*/

WCLCLASS CComboBox : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CComboBox(void);

	//
	// Standard methods.
	//
	void Reset(void) const;
	int Count(void) const;
	void TextLimit(int iLimit) const;
	int Add(const char* pszText) const;
	int Insert(const char* pszText, int iPos) const;
	int Delete(int iItem) const;
	int Find(const char* pszText, int iFirst = -1) const;
	int FindExact(const char* pszText, int iFirst = -1) const;
	void ItemData(int iItem, LPARAM lData) const;
	LPARAM ItemData(int iItem) const;
	void Select(int iItem) const;
	int Select(const char* pszText, int iFirst = -1) const;
	int Current(void) const;
	int TextLength(int iPos) const;
	int TextLength(void) const;
	int Text(char* pszText, int iPos) const;
	CString Text(int iPos) const;
	CString Text(void) const;

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

inline void CComboBox::Reset(void) const
{
	SendMessage(CB_RESETCONTENT, 0, 0L);
}

inline int CComboBox::Count(void) const
{
	return (int)SendMessage(CB_GETCOUNT, 0, 0L);
}

inline void CComboBox::TextLimit(int iLimit) const
{
	SendMessage(CB_LIMITTEXT, iLimit, 0L);
}

inline int CComboBox::Add(const char* pszText) const
{
	return (int)SendMessage(CB_ADDSTRING, 0, (LPARAM)(LPCSTR) pszText);
}

inline int CComboBox::Insert(const char* pszText, int iPos) const
{
	return (int)SendMessage(CB_INSERTSTRING, iPos, (LPARAM)(LPCSTR) pszText);
}

inline int CComboBox::Delete(int iItem) const
{
	return (int)SendMessage(CB_DELETESTRING, iItem, 0L);
}

inline int CComboBox::Find( const char* pszText, int iFirst) const
{
	return (int)SendMessage(CB_FINDSTRING, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline int CComboBox::FindExact(const char* pszText, int iFirst) const
{
	return (int)SendMessage(CB_FINDSTRINGEXACT, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline void CComboBox::ItemData(int iItem, LPARAM lData) const
{
	SendMessage(CB_SETITEMDATA, iItem, lData);
}

inline LPARAM CComboBox::ItemData(int iItem) const
{
	return SendMessage(LB_GETITEMDATA, iItem, 0L);
}

inline void CComboBox::Select(int iItem) const
{
	SendMessage(CB_SETCURSEL, iItem, 0L);
}

inline int CComboBox::Select(const char* pszText, int iFirst) const
{
	return (int)SendMessage(CB_SELECTSTRING, iFirst, (LPARAM)(LPCSTR) pszText);
}

inline int CComboBox::Current(void) const
{
	return (int) SendMessage(CB_GETCURSEL, 0, 0L);
}

inline int CComboBox::TextLength(int iPos) const
{
	return (int)SendMessage(CB_GETLBTEXTLEN, iPos, 0L);
}

inline int CComboBox::TextLength(void) const
{
	return (int)SendMessage(WM_GETTEXTLENGTH, 0, 0L);
}

inline int CComboBox::Text(char* pszText, int iPos) const
{
	return (int)SendMessage(CB_GETLBTEXT, iPos, (LPARAM)(LPCSTR) pszText);
}

#endif //COMBOBOX_HPP
