/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAMAIN.C - Dll entry/exit point and other initialisation functions.
**
******************************************************************************
*/

#include <windows.h>
#include "mdadefs.h"
#include "mdafuncs.h"

/**** Defines & Global variables. *******************************************/
HINSTANCE hDllInst=NULL;           /* DLL instance. */
WORD      wMDASeg=NULL;            /* Segment of MDA. */
LPSTR     lpMDA=NULL;              /* Full address of start of MDA. */
BOOL      bOn=FALSE;               /* Display output on/off. */

extern UINT iTimerID;			/* Resource monitor timer. */

/******************************************************************************
** Dll entry point on loading.
*/
int CALLBACK LibMain(HINSTANCE hInst, WORD wDataSeg, WORD wHeapSize, LPSTR lpszCmdLine)
{
	/* Check for first instance. */
	if (hDllInst == NULL)
     {
          BOOL bHasMono;      /* MDA available. */

          /* Save instance handle. */
		hDllInst = hInst;

          /* Check for mono adapter using BIOS int 10h. */
          _asm
          {
               mov  ax,1A00h
               int  10h
        
               mov  ax,00h
               cmp  bh,1
               jnz  none      
               mov  ax,01h

               none:
               mov  bHasMono,ax
          }

          /* Did we find a MDA?. */
          if (bHasMono)
          {
               /* Get segment and convert to full address. */
               wMDASeg = (WORD) (LOWORD(GetProcAddress(GetModuleHandle("KERNEL"), "__B000H")));
               if (wMDASeg != NULL)
                    lpMDA = (LPSTR) ((unsigned long) wMDASeg  << 16); 
          }
     }
     
	return TRUE;
}

/******************************************************************************
** Cleanup code for when DLL is unloaded.
*/
int EXPORTFUNC WEP(int nExitType)
{
	/* Kill the resource monitor timer. */
	if (iTimerID);
		KillTimer(NULL, iTimerID);
	
     /* Clear the display. */
     MDARestore();

	return 1;
}

/*****************************************************************************
** Check to see if the MDA is already in use. This checks for any 
** characters that are not spaces or zeroes.
*/
BOOL EXPORTFUNC MDAInUse(VOID)
{
     LPSTR     lpDisplay;
     int       iLoop;

     /* Check we have a valid MDA address. */
     if (!lpMDA)
          return FALSE;

     /* Setup loop. */     
     lpDisplay = lpMDA;
     iLoop = MDA_WIDTH * MDA_HEIGHT;

     /* Loop for each character. */
     while(iLoop--)
     {
          /* Check character. */
          if ((*lpDisplay != NULLCHAR) && (*lpDisplay != SPACE))
               return TRUE;
          
          /* Move to next character. */
          lpDisplay += 2;
     }

     return FALSE;
}

/*****************************************************************************
** Turn the output of the display functions on or off. A check is made to make
** sure that the display is not turned on if it does not exist.
*/
VOID EXPORTFUNC MDAOutput(BOOL bTurnOn)
{
     /* Check we have a valid MDA address. */
     if (!lpMDA)
          return;

     /* Determine new output state. */
     if (bTurnOn)
          bOn = TRUE;
     else
          bOn = FALSE;          
}

/*****************************************************************************
** Clear the MDA by setting all the characters to spaces, with the background
** as black and the foreground as normal. This works at 2 characters a time.
*/
VOID EXPORTFUNC MDARestore(VOID)
{
     DWORD FAR *lpDisplay;
     int       iLoop;

     /* Check output state. */
     if ( (!lpMDA) || (!bOn) )
          return;

     /* Setup loop for setting a DWORD at a time. */
     lpDisplay = (DWORD FAR *) lpMDA;
     iLoop = (MDA_WIDTH / 2) * MDA_HEIGHT;

     /* Clear 2 characters at a time. */
     while(iLoop--)
          *lpDisplay++ = 0x07200720;
}
