/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPHDRS.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	Wrapper to include all the main application headers.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPHDRS_HPP
#define APPHDRS_HPP

/******************************************************************************
**
** System headers.
**
*******************************************************************************
*/

#include "wcl.hpp"		// Windows C++ library and core headers.

/******************************************************************************
**
** Application specific headers.
**
*******************************************************************************
*/

#include "appbuild.hpp"
#ifdef WIN16
#include "rsc16.h"
#else
#include "rsc32.h"
#endif

#include "time.hpp"
#include "timeeb.hpp"
#include "date.hpp"
#include "dateeb.hpp"
#include "datetime.hpp"
#include "session.hpp"

#include "sesslist.hpp"
#include "sessenum.hpp"
#include "sessnlb.hpp"
#include "tasklist.hpp"
#include "tsklsten.hpp"
#include "tskcombo.hpp"

#include "export.hpp"
#include "printexp.hpp"
#include "fileexp.hpp"

#include "appdlg.hpp"
#include "appwnd.hpp"
#include "app.hpp"

#endif //APPHDRS_HPP
