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
#ifdef DEBUG

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus. */

/* My assert functions' prototypes. */
VOID FAR MyAssert(LPSTR, WORD, BOOL);
VOID FAR MyAssertEx(LPSTR, WORD, BOOL, LPSTR);

#define Assert(bExpr)              MyAssert(__FILE__, __LINE__, (bExpr))
#define AssertEx(bExpr, szMsg)     MyAssertEx(__FILE__, __LINE__, (bExpr), (szMsg))
#define TraceMsg(szMsg)            OutputDebugString((LPSTR) (szMsg))

#define IsValidWnd(hWindow)		(IsWindow((hWindow)))
#define IsValidPtr(pMem)			(((pMem) > NULL) ? TRUE : FALSE)
#define IsValidFn(lpFn)			(!IsBadCodePtr((lpFn)))
#define IsValidGDIObj(hObj)		(IsGDIObj((hObj)))

#else /* Is NDEBUG. */

#define Assert(bExpr)
#define AssertEx(bExpr, szMsg)
#define TraceMsg(szMsg)

#define IsValidWnd(hWindow)
#define IsValidPtr(pMem)
#define IsValidFn(lpFn)
#define IsValidGDIObj(hObj)

#endif /* DEBUG. */

#ifdef __cplusplus
}
#endif /* __cplusplus. */

#endif /* _DEBUG_H_ */
