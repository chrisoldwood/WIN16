# Microsoft Developer Studio Project File - Name="wcl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=wcl - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wcl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wcl.mak" CFG="wcl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wcl - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "wcl - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe

!IF  "$(CFG)" == "wcl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W4 /WX /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX"WCL.HPP" /FD /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "wcl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W4 /WX /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX"WCL.HPP" /FD /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "wcl - Win32 Release"
# Name "wcl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "*.c;*.cpp"
# Begin Source File

SOURCE=..\Source\Accel.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Assert.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Bitmap.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\BmpBtn.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Button.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\CheckBox.CPP
# End Source File
# Begin Source File

SOURCE=..\Source\Combobox.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Ctl3d.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Ctrlwnd.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\DC.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Dialog.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Dlgframe.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Editbox.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\File.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\FrameWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Globlmem.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Hashtble.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Heapmem.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Heapmgr.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\HintBar.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Inifile.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Label.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Libmain.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Listbox.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Localmem.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\MemDC.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Memlist.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Menu.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Module.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\MsgWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Path.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\PopupWnd.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintrDC.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\RadioBtn.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\ScreenDC.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\StatBar.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\String.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Task.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Toolbar.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Winmain.cpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wnd.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h;*.hpp"
# Begin Source File

SOURCE=..\Source\Accel.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Assert.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Bitmap.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\BmpBtn.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Button.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\CheckBox.HPP
# End Source File
# Begin Source File

SOURCE=..\Source\Combobox.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Ctl3d.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Ctrlwnd.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\DC.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Dialog.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Dlgframe.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Editbox.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\File.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\FrameWnd.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Hashtble.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Heapmgr.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Helpfile.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\HintBar.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Inifile.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Label.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Listbox.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\MemDC.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Memlist.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Memmgr.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Menu.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Module.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\MsgWnd.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Path.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Point.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\PopupWnd.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Pragmas.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\PrintrDC.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\RadioBtn.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Rect.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\ScreenDC.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Size.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\StatBar.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\String.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Task.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Toolbar.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wcl.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wclbuild.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wclrsc.h
# End Source File
# Begin Source File

SOURCE=..\Source\Wcltypes.hpp
# End Source File
# Begin Source File

SOURCE=..\Source\Wnd.hpp
# End Source File
# End Group
# End Target
# End Project
