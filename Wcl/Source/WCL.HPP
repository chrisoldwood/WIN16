/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WCL.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Wrapper to include all the core library headers.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef WCL_HPP
#define WCL_HPP

/******************************************************************************
**
** Standard headers.
**
*******************************************************************************
*/

#define STRICT

#include "pragmas.hpp"
#include <windows.h>
#include <windowsx.h>
#include <stddef.h>
#include <string.h>

/******************************************************************************
**
** Platform specific definitions.
**
*******************************************************************************
*/

#ifdef WIN32
//
// Win32 specific settings.
//

// Obsolete functions defined as macros.
#undef Yield

#else
//
// Win16 specific settings.
//

// For Win16 specific code.
#define WIN16

#endif


/******************************************************************************
**
** Library specific headers.
**
*******************************************************************************
*/

#include "wcltypes.hpp"
#include "wclbuild.hpp"
#include "assert.hpp"
#include "memmgr.hpp"
#include "wclrsc.h"
#include "hashtble.hpp"
#include "list.hpp"
#include "listenum.hpp"

#include "point.hpp"
#include "size.hpp"
#include "rect.hpp"
#include "string.hpp"
#include "path.hpp"

#include "menu.hpp"
#include "accel.hpp"
#include "bitmap.hpp"
#include "module.hpp"
#include "dc.hpp"
#include "screendc.hpp"
#include "printrdc.hpp"
#include "memdc.hpp"

#include "wnd.hpp"
#include "msgwnd.hpp"
#include "popupwnd.hpp"
#include "ctrlwnd.hpp"
#include "label.hpp"
#include "listbox.hpp"
#include "combobox.hpp"
#include "editbox.hpp"
#include "checkbox.hpp"
#include "radiobtn.hpp"
#include "button.hpp"
#include "bmpbtn.hpp"
#include "dialog.hpp"
#include "hintbar.hpp"
#include "statbar.hpp"
#include "toolbar.hpp"
#include "framewnd.hpp"
#include "dlgframe.hpp"
#include "view.hpp"
#include "gfxview.hpp"
#include "dlgview.hpp"
#include "sdiframe.hpp"
#include "tabpage.hpp"
#include "tabctrl.hpp"

#include "helpfile.hpp"
#include "inifile.hpp"
#include "ctl3d.hpp"
#include "task.hpp"
#include "file.hpp"

#endif //WCL_HPP
