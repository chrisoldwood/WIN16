/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BATFILE.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CBATFile class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef BATFILE_HPP
#define BATFILE_HPP

/******************************************************************************
** 
** This class is a CFile derived class used for writing .BAT format files.
**
*******************************************************************************
*/

class CBATFile : public CFile
{
public:
	//
	// Constructors/Destructor.
	//
	CBATFile(void);
	~CBATFile(void);

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

inline bool CBATFile::WriteString(const char* pszString)
{
	return Write(pszString, strlen(pszString));
}

inline bool CBATFile::WriteString(const char* pszString, int iLen)
{
	return Write(pszString, iLen);
}

/******************************************************************************
**
** Macros for BAT tags.
**
*******************************************************************************
*/

#define	BAT_CRLF			"\r\n"
#define	BAT_ECHO_OFF		"@ECHO OFF\r\n"
#define	BAT_ECHO_NEWLINE	"ECHO.\r\n"

#endif //BATFILE_HPP
