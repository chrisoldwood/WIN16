/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LABEL.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CLabel class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef LABEL_HPP
#define LABEL_HPP

/******************************************************************************
** 
** This is a text label.
**
*******************************************************************************
*/

WCLCLASS CLabel : public CCtrlWnd
{
public:
	//
	// Constructors/Destructor.
	//
	CLabel(void);

	//
	// Standard methods.
	//
	int TextLength(void) const;
	void Text(const char* pszText) const;
	void Text(char* pszText, uint iBufSize) const;
	CString Text(void) const;

/*
	void   Int(int iValue) const;
	int    Int(void) const;
	void   UInt(uint iValue) const;
	uint   UInt(void) const;
	void   Long(long lValue) const;
	long   Long(void) const;
	void   ULong(ulong lValue) const;
	ulong  ULong(void) const;
	void   Double(double fValue) const;
	double Double(void) const;
*/

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

inline int CLabel::TextLength(void) const
{
	return (int)SendMessage(WM_GETTEXTLENGTH, 0, 0L);
}

inline void CLabel::Text(const char* pszText) const
{
	SendMessage(WM_SETTEXT, 0, (LPARAM)(LPCSTR)pszText);
}

inline void CLabel::Text(char* pszText, uint iBufSize) const
{
	SendMessage(WM_GETTEXT, iBufSize, (LPARAM)(LPSTR)pszText);
}

#endif //LABEL_HPP
