/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		APPBUILD.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	Build dependant macros.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef APPBUILD_HPP
#define APPBUILD_HPP

#ifdef WCLDLL
//
// Using the DLL version of WCL.
//
#define APPCLASS	class EXPORT
#define APPSTRUCT	struct EXPORT
#define APPAPI		EXPORT

#else
//
// Using the LIB version of WCL.
//
#define APPCLASS	class
#define APPSTRUCT	struct
#define APPAPI

#endif //WCLDLL

#endif //APPBUILD_HPP
