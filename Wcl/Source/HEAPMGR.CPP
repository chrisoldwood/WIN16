/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HEAPMGR.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CHeapMgr class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "heapmgr.hpp"

#ifdef WIN16

// The one and only heap manager.
CHeapMgr HeapManager;

// Size of each heap.
#define HEAP_SIZE	4096L

// Macro to get the Data Segment.
#define GET_DS(Seg)	__asm { mov Seg,ds }

// Macro to set the Data Segment.
#define SET_DS(Seg)	__asm { mov ds,Seg }

/******************************************************************************
** Method:		Default Constructor
**
** Description:	Initialise the members.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CHeapMgr::CHeapMgr(void)
{
	m_lpListHead = NULL;
}

/******************************************************************************
** Method:		Malloc()
**
** Description:	Allocate a block of memory of the size specified from one of
**				the heaps. If required, allocate a new heap first and add it
**				to the list. Only the heap at the head of the list is checked
**				for free space as it's the most recently allocated.
**
** Parameters:	iSize			Size of request in bytes.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* CHeapMgr::Malloc(uint iSize)
{
	// Find a heap to satisfy the request.
	HeapInfo FAR* lpFreeHeap = FindFreeHeap(iSize);
	
	if (!lpFreeHeap)
	{
		// Allocate a new heap.
		void FAR* lpNewHeap = GlobalAllocPtr(GHND, HEAP_SIZE);
		if (!lpNewHeap)
			return NULL;
	    
		// Initialise heap.
		WORD wSegment = GetFarPtrSegment(lpNewHeap);
		::LocalInit(wSegment, 0, HEAP_SIZE-1);
		::UnlockSegment(wSegment);
		
		// Allocate a heap info block.
		HeapInfo FAR* lpInfo = (HeapInfo FAR*) NearMalloc(sizeof(HeapInfo));
		if (!lpInfo)
		{
			// Allocation failed.
			GlobalFreePtr(lpFreeHeap);
			return NULL;
		}
		
	    // Setup heap info.
		lpInfo->lpNext       = m_lpListHead;
		lpInfo->lpHeapMem    = lpNewHeap;
		lpInfo->iAllocations = 0;
		
		// Add to the head of the list.
		m_lpListHead = lpInfo;
	}
	
	// Allocate from the current heap.
	void FAR* lpMem = AllocateFromHeap(m_lpListHead, iSize);
	if (!lpMem)
		return NULL;
	
	// Update count for the heap.
	m_lpListHead->iAllocations++;
	
	return lpMem;
}

/******************************************************************************
** Method:		Free()
**
** Description:	Free up the specified block of memory. If the heap it was sub-
**				allocated from is now unused, free up the heap aswell.
**
** Parameters:	lpMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHeapMgr::Free(void FAR* lpMem)
{
	// Get the memory segment.
	WORD wMemSeg = GetFarPtrSegment(lpMem);
	
	// Get list head.
	HeapInfo FAR* lpHeap = m_lpListHead;
	
	// Find the heap that the memory
	// was allocated from.
	while(lpHeap)
	{
		// Get heap segment.
		WORD wHeapSeg = GetFarPtrSegment(lpHeap->lpHeapMem);
		
		// Found it?
		if (wHeapSeg == wMemSeg)
			break;
		
		// And on...
		lpHeap = lpHeap->lpNext;
	}

	// Heap found?
	if (!lpHeap)
	{
		ASSERT(FALSE);
		return;
	}
	
	// Free memory from heap.
	ReturnToHeap(lpHeap, lpMem);

	// Update allocation count.
	lpHeap->iAllocations--;
	
	// Heap unused?
	if (lpHeap->iAllocations)
		return;
		
	// Is list head?
	if (lpHeap == m_lpListHead)
	{
		// New list head.
		m_lpListHead = lpHeap->lpNext;
	}
	else
	{
		// Get list head.
		HeapInfo FAR* lpPrev = m_lpListHead;
		
		// Find previous item.
		while (lpPrev->lpNext != lpHeap)
			lpPrev = lpPrev->lpNext;
			
		// Remove heap from list.
		lpPrev->lpNext = lpHeap->lpNext;
	}
	
	// Free heap memory.
	GlobalFreePtr(lpHeap->lpHeapMem);
	
	// Free heap info header.
	NearFree((void NEAR*)(WORD)(DWORD)lpHeap);
}

/******************************************************************************
** Method:		FindFreeHeap()
**
** Description:	Find a heap that can satisfy the request. At the moment we just
**				check the current heap. This algorithm can be improved later to
**				better utilise the heaps we already have allocated.
**
** Parameters:	iSize		Size of request in bytes.
**
** Returns:		A heap		If one can satisfy the request.
**				NULL		If not.
**
*******************************************************************************
*/

HeapInfo FAR* CHeapMgr::FindFreeHeap(uint iSize)
{
	// Any heaps yet?
	if (!m_lpListHead)
		return NULL;
	
	// Check current.
	if (GetHeapFreeSpace(m_lpListHead) >= iSize)
		return m_lpListHead;
	
	// None free.
	return NULL;
}

// Turn optimisations off for the next few
// methods because they use some assembler.
#pragma optimize("", off)

/******************************************************************************
** Method:		GetHeapFreeSpace()
**
** Description:	Find out how much free space there is in the specified heap.
**
** Parameters:	lpHeap		The heap.
**
** Returns:		Free space in bytes.
**
*******************************************************************************
*/

uint CHeapMgr::GetHeapFreeSpace(HeapInfo FAR* lpHeap)
{
	ASSERT(lpHeap);
	
	// Get heap segment 
	WORD wOurDS;
	WORD wHeapDS = GetFarPtrSegment(lpHeap->lpHeapMem);

	// Switch the data segments.
	GET_DS(wOurDS);
	SET_DS(wHeapDS);
		
	// Get the free space.
	uint iFreeSpace = LocalCompact(0);
	
	// Restore data segment.
	SET_DS(wOurDS);
	
	return iFreeSpace;
}

/******************************************************************************
** Method:		AllocateFromHeap()
**
** Description:	Allocate a block of memory from the specified heap.
**
** Parameters:	lpHeap			The heap.
**				iSize			Size of request in bytes.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* CHeapMgr::AllocateFromHeap(HeapInfo FAR* lpHeap, uint iSize)
{
	ASSERT(lpHeap);
	
	// Get heap segment 
	WORD wOurDS;
	WORD wHeapDS = GetFarPtrSegment(lpHeap->lpHeapMem);

	// Switch the data segments.
	GET_DS(wOurDS);
	SET_DS(wHeapDS);
		
	// Allocate the block.
	WORD wOffset = (WORD) LocalAlloc((LPTR | LMEM_NOCOMPACT), iSize);
	
	// Restore data segment.
	SET_DS(wOurDS);
	
	// Convert to far pointer.
	return MakeFarPtr(wHeapDS, wOffset);
}

/******************************************************************************
** Method:		ReturnToHeap()
**
** Description:	Return a block of memory to the specified heap.
**
** Parameters:	lpHeap		The heap.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHeapMgr::ReturnToHeap(HeapInfo FAR* lpHeap, void FAR* lpMem)
{
	ASSERT(lpHeap);
	
	// Convert to near pointer.
	WORD wOffset = GetFarPtrOffset(lpMem);
	
	// Get heap segment 
	WORD wOurDS;
	WORD wHeapDS = GetFarPtrSegment(lpHeap->lpHeapMem);

	// Switch the data segments.
	GET_DS(wOurDS);
	SET_DS(wHeapDS);
		
	// Free the block.
	LocalFree((HLOCAL) wOffset);
	
	// Restore data segment.
	SET_DS(wOurDS);
}

// Turn optimisations back on.
#pragma optimize("", off)

/******************************************************************************
** Method:		Status()
**
** Description:	Show the status for each heap allocated.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CHeapMgr::Status(void)
{
	// Heaps in use?
	if (m_lpListHead)
	{
		TRACE("\nHeap manager status:\n");
		
		// Get list head.
		HeapInfo FAR* lpHeap = m_lpListHead;
	
		// Walk the list.
		while(lpHeap)
		{
			// Get the amount of free space.
			uint iFreeSpace = GetHeapFreeSpace(lpHeap);
			
			// Show location.
			TRACE3("Address: %Fp  Allocations: %d  FreeSpace: %d\n", 
					lpHeap->lpHeapMem, lpHeap->iAllocations, iFreeSpace);
				
			// And on...
			lpHeap = lpHeap->lpNext;
		}
	}
}

#endif
