/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		FILE.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CFile class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <sys\locking.h>
#include <io.h>

/******************************************************************************
** Method:		Default constructor
**
** Description:	Reset the members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CFile::CFile(void)
{
	m_hFile = HFILE_ERROR;
}

/******************************************************************************
** Method:		Constructor
**
** Description:	Contruction from a full path.
**
** Parameters:	rPath	The files path.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CFile::CFile(const CPath& rPath)
{
	m_Path  = rPath;
	m_hFile = HFILE_ERROR;
}

/******************************************************************************
** Method:		Deconstructor
**
** Description:	Close the file, if open.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CFile::~CFile(void)
{
	if (m_hFile != HFILE_ERROR)
		_lclose(m_hFile);
}

/******************************************************************************
** Method:		Create()
**
** Description:	Create a new file, or open and truncate an existing one.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFile::Create(void)
{
	m_hFile = _lcreat(m_Path, 0);

	// Error?
	if (m_hFile == HFILE_ERROR)
		return FALSE;
		
	return TRUE;
}

/******************************************************************************
** Method:		Open()
**
** Description:	Open an existing file for reading and/or writing.
**
** Parameters:	iAccessMode		Open access mode, as _lopen().
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFile::Open(int iAccessMode)
{
	m_hFile = _lopen(m_Path, iAccessMode);
	
	// Error?
	if (m_hFile == HFILE_ERROR)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		Close()
**
** Description:	Close the file.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFile::Close(void)
{
	ASSERT(m_hFile != HFILE_ERROR);

	_lclose(m_hFile);

	// Reset members.
	m_hFile = HFILE_ERROR;
}

/******************************************************************************
** Method:		Delete()
**
** Description:	Delete the file.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CFile::Delete(void)
{
	// Try and delete it.
	if (_unlink(m_Path) != 0)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		LockRegion()
**
** Description:	Lock a portion of the file. This cannot overlap another region.
**
** Parameters:	lStart		The first byte in the region.
**				lNumBytes	The number of bytes to lock.
**				bWait		Flag whether to wait for the lock.
**
** Returns:		TRUE		On success
**				FALSE		On failure
**
*******************************************************************************
*/

bool CFile::LockRegion(ulong lStart, ulong lNumBytes, bool bWait)
{
	int 	iMode;
	long	lOldPos;
	int		iResult;
		
	// Save old position and 
	// move to start of region.
	lOldPos = Pos();
	Pos(lStart);
		
	// Wait if already locked?
	if (bWait)
		iMode = _LK_LOCK;
	else
		iMode = _LK_NBLCK;
		
	// Lock region and restore position.
	iResult = _locking(m_hFile, iMode, lNumBytes);
	Pos(lOldPos);
    
    // Success?
    if (iResult == 0)
		return TRUE;
		 	
	return FALSE;
}

/******************************************************************************
** Method:		UnLockRegion()
**
** Description:	Unlock a portion of the file. This region must be exactly the
**				same as the region locked.
**
** Parameters:	lStart		The first byte in the region.
**				lNumBytes	The number of bytes to lock.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CFile::UnLockRegion(ulong lStart, ulong lNumBytes)
{
	long lOldPos;
		
	// Save old position and 
	// move to start of region.
	lOldPos = Pos();
	Pos(lStart);
		
	// UnLock region and restore position.
	_locking(m_hFile, _LK_UNLCK, lNumBytes);
	Pos(lOldPos);
}
