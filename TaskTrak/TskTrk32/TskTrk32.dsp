# Microsoft Developer Studio Project File - Name="TskTrk32" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TskTrk32 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TskTrk32.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TskTrk32.mak" CFG="TskTrk32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TskTrk32 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TskTrk32 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TskTrk32 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W4 /WX /GX /O2 /I "\dev\wcl\source" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX"APPHDRS.HPP" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TskTrk32 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W4 /WX /Gm /GX /Zi /Od /I "\dev\wcl\source" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX"APPHDRS.HPP" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG"
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TskTrk32 - Win32 Release"
# Name "TskTrk32 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "*.c;*.cpp"
# Begin Source File

SOURCE=..\Source\Aboutdlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\AddSnDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\App.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ClkInDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ClkOtDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Date.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\DateEb.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\DateTime.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\EdtSnDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ExprtDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\FileExp.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\List.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ListEnum.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ModSnDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintExp.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrSesDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\SesLstEn.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Session.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\SessList.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\SessnLb.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\SwTskDlg.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\TaskList.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Time.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\TimeEb.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\TskCombo.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h;*.hpp"
# Begin Source File

SOURCE=..\Source\Aboutdlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\AddSnDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\App.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppBuild.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppHdrs.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\AppWnd.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ClkInDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ClkOtDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Date.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\DateEb.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\DateTime.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\EdtSnDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Export.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ExprtDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\FileExp.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\List.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ListEnum.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ModSnDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintExp.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrSesDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\rsc32.h
# End Source File
# Begin Source File

SOURCE=..\Source\SesLstEn.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Session.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\SessList.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\SessnLb.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\SwTskDlg.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\TaskList.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Time.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\TimeEb.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\TskCombo.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\TskLstEn.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wclrsc.h
# End Source File
# End Group
# Begin Group "Resouce Files"

# PROP Default_Filter "*.rc;*.ico;*.bmp;*.rcv"
# Begin Source File

SOURCE=..\Source\App32.rc
# End Source File
# Begin Source File

SOURCE=..\Source\App32.rcv
# End Source File
# Begin Source File

SOURCE=..\Source\Appicon.ico
# End Source File
# Begin Source File

SOURCE=..\Source\ToolBar.bmp
# End Source File
# End Group
# Begin Group "Linker Files"

# PROP Default_Filter "*.obj;*.lib"
# Begin Source File

SOURCE=..\..\Wcl\Lib32\wcl.lib
# End Source File
# Begin Source File

SOURCE=..\..\Wcl\Lib32\Winmain.obj
# End Source File
# End Group
# End Target
# End Project
