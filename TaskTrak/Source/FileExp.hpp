/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FILEEXP.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CFileExport class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef FILEEXP_HPP
#define FILEEXP_HPP

/******************************************************************************
** 
** This is a CExport derived class, used to export to a file.
**
*******************************************************************************
*/

class CFileExport : public CExport
{
public:
	//
	// Constructors/Destructor.
	//
	CFileExport(const CPath& rFileName);
	~CFileExport(void);

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
	CFile	m_File;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //FILEEXP_HPP
