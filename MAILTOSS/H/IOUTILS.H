/*****************************************************************************
** (C) Chris Wood 1995.
**
** IOUTILS.H - File I/O utility functions header.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _IOUTILS_H_
#define _IOUTILS_H_

/**** Defs. *****************************************************************/
#define MAX_PATH_LEN		128		/* Max length of file path. */
#define FILENAME_LEN		12		/* Length of filename. */
#define FILEEXT_LEN			4		/* Length of file extension. */

#define MAX_FILENAME_LEN		(MAX_PATH_LEN + FILENAME_LEN)
#define MAX_DATABUF_LEN		1024		/* Length of temporary data buffer. */

/* _access() flags. */
#define FILE_HAS_MODE		0		/* File has this mode. */

#define FILE_EXISTS			0		/* File exists. */
#define FILE_WRITABLE		2		/* File is writable. */
#define FILE_READABLE		4		/* File is readable. */
#define FILE_READWRITE		6		/* File is R/W. */

/* _dos_findfirst() flags. */
#define FIND_NEXT			0xFFFF	/* Find next file. */
#define FILE_FOUND			0		/* File was found. */

/**** Prototypes. ***********************************************************/
extern char szDataBuffer[];			/* Temporary read/write buffer. */

extern BOOL FAR FileExists(LPSTR lpszFile);
extern BOOL FAR FileReadOnly(LPSTR lpszFile);
extern BOOL FAR FindFile(LPSTR lpszPath, unsigned int FAR *iType);

extern VOID CreateFullPathName(LPSTR lpszDir, LPSTR lpszFile, LPSTR lpszOutput);
extern VOID FAR StripPath(LPSTR lpszPath);
extern VOID FAR StripFileName(LPSTR lpszPath);
extern VOID FAR StripExtension(LPSTR lpszFileName);
extern VOID FAR GetPathFileName(LPSTR lpszPath, LPSTR lpszFileName);

extern VOID FAR CreateFileIODlg(VOID);
extern VOID FAR SetFileName(LPSTR lpszFileName);
extern VOID FAR SetUserName(LPSTR lpszUserName);
extern VOID FAR DestroyFileIODlg(VOID);

extern UINT FAR ReadLine(HFILE hFile, LPSTR lpszBuffer, UINT iBufSize);
extern BOOL FAR WriteLine(HFILE hFile, LPSTR lpszBuffer);

extern BOOL FAR MakeDir(LPSTR lpszDir);
extern BOOL FAR DelDir(LPSTR lpszDir);
extern BOOL FAR DelFile(LPSTR lpszFile);

#endif /* _IOUTILS_H_ */

