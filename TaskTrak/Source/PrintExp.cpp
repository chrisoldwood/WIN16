/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		PRINTEXP.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CPrintExport class definition.
**
*******************************************************************************
*/

#include "apphdrs.hpp"

/******************************************************************************
** Method:		Constructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrintExport::CPrintExport(CPrinterDC& rPrinter)
{
	// Intialise members.
	m_pPrinter     = &rPrinter;
   	m_hNormalFont  = NULL;
	m_hHeadingFont = NULL;
	m_iLineHeight  = 0;
	m_iPageOffset  = 0;
}

/******************************************************************************
** Method:		Deconstructor.
**
** Description:	.
**
** Parameters:	None.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

CPrintExport::~CPrintExport(void)
{
}

/******************************************************************************
** Method:		Init()
**
** Description:	Initialise the printer by creating a DC.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrintExport::Init(void)
{
	// Create an HDC.
	if (!m_pPrinter->CreateDC())
	{
		App.AppWnd()->Alert("Failed to initialise the printer");
		return FALSE;
	}
	
	// Initialise page settings.
	m_rcArea      = m_pPrinter->PrintableArea();
	m_iPageOffset = m_rcArea.top;
	
	// Create fonts.
	m_hNormalFont = CreateFont(0, 0, 0, 0, FW_DONTCARE, 0, 0, 0, ANSI_CHARSET,
								OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
								DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
								NULL);
	
	m_hHeadingFont = CreateFont(0, 0, 0, 0, FW_DONTCARE, 0, TRUE, 0, ANSI_CHARSET,
								OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
								DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
								NULL);
	
	CSize	m_NormalSize;
	CSize	m_HeadingSize;

	// Get font metrics.
	m_pPrinter->Font(m_hHeadingFont);
	m_HeadingSize = m_pPrinter->TextExtents("Ly");
	
	m_pPrinter->Font(m_hNormalFont);
	m_NormalSize = m_pPrinter->TextExtents("Ly");
	
	// Get line height.
	if (m_HeadingSize.cy > m_NormalSize.cy)
		m_iLineHeight = m_HeadingSize.cy;
	else
		m_iLineHeight = m_NormalSize.cy;
	
	// Start the document.
	if (!m_pPrinter->Start("TaskTracker"))
	{
		App.AppWnd()->Alert("Failed to start the document");
		return FALSE;
	}
	
	// Start the first page.
	if (!m_pPrinter->StartPage())
	{
		App.AppWnd()->Alert("Failed to start a new page");
		return FALSE;
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		Term()
**
** Description:	Cleanup the printer DC.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrintExport::Term(void)
{
	// Finish printing.
	m_pPrinter->EndPage();
	m_pPrinter->End();
	
	// Free resources.
	m_pPrinter->DeleteDC();

   	if (m_hNormalFont)
   		DeleteObject(m_hNormalFont);
   		
   	if (m_hHeadingFont)
   		DeleteObject(m_hHeadingFont);

	return TRUE;
}

/******************************************************************************
** Method:		SendLineBreak()
**
** Description:	Outputs a line break. If this overflows the current page, then
**				start a new one.
**
** Parameters:	None.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrintExport::SendLineBreak(void)
{
	// Move down to next line.
	m_iPageOffset += m_iLineHeight;

	// Outside current page?
	if ((m_iPageOffset+m_iLineHeight) > m_rcArea.bottom)
	{
		// Finish the current page.
		if (!m_pPrinter->EndPage())
		{
			App.AppWnd()->Alert("Failed to send the last page");
			return FALSE;
		}
			
		// Start a new page.
		if (!m_pPrinter->StartPage())
		{
			App.AppWnd()->Alert("Failed to start a new page");
			return FALSE;
		}
		
		// Reset cursor to page top.
		m_iPageOffset = m_rcArea.top;
	}

	return TRUE;
}

/******************************************************************************
** Method:		SendHeading()
**
** Description:	Outputs the heading for a period.
**
** Parameters:	pszText		The string to output.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrintExport::SendHeading(const char* pszText)
{
	// Select the font
	m_pPrinter->Font(m_hHeadingFont);

	// Print the heading
	m_pPrinter->TextOut(0, m_iPageOffset, pszText);

	return SendLineBreak();
}

/******************************************************************************
** Method:		SendText()
**
** Description:	Outputs a line of text.
**
** Parameters:	pszText		The string to output.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CPrintExport::SendText(const char* pszText)
{
	// Select the font.
	m_pPrinter->Font(m_hNormalFont);

	// Print the heading.
	m_pPrinter->TextOut(0, m_iPageOffset, pszText);
	
	return SendLineBreak();
}
