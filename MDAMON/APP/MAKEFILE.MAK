# 
# Makefile for the test application.
# (C) Chris Wood 1994.
# cwood@gst-soft.demon.co.uk
#

# The application target.
top: monitor.exe 

# The object files.
MONFILES=monitor.obj

# File dependencies.
$(MONFILES): monocode.h makefile.mak

# Libraries to link with.
LIBS=mlibcew commdlg shell libw toolhelp ..\dll\monocode

# Resource files.
RSC=monitor.rc monitor.ico

# Compilation & linking defs. Debug and non-debug.
CC=cl
CCOPT=-c -AM -Gw -Od -nologo -W4 -Zipe
#CCOPT=-c -AM -Gsw -Oceglont -nologo
DEBUG=/CO
#DEBUG=
LINKER=optlinks
RC=rc
MAPSYM=mapsym

.INIT:
     %setenv include=m:\public\c700\include
     %setenv lib=m:\public\c700\lib

# General compilation rule.
.c.obj:
     $(CC) $(CCOPT) $($[r,$@]) -Fo$@ $< >$[f,,$@,err]

monitor.res: $(RSC)
     $(RC) -r monitor.rc

monitor.exe: $(MONFILES) monitor.res monitor.def ..\dll\monocode.lib
     $(LINKER) $(DEBUG) /nologo /align:16 /map <@<
$(MONFILES)
monitor.exe
monitor.map
$(LIBS)
monitor.def
<
     $(RC) -k monitor.res monitor.exe
     $(MAPSYM) -n monitor.map
     copy monitor.exe ..
     