/*****************************************************************************
** 
** MONOCODE.H - Monochrome adapter access functions header file.
** (C) Chris Wood 1994.
** cwood@gst-soft.demon.co.uk.
**
** 05/03/94 Defines for common extended chars and styles.
** 30/03/94 Prototypes for basic functions.
**
******************************************************************************
*/

/**** DLL Function Prototypes. **********************************************/
extern WORD FAR PASCAL InitMono(void);
extern VOID FAR PASCAL ClearMono(void);
extern VOID FAR PASCAL PlotChar(int, int, char, char);
extern VOID FAR PASCAL HorizLine(int, int, int, char, char);
extern VOID FAR PASCAL VertLine(int, int, int, char, char);
extern VOID FAR PASCAL HorizString(int, int, LPSTR, char);
extern VOID FAR PASCAL VertString(int, int, LPSTR, char);

extern VOID FAR PASCAL ByteAsHex(void);
extern VOID FAR PASCAL WordAsHex(void);
extern VOID FAR PASCAL DWordAsHex(void);
extern VOID FAR PASCAL ByteAsDec(void);
extern VOID FAR PASCAL WordAsDec(void);
extern VOID FAR PASCAL DWordAsDec(void);
extern VOID FAR PASCAL DWordAsAddr(void);

extern VOID FAR PASCAL PlotFrame(int, int, int, int, char, char);
extern VOID FAR PASCAL ScrollUp(void);
extern VOID FAR PASCAL ScrollDown(void);
extern VOID FAR PASCAL ScrollLeft(void);
extern VOID FAR PASCAL ScrollRight(void);

extern VOID FAR PASCAL BoolAsString(void);
extern VOID FAR PASCAL CentreString(void);

extern VOID FAR PASCAL HorizMeter(void);
extern VOID FAR PASCAL VertMeter(void);
extern VOID FAR PASCAL FlagsAsDots(void);

/**** Error return codes. ***************************************************/
#define   ERR_NONE        0
#define   ERR_NOMONO     -1
#define   ERR_BADADDRESS -2

/**** Extended line character set types. ************************************/
#define   DUAL      0
#define   SINGLE    1

/**** Extended character codes. *********************************************/
#define   S_HORBAR       (char) 0xC4
#define   S_VERBAR       (char) 0xB3
#define   S_TOPLEFT      (char) 0xDA
#define   S_TOPRIGHT     (char) 0xBF
#define   S_BOTRIGHT     (char) 0xD9
#define   S_BOTLEFT      (char) 0xC0
#define   S_SIDELEFT     (char) 0xC3
#define   S_TOPMID       (char) 0xC2
#define   S_SIDERIGHT    (char) 0xB4
#define   S_BOTMID       (char) 0xC1
#define   S_CROSS        (char) 0xC5

#define   D_HORBAR       (char) 0xCD
#define   D_VERBAR       (char) 0xBA
#define   D_TOPLEFT      (char) 0xC9
#define   D_TOPRIGHT     (char) 0xBB
#define   D_BOTRIGHT     (char) 0xBC
#define   D_BOTLEFT      (char) 0xC8
#define   D_SIDELEFT     (char) 0xCC
#define   D_TOPMID       (char) 0xCB
#define   D_SIDERIGHT    (char) 0xB9
#define   D_BOTMID       (char) 0xCA
#define   D_CROSS        (char) 0xCE

#define   HALFBLOCK      (char) 0xB2
#define   FULLBLOCK      (char) 0xDB

/**** Character styles. *****************************************************/
#define   BLACK          (char) 0x00
#define   GREY           (char) 0x07
#define   WHITE          (char) 0x0F
#define   FLASHGREY      (char) 0x87
#define   FLASHWHITE     (char) 0x8F
