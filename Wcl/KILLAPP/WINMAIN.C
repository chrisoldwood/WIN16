/*****************************************************************************
** (C) Chris Wood 1995.
**
** WINMAIN.C - Application entry point.
**
******************************************************************************
*/

#include <windows.h>
#include <direct.h>

/**** Defs. *****************************************************************/
#define MAX_PATH		256				/* Max length of path. */
#define MAX_CLASS_NAME	80				/* max length of class name. */
#define MAX_TITLE_LEN	128				/* max length of window title. */

#define ignore(x)		if(x);			/* For unreferenced parameters. */

/**** Global Vars. **********************************************************/
HINSTANCE hAppInst;              			/* Application instance. */
HINSTANCE	hPrevInst;					/* Previous instance. */
LPSTR	lpszArgs;						/* Command line. */
char		szCWD[MAX_PATH];				/* Current working directory. */
char		szIniFile[MAX_PATH];			/* Application ini file full path. */
char		szIniFileName[] = "killapp.ini";	/* Application ini file name. */
char 	szClassName[MAX_CLASS_NAME];		/* Window class name to kill. */
char 	szWndTitle[MAX_TITLE_LEN];		/* Window title name to kill. */
LPSTR	lpszTitle;

/**** Prototypes. ***********************************************************/

/*****************************************************************************
** Application entry point.
*/
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, 
				int iCmdShow)
{
	int	iStrLen;				/* Length of CWD. */
     HWND hFindWnd;				/* App window to kill. */

	ignore(iCmdShow);
	     
	/* Setup this instance. */
	hAppInst  = hInstance;
	hPrevInst = hPrevInstance;
	lpszArgs  = lpszCmdLine;

	/* Get the current directory. */
	_getcwd((char*) szCWD, MAX_PATH);
	
	/* Tag a \ on if not one. */
	iStrLen = lstrlen((LPSTR) szCWD);
	if (szCWD[iStrLen-1] != '\\')
		szCWD[iStrLen] = '\\';
	
	/* Create the .ini filename. */
	lstrcpy(szIniFile, szCWD);
	lstrcat(szIniFile, szIniFileName);

	/* Get the windows class name. */
	GetPrivateProfileString("App", "ClassName", "", szClassName, MAX_CLASS_NAME, szIniFile);
	if (szClassName[0] == '\0')
	{
		MessageBox(NULL, "No window class name specified in .ini file.", "KillApp", MB_OK | MB_ICONSTOP);
		return FALSE;
	}

	/* Get the windows class name. */
	GetPrivateProfileString("App", "Title", "", szWndTitle, MAX_TITLE_LEN, szIniFile);
	if (szClassName[0] == '\0')
	{
		lpszTitle = NULL;
	}
	else
	{
		lpszTitle = szWndTitle;
	}

	/* Find the window. */
	hFindWnd = FindWindow(szClassName, lpszTitle);
	if (!hFindWnd)
		return FALSE;
		
	/* Kill it. */
	PostMessage(hFindWnd, WM_CLOSE, 0, 0L);
	/*DestroyWindow(hFindWnd);*/
		     
     /* Exit. */
     return FALSE;
}
