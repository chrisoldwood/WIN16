/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		GLOBLMEM.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	Global Memory management functions.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "memlist.hpp"

/******************************************************************************
** This object holds a list of allocations made from this heap.
*/

static CMemList GlobalMemList;

/******************************************************************************
** Function:	FarMallocRel()
**
** Description:	Allocate a block of memory from the Global Heap and return a
**				far pointer to it. This is the release version.
**
** Parameters:	dwSize			Size of request in bytes.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* WCLAPI FarMallocRel(DWORD dwSize)
{
	return (void FAR*)GlobalAllocPtr(GHND, dwSize);
}

/******************************************************************************
** Function:	FarFreeRel()
**
** Description:	Free a block of memory allocated from the Global Heap. This is
**				the release version.
**
** Parameters:	lpMem	A pointer to the block.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void WCLAPI FarFreeRel(void FAR* lpMem)
{
	GlobalFreePtr(lpMem);
}

/******************************************************************************
** Function:	FarMallocDbg()
**
** Description:	Allocate a block of memory from the Global Heap and return a
**				far pointer to it. This debug versions allocates additonal
**				space for a block header which stores info about where it was
**				allocated and adds a marker before and after the block to check
**				for writing under and overruns. It also fills the entire block
**				with a special value to show up uninitialsed data.
**
** Parameters:	dwSize			Size of request in bytes.
**				pszModule		The file this allocation was made in.
**				iLine			The module line number.
**
** Returns:		On success		A pointer to the block.
**				On failure		NULL.
**
*******************************************************************************
*/

void FAR* WCLAPI FarMallocDbg(DWORD dwSize, const char* pszModule, uint iLine)
{
	void FAR*		lpMem;
	DWORD			dwRealSize;
	
	ASSERT(dwSize);
	ASSERT(pszModule);
	
	// Calculate size of block including debugging info and markers.
	dwRealSize = dwSize + GlobalMemList.DebugInfoSize();
	
	// Allocate it.
	lpMem = (void FAR*)GlobalAllocPtr(GHND, dwRealSize);

	// Failed?
	if (!lpMem)
	{
		char szMsg[128];
		
		// Create message.
		wsprintf(szMsg, "Allocation Failed!\nBlock Size = %lu Bytes.\n\nDebug?", dwSize);
		
		// Notify user.
		if (MessageBox(NULL, szMsg, "Global Memory", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
		
		return NULL;
	}
	
	// Add to tracking list.
	GlobalMemList.Add(lpMem, dwSize, pszModule, iLine);
	
	// Skip header.
	lpMem = (BYTE FAR*)lpMem + GlobalMemList.DebugInfoSize() - 1;
	
	return lpMem;
}

/******************************************************************************
** Function:	FarFreeDbg()
**
** Description:	Free a block of memory allocated from the Global Heap. In this
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

void WCLAPI FarFreeDbg(void FAR* lpMem)
{
	ASSERT(lpMem);

	// Get pointer to the header.
	lpMem = (BYTE FAR*) lpMem - GlobalMemList.DebugInfoSize() + 1;

	// Valid block?
	if (!GlobalMemList.Delete(lpMem))
		return;
	
	// Finally free the block.
	GlobalFreePtr(lpMem);
}

/******************************************************************************
** Function:	FarMemoryUsage()
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

void WCLAPI FarMemoryUsage(void)
{
	// Dump out stats.
	TRACE("\nGlobal Memory Usage:-\n");
	GlobalMemList.Status();
}
