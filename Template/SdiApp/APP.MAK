# Microsoft Visual C++ generated build script - Do not modify

PROJ = APP
DEBUG = 1
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\DEV\TEMPLATE\SDIAPP\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = ABOUTDLG.CPP
RC = rc
CFLAGS_D_WEXE = /nologo /G2 /W4 /WX /Zi /AM /YX"APPHDRS.HPP" /Od /D "_DEBUG" /I "\DEV\WCL\SOURCE" /FR /Zn /GA /Fd"APP.PDB"   /Fp"APP.PCH"
CFLAGS_R_WEXE = /nologo /Gs /G2 /W4 /WX /AM /YX"APPHDRS.HPP" /Ox /Ob2 /D "NDEBUG" /I "\DEV\WCL\SOURCE" /GA /Fp"APP.PCH"
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = oldnames libw mlibcew commdlg.lib 
LIBS_R_WEXE = oldnames libw mlibcew commdlg.lib 
RCFLAGS = /nologo 
RESFLAGS = /nologo 
RUNFLAGS = 
DEFFILE = APP.DEF
OBJS_EXT = ..\..\WCL\LIB16M\WINMAIN.OBJ 
LIBS_EXT = ..\..\WCL\LIB16M\WCL.LIB 
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
SBRS = ABOUTDLG.SBR \
		APP.SBR \
		APPVIEW.SBR \
		APPWND.SBR


WINMAIN_DEP = 

WCL_DEP = 

APP16_RCDEP = d:\dev\template\sdiapp\wclrsc.h \
	d:\dev\template\sdiapp\appicon.ico \
	d:\dev\template\sdiapp\toolbar.bmp \
	d:\dev\template\sdiapp\app16.rcv


ABOUTDLG_DEP = d:\dev\template\sdiapp\apphdrs.hpp \
	d:\dev\template\sdiapp\appbuild.hpp \
	d:\dev\template\sdiapp\appwnd.hpp \
	d:\dev\template\sdiapp\appview.hpp \
	d:\dev\template\sdiapp\app.hpp \
	d:\dev\template\sdiapp\aboutdlg.hpp


APP_DEP = d:\dev\template\sdiapp\apphdrs.hpp \
	d:\dev\template\sdiapp\appbuild.hpp \
	d:\dev\template\sdiapp\appwnd.hpp \
	d:\dev\template\sdiapp\appview.hpp \
	d:\dev\template\sdiapp\app.hpp


APPVIEW_DEP = d:\dev\template\sdiapp\apphdrs.hpp \
	d:\dev\template\sdiapp\appbuild.hpp \
	d:\dev\template\sdiapp\appwnd.hpp \
	d:\dev\template\sdiapp\appview.hpp \
	d:\dev\template\sdiapp\app.hpp


APPWND_DEP = d:\dev\template\sdiapp\apphdrs.hpp \
	d:\dev\template\sdiapp\appbuild.hpp \
	d:\dev\template\sdiapp\appwnd.hpp \
	d:\dev\template\sdiapp\appview.hpp \
	d:\dev\template\sdiapp\app.hpp \
	d:\dev\template\sdiapp\aboutdlg.hpp


all:	$(PROJ).EXE $(PROJ).BSC

APP16.RES:	APP16.RC $(APP16_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r APP16.RC

ABOUTDLG.OBJ:	ABOUTDLG.CPP $(ABOUTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c ABOUTDLG.CPP

APP.OBJ:	APP.CPP $(APP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APP.CPP

APPVIEW.OBJ:	APPVIEW.CPP $(APPVIEW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APPVIEW.CPP

APPWND.OBJ:	APPWND.CPP $(APPWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APPWND.CPP


$(PROJ).EXE::	APP16.RES

$(PROJ).EXE::	ABOUTDLG.OBJ APP.OBJ APPVIEW.OBJ APPWND.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ABOUTDLG.OBJ +
APP.OBJ +
APPVIEW.OBJ +
APPWND.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
d:\msvc\lib\+
d:\msvc\mfc\lib\+
..\..\WCL\LIB16M\WCL.LIB+
$(LIBS)
$(DEFFILE);
<<
	link $(LFLAGS) @$(PROJ).CRF
	$(RC) $(RESFLAGS) APP16.RES $@
	@copy $(PROJ).CRF MSVC.BND

$(PROJ).EXE::	APP16.RES
	if not exist MSVC.BND 	$(RC) $(RESFLAGS) APP16.RES $@

run: $(PROJ).EXE
	$(PROJ) $(RUNFLAGS)


$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
