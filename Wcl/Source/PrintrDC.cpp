/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRINTRDC.CPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	CPrinterDC class methods.
**
*******************************************************************************
*/

#include "wcl.hpp"
#include <commdlg.h>

#ifdef WIN16
#include <print.h>
#endif

/******************************************************************************
** Method:		Default Constructor.
**
** Description:	Creates a description based on the default printer.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrinterDC::CPrinterDC(void)
{
	char szDefault[128];
	
	// Get the defualt printer.
	GetProfileString("Windows", "Device", "", szDefault, sizeof(szDefault));
	
	// A valid device?
	if ( (szDefault[0] == '\0') || (lstrcmp(szDefault, ",,,") == 0) )
	{
		// No defualt printer.
		m_bValid = FALSE;
		return;
	}
	
	// Get description.
	m_strName   = strtok(szDefault, ",");
	m_strDriver = strtok(NULL, ",");
	m_strPort   = strtok(NULL, ",");
	
	// Okay.
	m_bValid = TRUE;
}

/******************************************************************************
** Method:		Destructor
**
** Description:	Cleans up the DC before freeing.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrinterDC::~CPrinterDC(void)
{
	// Already deleted?
	if (m_hDC)
		DeleteDC();
}

/******************************************************************************
** Method:		Type()
**
** Description:	Returns the actual type of the device. This is used when you
**				need to know the actual device type to perform different
**				drawing actions and you only have a Device.
**
** Parameters:	None.
**
** Returns:		The device enumerated type.
**
*******************************************************************************
*/

CDC::Device CPrinterDC::Type(void) const
{
	return Printer;
}

/******************************************************************************
** Method:		CreateDC()
**
** Description:	Creates an actual HDC for the device.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CPrinterDC::CreateDC(void)
{
	// Valid description?
	if (!m_bValid)
		return FALSE;
	
	// Try and create it.
	m_hDC = ::CreateDC(m_strDriver, m_strName, m_strPort, NULL);
	
	// Got a valid DC?
	if (!m_hDC)
		return FALSE;

	// Save current state.
	m_iState = SaveState();
	
	// Okay.
	return TRUE;
}

/******************************************************************************
** Method:		DeleteDC()
**
** Description:	Cleans up the DC and deletes it.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPrinterDC::DeleteDC(void)
{
	// First delete any selected resources.
	Cleanup();

	// Restore DC to inital settings.
	RestoreState(m_iState);

	// Finally free up the HDC.
	::DeleteDC(m_hDC);
	m_hDC = NULL;
}

/******************************************************************************
** Method:		Select()
**
** Description:	Ask the user to select a printer from the common dialog.
**
** Parameters:	pParent		The dialogs parent.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrinterDC::Select(const CWnd* pParent)
{
	PRINTDLG PrtDlg;
	
	// Initialise structure.
	memset(&PrtDlg, 0, sizeof(PRINTDLG));
	
	PrtDlg.lStructSize = sizeof(PRINTDLG);
	PrtDlg.hwndOwner   = pParent->Handle();
	PrtDlg.Flags       = PD_PRINTSETUP;
	
	// Call up the dialog.
	bool bOkay = PrintDlg(&PrtDlg);
	
	// User pressed OK?
	if (bOkay)
	{
		ASSERT(PrtDlg.hDevNames);
		
		// Get a pointer to the description.
		LPCSTR 		lpszDevNames = (LPCSTR) GlobalLock(PrtDlg.hDevNames);
		LPDEVNAMES	lpDevNames   = (LPDEVNAMES) lpszDevNames;
		
		// Copy description.
		m_strName   = lpszDevNames + lpDevNames->wDeviceOffset;
		m_strDriver = lpszDevNames + lpDevNames->wDriverOffset;
		m_strPort   = lpszDevNames + lpDevNames->wOutputOffset;
		
		// Unlock the decription.
		GlobalUnlock(PrtDlg.hDevNames);
	}
	
	// Free Devmode?
	if (PrtDlg.hDevMode)
		GlobalFree(PrtDlg.hDevMode);

	// Free Devnames?
	if (PrtDlg.hDevNames)
		GlobalFree(PrtDlg.hDevNames);
		
	return bOkay;
}

/******************************************************************************
** Method:		Start()
**
** Description:	Start a new document.
**
** Parameters:	pszTitle	The title of the new document.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CPrinterDC::Start(const char* pszTitle)
{
	DOCINFO DocInfo;

	ASSERT(pszTitle);
	ASSERT(m_hDC);
	
	// Initialise.
	DocInfo.cbSize      = sizeof(DOCINFO);
	DocInfo.lpszDocName = pszTitle;
	DocInfo.lpszOutput  = NULL;
	
	m_iLastError = StartDoc(m_hDC, &DocInfo);

	// Error occurred?
	if (m_iLastError == SP_ERROR)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		Abort()
**
** Description:	Abort printing the current document.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CPrinterDC::Abort(void)
{
	ASSERT(m_hDC);

	AbortDoc(m_hDC);
}

/******************************************************************************
** Method:		End()
**
** Description:	Finish printing the document.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CPrinterDC::End(void)
{
	ASSERT(m_hDC);

	m_iLastError = EndDoc(m_hDC);

	// Error occurred?
	if (m_iLastError < 0)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		StartPage()
**
** Description:	Start a new page of the document.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CPrinterDC::StartPage(void)
{
	ASSERT(m_hDC);

	m_iLastError = ::StartPage(m_hDC);

	// Error occurred?
	if (m_iLastError <= 0)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		EndPage()
**
** Description:	Finish printing the current page.
**
** Parameters:	None.
**
** Returns:		TRUE	On success.
**				FALSE	On failure.
**
*******************************************************************************
*/

bool CPrinterDC::EndPage(void)
{
	ASSERT(m_hDC);

	m_iLastError = ::EndPage(m_hDC);

	// Error occurred?
	if (m_iLastError < 0)
		return FALSE;
	
	return TRUE;
}

/******************************************************************************
** Method:		PageArea()
**
** Description:	Gets the area for the page in pixels.
**
** Parameters:	None.
**
** Returns:		The page area.
**
*******************************************************************************
*/

CRect CPrinterDC::PageArea(void) const
{
	ASSERT(m_hDC);

	return CRect(0, 0, HorzRes(), VertRes());
}

/******************************************************************************
** Method:		PrintableArea()
**
** Description:	Gets the printable area for the page in pixels.
**
** Parameters:	None.
**
** Returns:		The printable area.
**
*******************************************************************************
*/

CRect CPrinterDC::PrintableArea(void) const
{
	ASSERT(m_hDC);

	CPoint	ptOffset(0, 0);
	CRect	rcPage = PageArea();

	// Get margin and adjust page.
	if (Escape(m_hDC, GETPRINTINGOFFSET, 0, NULL, &ptOffset) > 0)
	{
		rcPage.left    += ptOffset.x;
		rcPage.top     += ptOffset.y;
		rcPage.right   -= ptOffset.x;
		rcPage.bottom  -= ptOffset.y;
	}
	
	return rcPage;
}
