/*****************************************************************************
** (C) Chris Wood 1995.
**
** DEBUG.H - Debugging utils header.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _DEBUG_H_
#define _DEBUG_H_

/* Check the build type. */
#ifdef _DEBUG

/* My assert functions' prototypes. */
extern VOID FAR MyAssert(LPSTR, WORD, BOOL);

#define ASSERT(bExpr)              MyAssert(__FILE__, __LINE__, (bExpr))
#define TRACE(szMsg)            	OutputDebugString((LPSTR) (szMsg))

#define IsValidWnd(hWindow)		(IsWindow((hWindow)))
#define IsValidPtr(pMem)			(((pMem) > NULL) ? TRUE : FALSE)
#define IsValidFn(lpFn)			(!IsBadCodePtr((lpFn)))
#define IsValidFile(hFile)		(hFile != HFILE_ERROR)

#else /* Is NDEBUG. */

#define ASSERT(bExpr)
#define TRACE(szMsg)

#define IsValidWnd(hWindow)
#define IsValidPtr(pMem)
#define IsValidFn(lpFn)
#define IsValidFile(hFile)

#endif /* DEBUG. */

#endif /* _DEBUG_H_ */
