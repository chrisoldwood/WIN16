/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HEAPMGR.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHeapMgr class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef HEAPMGR_HPP
#define HEAPMGR_HPP

/******************************************************************************
** 
** This structure supplies information about a heap. The heap manager keeps a
** list of these structures.
**
*******************************************************************************
*/

typedef struct tagHeapInfo
{
	struct tagHeapInfo FAR*	lpNext;		// Next heap in list.
	void FAR*	lpHeapMem;				// Pointer to the heap.
	uint		iAllocations;			// Blocks allocated from it.
} HeapInfo;

/******************************************************************************
** 
** This class is used to manage a series of sub-heaps allocated from the Global
** Heap. This allows us to allocate lots of small blocks of global memory,
** without using up too many selectors.
**
** It works by allocating large blocks of global memory, and then using the
** LocalAlloc and LocalFree functions to manage a heap within each block.
**
*******************************************************************************
*/

WCLCLASS CHeapMgr
{
public:
	//
	// Constructors/Destructor.
	//
	CHeapMgr(void);
    
    //
    // Memory allocation methods.
    //
    void FAR* Malloc(uint iSize);
	void Free(void FAR* lpMem);
    
    //
    // Resource checking.
    //
	void Status(void);
    
protected:
	//
	// Members.
	//
	HeapInfo FAR*	m_lpListHead;		// List of allocated heaps.
	
	//
	// Internal methods.
	//
	WORD GetFarPtrSegment(void FAR* Ptr);
	WORD GetFarPtrOffset(void FAR* Ptr);
	void FAR* MakeFarPtr(WORD Segment, WORD Offset);
	
	HeapInfo FAR* FindFreeHeap(uint iSize);
	uint GetHeapFreeSpace(HeapInfo FAR* lpHeap);
	void FAR* AllocateFromHeap(HeapInfo FAR* lpHeap, uint iSize);
	void ReturnToHeap(HeapInfo FAR* lpHeap, void FAR* lpMem);
};

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

extern CHeapMgr HeapManager;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline WORD CHeapMgr::GetFarPtrSegment(void FAR* Ptr)
{
	return (WORD)(((DWORD)Ptr) >> 16);
}

inline WORD CHeapMgr::GetFarPtrOffset(void FAR* Ptr)
{
	return (WORD)(DWORD)Ptr;
}

inline void FAR* CHeapMgr::MakeFarPtr(WORD Segment, WORD Offset)
{
	return (void FAR*)((((DWORD)Segment) << 16) | ((DWORD)Offset));
}

#endif //HEAPMGR_HPP
