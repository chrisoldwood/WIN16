/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MEMMGR.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Memory management functions.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MEMMGR_HPP
#define MEMMGR_HPP

// Check memory model.
#if defined(M_I86MM) || defined(M_I86LM) || defined(WIN32)
#else
#error Only medium, large and Win32 memory models are supported.
#endif

#ifdef WIN16

/******************************************************************************
**
** Prototypes for the Local memory allocation functions.
** NB: You should use the build-dependant versions defined at the bottom.
**
*******************************************************************************
*/
void* WCLAPI NearMallocRel(uint iSize);
void  WCLAPI NearFreeRel(void* pMem);
void* WCLAPI NearMallocDbg(uint iSize, const char* pszModule, uint iLine);
void  WCLAPI NearFreeDbg(void* pMem);
void  WCLAPI NearMemoryUsage(void);

/******************************************************************************
**
** Prototypes for the Heap memory allocation functions.
** NB: You should use the build-dependant versions defined at the bottom.
**
*******************************************************************************
*/
void FAR* WCLAPI HeapMallocRel(uint iSize);
void      WCLAPI HeapFreeRel(void FAR* lpMem);
void FAR* WCLAPI HeapMallocDbg(uint iSize, const char* pszModule, uint iLine);
void      WCLAPI HeapFreeDbg(void FAR* lpMem);
void      WCLAPI HeapMemoryUsage(void);
void      WCLAPI HeapManagerStats(void);

#endif

/******************************************************************************
**
** Prototypes for the Global memory allocation functions.
** NB: You should use the build-dependant versions defined at the bottom.
**
*******************************************************************************
*/
void FAR* WCLAPI FarMallocRel(DWORD dwSize);
void      WCLAPI FarFreeRel(void FAR* lpMem);
void FAR* WCLAPI FarMallocDbg(DWORD dwSize, const char* pszModule, uint iLine);
void      WCLAPI FarFreeDbg(void FAR* lpMem);
void      WCLAPI FarMemoryUsage(void);

/******************************************************************************
**
** This is the debug version of the new operator. It takes the file and line
** number of where the allocation was made so that memory allocations can be
** tracked.
**
** For medium model build we use the Local memory routines and for large model
** builds we use our own heap management functions.
**
*******************************************************************************
*/

inline void* operator new (size_t iSize, const char* pszModule, uint iLine)
{
#if defined(M_I86MM)
	return NearMallocDbg(iSize, pszModule, iLine);
#elif defined(M_I86LM)
	return HeapMallocDbg(iSize, pszModule, iLine);
#else
	return FarMallocDbg(iSize, pszModule, iLine);
#endif
}

/******************************************************************************
**
** This is the release version of the new operator. It behaves as normal.
**
*******************************************************************************
*/

inline void* operator new (size_t iSize)
{
#if defined(M_I86MM)
	return NearMallocRel(iSize);
#elif defined(M_I86LM)
	return HeapMallocRel(iSize);
#else
	return FarMallocRel(iSize);
#endif
}

/******************************************************************************
**
** The delete operator. This depends on the build type.
**
*******************************************************************************
*/

inline void operator delete (void* pMem)
{
#ifdef _DEBUG
	#if defined(M_I86MM)
		NearFreeDbg(pMem);
	#elif defined(M_I86LM)
		HeapFreeDbg(pMem);
	#else
		FarFreeDbg(pMem);
	#endif
#else //NDEBUG
	#if defined(M_I86MM)
		NearFreeRel(pMem);
	#elif defined(M_I86LM)
		HeapFreeRel(pMem);
	#else
		FarFreeRel(pMem);
	#endif
#endif //_DEBUG
}


// Check for debug build
#ifdef _DEBUG
//
// Use debug version of 'new' operator
//
// WARNING: If you overload any new operators in any class you will get compiler
// errors becasue 'new' will be pre-processed by this.
//
#define new	new(__FILE__, __LINE__)

#ifdef WIN16

//
// Use debug versions of memory functions
//
#define	NearMalloc(x)	NearMallocDbg(x, __FILE__, __LINE__)
#define NearFree(x)		NearFreeDbg(x)
#define NearMemStats()	NearMemoryUsage()

#define	HeapMalloc(x)	HeapMallocDbg(x, __FILE__, __LINE__)
#define HeapFree(x)		HeapFreeDbg(x)
#define HeapMemStats()	HeapMemoryUsage()
#define HeapMgrStats()	HeapManagerStats()

#endif

#define	FarMalloc(x)	FarMallocDbg(x, __FILE__, __LINE__)
#define FarFree(x)		FarFreeDbg(x)
#define FarMemStats()	FarMemoryUsage()


#else //NDEBUG
//
// Use release versions of memory functions
//

#ifdef WIN16

#define	NearMalloc(x)	NearMallocRel(x)
#define NearFree(x)		NearFreeRel(x)
#define NearMemStats()

#define	HeapMalloc(x)	HeapMallocRel(x)
#define HeapFree(x)		HeapFreeRel(x)
#define HeapMemStats()
#define HeapMgrStats()

#endif

#define	FarMalloc(x)	FarMallocRel(x)
#define FarFree(x)		FarFreeRel(x)
#define FarMemStats()

#endif //_DEBUG


#endif //MEMMGR_HPP
