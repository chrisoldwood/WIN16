/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		LOCALMEM.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Local Memory management functions.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "memlist.hpp"

#ifdef WIN16

/******************************************************************************
** This object holds a list of allocations made from this heap.
*/

static CMemList LocalMemList;

/******************************************************************************
** Function:	NearMallocRel()
**
** Description:	Allocate a block of memory from the Local Heap and return a
**				far pointer to it. This is the release version.
**
** Parameters:	iSize			Size of request in bytes.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void* WCLAPI NearMallocRel(uint iSize)
{
	return (void*)(void NEAR*)LocalAlloc((LPTR | LMEM_NOCOMPACT), iSize);
}

/******************************************************************************
** Function:	NearFreeRel()
**
** Description:	Free a block of memory allocated from the local heap. This is
**				the release version.
**
** Parameters:	pMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI NearFreeRel(void* pMem)
{
#ifdef M_I86MM
	LocalFree((HLOCAL)pMem);
#else
	LocalFree((HLOCAL)(WORD)(DWORD)pMem);
#endif
}

/******************************************************************************
** Function:	NearMallocDbg()
**
** Description:	Allocate a block of memory from the Local Heap and return a
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

void* WCLAPI NearMallocDbg(uint iSize, const char* pszModule, uint iLine)
{
	void*	pMem;
	uint	iRealSize;
	
	ASSERT(iSize);
	ASSERT(pszModule);
	
	// Calculate size of block including debugging info and markers.
	iRealSize = iSize + LocalMemList.DebugInfoSize();
	
	// Allocate it.
	void NEAR* npMem = (void NEAR*)LocalAlloc((LPTR | LMEM_NOCOMPACT), iRealSize);

	// Failed?
	if (!npMem)
	{
		char szMsg[128];
		
		// Create message.
		wsprintf((LPSTR)szMsg, (LPSTR)"Allocation Failed!\nBlock Size = %u Bytes.\n\nDebug?", iSize);
		
		// Notiy user.
		if (MessageBox(NULL, szMsg, "Local Memory", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
		
		return NULL;
	}
	
	// Convert to far pointer
	// if large memory model.
	pMem = npMem;

	// Add to tracking list.
	LocalMemList.Add(pMem, iSize, pszModule, iLine);
	
	// Skip header.
	pMem = (BYTE*)pMem + LocalMemList.DebugInfoSize() - 1;
	
	return pMem;
}

/******************************************************************************
** Function:	NearFreeDbg()
**
** Description:	Free a block of memory allocated from the local heap. In this
**				version the markers at the start and end of the block are
**				checked to make sure no under or overrun has occurred. If not
**				the block is removed from the list and filled with a value to
**				destroy any previous data, which shows up usage after the block
**				has been free'd.
**
** Parameters:	pMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI NearFreeDbg(void* pMem)
{
	ASSERT(pMem);

	// Get pointer to the header.
	pMem = (BYTE*) pMem - LocalMemList.DebugInfoSize() + 1;
	
	// Valid block?
	if (!LocalMemList.Delete(pMem))
		return;
	
	// Finally free the block.
#ifdef M_I86MM
	LocalFree((HLOCAL)pMem);
#else
	LocalFree((HLOCAL)(WORD)(DWORD)pMem);
#endif
}

/******************************************************************************
** Function:	NearMemoryUsage()
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

void WCLAPI NearMemoryUsage(void)
{
	// Dump out stats.
	TRACE("\nLocal Memory Usage:-\n");
	LocalMemList.Status();
}

#endif
