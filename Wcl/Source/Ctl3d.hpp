/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		CTL3D.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CCtl3d class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef CTL3D_HPP
#define CTL3D_HPP

/******************************************************************************
**
** CTL3D Prototypes.
**
*******************************************************************************
*/

typedef BOOL (WINAPI *LPFNCTL3DREGISTER)(HINSTANCE);
typedef BOOL (WINAPI *LPFNCTL3DUNREGISTER)(HINSTANCE);
typedef BOOL (WINAPI *LPFNCTL3DAUTOSUBCLASS)(HINSTANCE);

/******************************************************************************
** 
** An encapsulation of the CTL3D.DLL module.
**
*******************************************************************************
*/

WCLCLASS CCtl3d : public CModule
{
public:
	//
	// Constructors/Destructor.
	//
	CCtl3d(void);

	bool Load(void);
	void Register(HINSTANCE hInstance) const;
	void Unregister(HINSTANCE hInstance) const;
	
protected:
	//
	// Members
	//
	LPFNCTL3DREGISTER 		m_lpfnCtl3dRegister;
	LPFNCTL3DAUTOSUBCLASS	m_lpfnCtl3dAutoSubclass;
	LPFNCTL3DUNREGISTER		m_lpfnCtl3dUnregister;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline void CCtl3d::Register(HINSTANCE hInstance) const
{
	if (m_hInstance)
	{
		m_lpfnCtl3dRegister(hInstance);
		m_lpfnCtl3dAutoSubclass(hInstance);
	}
}

inline void CCtl3d::Unregister(HINSTANCE hInstance) const
{
	if (m_hInstance)
	{
		m_lpfnCtl3dUnregister(hInstance);
	}
}

#endif //CTL3D_HPP
