/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MEMLIST.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CMemList memory tracking class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef MEMLIST_HPP
#define MEMLIST_HPP

#define NEW_MEM_MARKER	0xCC	// New blocks filled with this after allocation.
#define OLD_MEM_MARKER	0xCD	// Old blocks filled with this before freeing.

// For traversing >64K blocks.
#ifdef WIN16
typedef unsigned char _huge*	HPBYTE;
#else
typedef unsigned char*			HPBYTE;
#endif

/******************************************************************************
**
** This is the header that is placed at the start of every memory block. It
** contains the debug information about the block. The class below keeps a list
** of these.
**
*******************************************************************************
*/

typedef struct tagMemBlockInfo
{
	struct tagMemBlockInfo FAR*	lpNext;		// Pointer to next block.
	DWORD		dwSize;						// Size of this block.
	const char*	pszModule;					// Module allocated in.
	uint		iLine;						// Line number where allocated.
	uint		iAllocNum;					// Allocation number.
} MemBlockInfo;

/******************************************************************************
** 
** This is the class used to track memory allocations from the Local, Global
** and custom heaps. This class is not included as part of the standard headers
** because it is only used in 3 modules and is private to the library.
**
*******************************************************************************
*/

WCLCLASS CMemList
{
public:
	//
	// Constructors/Destructor.
	//
	CMemList(void);

	//
	// List management.
	//
	uint DebugInfoSize(void);
	void Add(void FAR* lpBlock, DWORD dwSize, const char* pszModule, uint iLine);
	BOOL Delete(void FAR* lpBlock);

	//
	// Resource checking.
	//
	void Status(void);
	
protected:
	//
	// Members.
	//
	MemBlockInfo FAR*	m_lpListHead;		// Head of blocks list.
	DWORD 				m_dwCurrAllocated;	// Total bytes allocated at present.
	DWORD 				m_dwMaxAllocated;	// Max bytes allocated at any time.
	uint				m_iNumAllocs;		// Number of allocations.

	//
	// Internal methods.
	//
	void FillBlock(HPBYTE hpBlock, DWORD dwSize, BYTE byMarker);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //MEMLIST_HPP
