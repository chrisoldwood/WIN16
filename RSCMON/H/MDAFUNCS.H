/*****************************************************************************
** (C) Chris Wood 1995.
**
** MDAFUNCS.H - MDA Library prototypes.
**
******************************************************************************
*/

/* Check for previous inclusion. */
#ifndef _MDAFUNCS_H_
#define _MDAFUNCS_H_

/**** Exported function types. **********************************************/
/* From MDAMAIN.C */
BOOL EXPORTFUNC MDAInUse(VOID);
VOID EXPORTFUNC MDAOutput(BOOL);
VOID EXPORTFUNC MDARestore(VOID);

/* From MDABASE.C */
VOID EXPORTFUNC MDADrawChar(int iSX, int iSY, BYTE cChar, BYTE cCol);
VOID EXPORTFUNC MDADrawHorizLine(int iSX, int iDX, int iY, BYTE cChar, BYTE cCol);
VOID EXPORTFUNC MDADrawVertLine(int iX, int iSY, int iDY, BYTE cChar, BYTE cCol);

/* From MDAFILL.C */
VOID EXPORTFUNC MDAClearRect(int iSX, int iSY, int iDX, int iDY);
VOID EXPORTFUNC MDAFillRect(int iSX, int iSY, int iDX, int iDY, BYTE cChar, BYTE cFGCol, BYTE cBGCol);

/* From MDASTRNG.C */
VOID EXPORTFUNC MDADrawLftString(int iX, int iY, LPSTR lpString, BYTE cCol);
VOID EXPORTFUNC MDADrawRgtString(int iX, int iY, LPSTR lpString, BYTE cCol);
VOID EXPORTFUNC MDADrawCtrString(int iY, LPSTR lpString, BYTE cCol);

/* From MDAFRAME.C */
VOID EXPORTFUNC MDADrawSFrame(int iSX, int iSY, int iDX, int iDY, BYTE cCol);
VOID EXPORTFUNC MDADrawDFrame(int iSX, int iSY, int iDX, int iDY, BYTE cCol);
VOID EXPORTFUNC MDADrawSHorizBar(int iSX, int iDX, int iY, BYTE);
VOID EXPORTFUNC MDADrawDHorizBar(int iSX, int iDX, int iY, BYTE);
VOID EXPORTFUNC MDADrawSVertBar(int iX, int iSY, int iDY, BYTE);
VOID EXPORTFUNC MDADrawDVertBar(int iX, int iSY, int iDY, BYTE);

/* From MDASCROL.C */
VOID EXPORTFUNC MDAScrollUp(int iSX, int iSY, int iDX, int iDY);
VOID EXPORTFUNC MDAScrollDown(int iSX, int iSY, int iDX, int iDY);
VOID EXPORTFUNC MDAScrollLeft(int iSX, int iSY, int iDX, int iDY);
VOID EXPORTFUNC MDAScrollRight(int iSX, int iSY, int iDX, int iDY);

/* From MDAVALUE.C */

/* From MDAGRAPH.C */
VOID EXPORTFUNC MDADrawHorizGraph(int iX, int iY, int iLen, int iVal, int iMax);
VOID EXPORTFUNC MDADrawHGraphMarker(int iX, int iY, int iLen, int iVal, int iMax, BYTE cMarker, BYTE cColour);

/* From MDARSC.C */

/* From MDAMEM.C */

/* From MDAAPP.C */
VOID EXPORTFUNC MDAAutoMonitor(VOID);

#endif /* _MDAFUNCS_H_ */
