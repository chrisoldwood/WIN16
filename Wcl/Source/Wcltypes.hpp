/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		WCLTYPES.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Common data types, defines and macros.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef WCLTYPES_HPP
#define WCLTYPES_HPP

/******************************************************************************
**
** Standard types.
**
*******************************************************************************
*/

typedef unsigned char	uchar;
typedef unsigned short	ushort;
typedef unsigned int	uint;
typedef unsigned long	ulong;
#if _MSC_VER < 1100
typedef signed   int	bool;
#endif

/******************************************************************************
**
** Size specific types.
**
*******************************************************************************
*/

typedef signed char		int8;
typedef signed short	int16;
typedef signed long		int32;

typedef unsigned char	uint8;
typedef unsigned short	uint16;
typedef unsigned long	uint32;

/******************************************************************************
**
** Windows specific defines.
**
*******************************************************************************
*/

#ifdef WIN16
#define EXPORT		__export
#else
#define EXPORT		__declspec(dllexport)
#endif

#define WINDOWPROC	EXPORT CALLBACK
#define DIALOGPROC	EXPORT CALLBACK

#endif //WCLTYPES_HPP
