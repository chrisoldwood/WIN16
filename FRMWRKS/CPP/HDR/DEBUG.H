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

/* My assert functions' prototypes. */
VOID FAR MyAssert(LPSTR, WORD, BOOL);
VOID FAR MyAssertEx(LPSTR, WORD, BOOL, LPSTR);

#define Assert(bExpr)              MyAssert(__FILE__, __LINE__, (bExpr))
#define AssertEx(bExpr, szMsg)     MyAssertEx(__FILE__, __LINE__, (bExpr), (szMsg))
#define TraceMsg(szMsg)            OutputDebugString((szMsg))

#else /* Is NDEBUG. */

#define Assert(bExpr)
#define Assert(bExpr, szMsg)
#define TraceMsg(szMsg)

#endif /* DEBUG. */
#endif /* _DEBUG_H_ */
