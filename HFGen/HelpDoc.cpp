/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HELPDOC.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CHelpDoc class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

// The current file version.
#define APP_FILE_VERSION	10

/******************************************************************************
** Method:		Constructor.
**
** Description:	Create a helpfile document which contains a single topic for
**				the contents.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHelpDoc::CHelpDoc(void)
{
	// Set default filename
	m_Path      = "Untitled";
	m_bUntitled = TRUE;
	m_bModified = TRUE;

	// Initialise project settings.
	m_strTitle         = "Title";
	m_strCopyright     = "Copyright";
	m_bCompress        = TRUE;

	m_iHdrParaSpacing  = 0;
	m_iHdrLineSpacing  = 0;
	m_iHdrLeftMargin   = 0;
	m_iHdrRightMargin  = 0;
	m_iHdrBgRed        = 255;
	m_iHdrBgGreen      = 255;
	m_iHdrBgBlue       = 128;

	m_iBodyParaSpacing = 0;
	m_iBodyLineSpacing = 0;
	m_iBodyLeftMargin  = 0;
	m_iBodyRightMargin = 0;
	
	// Create contents topic.
	CTopic* pTopic = new CTopic;
	if (!pTopic)
		return;

	// Initialise topic.
	pTopic->Name("Contents");
	pTopic->ContextName("Contents");
	pTopic->Keywords("Contents");
	pTopic->Text("Contents Page");

	// Add to topics list.
	m_TopicList.Add(pTopic);
}

/******************************************************************************
** Method:		Constructor.
**
** Description:	Create a helpfile document by specifying the path to a file.
**
** Parameters:	rPath	The path to the file.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHelpDoc::CHelpDoc(const CPath& rPath)
{
	// Set default filename
	m_Path      = rPath;
	m_bUntitled = FALSE;
	m_bModified = FALSE;
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

CHelpDoc::~CHelpDoc(void)
{
}

/******************************************************************************
** Method:		Load()
**
** Description:	Load the document.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::Load(void)
{
	CFile	AppFile;

	// Setup up path.
	AppFile.Path() = m_Path;

	// Open file.
	if (!AppFile.Open(OF_READ))
	{
		// File doesn't exist?
		if (!AppFile.Path().Exists())
			return TRUE;
			
		ReportFileError(AppFile.Path(), CFile::OpenErr);
		return FALSE;
	}

	char	szMagic[2];
	uint16	iVersion;

	// Read magic.
	if (!AppFile.Read(szMagic, sizeof(szMagic)))
	{
		ReportFileError(AppFile.Path(), CFile::ReadErr);
		return FALSE;
	}
	
	// Read version number.
	if (!AppFile.Read(iVersion))
	{
		ReportFileError(AppFile.Path(), CFile::ReadErr);
		return FALSE;
	}
	
	// Check header.
	if ( (szMagic[0] != 'H') || (szMagic[1] != 'F') )
	{
		ReportFileError(AppFile.Path(), CFile::FormatErr);
		return FALSE;
	}
	
	// Check version number.
	if (iVersion != APP_FILE_VERSION)
	{
		ReportFileError(AppFile.Path(), CFile::VersionErr);
		return FALSE;
	}
	
	// Read the actual data.
	if (!ReadData(AppFile))
	{
		ReportFileError(AppFile.Path(), CFile::ReadErr);
		return FALSE;
	}
		
	// Done.
	AppFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		ReadData()
**
** Description:	Do the actual reading of data to the file.
**
** Parameters:	rFile		The file to read from.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::ReadData(CFile& rFile)
{
	// Read project settings.
	if (!rFile.Read(m_strTitle))
		return FALSE;
		
	if (!rFile.Read(m_strCopyright))
		return FALSE;

	if (!rFile.Read(m_bCompress))
		return FALSE;

	if (!rFile.Read(m_iHdrParaSpacing))
		return FALSE;

	if (!rFile.Read(m_iHdrLineSpacing))
		return FALSE;

	if (!rFile.Read(m_iHdrLeftMargin))
		return FALSE;

	if (!rFile.Read(m_iHdrRightMargin))
		return FALSE;

	if (!rFile.Read(m_iHdrBgRed))
		return FALSE;

	if (!rFile.Read(m_iHdrBgGreen))
		return FALSE;

	if (!rFile.Read(m_iHdrBgBlue))
		return FALSE;

	if (!rFile.Read(m_iBodyParaSpacing))
		return FALSE;

	if (!rFile.Read(m_iBodyLineSpacing))
		return FALSE;

	if (!rFile.Read(m_iBodyLeftMargin))
		return FALSE;

	if (!rFile.Read(m_iBodyRightMargin))
		return FALSE;

	// Read the list of topics.
	if (!m_TopicList.Read(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		Save()
**
** Description:	Save the document.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::Save(void)
{
	CFile	AppFile;

	// Setup up path.
	AppFile.Path() = m_Path;

	// Create file.
	if (!AppFile.Create())
	{
		// File is read-only?
		if (AppFile.Path().ReadOnly())
			ReportFileError(AppFile.Path(), CFile::ReadOnlyErr);
		else
			ReportFileError(AppFile.Path(), CFile::CreateErr);

		return FALSE;
	}

	char	szMagic[2] = { 'H', 'F' };
	uint16	iVersion   = APP_FILE_VERSION;

	// Write magic.
	if (!AppFile.Write(szMagic, sizeof(szMagic)))
	{
		ReportFileError(AppFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Write version number.
	if (!AppFile.Write(iVersion))
	{
		ReportFileError(AppFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Write the actual data.
	if (!WriteData(AppFile))
	{
		ReportFileError(AppFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Done.
	AppFile.Close();

	// Mark as clean.
	m_bModified = FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		WriteData()
**
** Description:	Do the actual writing of data to the file.
**
** Parameters:	rFile		The file to write to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteData(CFile& rFile)
{
	// Write project settings.
	if (!rFile.Write(m_strTitle))
		return FALSE;
		
	if (!rFile.Write(m_strCopyright))
		return FALSE;

	if (!rFile.Write(m_bCompress))
		return FALSE;

	if (!rFile.Write(m_iHdrParaSpacing))
		return FALSE;

	if (!rFile.Write(m_iHdrLineSpacing))
		return FALSE;

	if (!rFile.Write(m_iHdrLeftMargin))
		return FALSE;

	if (!rFile.Write(m_iHdrRightMargin))
		return FALSE;

	if (!rFile.Write(m_iHdrBgRed))
		return FALSE;

	if (!rFile.Write(m_iHdrBgGreen))
		return FALSE;

	if (!rFile.Write(m_iHdrBgBlue))
		return FALSE;

	if (!rFile.Write(m_iBodyParaSpacing))
		return FALSE;

	if (!rFile.Write(m_iBodyLineSpacing))
		return FALSE;

	if (!rFile.Write(m_iBodyLeftMargin))
		return FALSE;

	if (!rFile.Write(m_iBodyRightMargin))
		return FALSE;

	// Write the list of topics.
	if (!m_TopicList.Write(rFile))
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		WriteRTF()
**
** Description:	Export the document to an RTF file.
**
** Parameters:	rPath	The filename to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteRTF(const CPath& rPath) const
{
	CRTFFile RTFFile;

	// Setup up path.
	RTFFile.Path() = rPath;

	// Create file.
	if (!RTFFile.Create())
	{
		// File is read-only?
		if (RTFFile.Path().ReadOnly())
			ReportFileError(RTFFile.Path(), CFile::ReadOnlyErr);
		else
			ReportFileError(RTFFile.Path(), CFile::CreateErr);

		return FALSE;
	}

	// Export the file.
	if (!WriteRTFHeader(RTFFile))
	{
		ReportFileError(RTFFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	if (!WriteRTFTopics(RTFFile))
	{
		ReportFileError(RTFFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	if (!WriteRTFTrailer(RTFFile))
	{
		ReportFileError(RTFFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Done.
	RTFFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		WriteRTFHeader()
**
** Description:	Export the .RTF file header. This contains the font table and
**				default style settings.
**
** Parameters:	rFile		The file to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteRTFHeader(CRTFFile& rFile) const
{
	const char* pszFont0 = "{\\f0\\froman Times New Roman;}\r\n";
	bool		bError = FALSE;

	bError |= !rFile.WriteString(RTF_DOC_START);
	bError |= !rFile.WriteString(RTF_DEF_FONT);
	bError |= !rFile.WriteString(RTF_FONT_TABLE);
	bError |= !rFile.WriteString(pszFont0);
	bError |= !rFile.WriteString(RTF_CLOSE_BRACE);

	if (bError)
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		WriteRTFTopics()
**
** Description:	Export the HelpFiles' topics.
**
** Parameters:	rFile		The file to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteRTFTopics(CRTFFile& rFile) const
{
	CTopicEnum	Enum(m_TopicList);
	CTopic*		pTopic;
	
	// For all topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		bool bError = FALSE;

		// Write context name footnote.
		bError |= !rFile.WriteString(RTF_CONTEXT_NAME);
		bError |= !rFile.WriteString(pTopic->ContextName());
		bError |= !rFile.WriteString(RTF_CLOSE_BRACE);

		// Write title footnote.
		bError |= !rFile.WriteString(RTF_TITLE);
		bError |= !rFile.WriteString(pTopic->Name());
		bError |= !rFile.WriteString(RTF_CLOSE_BRACE);

		// Write Keywords footnote.
		bError |= !rFile.WriteString(RTF_KEYWORDS);
		bError |= !rFile.WriteString(pTopic->Keywords());
		bError |= !rFile.WriteString(RTF_CLOSE_BRACE);

		// Write topic header.
		bError |= !rFile.WriteString(RTF_FIXED_REGION);
		bError |= !rFile.WriteString(pTopic->Name());
		bError |= !rFile.WriteString(RTF_CRLF);
		bError |= !rFile.WriteString(RTF_NEW_PARAGRAPH);
		bError |= !rFile.WriteString(RTF_PARAGRAPH_DEFS);

		// Write topic text.
		const char* pszText = pTopic->Text();
		
		// For the whole text.
		while(*pszText)
		{
			const char* pszLine = pszText;
			
			// Find the end of the line/paragrapgh/text.
			while ( (*pszLine != '\0') && (*pszLine != '\r') )
				pszLine++;
			
			// Get length of line.
			int iLen = pszLine - pszText;
			
			if (iLen)
			{
				/* Write line of text. */
				bError |= !rFile.WriteString(pszText, iLen);
				bError |= !rFile.WriteString(RTF_CRLF);
			}
			
			/* End of text? */
			if (*pszLine == '\0')
				break;
			
			/* Skip CR/LF. */
			pszLine += 2;
			
			/* Is another CR/LF? */
			if (*pszLine == '\r')
			{
				/* Start a new paragraph. */
				bError |= !rFile.WriteString(RTF_NEW_PARAGRAPH);
				pszLine += 2;
			}
			else
			{
				/* Start a new line. */
				bError |= !rFile.WriteString(RTF_NEW_LINE);
			}
			
			/* Move to next line. */
			pszText = pszLine;
		}
		
		// Write topic end.
		bError |= !rFile.WriteString(RTF_NEW_PAGE);

		if (bError)
			return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		WriteRTFTrailer()
**
** Description:	Export the .RTF file trailer. This is just the EOF marker.
**
** Parameters:	rFile		The file to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteRTFTrailer(CRTFFile& rFile) const
{
	bool bError = FALSE;

	bError |= !rFile.WriteString(RTF_DOC_END);

	if (bError)
		return FALSE;

	return TRUE;
}

/******************************************************************************
** Method:		ReportFileError()
**
** Description:	Report the file error to the user.
**
** Parameters:	rPath	The files' path.
**				eErr	The error.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHelpDoc::ReportFileError(const CPath& rPath, CFile::Error eErr) const
{
	char*		pszMsg      = "";
	const char*	pszFileName = rPath;

	// Decode error.
	switch(eErr)
	{
		case CFile::OpenErr:		pszMsg = "Failed to open the file:\n\n%s";		break;
		case CFile::CreateErr:		pszMsg = "Failed to create the file:\n\n%s";	break;
		case CFile::ReadOnlyErr:	pszMsg = "The file is read-only:\n\n%s";		break;
		case CFile::ReadErr:		pszMsg = "Failed to read from file:\n\n%s";		break;
		case CFile::WriteErr:		pszMsg = "Failed to write to file:\n\n%s";		break;
		case CFile::FormatErr:		pszMsg = "Invalid format for the file:\n\n%s";	break;
		case CFile::VersionErr:		pszMsg = "Invalid version of the file:\n\n%s";	break;
		default:					ASSERT(FALSE);									break;
	}
	
	// Show the message.
	App.AppWnd()->Alert(pszMsg, pszFileName);
}

/******************************************************************************
** Method:		Modified()
**
** Description:	Queries whether the document has been modified since the last
**				save.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

bool CHelpDoc::Modified(void) const
{
	// Ensure changes are committed.
	if (m_pView)
		m_pView->Commit();

	// First check this object.
	if (m_bModified)
		return TRUE;
		
	CTopicEnum	Enum(m_TopicList);
	CTopic*		pTopic;
	
	// Check topics.
	while((pTopic = Enum.Next()) != NULL)
	{
		if (pTopic->Modified())
			return TRUE;
	}
	
	return FALSE;
}

/******************************************************************************
** Method:		WriteHPJ()
**
** Description:	Export the project settings to an HPJ file.
**
** Parameters:	rPath	The filename to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteHPJ(const CPath& rPath) const
{
	CHPJFile HPJFile;

	// Setup up path.
	HPJFile.Path() = rPath;

	// Create file.
	if (!HPJFile.Create())
	{
		// File is read-only?
		if (HPJFile.Path().ReadOnly())
			ReportFileError(HPJFile.Path(), CFile::ReadOnlyErr);
		else
			ReportFileError(HPJFile.Path(), CFile::CreateErr);

		return FALSE;
	}

	// Export the file.
	if (!WriteHPJData(HPJFile))
	{
		ReportFileError(HPJFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Done.
	HPJFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		WriteHPJData()
**
** Description:	Write the actual project settings to the HPJ file.
**
** Parameters:	rFile	The file to write to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteHPJData(CHPJFile& rFile) const
{
	bool bError = FALSE;

	// Write the [Options] section.
	bError |= !rFile.WriteString(HPJ_OPTIONS_SECTION);
	bError |= !rFile.WriteString(HPJ_TITLE_ENTRY);
	bError |= !rFile.WriteString(HPJ_COPYRIGHT_ENTRY);
	bError |= !rFile.WriteString(HPJ_COMPRESS_ENTRY);
	bError |= !rFile.WriteString(HPJ_CONTENTS_ENTRY);
	bError |= !rFile.WriteString(HPJ_KEYPHRASE_ENTRY);
	bError |= !rFile.WriteString(HPJ_WARNING_ENTRY);
	bError |= !rFile.WriteString(HPJ_CRLF);

	// Write the [Files] section.
	bError |= !rFile.WriteString(HPJ_FILES_SECTION);
	bError |= !rFile.WriteString(m_Path.FileTitle());
	bError |= !rFile.WriteString(".RTF");
	bError |= !rFile.WriteString(HPJ_CRLF);
	bError |= !rFile.WriteString(HPJ_CRLF);

	// Write the [Windows] section.
	bError |= !rFile.WriteString(HPJ_WINDOWS_SECTION);
	bError |= !rFile.WriteString(HPJ_MAIN_ENTRY);
	bError |= !rFile.WriteString(HPJ_CRLF);

	if (bError)
		return FALSE;

	return TRUE;
}


/******************************************************************************
** Method:		WriteBAT()
**
** Description:	Write the build file for building the helpfile.
**
** Parameters:	rPath	The filename to export to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteBAT(const CPath& rPath) const
{
	CBATFile BATFile;

	// Setup up path.
	BATFile.Path() = rPath;

	// Create file.
	if (!BATFile.Create())
	{
		// File is read-only?
		if (BATFile.Path().ReadOnly())
			ReportFileError(BATFile.Path(), CFile::ReadOnlyErr);
		else
			ReportFileError(BATFile.Path(), CFile::CreateErr);

		return FALSE;
	}

	// Export the file.
	if (!WriteBATData(BATFile))
	{
		ReportFileError(BATFile.Path(), CFile::WriteErr);
		return FALSE;
	}

	// Done.
	BATFile.Close();

	return TRUE;
}

/******************************************************************************
** Method:		WriteBATData()
**
** Description:	Write the build commands to the build file.
**
** Parameters:	rFile	The file to write to.
**
** Returns:		TRUE or FALSE;
**
*******************************************************************************
*/

bool CHelpDoc::WriteBATData(CBATFile& rFile) const
{
	bool bError = FALSE;

	// Create the project file name.
	CPath strHPJFile = m_Path;
	strHPJFile.Extension("HPJ");

	// Write the header.
	bError |= !rFile.WriteString(BAT_ECHO_OFF);

	// Write the command line.
	bError |= !rFile.WriteString(App.Prefs().CompilerPath());
	bError |= !rFile.WriteString(" ");
	bError |= !rFile.WriteString(strHPJFile);
	bError |= !rFile.WriteString(BAT_CRLF);

	// Write the trailer.
	bError |= !rFile.WriteString(BAT_ECHO_NEWLINE);

	if (bError)
		return FALSE;

	return TRUE;
}
