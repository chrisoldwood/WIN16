/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRAGMAS.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Disable annoying Level 4 warnings.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef PRAGMAS_HPP
#define PRAGMAS_HPP

// Creating/using precompiled header.
#pragma warning ( disable : 4699 )

// Unreferenced formal parameter.
#pragma warning ( disable : 4100 )

// Unreferenced local function has been removed.
#pragma warning ( disable : 4505 )

// Statement has no effect
#pragma warning ( disable : 4705 )

// Inline function not expanded.
#pragma warning ( disable : 4710 )

// Non-constant aggregate initializer.
#pragma warning ( disable : 4204 )

// Conditional expression is constant.
// Caused by ASSERT(FALSE).
#pragma warning ( disable : 4127 )


#ifdef WIN32

// Nameless struct/union.
#pragma warning ( disable : 4201 )

// Unreferenced inline function removed.
#pragma warning ( disable : 4514 )

// Forcing value to bool true or false.
#pragma warning ( disable : 4800 )

#endif


#ifdef _DEBUG

// Unreachable code, caused by ASSERT macros
// when compiling a release build with asserts.
#pragma warning ( disable : 4702 )

#endif

#endif //PRAGMAS_HPP
