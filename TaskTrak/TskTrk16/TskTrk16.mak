# Microsoft Visual C++ generated build script - Do not modify

PROJ = TSKTRK16
DEBUG = 0
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\DEV\TASKTRAK\TSKTRK16\
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
CFLAGS_R_WEXE = /nologo /Gs /G3 /W4 /WX /AM /YX"APPHDRS.HPP" /O2 /Ox /Ob1 /D "NDEBUG" /I "\DEV\WCL\SOURCE" /GA /Fp"APP.PCH"
LFLAGS_D_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE /CO  
LFLAGS_R_WEXE = /NOLOGO /NOD /PACKC:61440 /STACK:10240 /ALIGN:16 /ONERROR:NOEXE  
LIBS_D_WEXE = oldnames libw mlibcew commdlg.lib 
LIBS_R_WEXE = oldnames libw mlibcew commdlg.lib 
RCFLAGS = /nologo /i ..\source 
RESFLAGS = /nologo 
RUNFLAGS = 
DEFFILE = APP16.DEF
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
		ADDSNDLG.SBR \
		APP.SBR \
		APPDLG.SBR \
		APPWND.SBR \
		CLKINDLG.SBR \
		CLKOTDLG.SBR \
		DATE.SBR \
		DATEEB.SBR \
		DATETIME.SBR \
		EDTSNDLG.SBR \
		EXPRTDLG.SBR \
		FILEEXP.SBR \
		MODSNDLG.SBR \
		PRINTDLG.SBR \
		PRINTEXP.SBR \
		PRSESDLG.SBR \
		PRTSKDLG.SBR \
		SESSENUM.SBR \
		SESSION.SBR \
		SESSLIST.SBR \
		SESSNLB.SBR \
		SWTSKDLG.SBR \
		TASKLIST.SBR \
		TIME.SBR \
		TIMEEB.SBR \
		TSKCOMBO.SBR


WINMAIN_DEP = 

WCL_DEP = 

APP16_RCDEP = d:\dev\tasktrak\source\wclrsc.h \
	d:\dev\tasktrak\source\appicon.ico \
	d:\dev\tasktrak\source\toolbar.bmp \
	d:\dev\tasktrak\source\app16.rcv


ABOUTDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\aboutdlg.hpp


ADDSNDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\addsndlg.hpp


APP_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


APPDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


APPWND_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\aboutdlg.hpp \
	d:\dev\tasktrak\source\clkindlg.hpp \
	d:\dev\tasktrak\source\clkotdlg.hpp \
	d:\dev\tasktrak\source\swtskdlg.hpp \
	d:\dev\tasktrak\source\edtsndlg.hpp \
	d:\dev\tasktrak\source\prsesdlg.hpp \
	d:\dev\tasktrak\source\prtskdlg.hpp \
	d:\dev\tasktrak\source\exprtdlg.hpp \
	d:\dev\tasktrak\source\printdlg.hpp


CLKINDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\clkindlg.hpp


CLKOTDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\clkotdlg.hpp


DATE_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


DATEEB_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


DATETIME_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


EDTSNDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\edtsndlg.hpp \
	d:\dev\tasktrak\source\addsndlg.hpp \
	d:\dev\tasktrak\source\modsndlg.hpp


EXPRTDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\exprtdlg.hpp


FILEEXP_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


MODSNDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\modsndlg.hpp


PRINTDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\printdlg.hpp


PRINTEXP_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


PRSESDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\prsesdlg.hpp


PRTSKDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\prtskdlg.hpp


SESSENUM_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


SESSION_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


SESSLIST_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


SESSNLB_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


SWTSKDLG_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp \
	d:\dev\tasktrak\source\swtskdlg.hpp


TASKLIST_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


TIME_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


TIMEEB_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


TSKCOMBO_DEP = d:\dev\tasktrak\source\apphdrs.hpp \
	d:\dev\tasktrak\source\appbuild.hpp \
	d:\dev\tasktrak\source\time.hpp \
	d:\dev\tasktrak\source\timeeb.hpp \
	d:\dev\tasktrak\source\date.hpp \
	d:\dev\tasktrak\source\dateeb.hpp \
	d:\dev\tasktrak\source\datetime.hpp \
	d:\dev\tasktrak\source\session.hpp \
	d:\dev\tasktrak\source\sesslist.hpp \
	d:\dev\tasktrak\source\sessenum.hpp \
	d:\dev\tasktrak\source\sessnlb.hpp \
	d:\dev\tasktrak\source\tasklist.hpp \
	d:\dev\tasktrak\source\tsklsten.hpp \
	d:\dev\tasktrak\source\tskcombo.hpp \
	d:\dev\tasktrak\source\export.hpp \
	d:\dev\tasktrak\source\printexp.hpp \
	d:\dev\tasktrak\source\fileexp.hpp \
	d:\dev\tasktrak\source\appdlg.hpp \
	d:\dev\tasktrak\source\appwnd.hpp \
	d:\dev\tasktrak\source\app.hpp


all:	$(PROJ).EXE

APP16.RES:	..\SOURCE\APP16.RC $(APP16_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r -FoD:\DEV\TASKTRAK\TSKTRK16\APP16.RES ..\SOURCE\APP16.RC

ABOUTDLG.OBJ:	..\SOURCE\ABOUTDLG.CPP $(ABOUTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c ..\SOURCE\ABOUTDLG.CPP

ADDSNDLG.OBJ:	..\SOURCE\ADDSNDLG.CPP $(ADDSNDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\ADDSNDLG.CPP

APP.OBJ:	..\SOURCE\APP.CPP $(APP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\APP.CPP

APPDLG.OBJ:	..\SOURCE\APPDLG.CPP $(APPDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\APPDLG.CPP

APPWND.OBJ:	..\SOURCE\APPWND.CPP $(APPWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\APPWND.CPP

CLKINDLG.OBJ:	..\SOURCE\CLKINDLG.CPP $(CLKINDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\CLKINDLG.CPP

CLKOTDLG.OBJ:	..\SOURCE\CLKOTDLG.CPP $(CLKOTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\CLKOTDLG.CPP

DATE.OBJ:	..\SOURCE\DATE.CPP $(DATE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DATE.CPP

DATEEB.OBJ:	..\SOURCE\DATEEB.CPP $(DATEEB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DATEEB.CPP

DATETIME.OBJ:	..\SOURCE\DATETIME.CPP $(DATETIME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DATETIME.CPP

EDTSNDLG.OBJ:	..\SOURCE\EDTSNDLG.CPP $(EDTSNDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\EDTSNDLG.CPP

EXPRTDLG.OBJ:	..\SOURCE\EXPRTDLG.CPP $(EXPRTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\EXPRTDLG.CPP

FILEEXP.OBJ:	..\SOURCE\FILEEXP.CPP $(FILEEXP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\FILEEXP.CPP

MODSNDLG.OBJ:	..\SOURCE\MODSNDLG.CPP $(MODSNDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MODSNDLG.CPP

PRINTDLG.OBJ:	..\SOURCE\PRINTDLG.CPP $(PRINTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PRINTDLG.CPP

PRINTEXP.OBJ:	..\SOURCE\PRINTEXP.CPP $(PRINTEXP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PRINTEXP.CPP

PRSESDLG.OBJ:	..\SOURCE\PRSESDLG.CPP $(PRSESDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PRSESDLG.CPP

PRTSKDLG.OBJ:	..\SOURCE\PRTSKDLG.CPP $(PRTSKDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PRTSKDLG.CPP

SESSENUM.OBJ:	..\SOURCE\SESSENUM.CPP $(SESSENUM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SESSENUM.CPP

SESSION.OBJ:	..\SOURCE\SESSION.CPP $(SESSION_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SESSION.CPP

SESSLIST.OBJ:	..\SOURCE\SESSLIST.CPP $(SESSLIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SESSLIST.CPP

SESSNLB.OBJ:	..\SOURCE\SESSNLB.CPP $(SESSNLB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SESSNLB.CPP

SWTSKDLG.OBJ:	..\SOURCE\SWTSKDLG.CPP $(SWTSKDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SWTSKDLG.CPP

TASKLIST.OBJ:	..\SOURCE\TASKLIST.CPP $(TASKLIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TASKLIST.CPP

TIME.OBJ:	..\SOURCE\TIME.CPP $(TIME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TIME.CPP

TIMEEB.OBJ:	..\SOURCE\TIMEEB.CPP $(TIMEEB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TIMEEB.CPP

TSKCOMBO.OBJ:	..\SOURCE\TSKCOMBO.CPP $(TSKCOMBO_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TSKCOMBO.CPP


$(PROJ).EXE::	APP16.RES

$(PROJ).EXE::	ABOUTDLG.OBJ ADDSNDLG.OBJ APP.OBJ APPDLG.OBJ APPWND.OBJ CLKINDLG.OBJ \
	CLKOTDLG.OBJ DATE.OBJ DATEEB.OBJ DATETIME.OBJ EDTSNDLG.OBJ EXPRTDLG.OBJ FILEEXP.OBJ \
	MODSNDLG.OBJ PRINTDLG.OBJ PRINTEXP.OBJ PRSESDLG.OBJ PRTSKDLG.OBJ SESSENUM.OBJ SESSION.OBJ \
	SESSLIST.OBJ SESSNLB.OBJ SWTSKDLG.OBJ TASKLIST.OBJ TIME.OBJ TIMEEB.OBJ TSKCOMBO.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ABOUTDLG.OBJ +
ADDSNDLG.OBJ +
APP.OBJ +
APPDLG.OBJ +
APPWND.OBJ +
CLKINDLG.OBJ +
CLKOTDLG.OBJ +
DATE.OBJ +
DATEEB.OBJ +
DATETIME.OBJ +
EDTSNDLG.OBJ +
EXPRTDLG.OBJ +
FILEEXP.OBJ +
MODSNDLG.OBJ +
PRINTDLG.OBJ +
PRINTEXP.OBJ +
PRSESDLG.OBJ +
PRTSKDLG.OBJ +
SESSENUM.OBJ +
SESSION.OBJ +
SESSLIST.OBJ +
SESSNLB.OBJ +
SWTSKDLG.OBJ +
TASKLIST.OBJ +
TIME.OBJ +
TIMEEB.OBJ +
TSKCOMBO.OBJ +
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
