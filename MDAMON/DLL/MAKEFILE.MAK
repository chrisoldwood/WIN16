# 
# Makefile for Monochrome adapater control code DLL. 
# (C) Chris Wood 1994.
# cwood@gst-soft.demon.co.uk
#

# The target.
.top: monocode.dll 

# Compilation & linking defs for debug & non-debug.
# Use -DPROTECT to add memory checking in case InitMono fails.
# Use -DCLIP to add clipping of output.
CC=cl
CCOPT=-c -Alnw -G2D -Od -nologo -W4 -Zipe -DISDLL -DPROTECT -DCLIP
#CCOPT=-c -Alnw -G2Ds -Oceglozt -Fa -nologo -DISDLL
DEBUG=/CO
#DEBUG=
LINKER=optlinks
MAPSYM=mapsym
RANLIB=implib

# Libraries to link with.
LIBS=libw mdllcew

# Paths for smake.
.INIT:
     %setenv include=m:\public\c700\include
     %setenv lib=m:\public\c700\lib

# General compilation rules.
monocode.obj: monocode.c makefile.mak
     $(CC) $(CCOPT) monocode.c > monocode.err

monocode.dll: monocode.obj monocode.def
     $(LINKER) $(DEBUG) /nologo /noe /packc:8192 /align:16 /map <@<
monocode.obj
monocode.dll
monocode.map
$(LIBS)
monocode.def
<
     $(RANLIB) monocode.lib monocode.dll
     $(MAPSYM) -n monocode.map
     copy monocode.dll ..

# Clean up unnecessary junk.
clean:
     del monocode.dll
     del monocode.sym
     del monocode.map
     del monocode.obj
     del monocode.err
