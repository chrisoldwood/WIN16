/*****************************************************************************
** (C) Chris Wood 1995.
**
** MAINWND.HPP - Application window class definition.
**
******************************************************************************
*/

// Check for previous inclusion.
#ifndef _MAINWND_HPP_
#define _MAINWND_HPP_

#include "basewnd.hpp"
               
/*****************************************************************************
** Application window class.
** We derive all the standard properties from BASEWND.
*/
class MAINWND : public BASEWND
{
public:
     MAINWND(HINSTANCE hInst);

	int 	MsgBox(LPSTR lpszMsg, UINT iStyle);

private:
	LPSTR lpszAppName;				// The application name.
};

#endif // _MAINWND_HPP_
