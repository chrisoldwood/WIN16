/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		EXPORT.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CExport class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef EXPORT_HPP
#define EXPORT_HPP

/******************************************************************************
** 
** This is an abstract class used for the device to export to.
**
*******************************************************************************
*/

class CExport
{
public:
	//
	// Constructors/Destructor.
	//
	virtual bool Init(void) = 0;
	virtual bool Term(void) = 0;
	
	//
	// Methods.
	//
	virtual bool SendLineBreak(void) = 0;
	virtual bool SendHeading(const char* pszText) = 0;
	virtual bool SendText(const char* pszText) = 0;

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

#endif //EXPORT_HPP
