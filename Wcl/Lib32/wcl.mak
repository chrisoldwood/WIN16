# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "wcl.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
OUTDIR=.
INTDIR=.

ALL : $(OUTDIR)/wcl.lib $(OUTDIR)/wcl.bsc

# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W4 /WX /GX /YX"WCL.HPP" /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /W4 /WX /GX /YX"WCL.HPP" /O2 /D "WIN32" /D "NDEBUG" /D\
 "_WINDOWS" /Fp$(OUTDIR)/"wcl.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"wcl.bsc" 
BSC32_SBRS= \
	

$(OUTDIR)/wcl.bsc : $(OUTDIR)  $(BSC32_SBRS)
LIB32=lib.exe
DEF_FLAGS=
DEF_FILE=
LIB32_OBJS= \
	$(INTDIR)/Task.obj \
	$(INTDIR)/COMBOBOX.OBJ \
	$(INTDIR)/LOCALMEM.OBJ \
	$(INTDIR)/Button.obj \
	$(INTDIR)/HEAPMGR.OBJ \
	$(INTDIR)/DC.obj \
	$(INTDIR)/DIALOG.OBJ \
	$(INTDIR)/Label.obj \
	$(INTDIR)/MEMLIST.OBJ \
	$(INTDIR)/Ctl3d.obj \
	$(INTDIR)/Wnd.obj \
	$(INTDIR)/LIBMAIN.OBJ \
	$(INTDIR)/Accel.obj \
	$(INTDIR)/INIFILE.OBJ \
	$(INTDIR)/CheckBox.obj \
	$(INTDIR)/RadioBtn.obj \
	$(INTDIR)/FILE.OBJ \
	$(INTDIR)/FrameWnd.obj \
	$(INTDIR)/BmpBtn.obj \
	$(INTDIR)/TOOLBAR.OBJ \
	$(INTDIR)/EDITBOX.OBJ \
	$(INTDIR)/MsgWnd.obj \
	$(INTDIR)/MODULE.OBJ \
	$(INTDIR)/MENU.OBJ \
	$(INTDIR)/GLOBLMEM.OBJ \
	$(INTDIR)/PopupWnd.obj \
	$(INTDIR)/BITMAP.OBJ \
	$(INTDIR)/PATH.OBJ \
	$(INTDIR)/MemDC.obj \
	$(INTDIR)/STRING.OBJ \
	$(INTDIR)/LISTBOX.OBJ \
	$(INTDIR)/PrintrDC.obj \
	$(INTDIR)/HEAPMEM.OBJ \
	$(INTDIR)/DLGFRAME.OBJ \
	$(INTDIR)/StatBar.obj \
	$(INTDIR)/CTRLWND.OBJ \
	$(INTDIR)/WINMAIN.OBJ \
	$(INTDIR)/ScreenDC.obj \
	$(INTDIR)/HASHTBLE.OBJ \
	$(INTDIR)/HintBar.obj \
	$(INTDIR)/ASSERT.OBJ
# ADD BASE LIB32 /NOLOGO
# ADD LIB32 /NOLOGO
LIB32_FLAGS=/NOLOGO /OUT:$(OUTDIR)\"wcl.lib" 

$(OUTDIR)/wcl.lib : $(OUTDIR)  $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
OUTDIR=.
INTDIR=.

ALL : $(OUTDIR)/wcl.lib $(OUTDIR)/wcl.bsc

# ADD BASE CPP /nologo /W3 /GX /Z7 /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W4 /WX /GX /Z7 /YX"WCL.HPP" /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr /Zn /c
CPP_PROJ=/nologo /W4 /WX /GX /Z7 /YX"WCL.HPP" /Od /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /Fr$(INTDIR)/ /Zn /Fp$(OUTDIR)/"wcl.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /Iu /o$(OUTDIR)/"wcl.bsc" 
BSC32_SBRS= \
	$(INTDIR)/Task.sbr \
	$(INTDIR)/COMBOBOX.SBR \
	$(INTDIR)/LOCALMEM.SBR \
	$(INTDIR)/Button.sbr \
	$(INTDIR)/HEAPMGR.SBR \
	$(INTDIR)/DC.sbr \
	$(INTDIR)/DIALOG.SBR \
	$(INTDIR)/Label.sbr \
	$(INTDIR)/MEMLIST.SBR \
	$(INTDIR)/Ctl3d.sbr \
	$(INTDIR)/Wnd.sbr \
	$(INTDIR)/LIBMAIN.SBR \
	$(INTDIR)/Accel.sbr \
	$(INTDIR)/INIFILE.SBR \
	$(INTDIR)/CheckBox.sbr \
	$(INTDIR)/RadioBtn.sbr \
	$(INTDIR)/FILE.SBR \
	$(INTDIR)/FrameWnd.sbr \
	$(INTDIR)/BmpBtn.sbr \
	$(INTDIR)/TOOLBAR.SBR \
	$(INTDIR)/EDITBOX.SBR \
	$(INTDIR)/MsgWnd.sbr \
	$(INTDIR)/MODULE.SBR \
	$(INTDIR)/MENU.SBR \
	$(INTDIR)/GLOBLMEM.SBR \
	$(INTDIR)/PopupWnd.sbr \
	$(INTDIR)/BITMAP.SBR \
	$(INTDIR)/PATH.SBR \
	$(INTDIR)/MemDC.sbr \
	$(INTDIR)/STRING.SBR \
	$(INTDIR)/LISTBOX.SBR \
	$(INTDIR)/PrintrDC.sbr \
	$(INTDIR)/HEAPMEM.SBR \
	$(INTDIR)/DLGFRAME.SBR \
	$(INTDIR)/StatBar.sbr \
	$(INTDIR)/CTRLWND.SBR \
	$(INTDIR)/WINMAIN.SBR \
	$(INTDIR)/ScreenDC.sbr \
	$(INTDIR)/HASHTBLE.SBR \
	$(INTDIR)/HintBar.sbr \
	$(INTDIR)/ASSERT.SBR

$(OUTDIR)/wcl.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=lib.exe
DEF_FLAGS=
DEF_FILE=
LIB32_OBJS= \
	$(INTDIR)/Task.obj \
	$(INTDIR)/COMBOBOX.OBJ \
	$(INTDIR)/LOCALMEM.OBJ \
	$(INTDIR)/Button.obj \
	$(INTDIR)/HEAPMGR.OBJ \
	$(INTDIR)/DC.obj \
	$(INTDIR)/DIALOG.OBJ \
	$(INTDIR)/Label.obj \
	$(INTDIR)/MEMLIST.OBJ \
	$(INTDIR)/Ctl3d.obj \
	$(INTDIR)/Wnd.obj \
	$(INTDIR)/LIBMAIN.OBJ \
	$(INTDIR)/Accel.obj \
	$(INTDIR)/INIFILE.OBJ \
	$(INTDIR)/CheckBox.obj \
	$(INTDIR)/RadioBtn.obj \
	$(INTDIR)/FILE.OBJ \
	$(INTDIR)/FrameWnd.obj \
	$(INTDIR)/BmpBtn.obj \
	$(INTDIR)/TOOLBAR.OBJ \
	$(INTDIR)/EDITBOX.OBJ \
	$(INTDIR)/MsgWnd.obj \
	$(INTDIR)/MODULE.OBJ \
	$(INTDIR)/MENU.OBJ \
	$(INTDIR)/GLOBLMEM.OBJ \
	$(INTDIR)/PopupWnd.obj \
	$(INTDIR)/BITMAP.OBJ \
	$(INTDIR)/PATH.OBJ \
	$(INTDIR)/MemDC.obj \
	$(INTDIR)/STRING.OBJ \
	$(INTDIR)/LISTBOX.OBJ \
	$(INTDIR)/PrintrDC.obj \
	$(INTDIR)/HEAPMEM.OBJ \
	$(INTDIR)/DLGFRAME.OBJ \
	$(INTDIR)/StatBar.obj \
	$(INTDIR)/CTRLWND.OBJ \
	$(INTDIR)/WINMAIN.OBJ \
	$(INTDIR)/ScreenDC.obj \
	$(INTDIR)/HASHTBLE.OBJ \
	$(INTDIR)/HintBar.obj \
	$(INTDIR)/ASSERT.OBJ
# ADD BASE LIB32 /NOLOGO
# ADD LIB32 /NOLOGO
LIB32_FLAGS=/NOLOGO /OUT:$(OUTDIR)\"wcl.lib" 

$(OUTDIR)/wcl.lib : $(OUTDIR)  $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Task.cpp
DEP_TASK_=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Task.obj :  $(SOURCE)  $(DEP_TASK_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\COMBOBOX.CPP
DEP_COMBO=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/COMBOBOX.OBJ :  $(SOURCE)  $(DEP_COMBO) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\LOCALMEM.CPP
DEP_LOCAL=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\MEMLIST.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/LOCALMEM.OBJ :  $(SOURCE)  $(DEP_LOCAL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Button.cpp
DEP_BUTTO=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Button.obj :  $(SOURCE)  $(DEP_BUTTO) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\HEAPMGR.CPP
DEP_HEAPM=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\HEAPMGR.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/HEAPMGR.OBJ :  $(SOURCE)  $(DEP_HEAPM) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\DC.cpp
DEP_DC_CP=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/DC.obj :  $(SOURCE)  $(DEP_DC_CP) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\DIALOG.CPP
DEP_DIALO=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/DIALOG.OBJ :  $(SOURCE)  $(DEP_DIALO) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Label.cpp
DEP_LABEL=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Label.obj :  $(SOURCE)  $(DEP_LABEL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\MEMLIST.CPP
DEP_MEMLI=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\MEMLIST.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/MEMLIST.OBJ :  $(SOURCE)  $(DEP_MEMLI) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Ctl3d.cpp
DEP_CTL3D=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Ctl3d.obj :  $(SOURCE)  $(DEP_CTL3D) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Wnd.cpp
DEP_WND_C=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Wnd.obj :  $(SOURCE)  $(DEP_WND_C) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\LIBMAIN.CPP
DEP_LIBMA=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/LIBMAIN.OBJ :  $(SOURCE)  $(DEP_LIBMA) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\Accel.cpp
DEP_ACCEL=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/Accel.obj :  $(SOURCE)  $(DEP_ACCEL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\INIFILE.CPP
DEP_INIFI=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/INIFILE.OBJ :  $(SOURCE)  $(DEP_INIFI) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\CheckBox.CPP
DEP_CHECK=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/CheckBox.obj :  $(SOURCE)  $(DEP_CHECK) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\RadioBtn.cpp
DEP_RADIO=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/RadioBtn.obj :  $(SOURCE)  $(DEP_RADIO) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\FILE.CPP
DEP_FILE_=\
	\Dev\Wcl\Source\WCL.HPP\
	\MSVC20\INCLUDE\sys\LOCKING.H\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/FILE.OBJ :  $(SOURCE)  $(DEP_FILE_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\FrameWnd.cpp
DEP_FRAME=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/FrameWnd.obj :  $(SOURCE)  $(DEP_FRAME) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\BmpBtn.cpp
DEP_BMPBT=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/BmpBtn.obj :  $(SOURCE)  $(DEP_BMPBT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\TOOLBAR.CPP
DEP_TOOLB=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/TOOLBAR.OBJ :  $(SOURCE)  $(DEP_TOOLB) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\EDITBOX.CPP
DEP_EDITB=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/EDITBOX.OBJ :  $(SOURCE)  $(DEP_EDITB) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\MsgWnd.cpp
DEP_MSGWN=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/MsgWnd.obj :  $(SOURCE)  $(DEP_MSGWN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\MODULE.CPP
DEP_MODUL=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/MODULE.OBJ :  $(SOURCE)  $(DEP_MODUL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\MENU.CPP
DEP_MENU_=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/MENU.OBJ :  $(SOURCE)  $(DEP_MENU_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\GLOBLMEM.CPP
DEP_GLOBL=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\MEMLIST.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/GLOBLMEM.OBJ :  $(SOURCE)  $(DEP_GLOBL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\PopupWnd.cpp
DEP_POPUP=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/PopupWnd.obj :  $(SOURCE)  $(DEP_POPUP) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\BITMAP.CPP
DEP_BITMA=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/BITMAP.OBJ :  $(SOURCE)  $(DEP_BITMA) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\PATH.CPP
DEP_PATH_=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/PATH.OBJ :  $(SOURCE)  $(DEP_PATH_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\MemDC.cpp
DEP_MEMDC=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/MemDC.obj :  $(SOURCE)  $(DEP_MEMDC) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\STRING.CPP
DEP_STRIN=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/STRING.OBJ :  $(SOURCE)  $(DEP_STRIN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\LISTBOX.CPP
DEP_LISTB=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/LISTBOX.OBJ :  $(SOURCE)  $(DEP_LISTB) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\PrintrDC.cpp
DEP_PRINT=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/PrintrDC.obj :  $(SOURCE)  $(DEP_PRINT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\HEAPMEM.CPP
DEP_HEAPME=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\HEAPMGR.HPP\
	\Dev\Wcl\Source\MEMLIST.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/HEAPMEM.OBJ :  $(SOURCE)  $(DEP_HEAPME) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\DLGFRAME.CPP
DEP_DLGFR=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/DLGFRAME.OBJ :  $(SOURCE)  $(DEP_DLGFR) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\StatBar.cpp
DEP_STATB=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/StatBar.obj :  $(SOURCE)  $(DEP_STATB) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\CTRLWND.CPP
DEP_CTRLW=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/CTRLWND.OBJ :  $(SOURCE)  $(DEP_CTRLW) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\WINMAIN.CPP
DEP_WINMA=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/WINMAIN.OBJ :  $(SOURCE)  $(DEP_WINMA) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\ScreenDC.cpp
DEP_SCREE=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/ScreenDC.obj :  $(SOURCE)  $(DEP_SCREE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\HASHTBLE.CPP
DEP_HASHT=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/HASHTBLE.OBJ :  $(SOURCE)  $(DEP_HASHT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\HintBar.cpp
DEP_HINTB=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/HintBar.obj :  $(SOURCE)  $(DEP_HINTB) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Source\ASSERT.CPP
DEP_ASSER=\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\ASSERT.HPP\
	\Dev\Wcl\Source\MEMMGR.HPP\
	\Dev\Wcl\Source\WCLRSC.H\
	\Dev\Wcl\Source\HASHTBLE.HPP\
	\Dev\Wcl\Source\POINT.HPP\
	\Dev\Wcl\Source\SIZE.HPP\
	\Dev\Wcl\Source\RECT.HPP\
	\Dev\Wcl\Source\STRING.HPP\
	\Dev\Wcl\Source\PATH.HPP\
	\Dev\Wcl\Source\MENU.HPP\
	\Dev\Wcl\Source\Accel.hpp\
	\Dev\Wcl\Source\BITMAP.HPP\
	\Dev\Wcl\Source\MODULE.HPP\
	\Dev\Wcl\Source\DC.hpp\
	\Dev\Wcl\Source\ScreenDC.hpp\
	\Dev\Wcl\Source\PrintrDC.hpp\
	\Dev\Wcl\Source\MemDC.hpp\
	\Dev\Wcl\Source\Wnd.hpp\
	\Dev\Wcl\Source\MsgWnd.hpp\
	\Dev\Wcl\Source\PopupWnd.hpp\
	\Dev\Wcl\Source\CTRLWND.HPP\
	\Dev\Wcl\Source\Label.hpp\
	\Dev\Wcl\Source\LISTBOX.HPP\
	\Dev\Wcl\Source\COMBOBOX.HPP\
	\Dev\Wcl\Source\EDITBOX.HPP\
	\Dev\Wcl\Source\CheckBox.HPP\
	\Dev\Wcl\Source\RadioBtn.hpp\
	\Dev\Wcl\Source\Button.hpp\
	\Dev\Wcl\Source\BmpBtn.hpp\
	\Dev\Wcl\Source\DIALOG.HPP\
	\Dev\Wcl\Source\HintBar.hpp\
	\Dev\Wcl\Source\StatBar.hpp\
	\Dev\Wcl\Source\TOOLBAR.HPP\
	\Dev\Wcl\Source\FrameWnd.hpp\
	\Dev\Wcl\Source\DLGFRAME.HPP\
	\Dev\Wcl\Source\HELPFILE.HPP\
	\Dev\Wcl\Source\INIFILE.HPP\
	\Dev\Wcl\Source\Ctl3d.hpp\
	\Dev\Wcl\Source\Task.hpp\
	\Dev\Wcl\Source\FILE.HPP

$(INTDIR)/ASSERT.OBJ :  $(SOURCE)  $(DEP_ASSER) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
# End Group
# End Project
################################################################################
