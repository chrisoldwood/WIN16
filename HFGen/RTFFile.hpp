/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		RTFFILE.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CRTFFile class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef RTFFILE_HPP
#define RTFFILE_HPP

/******************************************************************************
** 
** This class is a CFile derived class used for writing .RTF format files.
**
*******************************************************************************
*/

class CRTFFile : public CFile
{
public:
	//
	// Constructors/Destructor.
	//
	CRTFFile(void);
	~CRTFFile(void);

	//
	// Core methods.
	//
	bool WriteString(const char* pszString);
	bool WriteString(const char* pszString, int iLen);
	
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

inline bool CRTFFile::WriteString(const char* pszString)
{
	return Write(pszString, strlen(pszString));
}

inline bool CRTFFile::WriteString(const char* pszString, int iLen)
{
	return Write(pszString, iLen);
}

/******************************************************************************
**
** Macros for RTF tags.
**
*******************************************************************************
*/

#define	RTF_CRLF			"\r\n"
#define RTF_OPEN_BRACE		"{\r\n"
#define	RTF_CLOSE_BRACE		"}\r\n"
#define	RTF_DOC_START		"{\\rtf\\ansi\r\n"
#define	RTF_DOC_END			"}\r\n"
#define RTF_NEW_LINE		"\\line\r\n"
#define RTF_NEW_PARAGRAPH	"\\par\r\n"
#define RTF_NEW_PAGE		"\\page\r\n\r\n"
#define	RTF_DEF_FONT		"\\deff0\r\n"
#define	RTF_FONT_TABLE		"{\\fonttbl\r\n"
#define RTF_CONTEXT_NAME	"#{\\footnote "
#define	RTF_TITLE			"${\\footnote "
#define RTF_KEYWORDS		"K{\\footnote "
#define RTF_FIXED_REGION	"\\keepn\r\n"
#define RTF_PARAGRAPH_DEFS	"\\pard\r\n"

#endif //RTFFILE_HPP
