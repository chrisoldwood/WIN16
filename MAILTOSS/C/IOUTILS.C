/*****************************************************************************
** (C) Chris Wood 1995.
**
** IOUTILS.C - File I/O utility functions.
**
******************************************************************************
*/

#include "af.h"
#include <io.h>
#include <dos.h>
#include <direct.h>
#include "ioutils.h"

/**** Global vars. **********************************************************/
char	szFileName[MAX_FILENAME_LEN+1];	/* Temporary filename buffer. */
char szDataBuffer[MAX_DATABUF_LEN+1];	/* Temporary read buffer. */

/*******************************************************************************
** Check if a file exists.
*/
BOOL FAR FileExists(LPSTR lpszFile)
{
	ASSERT(IsValidPtr(lpszFile));
	
	/* First copy to NEAR buffer. */
	lstrcpy(szFileName, lpszFile);
	
	/* Check access mode. */
	if (_access(szFileName, FILE_EXISTS) == FILE_HAS_MODE)
		return TRUE;
	
	return FALSE;
}

/*******************************************************************************
** Check if a file is read-only.
*/
BOOL FAR FileReadOnly(LPSTR lpszFile)
{
	ASSERT(IsValidPtr(lpszFile));
	
	/* First copy to NEAR buffer. */
	lstrcpy(szFileName, lpszFile);
	
	/* Check access mode. */
	if (_access(szFileName, FILE_WRITABLE) != FILE_HAS_MODE)
		return TRUE;
	
	return FALSE;
}

/*******************************************************************************
** Find files in a path. This wraps up the calls to find-first and find-next by
** using the path as the return buffer and the file type as a flag to the first
** or next call.
*/
BOOL FAR FindFile(LPSTR lpszPath, unsigned int FAR *iType)
{
static struct _find_t	FindData;
static char			szFilePath[MAX_FILENAME_LEN+1];

	ASSERT(IsValidPtr(lpszPath));
	ASSERT(IsValidPtr(iType));
	
	/* Check for first or next call. */
	if (*iType != FIND_NEXT)
	{
		/* First copy to NEAR buffer. */
		lstrcpy(szFilePath, lpszPath);
		
		/* Find first file. */
		if (_dos_findfirst(szFilePath, *iType, &FindData) == FILE_FOUND)
		{
			/* Strip search name from path. */
			StripFileName(szFilePath);

			/* Copy filename into buffer. */
			StripFileName(lpszPath);
			lstrcat(lpszPath, FindData.name);
			
			*iType = FIND_NEXT;
			return TRUE;
		}
	}
	else /* *iType == FIND_NEXT */
	{
		/* Find next file. */
		if (_dos_findnext(&FindData) == FILE_FOUND)
		{
			/* Copy filename into buffer. */
			lstrcpy(lpszPath, szFilePath);
			lstrcat(lpszPath, FindData.name);
			return TRUE;
		}
	}
	
	return FALSE;
}

/*******************************************************************************
** Create a full pathname from a path and a filename.
*/
VOID CreateFullPathName(LPSTR lpszDir, LPSTR lpszFile, LPSTR lpszOutput)
{
	UINT iStrLen;
	
	ASSERT(IsValidPtr(lpszDir));
	ASSERT(IsValidPtr(lpszFile));
	ASSERT(IsValidPtr(lpszOutput));

	/* Copy in directory. */
	lstrcpy(lpszOutput, lpszDir);
	
	/* Check for trailing \. */
	iStrLen = lstrlen(lpszDir);
	if (lpszDir[iStrLen-1] != '\\')
		lstrcat(lpszOutput, "\\");
		
	/* Add in file name. */
	lstrcat(lpszOutput, lpszFile);
}

/*******************************************************************************
** Strip the path to leave the filename.
*/
VOID FAR StripPath(LPSTR lpszPath)
{
	LPSTR 	lpszFileName;
	int		iStrLen;
	
	ASSERT(IsValidPtr(lpszPath));

	/* Go to end of string. */
	iStrLen = lstrlen(lpszPath);
	lpszFileName = &lpszPath[iStrLen-1];
	
	/* Search back to first \ or : */
	while ( (*lpszFileName != '\\') && (*lpszFileName != ':') )
		lpszFileName--;
	
	/* Move back to start of filename. */
	ASSERT((lpszFileName >= lpszPath));
	lpszFileName++;
	
	/* Copy filename to start of buffer. */
	while (*lpszFileName != '\0')
		*lpszPath++ = *lpszFileName++;
		
	/* Copy in EOL. */
	*lpszPath = '\0';
}

/*******************************************************************************
** Strip the filename to leave the path.
*/
VOID FAR StripFileName(LPSTR lpszPath)
{
	LPSTR 	lpszFileName;
	int		iStrLen;
	
	ASSERT(IsValidPtr(lpszPath));

	/* Go to end of string. */
	iStrLen = lstrlen(lpszPath);
	lpszFileName = &lpszPath[iStrLen-1];
	
	/* Search back to first \ or : replacing chars with EOL. */
	while ( (*lpszFileName != '\\') && (*lpszFileName != ':') )
		*lpszFileName-- = '\0';
	
	/* Move back to start of filename. */
	ASSERT((lpszFileName >= lpszPath));
}

/*******************************************************************************
** Strip the extension off a file.
*/
VOID FAR StripExtension(LPSTR lpszFileName)
{
	ASSERT(IsValidPtr(lpszFileName));

	while ( (*lpszFileName != '\0') && (*lpszFileName != '.') )
		lpszFileName++;
	
	if (*lpszFileName == '.')
		*lpszFileName = '\0';
}

/*******************************************************************************
** Get the filename only from the full path.
*/
VOID FAR GetPathFileName(LPSTR lpszPath, LPSTR lpszFileName)
{
	LPSTR	lpszName;
	int		iStrLen;

	ASSERT(IsValidPtr(lpszPath));
	ASSERT(IsValidPtr(lpszFileName));

	/* Go to end of string. */
	iStrLen  = lstrlen(lpszPath);
	lpszName = &lpszPath[iStrLen-1];
	
	/* Search back to first \ or : */
	while ( (*lpszName != '\\') && (*lpszName != ':') )
		lpszName--;
	
	/* Move back to start of filename. */
	ASSERT((lpszName >= lpszPath));
	lpszName++;
	
	/* Copy filename to output buffer. */
	while (*lpszName != '\0')
		*lpszFileName++ = *lpszName++;
		
	/* Copy in EOL. */
	*lpszFileName = '\0';
}

/*******************************************************************************
** Read a line of text from a file, or up to the length of the buffer.
*/
UINT FAR ReadLine(HFILE hFile, LPSTR lpszBuffer, UINT iBufSize)
{
	UINT iCount = 0;

	ASSERT(IsValidFile(hFile));
	ASSERT(IsValidPtr(lpszBuffer));
	ASSERT(iBufSize);
	
	/* Read until buffer full. */
	while (iCount < iBufSize)
	{
		/* Read a character. */
		if (_lread(hFile, lpszBuffer, 1) != 1)
		{    
			/* Premature EOF? */
			*lpszBuffer = '\0';
			break;
		}
		
		/* Check for CR or LF. */
		if (*lpszBuffer == '\r')
		{
			/* Read LF. */
			_lread(hFile, lpszBuffer, 1);
			*lpszBuffer = '\0';
			break;
		}
		else if (*lpszBuffer == '\n')
		{
			*lpszBuffer = '\0';
			break;
		}
		
		/* Next char. */
		iCount++;
		lpszBuffer++;
	}

	return iCount;
}

/*******************************************************************************
** Write a line of text to the file.
*/
BOOL FAR WriteLine(HFILE hFile, LPSTR lpszBuffer)
{
	UINT iStrLen;

	ASSERT(IsValidFile(hFile));
	ASSERT(IsValidPtr(lpszBuffer));
	
	/* Get line length. */
	iStrLen = lstrlen(lpszBuffer);
	
	/* Write out in one go. */
	if (_lwrite(hFile, lpszBuffer, iStrLen) == iStrLen)
		return TRUE;
		
	return FALSE;
}

/*******************************************************************************
** Make a new directory.
*/
BOOL FAR MakeDir(LPSTR lpszDir)
{
	ASSERT(IsValidPtr(lpszDir));
	
	/* First copy to NEAR buffer. */
	lstrcpy(szFileName, lpszDir);
	
	/* Make. */
	if (_mkdir(szFileName) == 0)
		return TRUE;
	
	return FALSE;
}

/*******************************************************************************
** Delete a directory.
*/
BOOL FAR DelDir(LPSTR lpszDir)
{
	ASSERT(IsValidPtr(lpszDir));
	
	/* First copy to NEAR buffer. */
	lstrcpy(szFileName, lpszDir);
	
	/* Delete. */
	if (_rmdir(szFileName) == 0)
		return TRUE;
	
	return FALSE;
}

/*******************************************************************************
** Delete a file.
*/
BOOL FAR DelFile(LPSTR lpszFile)
{
	ASSERT(IsValidPtr(lpszFile));
	
	/* First copy to NEAR buffer. */
	lstrcpy(szFileName, lpszFile);
	
	/* Delete. */
	if (remove(szFileName) == 0)
		return TRUE;
	
	return FALSE;
}
