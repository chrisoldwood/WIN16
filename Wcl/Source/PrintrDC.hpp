/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRINTRDC.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CPrinterDC class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRINTRDC_HPP
#define PRINTRDC_HPP

/******************************************************************************
** 
** This is a CDC derived class that is appropriate for printing. It is
** different from other devices in that a create method must be called to
** actually get an HDC, this is because a CPrinterDC may be around for longer
** than the actual HDC is needed.
**
*******************************************************************************
*/

WCLCLASS CPrinterDC : public CDC
{
public:
	//
	// Constructors/Destructor.
	//
	CPrinterDC(void);
	~CPrinterDC(void);

	bool CreateDC(void);
	void DeleteDC(void);
	
	//
	// Member access.
	//
	const char*	Name(void) const;
	const char*	Driver(void) const;
	const char*	Port(void) const;
	virtual	Device Type(void) const;

	//
	// Commands.
	//
	bool Select(const CWnd* pParent);
	bool Start(const char* pszTitle);
	void Abort(void);
	bool End(void);
	bool StartPage(void);
	bool EndPage(void);

	//
	// Attributes.
	//
	CRect PageArea(void) const;
	CRect PrintableArea(void) const;
	
protected:
	//
	// Members.
	//
	CString		m_strName;		// The human-readable name.
	CString		m_strDriver;	// The printer driver.
	CString		m_strPort;		// The output port.
	bool		m_bValid;		// Device is valid?
	int			m_iLastError;	// Last printing error.
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline const char* CPrinterDC::Name(void) const
{
	return m_strName;
}

inline const char* CPrinterDC::Driver(void) const
{
	return m_strDriver;
}

inline const char* CPrinterDC::Port(void) const
{
	return m_strPort;
}

#endif //PRINTRDC_HPP
