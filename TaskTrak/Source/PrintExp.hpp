/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRINTEXP.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CPrintExport class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRINTEXP_HPP
#define PRINTEXP_HPP

/******************************************************************************
** 
** This is a CExport derived class, used to export to a printer.
**
*******************************************************************************
*/

class CPrintExport : public CExport
{
public:
	//
	// Constructors/Destructor.
	//
	CPrintExport(CPrinterDC& rPrinter);
	~CPrintExport(void);

	virtual bool Init(void);
	virtual bool Term(void);
	
	//
	// Methods.
	//
	virtual bool SendLineBreak(void);
	virtual bool SendHeading(const char* pszText);
	virtual bool SendText(const char* pszText);

protected:
	//
	// Members.
	//
	CPrinterDC*	m_pPrinter;
	CRect		m_rcArea;
	HFONT		m_hNormalFont;
	HFONT		m_hHeadingFont;
	int			m_iLineHeight;
	int			m_iPageOffset;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //PRINTEXP_HPP
