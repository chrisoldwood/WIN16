/*****************************************************************************
** (C) Chris Wood 1995.
**
** BASEDEFS.H - Basic data types, definitions and compiler pragmas.
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

/**** Windows function types. ***********************************************/
#ifndef WINDOWPROC
#define WINDOWPROC  LRESULT CALLBACK
#endif

#ifndef DIALOGPROC
#define DIALOGPROC  BOOL CALLBACK
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

#endif /* _BASEDEFS_H_ */
