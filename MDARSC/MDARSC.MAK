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
!MESSAGE NMAKE /f "mdarsc.mak" CFG="Win32 Debug"
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
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : .\WinRel\mdarsc.exe .\WinRel\mdarsc.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /WX /GX /YX /O2 /I "h" /I "rsc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /W3 /WX /GX /YX /O2 /I "h" /I "rsc" /D "WIN32" /D "NDEBUG" /D\
 "_WINDOWS" /Fp$(OUTDIR)/"mdarsc.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /i "h" /d "NDEBUG"
RSC_PROJ=/l 0x809 /fo$(INTDIR)/"APP.res" /i "h" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"mdarsc.bsc" 
BSC32_SBRS= \
	

.\WinRel\mdarsc.bsc : $(OUTDIR)  $(BSC32_SBRS)
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# ADD LINK32 ctl3d32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
LINK32_FLAGS=ctl3d32.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"mdarsc.pdb" /MACHINE:I386\
 /DEF:".\APP.DEF" /OUT:$(OUTDIR)/"mdarsc.exe" 
DEF_FILE=.\APP.DEF
LINK32_OBJS= \
	.\WinRel\WINUTILS.OBJ \
	.\WinRel\DEBUG.OBJ \
	.\WinRel\WINMAIN.OBJ \
	.\WinRel\APPWND.OBJ \
	.\WinRel\ABOUTDLG.OBJ \
	.\WinRel\RSCOUT.OBJ \
	.\WinRel\APP.res \
	.\lib\MDATHUNK.LIB

.\WinRel\mdarsc.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : .\WinDebug\mdarsc.exe .\WinDebug\mdarsc.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE CPP /nologo /W3 /GX /Zi /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /WX /GX /Zi /YX /Od /I "h" /I "rsc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr /Zn /c
CPP_PROJ=/nologo /W3 /WX /GX /Zi /YX /Od /I "h" /I "rsc" /D "WIN32" /D "_DEBUG"\
 /D "_WINDOWS" /Fr$(INTDIR)/ /Zn /Fp$(OUTDIR)/"mdarsc.pch" /Fo$(INTDIR)/\
 /Fd$(OUTDIR)/"mdarsc.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /i "h" /d "_DEBUG"
RSC_PROJ=/l 0x809 /fo$(INTDIR)/"APP.res" /i "h" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /Iu /o$(OUTDIR)/"mdarsc.bsc" 
BSC32_SBRS= \
	.\WinDebug\WINUTILS.SBR \
	.\WinDebug\DEBUG.SBR \
	.\WinDebug\WINMAIN.SBR \
	.\WinDebug\APPWND.SBR \
	.\WinDebug\ABOUTDLG.SBR \
	.\WinDebug\RSCOUT.SBR

.\WinDebug\mdarsc.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# ADD LINK32 ctl3d32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no /DEBUG /MACHINE:I386
LINK32_FLAGS=ctl3d32.lib kernel32.lib user32.lib gdi32.lib winspool.lib\
 comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:no /PDB:$(OUTDIR)/"mdarsc.pdb" /DEBUG\
 /MACHINE:I386 /DEF:".\APP.DEF" /OUT:$(OUTDIR)/"mdarsc.exe" 
DEF_FILE=.\APP.DEF
LINK32_OBJS= \
	.\WinDebug\WINUTILS.OBJ \
	.\WinDebug\DEBUG.OBJ \
	.\WinDebug\WINMAIN.OBJ \
	.\WinDebug\APPWND.OBJ \
	.\WinDebug\ABOUTDLG.OBJ \
	.\WinDebug\RSCOUT.OBJ \
	.\WinDebug\APP.res \
	.\lib\MDATHUNK.LIB

.\WinDebug\mdarsc.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
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

SOURCE=.\c\WINUTILS.C
DEP_WINUT=\
	.\h\AF.H\
	.\h\WINUTILS.H\
	.\h\BASEDEFS.H\
	.\h\DEBUG.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\WINUTILS.OBJ :  $(SOURCE)  $(DEP_WINUT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\WINUTILS.OBJ :  $(SOURCE)  $(DEP_WINUT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\c\DEBUG.C

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\DEBUG.OBJ :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\DEBUG.OBJ :  $(SOURCE)  $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\c\WINMAIN.C
DEP_WINMA=\
	.\h\AF.H\
	.\h\WINUTILS.H\
	.\h\STRNGRSC.H\
	.\h\BASEDEFS.H\
	.\h\DEBUG.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\WINMAIN.OBJ :  $(SOURCE)  $(DEP_WINMA) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\WINMAIN.OBJ :  $(SOURCE)  $(DEP_WINMA) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\c\APPWND.C
DEP_APPWN=\
	.\h\AF.H\
	.\h\WINUTILS.H\
	.\h\MENURSC.H\
	.\h\STRNGRSC.H\
	.\h\BASEDEFS.H\
	.\h\DEBUG.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\APPWND.OBJ :  $(SOURCE)  $(DEP_APPWN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\APPWND.OBJ :  $(SOURCE)  $(DEP_APPWN) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\c\ABOUTDLG.C
DEP_ABOUT=\
	.\h\AF.H\
	.\h\WINUTILS.H\
	.\h\BASEDEFS.H\
	.\h\DEBUG.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\ABOUTDLG.OBJ :  $(SOURCE)  $(DEP_ABOUT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\ABOUTDLG.OBJ :  $(SOURCE)  $(DEP_ABOUT) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\c\RSCOUT.C
DEP_RSCOU=\
	.\h\AF.H\
	.\h\MENURSC.H\
	.\h\BASEDEFS.H\
	.\h\DEBUG.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\RSCOUT.OBJ :  $(SOURCE)  $(DEP_RSCOU) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\RSCOUT.OBJ :  $(SOURCE)  $(DEP_RSCOU) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "Resources"

################################################################################
# Begin Source File

SOURCE=.\rsc\APP.RC
DEP_APP_R=\
	.\rsc\APP.ICO\
	.\h\MENURSC.H\
	.\h\STRNGRSC.H

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\APP.res :  $(SOURCE)  $(DEP_APP_R) $(INTDIR)
   $(RSC) /l 0x809 /fo$(INTDIR)/"APP.res" /i "h" /i "rsc" /d "NDEBUG"\
  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

.\WinDebug\APP.res :  $(SOURCE)  $(DEP_APP_R) $(INTDIR)
   $(RSC) /l 0x809 /fo$(INTDIR)/"APP.res" /i "h" /i "rsc" /d "_DEBUG"\
  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
################################################################################
# Begin Group "Libraries"

################################################################################
# Begin Source File

SOURCE=.\lib\MDATHUNK.LIB
# End Source File
################################################################################
# Begin Source File

SOURCE=.\APP.DEF
# End Source File
# End Group
# End Project
################################################################################
