/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FILE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CFile class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef FILE_HPP
#define FILE_HPP

/******************************************************************************
** 
** This class encapsulates I/O to a binary/ASCII file.
**
*******************************************************************************
*/

WCLCLASS CFile
{
public:
	//
	// Constructors/Destructor.
	//
	CFile(void);
	CFile(const CPath& rPath);
	~CFile(void);
	
	//
	// File errors.
	//
	enum Error
	{
		OpenErr,
		CreateErr,
		ReadOnlyErr,
		ReadErr,
		WriteErr,
		FormatErr,
		VersionErr
	};

	//
	// Seek positions.
	//
	enum SeekPos
	{
		Start   = 0,			// From the start of the file.
		Current = 1,			// From the files' current position.
		End     = 2				// From the end of the file.
	};

	//
	// Member access.
	//
	HFILE Handle(void) const;
	CPath& Path(void);

	//
	// Open/Close operations.
	//
	bool Create(void);
	bool Open(int iAccessMode);
	void Close(void);
	bool Delete(void);

	//
	// Data operations.
	//
	bool Read(void* pBuffer, uint iNumBytes);
	bool Read(int8&   rBuffer);
	bool Read(int16&  rBuffer);
	bool Read(int32&  rBuffer);
	bool Read(uint8&  rBuffer);
	bool Read(uint16& rBuffer);
	bool Read(uint32& rBuffer);
	bool Read(CString& rBuffer);

	bool Write(const void* pBuffer, uint iNumBytes);
	bool Write(const int8&   rBuffer);
	bool Write(const int16&  rBuffer);
	bool Write(const int32&  rBuffer);
	bool Write(const uint8&  rBuffer);
	bool Write(const uint16& rBuffer);
	bool Write(const uint32& rBuffer);
	bool Write(const CString& rBuffer);

	//
	// CFile position.
	//
	ulong Pos(void) const;
	void Pos(ulong lNewPos, SeekPos ePos = Start);
	void MoveToStart(void);
	void MoveToEnd(void);
	void SkipBytes(ulong lNumBytes);

	//
	// Others.
	//
	bool LockRegion(ulong lStart, ulong lNumBytes, bool bWait = TRUE);
	void UnLockRegion(ulong lStart, ulong lNumBytes);
	
protected:
	//
	// Members.
	//
	CPath	m_Path;
	HFILE	m_hFile;
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline HFILE CFile::Handle(void) const
{
	return m_hFile;
}

inline CPath& CFile::Path(void)
{
	return m_Path;
}

inline ulong CFile::Pos(void) const
{
	ASSERT(m_hFile != HFILE_ERROR);

	return _llseek(m_hFile, 0, 0);
}

inline void CFile::Pos(ulong lNewPos, SeekPos ePos)
{
	ASSERT(m_hFile != HFILE_ERROR);

	_llseek(m_hFile, lNewPos, ePos);
}

inline void CFile::MoveToStart(void)
{
	ASSERT(m_hFile != HFILE_ERROR);

	_llseek(m_hFile, 0, 0);
}

inline void CFile::MoveToEnd(void)
{
	ASSERT(m_hFile != HFILE_ERROR);

	_llseek(m_hFile, 0, 2);
}

inline void CFile::SkipBytes(ulong lNumBytes)
{
	ASSERT(m_hFile != HFILE_ERROR);

	_llseek(m_hFile, lNumBytes, 1);
}

inline bool CFile::Read(void* pBuffer, uint iNumBytes)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return (_lread(m_hFile, pBuffer, iNumBytes) == iNumBytes);
}

inline bool CFile::Read(int8& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(int8));
}

inline bool CFile::Read(int16& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(int16));
}

inline bool CFile::Read(int32& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(int32));
}

inline bool CFile::Read(uint8&  rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(uint8));
}

inline bool CFile::Read(uint16& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(uint16));
}

inline bool CFile::Read(uint32& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Read(&rBuffer, sizeof(uint32));
}

inline bool CFile::Read(CString& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);
	
	return rBuffer.Read(*this);
}

inline bool CFile::Write(const void* pBuffer, uint iNumBytes)
{
	ASSERT(m_hFile != HFILE_ERROR);

#ifdef WIN16
	return (_lwrite(m_hFile, pBuffer, iNumBytes) == iNumBytes);
#else
	return (_lwrite(m_hFile, (const char*)pBuffer, iNumBytes) == iNumBytes);
#endif
}

inline bool CFile::Write(const int8&  rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(int8));
}

inline bool CFile::Write(const int16& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(int16));
}

inline bool CFile::Write(const int32& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(int16));
}

inline bool CFile::Write(const uint8&  rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(uint8));
}

inline bool CFile::Write(const uint16& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(uint16));
}

inline bool CFile::Write(const uint32& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);

	return Write((void*) &rBuffer, sizeof(uint32));
}

inline bool CFile::Write(const CString& rBuffer)
{
	ASSERT(m_hFile != HFILE_ERROR);
	
	return rBuffer.Write(*this);
}

#endif //FILE_HPP
