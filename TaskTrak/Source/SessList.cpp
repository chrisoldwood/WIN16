/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SESSLIST.CPP
** COMPONENT:	The Application.
** DESCRIPTION:	CSessionList class definition.
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

CSessionList::CSessionList(void)
{
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

CSessionList::~CSessionList(void)
{
	CSessionEnum	Enum(*this);
	CSession*		pSession;
	
	// Free all sessions.
	while((pSession = Enum.Next()) != NULL)
		delete pSession;
}

/******************************************************************************
** Method:		Add()
**
** Description:	Add a session to the list sorted by time.
**
** Parameters:	pNewSession		The new session.
**
** Returns:		Nothing.
**
*******************************************************************************
*/

void CSessionList::Add(const CSession* pNewSession)
{
	CSessionEnum	Enum(*this);
	CSession*		pCurrSession;
	CSession*		pPrevSession = NULL;
	
	// Free all sessions.
	while((pCurrSession = Enum.Next()) != NULL)
	{
		/* New session starts earlier? */
		if (pNewSession->Start() < pCurrSession->Start())
			break;
		
		/* Remember current session. */
		pPrevSession = pCurrSession;
    }
    
	CList::Insert((void*)pNewSession, pPrevSession);
}

/******************************************************************************
** Method:		Read()
**
** Description:	Read a session list from a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CSessionList::Read(CFile& rFile)
{
	CSession*	pSession;
	int16 		iCount;
	
	// Read count.
	if (!rFile.Read(iCount))
		return FALSE;

	// Read sessions.
	while(iCount--)
	{
		pSession = new CSession;
		ASSERT(pSession);

		if (!pSession->Read(rFile))
			return FALSE;
			
		Add(pSession);
	}
	
	return TRUE;
}

/******************************************************************************
** Method:		Write()
**
** Description:	Write a session list to a file.
**
** Parameters:	rFile	The file.
**
** Returns:		TRUE or FALSE.
**
*******************************************************************************
*/

bool CSessionList::Write(CFile& rFile)
{
	CSessionEnum	Enum(*this);
	CSession*		pSession;
	int16			iCount = (int16) Length();
	
	// Write count.
	if (!rFile.Write(iCount))
		return FALSE;
	
	// Write sessions.
	while((pSession = Enum.Next()) != NULL)
	{
		if (!pSession->Write(rFile))
			return FALSE;
	}
	
	return TRUE;
}
