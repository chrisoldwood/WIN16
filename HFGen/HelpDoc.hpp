/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HELPDOC.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CHelpDoc class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HELPDOC_HPP
#define HELPDOC_HPP

// Forward references.
class CAppView;

/******************************************************************************
** 
** This is the top level document object.
**
*******************************************************************************
*/

class CHelpDoc
{
public:
	//
	// Constructors/Destructor.
	//
	CHelpDoc(void);
	CHelpDoc(const CPath& rPath);
	~CHelpDoc(void);
	
	//
	// Member access.
	//
	CTopicList& TopicList(void);
	bool Untitled(void) const;
	const CPath& Path(void) const;
	bool Modified(void) const;
	
	void View(CAppView* pView);
	void Path(const CPath& rPath);

	//
	// Properties.
	//
	const CString& Title(void) const;
	const CString& Copyright(void) const;
	bool Compress(void) const;

	int HdrParaSpacing(void) const;
	int HdrLineSpacing(void) const;
	int HdrLeftMargin(void) const;
	int HdrRightMargin(void) const;
	int HdrBgRed(void) const;
	int HdrBgGreen(void) const;
	int HdrBgBlue(void) const;

	int BodyParaSpacing(void) const;
	int BodyLineSpacing(void) const;
	int BodyLeftMargin(void) const;
	int BodyRightMargin(void) const;

	//
	// Serialisation.
	//
	bool Load(void);
	bool Save(void);
	bool WriteRTF(const CPath& rPath) const;
	bool WriteHPJ(const CPath& rPath) const;
	bool WriteBAT(const CPath& rPath) const;

protected:
	//
	// Members.
	//
	CPath		m_Path;				// Path to file.
	bool		m_bUntitled;		// Saved yet flag.
	bool		m_bModified;		// Dirty flag.
	CTopicList	m_TopicList;		// List of topics.
	CAppView*	m_pView;			// View on document.

	//
	// Document settings.
	//
	CString		m_strTitle;			// Title.
	CString		m_strCopyright;		// Copyright notice.
	int16		m_bCompress;		// Compression flag.

	int16		m_iHdrParaSpacing;	// Space between paragraphs.
	int16		m_iHdrLineSpacing;	// Space between paragraph lines.
	int16		m_iHdrLeftMargin;	// Left margin.
	int16		m_iHdrRightMargin;	// Right margin.
	int16		m_iHdrBgRed;		// Header background colour.
	int16		m_iHdrBgGreen;
	int16		m_iHdrBgBlue;

	int16		m_iBodyParaSpacing;	// Space between paragraphs.
	int16		m_iBodyLineSpacing;	// Space between paragraph lines.
	int16		m_iBodyLeftMargin;	// Left margin.
	int16		m_iBodyRightMargin;	// Right margin.

	//
	// Internal methods.
	//
	bool ReadData(CFile& rFile);
	bool WriteData(CFile& rFile);
	bool WriteRTFHeader(CRTFFile& rFile) const;
	bool WriteRTFTopics(CRTFFile& rFile) const;
	bool WriteRTFTrailer(CRTFFile& rFile) const;
	bool WriteHPJData(CHPJFile& rFile) const;
	bool WriteBATData(CBATFile& rFile) const;
	void ReportFileError(const CPath& rPath, CFile::Error eErr) const;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CTopicList& CHelpDoc::TopicList(void)
{
	return m_TopicList;
}

inline bool CHelpDoc::Untitled(void) const
{
	return m_bUntitled;
}

inline const CPath& CHelpDoc::Path(void) const
{
	return m_Path;
}

inline void CHelpDoc::View(CAppView* pView)
{
	m_pView = pView;
}

inline void CHelpDoc::Path(const CPath& rPath)
{
	m_Path      = rPath;
	m_bUntitled = FALSE;
}

inline const CString& CHelpDoc::Title(void) const
{
	return m_strTitle;
}

inline const CString& CHelpDoc::Copyright(void) const
{
	return m_strCopyright;
}

inline bool CHelpDoc::Compress(void) const
{
	return m_bCompress;
}

inline int CHelpDoc::HdrParaSpacing(void) const
{
	return m_iHdrParaSpacing;
}

inline int CHelpDoc::HdrLineSpacing(void) const
{
	return m_iHdrLineSpacing;
}

inline int CHelpDoc::HdrLeftMargin(void) const
{
	return m_iHdrLeftMargin;
}

inline int CHelpDoc::HdrRightMargin(void) const
{
	return m_iHdrRightMargin;
}

#endif //HELPDOC_HPP
