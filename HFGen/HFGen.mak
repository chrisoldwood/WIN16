# Microsoft Visual C++ generated build script - Do not modify

PROJ = HFGEN
DEBUG = 1
PROGTYPE = 0
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = /d_DEBUG 
R_RCDEFINES = /dNDEBUG 
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\DEV\HFGEN\
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
OBJS_EXT = ..\WCL\LIB16M\WINMAIN.OBJ 
LIBS_EXT = ..\WCL\LIB16M\WCL.LIB 
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
		ADDTPDLG.SBR \
		APP.SBR \
		APPVIEW.SBR \
		APPWND.SBR \
		BATFILE.SBR \
		BODYTAB.SBR \
		COMPDLG.SBR \
		GENRLTAB.SBR \
		HEADRTAB.SBR \
		HELPDOC.SBR \
		HPJFILE.SBR \
		PREFS.SBR \
		PROJDLG.SBR \
		RTFFILE.SBR \
		TOPIC.SBR \
		TOPICEB.SBR \
		TOPICENM.SBR \
		TOPICLST.SBR \
		TOPICSLB.SBR


WINMAIN_DEP = 

WCL_DEP = 

APP16_RCDEP = d:\dev\hfgen\wclrsc.h \
	d:\dev\hfgen\appicon.ico \
	d:\dev\hfgen\toolbar.bmp \
	d:\dev\hfgen\splitter.cur \
	d:\dev\hfgen\app16.rcv


ABOUTDLG_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\aboutdlg.hpp


ADDTPDLG_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\addtpdlg.hpp


APP_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


APPVIEW_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


APPWND_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\aboutdlg.hpp \
	d:\dev\hfgen\addtpdlg.hpp \
	d:\dev\hfgen\compdlg.hpp \
	d:\dev\hfgen\projdlg.hpp \
	d:\dev\hfgen\genrltab.hpp \
	d:\dev\hfgen\headrtab.hpp \
	d:\dev\hfgen\bodytab.hpp


BATFILE_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


BODYTAB_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


COMPDLG_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\compdlg.hpp


GENRLTAB_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\genrltab.hpp


HEADRTAB_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


HELPDOC_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


HPJFILE_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


PREFS_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


PROJDLG_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp \
	d:\dev\hfgen\projdlg.hpp \
	d:\dev\hfgen\genrltab.hpp \
	d:\dev\hfgen\headrtab.hpp \
	d:\dev\hfgen\bodytab.hpp


RTFFILE_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


TOPIC_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


TOPICEB_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


TOPICENM_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


TOPICLST_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


TOPICSLB_DEP = d:\dev\hfgen\apphdrs.hpp \
	d:\dev\hfgen\appbuild.hpp \
	d:\dev\hfgen\topic.hpp \
	d:\dev\hfgen\topiclst.hpp \
	d:\dev\hfgen\topicenm.hpp \
	d:\dev\hfgen\rtffile.hpp \
	d:\dev\hfgen\hpjfile.hpp \
	d:\dev\hfgen\batfile.hpp \
	d:\dev\hfgen\helpdoc.hpp \
	d:\dev\hfgen\appwnd.hpp \
	d:\dev\hfgen\topiceb.hpp \
	d:\dev\hfgen\topicslb.hpp \
	d:\dev\hfgen\appview.hpp \
	d:\dev\hfgen\prefs.hpp \
	d:\dev\hfgen\app.hpp


all:	$(PROJ).EXE $(PROJ).BSC

APP16.RES:	APP16.RC $(APP16_RCDEP)
	$(RC) $(RCFLAGS) $(RCDEFINES) -r APP16.RC

ABOUTDLG.OBJ:	ABOUTDLG.CPP $(ABOUTDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c ABOUTDLG.CPP

ADDTPDLG.OBJ:	ADDTPDLG.CPP $(ADDTPDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ADDTPDLG.CPP

APP.OBJ:	APP.CPP $(APP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APP.CPP

APPVIEW.OBJ:	APPVIEW.CPP $(APPVIEW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APPVIEW.CPP

APPWND.OBJ:	APPWND.CPP $(APPWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c APPWND.CPP

BATFILE.OBJ:	BATFILE.CPP $(BATFILE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c BATFILE.CPP

BODYTAB.OBJ:	BODYTAB.CPP $(BODYTAB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c BODYTAB.CPP

COMPDLG.OBJ:	COMPDLG.CPP $(COMPDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c COMPDLG.CPP

GENRLTAB.OBJ:	GENRLTAB.CPP $(GENRLTAB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c GENRLTAB.CPP

HEADRTAB.OBJ:	HEADRTAB.CPP $(HEADRTAB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HEADRTAB.CPP

HELPDOC.OBJ:	HELPDOC.CPP $(HELPDOC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HELPDOC.CPP

HPJFILE.OBJ:	HPJFILE.CPP $(HPJFILE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c HPJFILE.CPP

PREFS.OBJ:	PREFS.CPP $(PREFS_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c PREFS.CPP

PROJDLG.OBJ:	PROJDLG.CPP $(PROJDLG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c PROJDLG.CPP

RTFFILE.OBJ:	RTFFILE.CPP $(RTFFILE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c RTFFILE.CPP

TOPIC.OBJ:	TOPIC.CPP $(TOPIC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TOPIC.CPP

TOPICEB.OBJ:	TOPICEB.CPP $(TOPICEB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TOPICEB.CPP

TOPICENM.OBJ:	TOPICENM.CPP $(TOPICENM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TOPICENM.CPP

TOPICLST.OBJ:	TOPICLST.CPP $(TOPICLST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TOPICLST.CPP

TOPICSLB.OBJ:	TOPICSLB.CPP $(TOPICSLB_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c TOPICSLB.CPP


$(PROJ).EXE::	APP16.RES

$(PROJ).EXE::	ABOUTDLG.OBJ ADDTPDLG.OBJ APP.OBJ APPVIEW.OBJ APPWND.OBJ BATFILE.OBJ \
	BODYTAB.OBJ COMPDLG.OBJ GENRLTAB.OBJ HEADRTAB.OBJ HELPDOC.OBJ HPJFILE.OBJ PREFS.OBJ \
	PROJDLG.OBJ RTFFILE.OBJ TOPIC.OBJ TOPICEB.OBJ TOPICENM.OBJ TOPICLST.OBJ TOPICSLB.OBJ $(OBJS_EXT) $(DEFFILE)
	echo >NUL @<<$(PROJ).CRF
ABOUTDLG.OBJ +
ADDTPDLG.OBJ +
APP.OBJ +
APPVIEW.OBJ +
APPWND.OBJ +
BATFILE.OBJ +
BODYTAB.OBJ +
COMPDLG.OBJ +
GENRLTAB.OBJ +
HEADRTAB.OBJ +
HELPDOC.OBJ +
HPJFILE.OBJ +
PREFS.OBJ +
PROJDLG.OBJ +
RTFFILE.OBJ +
TOPIC.OBJ +
TOPICEB.OBJ +
TOPICENM.OBJ +
TOPICLST.OBJ +
TOPICSLB.OBJ +
$(OBJS_EXT)
$(PROJ).EXE
$(MAPFILE)
d:\msvc\lib\+
d:\msvc\mfc\lib\+
..\WCL\LIB16M\WCL.LIB+
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
