/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		HEAPMEM.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Heap Memory management functions.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "heapmgr.hpp"
#include "memlist.hpp"

/******************************************************************************
** This object holds a list of allocations made from our own heap.
*/

static CMemList HeapMemList;

/******************************************************************************
** Function:	HeapMallocRel()
**
** Description:	Allocate a block of memory from our own Heap and return a
**				far pointer to it. This is the release version.
**
** Parameters:	iSize			Size of request in bytes.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* WCLAPI HeapMallocRel(uint iSize)
{
	return HeapManager.Malloc(iSize);
}

/******************************************************************************
** Function:	HeapFreeRel()
**
** Description:	Free a block of memory allocated from our own Heap. This is
**				the release version.
**
** Parameters:	lpMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI HeapFreeRel(void FAR* lpMem)
{
	HeapManager.Free(lpMem);
}

/******************************************************************************
** Function:	HeapMallocDbg()
**
** Description:	Allocate a block of memory from our own Heap and return a
**				far pointer to it. This debug versions allocates additonal
**				space for a block header which stores info about where it was
**				allocated and adds a marker before and after the block to check
**				for writing under and overruns. It also fills the entire block
**				with a special value to show up uninitialsed data.
**
** Parameters:	iSize			Size of request in bytes.
**				pszModule		The file this allocation was made in.
**				iLine			The module line number.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* WCLAPI HeapMallocDbg(uint iSize, const char* pszModule, uint iLine)
{
	void FAR*	lpMem;
	uint		iRealSize;
	
	ASSERT(iSize);
	ASSERT(pszModule);
	
	// Calculate size of block including debugging info and markers.
	iRealSize = iSize + HeapMemList.DebugInfoSize();
	
	// Allocate it.
	lpMem = (void FAR*)HeapManager.Malloc(iRealSize);

	// Failed?
	if (!lpMem)
	{
		char szMsg[128];
		
		// Create message.
		wsprintf(szMsg, "Allocation Failed!\nBlock Size = %u Bytes.\n\nDebug?", iSize);
		
		// Notify user.
		if (MessageBox(NULL, szMsg, "Heap Memory", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
		
		return NULL;
	}
	
	// Add to tracking list.
	HeapMemList.Add(lpMem, iSize, pszModule, iLine);
	
	// Skip header.
	lpMem = (BYTE FAR*)lpMem + HeapMemList.DebugInfoSize() - 1;
	
	return lpMem;
}

/******************************************************************************
** Function:	HeapFreeDbg()
**
** Description:	Free a block of memory allocated from our own Heap. In this
**				version the markers at the start and end of the block are
**				checked to make sure no under or overrun has occurred. If not
**				the block is removed from the list and filled with a value to
**				destroy any previous data, which shows up usage after the block
**				has been free'd.
**
** Parameters:	lpMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI HeapFreeDbg(void FAR* lpMem)
{
	ASSERT(lpMem);

	// Get pointer to the header.
	lpMem = (BYTE FAR*) lpMem - HeapMemList.DebugInfoSize() + 1;

	// Valid block?
	if (!HeapMemList.Delete(lpMem))
		return;
	
	// Finally free the block.
	HeapManager.Free(lpMem);
}

/******************************************************************************
** Function:	HeapMemoryUsage()
**
** Description:	Displays info about the max bytes ever in use, and walk the
**				list of unfree'd blocks, reporting where they were alocated.
**
** Parameters:	Nothing.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI HeapMemoryUsage(void)
{
	// Dump out stats.
	TRACE("\nHeap Memory Usage:-\n");
	HeapMemList.Status();
}

/******************************************************************************
** Function:	HeapManagerStats()
**
** Description:	Displays info about the current state of the heap manager.
**
** Parameters:	Nothing.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI HeapManagerStats(void)
{
	HeapManager.Status();
}
