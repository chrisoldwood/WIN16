/*****************************************************************************
** (C) Chris Wood 1995.
**
** DEBUG.C - Debugging functions.
**
******************************************************************************
*/

#include <windows.h>

/* Check build type. */
#ifdef DEBUG

#pragma message ( "DEBUG BUILD" )

/**** Defs. ******************************************************************/
#define DEBUG_MSG_LEN    128       /* Max length of debug message. */

/******************************************************************************
** My simple assert function. This will cause a debug break if the value is 
** not okay and display a simple message.
*/
VOID FAR MyAssert(LPSTR lpszModule, WORD wLineNum, BOOL bExpr)
{
     BYTE szMsg[DEBUG_MSG_LEN];    /* The full message. */

     /* Check the expression. */
     if(!bExpr)
     {
          /* Copy the module and line number into the message. */
          wsprintf((LPSTR) szMsg, (LPSTR) "ASSERT Failed: Module %s Line %d\n", 
          		lpszModule, wLineNum);

          /* Display message. */
          OutputDebugString((LPSTR) szMsg);
          DebugBreak();
     }
}

/******************************************************************************
** My extended assert function. This will also cause a debug break if the value
** is not okay but allow a more flexible message.
*/
VOID FAR MyAssertEx(LPSTR lpszModule, WORD wLineNum, BOOL bExpr, LPSTR lpszType)
{
     BYTE szMsg[DEBUG_MSG_LEN];    /* The full message. */

     /* Check the expression. */
     if(!bExpr)
     {
          /* Copy the module and line number into the message. */
          wsprintf((LPSTR) szMsg, (LPSTR) "%s Failed: Module %s Line %d\n", 
          		lpszType, lpszModule, wLineNum);

          /* Display message. */
          OutputDebugString((LPSTR) szMsg);
          DebugBreak();
     }
}

#else /* NDEBUG. */

#pragma message ( "NON-DEBUG BUILD" )

#endif /* DEBUG. */
