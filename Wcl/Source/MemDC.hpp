/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MEMDC.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CMemDC class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MEMDC_HPP
#define MEMDC_HPP

// Forward declaration.
class CWnd;

/******************************************************************************
** 
** This is a Device derived class that is used when creating a dc compatible
** with another dc.
**
*******************************************************************************
*/

WCLCLASS CMemDC : public CDC
{
public:
	//
	// Constructors/Destructor.
	//
	CMemDC(const CDC& rDC);
	~CMemDC(void);
	
	//
	// Member access.
	//
	virtual	Device Type(void) const;
	
protected:
	//
	// Members.
	//
	Device	m_devType;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //MEMDC_HPP
