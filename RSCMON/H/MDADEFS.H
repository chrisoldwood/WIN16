/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDADEFS.H - MDA Library Global Definitions.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _MDADEFS_H_
#define _MDADEFS_H_

/**** Exported function types. **********************************************/
#ifndef EXPORT
#define EXPORT      __export
#endif

#ifndef EXPORTFUNC
#define EXPORTFUNC  CALLBACK EXPORT
#endif

/**** Display dimensions. ***************************************************/
#define MDA_WIDTH        80
#define MDA_HEIGHT       25

/**** Display colours. ******************************************************/
#define BLACK            (BYTE) 0x00
#define NORMAL           (BYTE) 0x07
#define BRIGHT           (BYTE) 0x0F

/**** Normal character codes. ***********************************************/
#define NULLCHAR         (BYTE) 0x00
#define SPACE            (BYTE) 0x20

/**** Extended character codes for single pixel lines. **********************/
#define S_HORZBAR        (BYTE) 0xC4
#define S_VERTBAR        (BYTE) 0xB3
#define S_TOPLEFT        (BYTE) 0xDA
#define S_TOPRIGHT       (BYTE) 0xBF
#define S_BOTRIGHT       (BYTE) 0xD9
#define S_BOTLEFT        (BYTE) 0xC0
#define S_SIDELEFT       (BYTE) 0xC3
#define S_TOPMID         (BYTE) 0xC2
#define S_SIDERIGHT      (BYTE) 0xB4
#define S_BOTMID         (BYTE) 0xC1
#define S_CROSS          (BYTE) 0xC5

/**** Extended character codes for double pixel lines. **********************/
#define D_HORZBAR        (BYTE) 0xCD
#define D_VERTBAR        (BYTE) 0xBA
#define D_TOPLEFT        (BYTE) 0xC9
#define D_TOPRIGHT       (BYTE) 0xBB
#define D_BOTRIGHT       (BYTE) 0xBC
#define D_BOTLEFT        (BYTE) 0xC8
#define D_SIDELEFT       (BYTE) 0xCC
#define D_TOPMID         (BYTE) 0xCB
#define D_SIDERIGHT      (BYTE) 0xB9
#define D_BOTMID         (BYTE) 0xCA
#define D_CROSS          (BYTE) 0xCE

/**** Extended character codes for graphic blocks. **************************/
#define SPARSEBLOCK      (BYTE) 0xB0
#define QTRBLOCK         (BYTE) 0xB1
#define HALFBLOCK        (BYTE) 0xB2
#define FULLBLOCK        (BYTE) 0xDB

/**** Extended character codes for 'proper' arrows. *************************/
#define LEFTARROW        (BYTE) 0x1B
#define RIGHTARROW       (BYTE) 0x1A
#define UPARROW          (BYTE) 0x18
#define DOWNARROW        (BYTE) 0x19
#define UDARROW          (BYTE) 0x12
#define LRARROW          (BYTE) 0x1D

/**** Extended character codes for 'nudge' arrows. **************************/
#define LEFTNUDGE        (BYTE) 0x11
#define RIGHTNUDGE       (BYTE) 0x10
#define UPNUDGE          (BYTE) 0x1E
#define DOWNNUDGE        (BYTE) 0x1F

/**** Extended character codes for some other useful chars. *****************/
#define TICK             (BYTE) 0xFB
#define APPROX           (BYTE) 0xF7

/**** Turn off certain compiler warnings. ***********************************/
#pragma warning ( disable : 4100 ) /* Unreferenced formal parameter. */
#pragma warning ( disable : 4001 ) /* Single line comment. */

#endif /* _MDADEFS_H_ */
