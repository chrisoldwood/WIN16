/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		MEMLIST.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CMemList class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include "memlist.hpp"

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

CMemList::CMemList(void)
{
}

/******************************************************************************
** Method:		DebugInfoSize()
**
** Description:	Get the size of the debug info header and guard bytes.
**
** Parameters:	None.
**
** Returns:		The size of the header and guard bytes.
**
*******************************************************************************
*/

uint CMemList::DebugInfoSize(void)
{
	return (sizeof(MemBlockInfo) + 2);
}

/******************************************************************************
** Method:		Add()
**
** Description:	Add a new block to the list, setting up the header and marking
**				the block contents as new. New blocks are added to the head of
**				the list. The debug header is included as part of the memory
**				block and is stored at the start.
**
** Parameters:	lpBlock		A pointer to the memory blocks (inc. header).
**				dwSize		The size of the block (exc. header).
**				pszModule	The module it was allocated in.
**				iLine		The modules' line number.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMemList::Add(void FAR* lpBlock, DWORD dwSize, const char* pszModule, uint iLine)
{
	m_iNumAllocs++;

	// Get pointer to debug header.
	MemBlockInfo FAR* lpHeader = (MemBlockInfo FAR*) lpBlock;
	
	// Save header info.
	lpHeader->dwSize    = dwSize;
	lpHeader->pszModule = pszModule;
	lpHeader->iLine     = iLine;
	lpHeader->iAllocNum = m_iNumAllocs;
	
	// Get pointer to underflow guard byte.
	HPBYTE hpBlock = (HPBYTE) (lpHeader + 1);
	
	// Initialise memory block.
	FillBlock(hpBlock, dwSize + 2, NEW_MEM_MARKER);
	
	// Update total bytes allocated.
	m_dwCurrAllocated += dwSize;
	
	// Max to date?
	if (m_dwCurrAllocated > m_dwMaxAllocated)
		m_dwMaxAllocated = m_dwCurrAllocated;

	// Add to the head of the list.
	lpHeader->lpNext = m_lpListHead;
	m_lpListHead     = lpHeader;
}

/******************************************************************************
** Method:		Delete()
**
** Description:	Remove a block from the list, checking the header and marking
**				the block contents as old. Any problems with the block are
**				reported here. The actual memory should not be freed if this
**				method returns FALSE.
**
** Parameters:	lpBlock		A pointer to the memory block (inc. header).
**
** Returns:		TRUE		If the block was allocated.
**				FALSE		If the pointer is invalid.
**
*******************************************************************************
*/

BOOL CMemList::Delete(void FAR* lpBlock)
{
	// Get list head.
	MemBlockInfo FAR* lpHeader = m_lpListHead;
	
	// Walk the list.
	while(lpHeader)
	{
		// Found it?
		if (lpHeader == lpBlock)
			break;
		
		// And on...
		lpHeader = lpHeader->lpNext;
	}

	// Block found?
	if (!lpHeader)
	{
		// Notify user.
		if (MessageBox(NULL, "Attempt to free an unallocated block!\n\nDebug?",
						"Memory Error", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
		
		return FALSE;
	}

	// Get pointer to underflow and overflow guard bytes.
	HPBYTE hpStartByte = (HPBYTE) (lpHeader + 1);
	HPBYTE hpEndByte   = hpStartByte + lpHeader->dwSize + 1;

	// Check for underflow.
	if (*hpStartByte != NEW_MEM_MARKER)
	{
		// Notify user.
		if (MessageBox(NULL, "Memory block underflow!\n\nDebug?",
						"Memory Error", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
	}	

	// Check for overflow.
	if (*hpEndByte != NEW_MEM_MARKER)
	{
		// Notify user.
		if (MessageBox(NULL, "Memory block overflow!\n\nDebug?",
						"Memory Error", MB_YESNO | MB_ICONSTOP) == IDYES)
		{
			// Cause an INT 3.
			DebugBreak();
		}
	}	
	
	// Deinitialise memory block.
	FillBlock(hpStartByte, lpHeader->dwSize + 2, OLD_MEM_MARKER);
	
	// Is list head?
	if (lpHeader == m_lpListHead)
	{
		// New list head.
		m_lpListHead = lpHeader->lpNext;
	}
	else
	{
		// Get list head.
		MemBlockInfo FAR* lpPrev = m_lpListHead;
		
		// Find previous item.
		while (lpPrev->lpNext != lpHeader)
			lpPrev = lpPrev->lpNext;
			
		// Remove from list.
		lpPrev->lpNext = lpHeader->lpNext;
	}

	// Update total bytes allocated.
	m_dwCurrAllocated -= lpHeader->dwSize;
	
	return TRUE;
}

/******************************************************************************
** Method:		FillBlock()
**
** Description:	Fill the block with a predefined value. This helps you see if
**				you are using an uninitialised block or a block after it's been
**				deleted.
**
** Parameters:	hpBlock		A pointer to the start of the memory to fill.
**				dwSize		The number of bytes to fill.
**				cMarker		The byte to fill it with.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMemList::FillBlock(HPBYTE hpBlock, DWORD dwSize, BYTE cMarker)
{
	while(dwSize--)
		*hpBlock++ = cMarker;
}

/******************************************************************************
** Method:		Status()
**
** Description:	Show the status of the list. This shows blocks still in use and
**				where they were allocated.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CMemList::Status(void)
{
	// Dump out stats.
	TRACE1("Total Allocations  : %u\n",  m_iNumAllocs);
	TRACE1("Max Bytes ever used: %lu\n", m_dwMaxAllocated);
	TRACE1("Bytes still in use : %lu\n", m_dwCurrAllocated);
		
	// Blocks still in use?
	if (m_lpListHead)
	{
		// Get list head.
		MemBlockInfo FAR* lpBlock = m_lpListHead;
	
		// Walk the list.
		while(lpBlock)
		{
			// Show location.
			TRACE4("ALLOC: %03u FILE: %s LINE: %u SIZE: %lu\n", 
					lpBlock->iAllocNum, lpBlock->pszModule, 
					lpBlock->iLine, lpBlock->dwSize);
				
			// And on...
			lpBlock = lpBlock->lpNext;
		}
	}
}
