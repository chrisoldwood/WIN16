/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FILEEXP.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CFileExport class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"
#include <stdio.h>

/******************************************************************************
** Method:		Constructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CFileExport::CFileExport(const CPath& rFileName)
{
	// Initialse filename.
	m_File.Path() = rFileName;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CFileExport::~CFileExport(void)
{
}

/******************************************************************************
** Method:		Init()
**
** Description:	Initialise the file by opening it.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFileExport::Init(void)
{
	if (!m_File.Create())
	{
		if (m_File.Path().ReadOnly())
			App.ReportFileError(CFile::ReadOnlyErr, m_File.Path());
		else
			App.ReportFileError(CFile::CreateErr, m_File.Path());

		return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		Term()
**
** Description:	Close the file.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFileExport::Term(void)
{
	m_File.Close();
	return TRUE;
}

/******************************************************************************
** Method:		SendLineBreak()
**
** Description:	Outputs a line break.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFileExport::SendLineBreak(void)
{
	// Write CR/LF.
	if (!m_File.Write("\r\n", 2))
	{
		App.ReportFileError(CFile::WriteErr, m_File.Path());
		return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		SendHeading()
**
** Description:	Outputs the heading for a period.
**
** Parameters:	pszText		The string to output.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFileExport::SendHeading(const char* pszText)
{
	int iLen = strlen(pszText);
	
	// Write string.
	if (!m_File.Write(pszText, iLen))
	{
		App.ReportFileError(CFile::WriteErr, m_File.Path());
		return FALSE;
	}
	
	// Add CR/LF to string.
	if (!SendLineBreak())
		return FALSE;
	
	// Underline string.
	for(int i = 0; i < iLen; i++)
	{
		if (!m_File.Write("-", 1))
		{
			App.ReportFileError(CFile::WriteErr, m_File.Path());
			return FALSE;
		}
	}
	
	// Add CR/LF to underline.
	if (!SendLineBreak())
		return FALSE;

	return TRUE;	
}

/******************************************************************************
** Method:		SendText()
**
** Description:	Outputs a line of text.
**
** Parameters:	pszText		The string to output.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFileExport::SendText(const char* pszText)
{
	// Write string.
	if (!m_File.Write(pszText, strlen(pszText)))
	{
		App.ReportFileError(CFile::WriteErr, m_File.Path());
		return FALSE;
	}
	
	// Add CR/LF to string.
	if (!SendLineBreak())
		return FALSE;
	
	return TRUE;
}
