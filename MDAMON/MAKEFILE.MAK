# 
# Top level makefile. 
# This makes the DLL, APP & Helptext.
# (C) Chris Wood 1994.
# cwood@gst-soft.demon.co.uk
#

# The targets.
.top: monocode.dll monitor.exe monocode.hlp

# Run through the directories calling smake.
# First pass compiles, second pass cleans up.
MAKE=smake

monocode.dll:
     cd dll
     $(MAKE) monocode.dll
     $(MAKE) clean
     echo Monochrome code DLL compiled.
     echo.
     cd ..

monitor.exe:
     cd app
     $(MAKE) monitor.exe
     $(MAKE) clean
     echo Test application compiled.
     echo.
     cd ..

monocode.hlp:
     cd help
     $(MAKE) monocode.hlp
     $(MAKE) clean
     echo Monocode API Helptext compiled.
     echo.
     cd ..
