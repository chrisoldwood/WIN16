# Microsoft Visual C++ generated build script - Do not modify

PROJ = WCL
DEBUG = 0
PROGTYPE = 4
CALLER = 
ARGS = 
DLLS = 
D_RCDEFINES = -d_DEBUG
R_RCDEFINES = -dNDEBUG
ORIGIN = MSVC
ORIGIN_VER = 1.00
PROJPATH = D:\DEV\WCL\LIB16M\
USEMFC = 0
CC = cl
CPP = cl
CXX = cl
CCREATEPCHFLAG = 
CPPCREATEPCHFLAG = 
CUSEPCHFLAG = 
CPPUSEPCHFLAG = 
FIRSTC =             
FIRSTCPP = ACCEL.CPP   
RC = rc
CFLAGS_D_LIB = /nologo /G2 /W4 /WX /Z7 /AM /YX"WCL.HPP" /Od /D "_DEBUG" /FR /Zn /GA /Fp"WCL.PCH"
CFLAGS_R_LIB = /nologo /Gs /G3 /W4 /WX /AM /YX"WCL.HPP" /O2 /Ox /Ob1 /D "NDEBUG" /GA /Fp"WCL.PCH"
RCFLAGS = /nologo
RESFLAGS = /nologo
RUNFLAGS = 
OBJS_EXT = 
LIBS_EXT = 
!if "$(DEBUG)" == "1"
CFLAGS = $(CFLAGS_D_LIB)
LFLAGS = 
LIBS = 
MAPFILE = nul
RCDEFINES = $(D_RCDEFINES)
!else
CFLAGS = $(CFLAGS_R_LIB)
LFLAGS = 
LIBS = 
MAPFILE = nul
RCDEFINES = $(R_RCDEFINES)
!endif
!if [if exist MSVC.BND del MSVC.BND]
!endif
SBRS = ACCEL.SBR \
		ASSERT.SBR \
		BITMAP.SBR \
		BMPBTN.SBR \
		BUTTON.SBR \
		CHECKBOX.SBR \
		COMBOBOX.SBR \
		CTL3D.SBR \
		CTRLWND.SBR \
		DC.SBR \
		DIALOG.SBR \
		DLGFRAME.SBR \
		DLGVIEW.SBR \
		EDITBOX.SBR \
		FILE.SBR \
		FRAMEWND.SBR \
		GFXVIEW.SBR \
		GLOBLMEM.SBR \
		HASHTBLE.SBR \
		HEAPMEM.SBR \
		HEAPMGR.SBR \
		HINTBAR.SBR \
		INIFILE.SBR \
		LABEL.SBR \
		LIBMAIN.SBR \
		LIST.SBR \
		LISTBOX.SBR \
		LISTENUM.SBR \
		LOCALMEM.SBR \
		MEMDC.SBR \
		MEMLIST.SBR \
		MENU.SBR \
		MODULE.SBR \
		MSGWND.SBR \
		PATH.SBR \
		POPUPWND.SBR \
		PRINTRDC.SBR \
		RADIOBTN.SBR \
		SCREENDC.SBR \
		SDIFRAME.SBR \
		STATBAR.SBR \
		STRING.SBR \
		TABCTRL.SBR \
		TABPAGE.SBR \
		TASK.SBR \
		TOOLBAR.SBR \
		VIEW.SBR \
		WINMAIN.SBR \
		WND.SBR


ACCEL_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


ASSERT_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


BITMAP_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


BMPBTN_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


BUTTON_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


CHECKBOX_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


COMBOBOX_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


CTL3D_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


CTRLWND_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


DC_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


DIALOG_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


DLGFRAME_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


DLGVIEW_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


EDITBOX_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


FILE_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


FRAMEWND_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


GFXVIEW_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


GLOBLMEM_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp \
	d:\dev\wcl\source\memlist.hpp


HASHTBLE_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


HEAPMEM_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp \
	d:\dev\wcl\source\heapmgr.hpp \
	d:\dev\wcl\source\memlist.hpp


HEAPMGR_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp \
	d:\dev\wcl\source\heapmgr.hpp


HINTBAR_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


INIFILE_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LABEL_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LIBMAIN_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LIST_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LISTBOX_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LISTENUM_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


LOCALMEM_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp \
	d:\dev\wcl\source\memlist.hpp


MEMDC_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


MEMLIST_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp \
	d:\dev\wcl\source\memlist.hpp


MENU_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


MODULE_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


MSGWND_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


PATH_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


POPUPWND_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


PRINTRDC_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


RADIOBTN_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


SCREENDC_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


SDIFRAME_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


STATBAR_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


STRING_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


TABCTRL_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


TABPAGE_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


TASK_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


TOOLBAR_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


VIEW_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


WINMAIN_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


WND_DEP = d:\dev\wcl\source\wcl.hpp \
	d:\dev\wcl\source\pragmas.hpp \
	d:\dev\wcl\source\wcltypes.hpp \
	d:\dev\wcl\source\wclbuild.hpp \
	d:\dev\wcl\source\assert.hpp \
	d:\dev\wcl\source\memmgr.hpp \
	d:\dev\wcl\source\wclrsc.h \
	d:\dev\wcl\source\hashtble.hpp \
	d:\dev\wcl\source\list.hpp \
	d:\dev\wcl\source\listenum.hpp \
	d:\dev\wcl\source\point.hpp \
	d:\dev\wcl\source\size.hpp \
	d:\dev\wcl\source\rect.hpp \
	d:\dev\wcl\source\string.hpp \
	d:\dev\wcl\source\path.hpp \
	d:\dev\wcl\source\menu.hpp \
	d:\dev\wcl\source\accel.hpp \
	d:\dev\wcl\source\bitmap.hpp \
	d:\dev\wcl\source\module.hpp \
	d:\dev\wcl\source\dc.hpp \
	d:\dev\wcl\source\screendc.hpp \
	d:\dev\wcl\source\printrdc.hpp \
	d:\dev\wcl\source\memdc.hpp \
	d:\dev\wcl\source\wnd.hpp \
	d:\dev\wcl\source\msgwnd.hpp \
	d:\dev\wcl\source\popupwnd.hpp \
	d:\dev\wcl\source\ctrlwnd.hpp \
	d:\dev\wcl\source\label.hpp \
	d:\dev\wcl\source\listbox.hpp \
	d:\dev\wcl\source\combobox.hpp \
	d:\dev\wcl\source\editbox.hpp \
	d:\dev\wcl\source\checkbox.hpp \
	d:\dev\wcl\source\radiobtn.hpp \
	d:\dev\wcl\source\button.hpp \
	d:\dev\wcl\source\bmpbtn.hpp \
	d:\dev\wcl\source\dialog.hpp \
	d:\dev\wcl\source\hintbar.hpp \
	d:\dev\wcl\source\statbar.hpp \
	d:\dev\wcl\source\toolbar.hpp \
	d:\dev\wcl\source\framewnd.hpp \
	d:\dev\wcl\source\dlgframe.hpp \
	d:\dev\wcl\source\view.hpp \
	d:\dev\wcl\source\gfxview.hpp \
	d:\dev\wcl\source\dlgview.hpp \
	d:\dev\wcl\source\sdiframe.hpp \
	d:\dev\wcl\source\tabpage.hpp \
	d:\dev\wcl\source\tabctrl.hpp \
	d:\dev\wcl\source\helpfile.hpp \
	d:\dev\wcl\source\inifile.hpp \
	d:\dev\wcl\source\ctl3d.hpp \
	d:\dev\wcl\source\task.hpp \
	d:\dev\wcl\source\file.hpp


all:	$(PROJ).LIB

ACCEL.OBJ:	..\SOURCE\ACCEL.CPP $(ACCEL_DEP)
	$(CPP) $(CFLAGS) $(CPPCREATEPCHFLAG) /c ..\SOURCE\ACCEL.CPP

ASSERT.OBJ:	..\SOURCE\ASSERT.CPP $(ASSERT_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\ASSERT.CPP

BITMAP.OBJ:	..\SOURCE\BITMAP.CPP $(BITMAP_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\BITMAP.CPP

BMPBTN.OBJ:	..\SOURCE\BMPBTN.CPP $(BMPBTN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\BMPBTN.CPP

BUTTON.OBJ:	..\SOURCE\BUTTON.CPP $(BUTTON_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\BUTTON.CPP

CHECKBOX.OBJ:	..\SOURCE\CHECKBOX.CPP $(CHECKBOX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\CHECKBOX.CPP

COMBOBOX.OBJ:	..\SOURCE\COMBOBOX.CPP $(COMBOBOX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\COMBOBOX.CPP

CTL3D.OBJ:	..\SOURCE\CTL3D.CPP $(CTL3D_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\CTL3D.CPP

CTRLWND.OBJ:	..\SOURCE\CTRLWND.CPP $(CTRLWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\CTRLWND.CPP

DC.OBJ:	..\SOURCE\DC.CPP $(DC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DC.CPP

DIALOG.OBJ:	..\SOURCE\DIALOG.CPP $(DIALOG_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DIALOG.CPP

DLGFRAME.OBJ:	..\SOURCE\DLGFRAME.CPP $(DLGFRAME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DLGFRAME.CPP

DLGVIEW.OBJ:	..\SOURCE\DLGVIEW.CPP $(DLGVIEW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\DLGVIEW.CPP

EDITBOX.OBJ:	..\SOURCE\EDITBOX.CPP $(EDITBOX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\EDITBOX.CPP

FILE.OBJ:	..\SOURCE\FILE.CPP $(FILE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\FILE.CPP

FRAMEWND.OBJ:	..\SOURCE\FRAMEWND.CPP $(FRAMEWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\FRAMEWND.CPP

GFXVIEW.OBJ:	..\SOURCE\GFXVIEW.CPP $(GFXVIEW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\GFXVIEW.CPP

GLOBLMEM.OBJ:	..\SOURCE\GLOBLMEM.CPP $(GLOBLMEM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\GLOBLMEM.CPP

HASHTBLE.OBJ:	..\SOURCE\HASHTBLE.CPP $(HASHTBLE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\HASHTBLE.CPP

HEAPMEM.OBJ:	..\SOURCE\HEAPMEM.CPP $(HEAPMEM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\HEAPMEM.CPP

HEAPMGR.OBJ:	..\SOURCE\HEAPMGR.CPP $(HEAPMGR_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\HEAPMGR.CPP

HINTBAR.OBJ:	..\SOURCE\HINTBAR.CPP $(HINTBAR_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\HINTBAR.CPP

INIFILE.OBJ:	..\SOURCE\INIFILE.CPP $(INIFILE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\INIFILE.CPP

LABEL.OBJ:	..\SOURCE\LABEL.CPP $(LABEL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LABEL.CPP

LIBMAIN.OBJ:	..\SOURCE\LIBMAIN.CPP $(LIBMAIN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LIBMAIN.CPP

LIST.OBJ:	..\SOURCE\LIST.CPP $(LIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LIST.CPP

LISTBOX.OBJ:	..\SOURCE\LISTBOX.CPP $(LISTBOX_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LISTBOX.CPP

LISTENUM.OBJ:	..\SOURCE\LISTENUM.CPP $(LISTENUM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LISTENUM.CPP

LOCALMEM.OBJ:	..\SOURCE\LOCALMEM.CPP $(LOCALMEM_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\LOCALMEM.CPP

MEMDC.OBJ:	..\SOURCE\MEMDC.CPP $(MEMDC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MEMDC.CPP

MEMLIST.OBJ:	..\SOURCE\MEMLIST.CPP $(MEMLIST_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MEMLIST.CPP

MENU.OBJ:	..\SOURCE\MENU.CPP $(MENU_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MENU.CPP

MODULE.OBJ:	..\SOURCE\MODULE.CPP $(MODULE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MODULE.CPP

MSGWND.OBJ:	..\SOURCE\MSGWND.CPP $(MSGWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\MSGWND.CPP

PATH.OBJ:	..\SOURCE\PATH.CPP $(PATH_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PATH.CPP

POPUPWND.OBJ:	..\SOURCE\POPUPWND.CPP $(POPUPWND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\POPUPWND.CPP

PRINTRDC.OBJ:	..\SOURCE\PRINTRDC.CPP $(PRINTRDC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\PRINTRDC.CPP

RADIOBTN.OBJ:	..\SOURCE\RADIOBTN.CPP $(RADIOBTN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\RADIOBTN.CPP

SCREENDC.OBJ:	..\SOURCE\SCREENDC.CPP $(SCREENDC_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SCREENDC.CPP

SDIFRAME.OBJ:	..\SOURCE\SDIFRAME.CPP $(SDIFRAME_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\SDIFRAME.CPP

STATBAR.OBJ:	..\SOURCE\STATBAR.CPP $(STATBAR_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\STATBAR.CPP

STRING.OBJ:	..\SOURCE\STRING.CPP $(STRING_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\STRING.CPP

TABCTRL.OBJ:	..\SOURCE\TABCTRL.CPP $(TABCTRL_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TABCTRL.CPP

TABPAGE.OBJ:	..\SOURCE\TABPAGE.CPP $(TABPAGE_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TABPAGE.CPP

TASK.OBJ:	..\SOURCE\TASK.CPP $(TASK_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TASK.CPP

TOOLBAR.OBJ:	..\SOURCE\TOOLBAR.CPP $(TOOLBAR_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\TOOLBAR.CPP

VIEW.OBJ:	..\SOURCE\VIEW.CPP $(VIEW_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\VIEW.CPP

WINMAIN.OBJ:	..\SOURCE\WINMAIN.CPP $(WINMAIN_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\WINMAIN.CPP

WND.OBJ:	..\SOURCE\WND.CPP $(WND_DEP)
	$(CPP) $(CFLAGS) $(CPPUSEPCHFLAG) /c ..\SOURCE\WND.CPP

$(PROJ).LIB::	ACCEL.OBJ ASSERT.OBJ BITMAP.OBJ BMPBTN.OBJ BUTTON.OBJ CHECKBOX.OBJ \
	COMBOBOX.OBJ CTL3D.OBJ CTRLWND.OBJ DC.OBJ DIALOG.OBJ DLGFRAME.OBJ DLGVIEW.OBJ EDITBOX.OBJ \
	FILE.OBJ FRAMEWND.OBJ GFXVIEW.OBJ GLOBLMEM.OBJ HASHTBLE.OBJ HEAPMEM.OBJ HEAPMGR.OBJ \
	HINTBAR.OBJ INIFILE.OBJ LABEL.OBJ LIBMAIN.OBJ LIST.OBJ LISTBOX.OBJ LISTENUM.OBJ LOCALMEM.OBJ \
	MEMDC.OBJ MEMLIST.OBJ MENU.OBJ MODULE.OBJ MSGWND.OBJ PATH.OBJ POPUPWND.OBJ PRINTRDC.OBJ \
	RADIOBTN.OBJ SCREENDC.OBJ SDIFRAME.OBJ STATBAR.OBJ STRING.OBJ TABCTRL.OBJ TABPAGE.OBJ \
	TASK.OBJ TOOLBAR.OBJ VIEW.OBJ WINMAIN.OBJ WND.OBJ $(OBJS_EXT)
	echo >NUL @<<$(PROJ).CRF
$@ /PAGESIZE:64
y
+ACCEL.OBJ &
+ASSERT.OBJ &
+BITMAP.OBJ &
+BMPBTN.OBJ &
+BUTTON.OBJ &
+CHECKBOX.OBJ &
+COMBOBOX.OBJ &
+CTL3D.OBJ &
+CTRLWND.OBJ &
+DC.OBJ &
+DIALOG.OBJ &
+DLGFRAME.OBJ &
+DLGVIEW.OBJ &
+EDITBOX.OBJ &
+FILE.OBJ &
+FRAMEWND.OBJ &
+GFXVIEW.OBJ &
+GLOBLMEM.OBJ &
+HASHTBLE.OBJ &
+HEAPMEM.OBJ &
+HEAPMGR.OBJ &
+HINTBAR.OBJ &
+INIFILE.OBJ &
+LABEL.OBJ &
+LIBMAIN.OBJ &
+LIST.OBJ &
+LISTBOX.OBJ &
+LISTENUM.OBJ &
+LOCALMEM.OBJ &
+MEMDC.OBJ &
+MEMLIST.OBJ &
+MENU.OBJ &
+MODULE.OBJ &
+MSGWND.OBJ &
+PATH.OBJ &
+POPUPWND.OBJ &
+PRINTRDC.OBJ &
+RADIOBTN.OBJ &
+SCREENDC.OBJ &
+SDIFRAME.OBJ &
+STATBAR.OBJ &
+STRING.OBJ &
+TABCTRL.OBJ &
+TABPAGE.OBJ &
+TASK.OBJ &
+TOOLBAR.OBJ &
+VIEW.OBJ &
+WINMAIN.OBJ &
+WND.OBJ &
;
<<
	if exist $@ del $@
	lib @$(PROJ).CRF

$(PROJ).BSC: $(SBRS)
	bscmake @<<
/o$@ $(SBRS)
<<
