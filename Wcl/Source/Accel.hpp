/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		ACCEL.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CAccel class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef ACCEL_HPP
#define ACCEL_HPP

/******************************************************************************
** 
** This encapsulates a Windows accelerator table.
**
*******************************************************************************
*/

WCLCLASS CAccel
{
public:
	//
	// Constructors/Destructor.
	//
	CAccel(void);
	CAccel(HACCEL hAccel);
	
	//
	// Member access.
	//
	HACCEL Handle(void) const;

	//
	// Member setting.
	//
	void LoadRsc(uint iID);

	//
	// Message handling.
	//
	bool Translate(HWND hWnd, MSG* pMsg);
	
protected:
	//
	// Members.
	//
	HACCEL	m_hAccel;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CAccel::CAccel(void)
{
	m_hAccel = NULL;
}

inline CAccel::CAccel(HACCEL hAccel)
{
	m_hAccel = hAccel;
}

inline HACCEL CAccel::Handle(void) const
{
	return m_hAccel;
}

#endif //ACCEL_HPP
