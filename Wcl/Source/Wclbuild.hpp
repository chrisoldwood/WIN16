/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WCLBUILD.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Build dependant macros.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef WCLBUILD_HPP
#define WCLBUILD_HPP

#ifdef EXPORTWCL
//
// Building the library as a DLL.
//
#define WCLCLASS	class EXPORT
#define WCLSTRUCT	struct EXPORT
#define WCLAPI		EXPORT

#else

#ifdef WCLDLL
//
// Building an application component that
// will be linked to the DLL version.
//
#define WCLCLASS	class EXPORT
#define WCLSTRUCT	struct EXPORT
#define WCLAPI		EXPORT

#else
//
// Building the library as a LIB.
//
#define WCLCLASS	class
#define WCLSTRUCT	struct
#define WCLAPI

#endif //WCLDLL
#endif //EXPORTWCL

#endif //WCLBUILD_HPP
