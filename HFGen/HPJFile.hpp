/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HPJFILE.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CHPJFile class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HPJFILE_HPP
#define HPJFILE_HPP

/******************************************************************************
** 
** This class is a CFile derived class used for writing .HPJ format files.
**
*******************************************************************************
*/

class CHPJFile : public CFile
{
public:
	//
	// Constructors/Destructor.
	//
	CHPJFile(void);
	~CHPJFile(void);

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

inline bool CHPJFile::WriteString(const char* pszString)
{
	return Write(pszString, strlen(pszString));
}

inline bool CHPJFile::WriteString(const char* pszString, int iLen)
{
	return Write(pszString, iLen);
}

/******************************************************************************
**
** Macros for HPJ tags.
**
*******************************************************************************
*/

#define	HPJ_CRLF			"\r\n"
#define HPJ_OPTIONS_SECTION	"[OPTIONS]\r\n"
#define HPJ_TITLE_ENTRY		"TITLE=Test Help\r\n"
#define HPJ_COPYRIGHT_ENTRY	"COPYRIGHT=(C) Chris Wood 1998.\r\n"
#define HPJ_COMPRESS_ENTRY	"COMPRESS=HIGH\r\n"
#define HPJ_CONTENTS_ENTRY	"CONTENTS=Contents\r\n"
#define HPJ_KEYPHRASE_ENTRY	"OLDKEYPHRASE=NO\r\n"
#define HPJ_WARNING_ENTRY	"WARNING=3\r\n"
#define HPJ_FILES_SECTION	"[FILES]\r\n"
#define HPJ_WINDOWS_SECTION	"[WINDOWS]\r\n"
#define HPJ_MAIN_ENTRY		"MAIN=,,0,,(192,192,192)\r\n"
#define HPJ_ALIAS_SECTION	"[ALIAS]\r\n"
#define HPJ_MAP_SECTION		"[MAP]\r\n"

#endif //HPJFILE_HPP
