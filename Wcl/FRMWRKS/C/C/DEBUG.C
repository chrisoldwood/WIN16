/*****************************************************************************
** (C) Chris Wood 1995.
**
** DEBUG.C - Debugging utilities.
**
******************************************************************************
*/

#include <windows.h>
#include "apptypes.h"

/* Check build type. */
#ifdef DEBUG

/**** Defines & Global variables. *******************************************/
/* Configure the display of assert messages.*/
#define   ASSERT_AS_DBMSG          /* Output as a debug message.*/
#undef	ASSERT_AS_MSGBOX         /* Output to a message box. */

extern BYTE szAppName[];           /* The application name. */
extern HWND hAppWnd;               /* The main window. */

/******************************************************************************
** My simple assert function. This will cause a debug break if the value is 
** not okay and display a simple message.
*/
VOID FAR MyAssert(LPSTR lpszModule, WORD wLineNum, BOOL bExpr)
{
     BYTE szMsg[128];         /* The full message. */

     /* Check the exporession. */
     if(!bExpr)
     {
          /* Copy the module and line number into the message. */
          wsprintf((LPSTR) szMsg, (LPSTR) "ASSERT Failed: Module %s Line %d\n", 
          		lpszModule, wLineNum);

          /* Display message. */
#ifdef ASSERT_AS_DBMSG
          OutputDebugString((LPSTR) szMsg);
#else /* ASSERT_AS_MSGBOX. */
          MessageBox(hAppWnd, (LPSTR) szMsg, (LPSTR) szAppName, MB_OK | MB_ICONEXCLAMATION);
#endif

          /* Force a break. */
          DebugBreak();
     }
}

/******************************************************************************
** My extended assert function. This will also cause a debug break if the value
** is not okay but allow a more flexible message.
*/
VOID FAR MyAssertEx(LPSTR lpszModule, WORD wLineNum, BOOL bExpr, LPSTR lpszType)
{
     BYTE szMsg[128];         /* The full message. */

     /* Check the exporession. */
     if(!bExpr)
     {
          /* Copy the type, module and line number into the message. */
          wsprintf((LPSTR) szMsg, (LPSTR) "%s Failed: Module %s Line %d\n", 
          		lpszType, lpszModule, wLineNum);

          /* Display message. */
#ifdef ASSERT_AS_DBMSG
          OutputDebugString((LPSTR) szMsg);
#else /* ASSERT_AS_MSGBOX. */
          MessageBox(hAppWnd, (LPSTR) szMsg, (LPSTR) szAppName, MB_OK | MB_ICONEXCLAMATION);
#endif

          /* Force a break. */
          DebugBreak();
     }
}

#endif /* DEBUG. */
