/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPTYPES.H - Basic data types and definitions.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _APPTYPES_H_
#define _APPTYPES_H_

/**** Global data types. ****************************************************/
#ifndef VOID
#define VOID   void
#endif

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
#endif

#ifndef ERROR
#define ERROR  0
#endif

#endif /* _APPTYPES_H_ */
