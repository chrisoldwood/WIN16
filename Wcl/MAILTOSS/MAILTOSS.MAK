# Microsoft Visual C++ generated build script - Do not modify

PROJ = MAILTOSS
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = C:\DEV\NETWARE\MAILTOSS\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC = APPUTILS.C  
FIRSTCPP =             
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W4 /WX /Zi /AM /Od /D "_DEBUG" /D "NWWIN" /FR /Zn /GA /Fd"MAILTOSS.PDB"
CFLAGS_R_WEXE = /nologo /Gs /G2 /Gy /W4 /WX /Gf /AM /O2 /D "NDEBUG" /D "NWWIN" /GA 
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = oldnames libw mlibcew nwcalls lzexpand.lib 
LIBS_R_WEXE = oldnames libw mlibcew nwcalls lzexpand.lib 
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
DEFFILE = MAILTOSS.DEF
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_WEXE)
LFLAGS = $(LFLAGS_D_WEXE)
LIBS = $(LIBS_D_WEXE)
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_WEXE)
LFLAGS = $(LFLAGS_R_WEXE)
LIBS = $(LIBS_R_WEXE)
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = APPUTILS.SBR \
		DEBUG.SBR \
		IODLG.SBR \
		IOUTILS.SBR \
		RSCUTILS.SBR \
		WINMAIN.SBR


APPUTILS_DEP = h\af.h \
	h\basedefs.h \
	h\debug.h \
	h\apputils.h


DEBUG_DEP = 

IODLG_DEP = h\af.h \
	h\basedefs.h \
	h\debug.h \
	h\apputils.h \
	h\rscutils.h


IOUTILS_DEP = h\af.h \
	h\basedefs.h \
	h\debug.h \
	h\ioutils.h


RSCUTILS_DEP = h\af.h \
	h\basedefs.h \
	h\debug.h \
	h\rscutils.h


WINMAIN_DEP = h\af.h \
	h\basedefs.h \
	h\debug.h \
	nw_inc\nwcalls.h \
	nw_inc\nwcaldef.h \
	nw_inc\nwalias.h \
	nw_inc\nwafp.h \
	nw_inc\nwbindry.h \
	nw_inc\nwconnec.h \
	nw_inc\nwdel.h \
	nw_inc\nwdentry.h \
	nw_inc\nwdirect.h \
	nw_inc\nwdpath.h \
	nw_inc\nwea.h \
	nw_inc\nwnamspc.h \
	nw_inc\nwerror.h \
	nw_inc\nwfile.h \
	nw_inc\nwmisc.h \
	nw_inc\nwmsg.h \
	nw_inc\nwprint.h \
	nw_inc\nwqms.h \
	nw_inc\nwserver.h \
	nw_inc\nwsync.h \
	nw_inc\nwtts.h \
	nw_inc\nwvol.h \
	nw_inc\nwacct.h \
	nw_inc\nwfse.h \
	nw_inc\nwmigrat.h \
	h\rscutils.h \
	h\ioutils.h \
	h\apputils.h


MAILTOSS_RCDEP = c:\dev\netware\mailtoss\rsc\mailtoss.ico


all:	$(PROJ).EXE

APPUTILS.OBJ:	C\APPUTILS.C $(APPUTILS_DEP)
	$(CC) $(CFLAGS) $(CCREATEPCHFLAG) /c C\APPUTILS.C

DEBUG.OBJ:	C\DEBUG.C $(DEBUG_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c C\DEBUG.C

IODLG.OBJ:	C\IODLG.C $(IODLG_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c C\IODLG.C

IOUTILS.OBJ:	C\IOUTILS.C $(IOUTILS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c C\IOUTILS.C

RSCUTILS.OBJ:	C\RSCUTILS.C $(RSCUTILS_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c C\RSCUTILS.C

WINMAIN.OBJ:	C\WINMAIN.C $(WINMAIN_DEP)
	$(CC) $(CFLAGS) $(CUSEPCHFLAG) /c C\WINMAIN.C

MAILTOSS.RES:	RSC\MAILTOSS.RC $(MAILTOSS_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r -FoC:\DEV\NETWARE\MAILTOSS\MAILTOSS.RES RSC\MAILTOSS.RC


$(PROJ).EXE::	MAILTOSS.RES

$(PROJ).EXE::	APPUTILS.OBJ DEBUG.OBJ IODLG.OBJ IOUTILS.OBJ RSCUTILS.OBJ WINMAIN.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
APPUTILS.OBJ +
DEBUG.OBJ +
IODLG.OBJ +
IOUTILS.OBJ +
RSCUTILS.OBJ +
WINMAIN.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
s:\public\vc151\lib\+
s:\public\vc151\mfc\lib\+
nw_lib\+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) MAILTOSS.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	MAILTOSS.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) MAILTOSS.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
