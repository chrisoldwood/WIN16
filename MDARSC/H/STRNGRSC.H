/*****************************************************************************
** (C) Chris Wood 1995.
**
** STRNGRSC.H - String resource IDs.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _STRNGRSC_H_
#define _STRNGRSC_H_

/* 
** Startup. 
*/
#define IDS_APPNAME		1000		/* Application name. */
#define IDS_VERSION      1001      /* Version number. */
#define IDS_COPYRIGHT    1002      /* Copyright message. */

#define IDS_PRGWNDCLASS	1003		/* Program window class. */
#define IDS_CLIWNDCLASS	1004		/* Client window class. */
#define IDS_DILWNDCLASS	1005		/* DIL window class. */

/* 
** Menu/Button hints. 
*/
#define IDS_MENUHINTS	2000		/* Menu hints - base value. */

/* System menu. */
#define IDM_SYSRESTORE	61728	/* Restore window. */
#define IDM_SYSMOVE		61456	/* Move window. */
#define IDM_SYSSIZE		61440	/* Resize window. */
#define IDM_SYSMINIMISE	61472	/* Minimise window. */
#define IDM_SYSMAXIMISE	61488	/* Maximise window. */
#define IDM_SYSCLOSE	61536	/* Close application. */
#define IDM_SYSSWITCH	61744	/* Switch to another application. */

#endif /* _STRNGRSC_H_ */
