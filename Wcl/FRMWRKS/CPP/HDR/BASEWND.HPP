/*****************************************************************************
** (C) Chris Wood 1995.
**
** BASEWND.HPP - Basic window class definition.
**
******************************************************************************
*/

// Check for previous inclusion.
#ifndef _BASEWND_HPP_
#define _BASEWND_HPP_
               
/*****************************************************************************
** Window creation parameter block.
** This defines all the variable parameters for window creation.
*/
struct WNDCREATE 
{
	LPSTR	lpszTitle;
	DWORD	dwStyle;
	RECT		rcPos;
	HMENU	hMenu;
};
                                  
/*****************************************************************************
** Base window class.
** This class encapsulates the registration, creation and behaviour of a
** window.
*/
class BASEWND
{
public:
	static WNDCLASS  RegArgs;			// The registration info.
	static WNDCREATE CreateArgs;    		// The window creation args.
              
	BASEWND(LPSTR lpszClassName);

     BOOL Create(VOID);
	HWND	GetHandle(VOID);
	BOOL	Show(int State);
	VOID Centre(VOID);

protected:
	HWND	hWnd;						// The windows' handle.

};

#endif // _BASEWND_HPP_
