/*****************************************************************************
** (C) Chris Wood 1995.
**
** BASEDEFS.H - Basic data types and common definitions.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _BASEDEFS_H_
#define _BASEDEFS_H_

/**** Global data types. ****************************************************/
#ifndef VOID
#define VOID   void
#endif

typedef VOID FAR *	LPVOID;
typedef VOID NEAR *	PVOID;

/**** Windows function types. ***********************************************/
#ifndef EXPORT
#define EXPORT      __export
#endif

#ifndef WINDOWPROC
#define WINDOWPROC  LRESULT CALLBACK EXPORT
#endif

#ifndef DIALOGPROC
#define DIALOGPROC  BOOL CALLBACK EXPORT
#endif

#ifndef EXPORTFUNC
#define EXPORTFUNC  CALLBACK EXPORT
#endif

/**** Other useful global defs. *********************************************/
#ifndef TRUE
#define TRUE   1
#define FALSE  0
#endif

#ifndef OKAY
#define OKAY   1
#define ERROR	0
#endif

/**** Application specific global defs. *************************************/

#endif /* _BASEDEFS_H_ */
