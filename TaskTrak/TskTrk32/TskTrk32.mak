# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "TskTrk32.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
OUTDIR=.
INTDIR=.

ALL : .\TskTrk32.exe .\TskTrk32.bsc

MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe
BSC32=bscmake.exe
LINK32=link.exe
DEF_FILE=
LINK32_OBJS= \
	.\AppWnd.obj \
	.\ClkOtDlg.obj \
	.\SessnLb.obj \
	.\ListEnum.obj \
	.\SesLstEn.obj \
	.\DateTime.obj \
	$(INTDIR)/wcl.lib \
	.\ClkInDlg.obj \
	.\SessList.obj \
	.\EdtSnDlg.obj \
	.\ExprtDlg.obj \
	.\AddSnDlg.obj \
	.\App32.res \
	.\Time.obj \
	.\TimeEb.obj \
	.\App.obj \
	.\PrSesDlg.obj \
	.\ABOUTDLG.OBJ \
	.\FileExp.obj \
	.\SwTskDlg.obj \
	.\Date.obj \
	.\TaskList.obj \
	.\TskCombo.obj \
	.\DateEb.obj \
	.\PrintDlg.obj \
	$(INTDIR)/WINMAIN.obj \
	.\AppDlg.obj \
	.\Session.obj \
	.\ModSnDlg.obj \
	.\List.obj \
	.\PrintExp.obj

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W4 /WX /GX /YX"APPHDRS.HPP" /O2 /I "\Dev\Wcl\Source" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /W4 /WX /GX /YX"APPHDRS.HPP" /O2 /I "\Dev\Wcl\Source" /D\
 "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp$(OUTDIR)/"TskTrk32.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
RSC_PROJ=/l 0x809 /fo$(INTDIR)/"App32.res" /d "NDEBUG" 
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"TskTrk32.bsc" 
BSC32_SBRS= \
	
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"TskTrk32.pdb" /MACHINE:I386\
 /OUT:$(OUTDIR)/"TskTrk32.exe" 

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W4 /WX /GX /Zi /YX"APPHDRS.HPP" /Od /I "\Dev\Wcl\Source" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr /Zn /c
CPP_PROJ=/nologo /W4 /WX /GX /Zi /YX"APPHDRS.HPP" /Od /I "\Dev\Wcl\Source" /D\
 "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr$(INTDIR)/ /Zn /Fp$(OUTDIR)/"TskTrk32.pch"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"TskTrk32.pdb" /c 
CPP_OBJS=
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
RSC_PROJ=/l 0x809 /fo$(INTDIR)/"App32.res" /d "_DEBUG" 
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /Iu /o$(OUTDIR)/"TskTrk32.bsc" 
BSC32_SBRS= \
	.\AppWnd.sbr \
	.\ClkOtDlg.sbr \
	.\SessnLb.sbr \
	.\ListEnum.sbr \
	.\SesLstEn.sbr \
	.\DateTime.sbr \
	.\ClkInDlg.sbr \
	.\SessList.sbr \
	.\EdtSnDlg.sbr \
	.\ExprtDlg.sbr \
	.\AddSnDlg.sbr \
	.\Time.sbr \
	.\TimeEb.sbr \
	.\App.sbr \
	.\PrSesDlg.sbr \
	.\ABOUTDLG.SBR \
	.\FileExp.sbr \
	.\SwTskDlg.sbr \
	.\Date.sbr \
	.\TaskList.sbr \
	.\TskCombo.sbr \
	.\DateEb.sbr \
	.\PrintDlg.sbr \
	.\AppDlg.sbr \
	.\Session.sbr \
	.\ModSnDlg.sbr \
	.\List.sbr \
	.\PrintExp.sbr
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no /DEBUG /MACHINE:I386
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"TskTrk32.pdb" /DEBUG\
 /MACHINE:I386 /OUT:$(OUTDIR)/"TskTrk32.exe" 

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.\TskTrk32.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

.\TskTrk32.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\AppWnd.cpp
DEP_APPWN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\aboutdlg.hpp\
	\Dev\TaskTrak\Source\clkindlg.hpp\
	\Dev\TaskTrak\Source\clkotdlg.hpp\
	\Dev\TaskTrak\Source\swtskdlg.hpp\
	\Dev\TaskTrak\Source\edtsndlg.hpp\
	\Dev\TaskTrak\Source\prsesdlg.hpp\
	\Dev\TaskTrak\Source\exprtdlg.hpp\
	\Dev\TaskTrak\Source\printdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\AppWnd.obj :  $(SOURCE)  $(DEP_APPWN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ClkOtDlg.cpp
DEP_CLKOT=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\clkotdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ClkOtDlg.obj :  $(SOURCE)  $(DEP_CLKOT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\SessnLb.cpp
DEP_SESSN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\SessnLb.obj :  $(SOURCE)  $(DEP_SESSN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ListEnum.cpp
DEP_LISTE=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ListEnum.obj :  $(SOURCE)  $(DEP_LISTE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\SesLstEn.cpp
DEP_SESLS=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\SesLstEn.obj :  $(SOURCE)  $(DEP_SESLS) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\DateTime.cpp
DEP_DATET=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\DateTime.obj :  $(SOURCE)  $(DEP_DATET) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Lib32\wcl.lib
# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ClkInDlg.cpp
DEP_CLKIN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\clkindlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ClkInDlg.obj :  $(SOURCE)  $(DEP_CLKIN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\SessList.cpp
DEP_SESSL=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\SessList.obj :  $(SOURCE)  $(DEP_SESSL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\EdtSnDlg.cpp
DEP_EDTSN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\edtsndlg.hpp\
	\Dev\TaskTrak\Source\addsndlg.hpp\
	\Dev\TaskTrak\Source\modsndlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\EdtSnDlg.obj :  $(SOURCE)  $(DEP_EDTSN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ExprtDlg.cpp
DEP_EXPRT=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\exprtdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ExprtDlg.obj :  $(SOURCE)  $(DEP_EXPRT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\AddSnDlg.cpp
DEP_ADDSN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\addsndlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\AddSnDlg.obj :  $(SOURCE)  $(DEP_ADDSN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\App32.rc
DEP_APP32=\
	\Dev\TaskTrak\Source\APPICON.ICO\
	\Dev\TaskTrak\Source\TOOLBAR.BMP\
	\Dev\TaskTrak\Source\wclrsc.h\
	\Dev\TaskTrak\Source\app32.rcv

!IF  "$(CFG)" == "Win32 Release"

.\App32.res :  $(SOURCE)  $(DEP_APP32) $(INTDIR)
   $(RSC) /l 0x809 /fo$(INTDIR)/"App32.res" /i "\Dev\TaskTrak\Source" /d\
 "NDEBUG"  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\App32.res :  $(SOURCE)  $(DEP_APP32) $(INTDIR)
   $(RSC) /l 0x809 /fo$(INTDIR)/"App32.res" /i "\Dev\TaskTrak\Source" /d\
 "_DEBUG"  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\Time.cpp
DEP_TIME_=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\Time.obj :  $(SOURCE)  $(DEP_TIME_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\TimeEb.cpp
DEP_TIMEE=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\TimeEb.obj :  $(SOURCE)  $(DEP_TIMEE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\App.cpp
DEP_APP_C=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\App.obj :  $(SOURCE)  $(DEP_APP_C) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\PrSesDlg.cpp
DEP_PRSES=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\prsesdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\PrSesDlg.obj :  $(SOURCE)  $(DEP_PRSES) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ABOUTDLG.CPP
DEP_ABOUT=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\aboutdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ABOUTDLG.OBJ :  $(SOURCE)  $(DEP_ABOUT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\FileExp.cpp
DEP_FILEE=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\FileExp.obj :  $(SOURCE)  $(DEP_FILEE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\SwTskDlg.cpp
DEP_SWTSK=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\swtskdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\SwTskDlg.obj :  $(SOURCE)  $(DEP_SWTSK) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\Date.cpp
DEP_DATE_=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\Date.obj :  $(SOURCE)  $(DEP_DATE_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\TaskList.cpp
DEP_TASKL=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\TaskList.obj :  $(SOURCE)  $(DEP_TASKL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\TskCombo.cpp
DEP_TSKCO=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\TskCombo.obj :  $(SOURCE)  $(DEP_TSKCO) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\DateEb.cpp
DEP_DATEE=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\DateEb.obj :  $(SOURCE)  $(DEP_DATEE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\PrintDlg.cpp
DEP_PRINT=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\printdlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\PrintDlg.obj :  $(SOURCE)  $(DEP_PRINT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\Wcl\Lib32\WINMAIN.obj
# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\AppDlg.cpp
DEP_APPDL=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\AppDlg.obj :  $(SOURCE)  $(DEP_APPDL) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\Session.cpp
DEP_SESSI=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\Session.obj :  $(SOURCE)  $(DEP_SESSI) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\ModSnDlg.cpp
DEP_MODSN=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\TaskTrak\Source\modsndlg.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\ModSnDlg.obj :  $(SOURCE)  $(DEP_MODSN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\List.cpp
DEP_LIST_=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\List.obj :  $(SOURCE)  $(DEP_LIST_) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Dev\TaskTrak\Source\PrintExp.cpp
DEP_PRINTE=\
	\Dev\TaskTrak\Source\apphdrs.hpp\
	\Dev\Wcl\Source\WCL.HPP\
	\Dev\TaskTrak\Source\appbuild.hpp\
	\Dev\TaskTrak\Source\time.hpp\
	\Dev\TaskTrak\Source\timeeb.hpp\
	\Dev\TaskTrak\Source\date.hpp\
	\Dev\TaskTrak\Source\dateeb.hpp\
	\Dev\TaskTrak\Source\datetime.hpp\
	\Dev\TaskTrak\Source\session.hpp\
	\Dev\TaskTrak\Source\list.hpp\
	\Dev\TaskTrak\Source\listenum.hpp\
	\Dev\TaskTrak\Source\sesslist.hpp\
	\Dev\TaskTrak\Source\seslsten.hpp\
	\Dev\TaskTrak\Source\sessnlb.hpp\
	\Dev\TaskTrak\Source\tasklist.hpp\
	\Dev\TaskTrak\Source\tsklsten.hpp\
	\Dev\TaskTrak\Source\tskcombo.hpp\
	\Dev\TaskTrak\Source\export.hpp\
	\Dev\TaskTrak\Source\printexp.hpp\
	\Dev\TaskTrak\Source\fileexp.hpp\
	\Dev\TaskTrak\Source\appdlg.hpp\
	\Dev\TaskTrak\Source\appwnd.hpp\
	\Dev\TaskTrak\Source\app.hpp\
	\Dev\Wcl\Source\PRAGMAS.HPP\
	\Dev\Wcl\Source\WCLTYPES.HPP\
	\Dev\Wcl\Source\Wclbuild.hpp\
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

.\PrintExp.obj :  $(SOURCE)  $(DEP_PRINTE) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

# End Source File
# End Group
# End Project
################################################################################
