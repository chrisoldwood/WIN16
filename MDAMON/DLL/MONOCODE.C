/*****************************************************************************
**
** MONOCODE.C - Monochrome adapter access functions code.
** (C) Chris Wood 1994.
** cwood@gst-soft.demon.co.uk.
**
** 05/04/94 Add compiler options for protecting and clipping.
** 30/03/94 Basic functions for intialising and drawing.
**
******************************************************************************
*/

#include <windows.h>

/**** Prototypes for this module. *******************************************/
WORD FAR PASCAL __export InitMono(void);
VOID FAR PASCAL __export ClearMono(void);
VOID FAR PASCAL __export PlotChar(int, int, char, char);
VOID FAR PASCAL __export HorizLine(int, int, int, char, char);
VOID FAR PASCAL __export VertLine(int, int, int, char, char);
VOID FAR PASCAL __export HorizString(int, int, LPSTR, char);
VOID FAR PASCAL __export VertString(int, int, LPSTR, char);

VOID FAR PASCAL __export ByteAsHex(void);
VOID FAR PASCAL __export WordAsHex(void);
VOID FAR PASCAL __export DWordAsHex(void);
VOID FAR PASCAL __export ByteAsDec(void);
VOID FAR PASCAL __export WordAsDec(void);
VOID FAR PASCAL __export DWordAsDec(void);
VOID FAR PASCAL __export DWordAsAddr(void);

VOID FAR PASCAL __export PlotFrame(int, int, int, int, char, char);
VOID FAR PASCAL __export ScrollUp(void);
VOID FAR PASCAL __export ScrollDown(void);
VOID FAR PASCAL __export ScrollLeft(void);
VOID FAR PASCAL __export ScrollRight(void);

VOID FAR PASCAL __export BoolAsString(void);
VOID FAR PASCAL __export CentreString(void);

VOID FAR PASCAL __export HorizMeter(void);
VOID FAR PASCAL __export VertMeter(void);
VOID FAR PASCAL __export FlagsAsDots(void);

/**** Defines & Global variables. *******************************************/
/* Intitialise error codes. */
#define   ERR_NONE        0
#define   ERR_NOMONO     -1
#define   ERR_BADADDRESS -2

/* Mono RAM address. */
WORD      sMonoMem;      /* Segment of mono adapter RAM. */
LPSTR     lpMonoMem;     /* Full address of mono adapter RAM. */

/* Extended character line arrays. */
#define   DUAL      0
#define   SINGLE    1

#define   HORBAR    0
#define   VERBAR    1
#define   TOPLEFT   2
#define   TOPRIGHT  3
#define   BOTRIGHT  4
#define   BOTLEFT   5
#define   SIDELEFT  6
#define   TOPMID    7
#define   SIDERIGHT 8
#define   BOTMID    9
#define   CROSS     10

char      szDual[]   = { (char) 0xCD, (char) 0xBA, (char) 0xC9, (char) 0xBB, 
                         (char) 0xBC, (char) 0xC8, (char) 0xCC, (char) 0xCB, 
                         (char) 0xB9, (char) 0xCA, (char) 0xCE };
char      szSingle[] = { (char) 0xC4, (char) 0xB3, (char) 0xDA, (char) 0xBF, 
                         (char) 0xD9, (char) 0xC0, (char) 0xC3, (char) 0xC2, 
                         (char) 0xB4, (char) 0xC1, (char) 0xC5 };

/*
******************************************************************************
** Basic drawing functions.
******************************************************************************
*/

/****************************************************************************
** Check to see if a Mono adapter is available. If so get the address of the 
** mono adapter video RAM from the special selector __B000H. Then clear. 
** The return code can signal one of three things. All is okay, ERR_NONE. No
** mono adapter was found, ERR_NOMONO. Could not get a valid address for the
** video RAM, ERR_BADADDRESS.
*/
WORD FAR PASCAL __export InitMono(VOID)
{
     BOOL bHasMono;
     
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
     if (!bHasMono)
          return (WORD) ERR_NOMONO;
     
     /* Get segment and convert to full address. */
     sMonoMem = (WORD) (LOWORD(GetProcAddress(GetModuleHandle("KERNEL"), "__B000H")));
     if (sMonoMem == NULL)
          return (WORD) ERR_BADADDRESS;
     lpMonoMem = (LPSTR) ((unsigned long) sMonoMem  << 16); 

     /* Clear all bytes to zero. */
     ClearMono();
     return (WORD) ERR_NONE;
}

/*****************************************************************************
** Clear the mono RAM chars and attributes to zeros.
*/
VOID FAR PASCAL __export ClearMono(VOID)
{
     WORD FAR  *lpDisplay;
     int       iLoop;

#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif
     
     lpDisplay = (WORD FAR *) lpMonoMem;
     iLoop = 2000;

     while(iLoop--)
          *lpDisplay++ = NULL;
}

/*****************************************************************************
** Plot the character cChar at the location iX,iY, and set its attribute to
** cStyle.
*/
VOID FAR PASCAL __export PlotChar(int iX, int iY, char cChar, char cStyle)
{
     WORD FAR  *lpDisplay;

#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     if ((iX < 0) || (iX > 79) 
     || (iY < 0) || (iY > 24))
          return;
#endif

     lpDisplay  = (WORD FAR *) (lpMonoMem + ((iY * 160) + (iX * 2)));          
     *lpDisplay = (((WORD) cStyle) << 8) + (WORD) cChar;
}

/*****************************************************************************
** Draw a horizontal line of characters cChar from iSX,iY to iDX,iY and set 
** the attributes to cStyle.
*/
VOID FAR PASCAL __export HorizLine(int iSX, int iDX, int iY, char cChar, char cStyle)
{
     WORD FAR  *lpDisplay;
     int       iLoop;

#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     if ((iSX < 0) || (iSX > 79)
     || (iDX < 0) || (iDX > 79) 
     || (iY < 0) || (iY > 24))
          return;
#endif

     lpDisplay = (WORD FAR *) (lpMonoMem + ((iY * 160) + (iSX * 2)));     
     iLoop = iDX - iSX + 1;

     while(iLoop--)
          *lpDisplay++ = (((WORD) cStyle) << 8) + (WORD) cChar;    
}

/****************************************************************************
** Draw a vertical line of characters cChar from iX,iSY to iX,iDY and set 
** the attributes to cStyle.
*/
VOID FAR PASCAL __export VertLine(int iX, int iSY, int iDY, char cChar, char cStyle)
{
     WORD FAR  *lpDisplay;
     int       iLoop;
     
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     if ((iX < 0) || (iX > 79)
     || (iSY < 0) || (iSY > 24) 
     || (iDY < 0) || (iDY > 24))
          return;
#endif

     lpDisplay = (WORD FAR *) (lpMonoMem + ((iSY * 160) + (iX * 2)));     
     iLoop = iDY - iSY + 1;    

     while(iLoop--)
     {
          *lpDisplay = (((WORD) cStyle) << 8) + (WORD) cChar;
          lpDisplay += 80;
     }
}

/*****************************************************************************
** Plot a string of characters held in lpString from the position iX,iY across
** the display with attribute cStyle.
*/
VOID FAR PASCAL __export HorizString(int iX, int iY, LPSTR lpString, char cStyle)
{
     LPSTR     lpDisplay;
     
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     {
     int  iLength;
     iLength = lstrlen(lpString);
     
     if ((iY < 0) || (iY > 24)
     || (iX < 0) || (iX > 79) 
     || (iX+iLength > 79))
          return;
     }
#endif

     lpDisplay = lpMonoMem + ((iY * 160) + (iX * 2));
     while(*lpString)
     {
          *lpDisplay++ = *lpString++;
          *lpDisplay++ = cStyle;
     }     
}

/*****************************************************************************
** Plot a string of characters held in lpString from the position iX,iY down
** the display with attribute cStyle.
*/
VOID FAR PASCAL __export VertString(int iX, int iY, LPSTR lpString, char cStyle)
{
     LPSTR     lpDisplay;
     
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     {
     int  iLength;
     iLength = lstrlen(lpString);
     
     if ((iY < 0) || (iY > 24)
     || (iX < 0) || (iX > 79) 
     || (iY+iLength > 24))
          return;
     }
#endif

     lpDisplay = lpMonoMem + ((iY * 160) + (iX * 2));
     while(*lpString)
     {
          *lpDisplay++ = *lpString++;
          *lpDisplay++ = cStyle;
           lpDisplay  += 158;
     }     
}

/*
******************************************************************************
** Area manipulation functions..
******************************************************************************
*/

/*****************************************************************************
** Draw a rectangular frame from iSX,iSY to iDX,iDY. The type specifies 
** whether to draw the lines as single or double line characters from the
** extended character set. The style is applied to all characters.
*/
VOID FAR PASCAL __export PlotFrame(int iSX, int iSY, int iDX, int iDY, char cType, char cStyle)
{
     LPSTR     lpExtChars;
     
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
     if ((iSX < 0) || (iSX > 79)
     || (iDX < 0) || (iDX > 79)
     || (iSY < 0) || (iSY > 24)
     || (iDY < 0) || (iDY > 24))
          return;
#endif

     if (cType == DUAL)
          lpExtChars = szDual;
     else
          lpExtChars = szSingle;

     HorizLine(iSX, iDX, iSY, lpExtChars[HORBAR], cStyle);
     HorizLine(iSX, iDX, iDY, lpExtChars[HORBAR], cStyle);
     VertLine(iSX, iSY, iDY, lpExtChars[VERBAR], cStyle);
     VertLine(iDX, iSY, iDY, lpExtChars[VERBAR], cStyle);
     
     PlotChar(iSX, iSY, lpExtChars[TOPLEFT], cStyle);
     PlotChar(iDX, iSY, lpExtChars[TOPRIGHT], cStyle);
     PlotChar(iDX, iDY, lpExtChars[BOTRIGHT], cStyle);
     PlotChar(iSX, iDY, lpExtChars[BOTLEFT], cStyle);
}

VOID FAR PASCAL __export ScrollUp()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export ScrollDown()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export ScrollLeft()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export ScrollRight()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

/*
******************************************************************************
** Number display functions.
******************************************************************************
*/

VOID FAR PASCAL __export ByteAsHex()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export WordAsHex()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export DWordAsHex()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export ByteAsDec()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export WordAsDec()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export DWordAsDec()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export DWordAsAddr()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

/*
******************************************************************************
** String display functions.
******************************************************************************
*/

VOID FAR PASCAL __export BoolAsString()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export CentreString()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

/*
******************************************************************************
** Graphical display functions.
******************************************************************************
*/

VOID FAR PASCAL __export HorizMeter()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export VertMeter()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

VOID FAR PASCAL __export FlagsAsDots()
{
#ifdef PROTECT
     if (lpMonoMem == NULL)
          return;
#endif

#ifdef CLIP
#endif

}

/*
******************************************************************************
** Special function to include if compiling as a .DLL.
******************************************************************************
*/

#ifdef ISDLL

/*****************************************************************************
** DLL exit point.
*/
int CALLBACK WEP(int nExitType)
{
     return 1;
}

#endif
     