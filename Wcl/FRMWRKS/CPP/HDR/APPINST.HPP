/*****************************************************************************
** (C) Chris Wood 1995.
**
** APPINST.HPP - Application instance class definition.
**
******************************************************************************
*/

// Check for previous inclusion.
#ifndef _APPINST_HPP_
#define _APPINST_HPP_

#include "modinst.hpp"
     
/*****************************************************************************
** Application instance class.
*/
class APPINST : public MODINST
{
private:   
	HINSTANCE hPrevInst;			// Previous application instance.
	LPSTR	lpszArgs;				// Command line. 
     BOOL		bUsingCtl3d;			// Are using Ctl3d?
     
	BOOL Initialise(HINSTANCE hCurr, HINSTANCE hPrev, LPSTR lpszCmdLine);
	VOID InitCtl3d(VOID);
	VOID TermCtl3d(VOID);

friend int PASCAL WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
};

#endif // _APPINST_HPP_
