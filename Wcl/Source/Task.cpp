/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CTask.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CTask class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <stdio.h>
#include <stdarg.h>
#include "hashtble.hpp"

/******************************************************************************
**
** Local variables.
**
*******************************************************************************
*/

#ifdef WIN16
// Application objects hash table.
CHashTable AppTable(1);
#else
//Application object.
static CTask* pThis = NULL;
#endif

// MessageBox() message buffer.
static char	szMsg[256];

#pragma optimize("", off)

/******************************************************************************
** Method:		Default Constructor
**
** Description:	It just saves a copy of itself so that access to it can be 
**				obtained from anywhere. This uses the stack	segment as a unique
**				ID for the app because when the library is built as a DLL it
**				needs to distinguish between multiple apps.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTask::CTask(void)
{
#ifdef WIN16

	WORD wStackSeg;
	
	// Get the stack segment.
	__asm
	{
		mov	wStackSeg, SS
	}

#ifdef M_I86MM
	AppTable.Add(wStackSeg, (ulong)(WORD)this);
#else
	AppTable.Add(wStackSeg, (ulong)this);
#endif

#else //WIN32

	pThis = this;

#endif

	// Reset members.
	m_pModule = NULL;
	m_pAppWnd = NULL;

	// Reset private members.
	m_iBusyCount = 0;
	m_hOldCursor = NULL;
}

/******************************************************************************
** Method:		Destructor
**
** Description:	It deletes the mapping.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTask::~CTask(void)
{
#ifdef WIN16

	WORD wStackSeg;

	// Get the stack segment.
	__asm
	{
		mov	wStackSeg, SS
	}

	AppTable.Delete(wStackSeg);

#else //WIN32

	pThis = NULL;

#endif

	TRACE("\nResource usage:\n");

	// Show resource usage.
#ifdef WIN16
	NearMemStats();
	HeapMemStats();
	HeapMgrStats();
#endif
	FarMemStats();
}

/******************************************************************************
** Method:		This()
**
** Description:	Get a pointer to the application object. This uses the stack
**				segment as a hash key into the hash table of apps.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CTask* CTask::This(void)
{
#ifdef WIN16

	WORD  wStackSeg;

	// Get the stack segment.
	__asm
	{
		mov	wStackSeg, SS
	}

#ifdef M_I86MM
	return (CTask*)(WORD) AppTable.Find(wStackSeg);
#else
	return (CTask*) AppTable.Find(wStackSeg);
#endif

#else //WIN32

	return pThis;

#endif
}

#pragma optimize("", on)

/******************************************************************************
** Method:		Initialise()
**
** Description:	Initialise the App base class memebers.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure
**
*******************************************************************************
*/

bool CTask::Initialise(void)
{
	// Get the application title.
	m_strTitle.LoadRsc(IDS_APP_TITLE);

#ifdef WIN16
	// Try both versions of CTL3D.
	m_Ctl3d.Path() = "CTL3DV2.DLL";
	if (m_Ctl3d.Load())
		m_Ctl3d.Register(m_pModule->Handle());

	m_Ctl3d.Path() = "CTL3D.DLL";
	if (m_Ctl3d.Load())
		m_Ctl3d.Register(m_pModule->Handle());
#else
//	m_Ctl3d.Path() = "CTL3D32.DLL";
//	if (m_Ctl3d.Load())
//		m_Ctl3d.Register(m_pModule->Handle());
#endif

	//Success
	return TRUE;
}

/******************************************************************************
** Method:		Terminate()
**
** Description:	Cleanup any resources used in the App base class memebers.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure
**
*******************************************************************************
*/

bool CTask::Terminate(void)
{
	m_strTitle.Free();

#ifdef WIN16
	m_Ctl3d.Unregister(m_pModule->Handle());
	m_Ctl3d.Free();
	m_Ctl3d.Path().Free();
#endif

	return TRUE;
}

/******************************************************************************
** Methods:		Alert()
**				Notify()
**				Query()
**				QueryEx()
**
** Description:	Displays a message box with no parent window.
**				QueryEx() is for Yes/No/Cancel message boxes.
**
** Parameters:	pszMsg			The message format.
**				...				Variable number of arguments.
**
** Returns:		Result from MessageBox() if appropriate.
**
*******************************************************************************
*/

void CTask::Alert(const char* pszMsg, ...) const
{
	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	MessageBox(NULL, szMsg, m_strTitle, MB_OK | MB_ICONSTOP);
}

void CTask::Notify(const char* pszMsg, ...) const
{
	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	MessageBox(NULL, szMsg, m_strTitle, MB_OK | MB_ICONINFORMATION);
}

int CTask::Query(const char* pszMsg, ...) const
{
	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	return MessageBox(NULL, szMsg, m_strTitle, MB_YESNO | MB_ICONQUESTION);
}

int CTask::QueryEx(const char* pszMsg, ...) const
{
	// Setup arguments.
	va_list	args;
	va_start(args, pszMsg);
	
	// Form message.
	vsprintf((char*)szMsg, pszMsg, args);
	
	return MessageBox(NULL, szMsg, m_strTitle, MB_YESNOCANCEL | MB_ICONQUESTION);
}

/******************************************************************************
** Method:		Busy()
**
** Description:	Notify the user that the application is now busy, or is no
**				longer busy.
**
** Parameters:	bBusy		New state.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTask::Busy(bool bBusy)
{
	// Now busy?
	if (bBusy)
	{
		// No previous calls?
		if (!m_iBusyCount)
		{
			// Set hourglass and save old cursor.
			m_hOldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
		}

		// Inc. number of calls.
		m_iBusyCount++;
	}
	else
	{
		// Dec. number of calls.
		m_iBusyCount--;
		
		ASSERT(m_iBusyCount >= 0);
		
		// Last call?
		if (!m_iBusyCount)
		{
			SetCursor(m_hOldCursor);
		}
	}
}

/******************************************************************************
** Method:		MessageLoop()
**
** Description:	This is the default main message loop. It waits for a message
**				to arrive and calls the virtual message handler when one does.
**				
** Parameters:	None.
**
** Returns:		WPARAM of WM_QUIT message.
**
*******************************************************************************
*/

int CTask::MessageLoop(void) const
{
	// Forever.
	for (;;)
	{
		MSG Msg;
	
		// Message waiting?
		if(PeekMessage(&Msg, NULL, NULL, NULL, PM_NOREMOVE))
		{
			bool bProcessed = FALSE;
			
			// Is WM_QUIT?
			if (!GetMessage(&Msg, NULL, NULL, NULL))
				return Msg.wParam;

//			TRACE1("Message: %04X\n", Msg.message);

			CListEnum	Enum(m_MsgFilters);
			CWnd*		pWnd = NULL;

			// Allow message filters first crack.
			while( ((pWnd = (CWnd*) Enum.Next()) != NULL) && (!bProcessed) )
				bProcessed = pWnd->FilterMessage(&Msg);

			// Allow the app window to process next.
			if (m_pAppWnd)
				bProcessed = m_pAppWnd->ProcessMsg(&Msg);
			
			// Still unprocessed?
			if (!bProcessed)
			{
				TranslateMessage(&Msg);
				DispatchMessage(&Msg);
			}
		}
		else
		{
			// Yield.
			WaitMessage();
		}
	}
}

/******************************************************************************
** Method:		Yield()
**
** Description:	Yield CPU time to another task.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTask::Yield(void) const
{
	MSG	Msg;

	// Message waiting?
	while(PeekMessage(&Msg, NULL, NULL, NULL, PM_NOREMOVE))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
}

/******************************************************************************
** Method:		AddMsgFilter()
**
** Description:	Add a window to filter messages.
**
** Parameters:	pWnd	The window to do the filtering.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTask::AddMsgFilter(CWnd* pWnd)
{
	m_MsgFilters.Add(pWnd);
}

/******************************************************************************
** Method:		AddMsgFilter()
**
** Description:	Add a window to filter messages.
**
** Parameters:	pWnd	The window to do the filtering.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CTask::DelMsgFilter(CWnd* pWnd)
{
	m_MsgFilters.Remove(pWnd);
}
