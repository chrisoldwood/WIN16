/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		SIZE.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CSize class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef SIZE_HPP
#define SIZE_HPP

/******************************************************************************
** 
** This is a class based version of the standard Windows SIZE structure.
**
*******************************************************************************
*/

WCLCLASS CSize : public tagSIZE
{
public:
	//
	// Constructors/Destructor.
	//
	CSize(void);
	CSize(int iWidth, int iHeight);
	
	//
	// Misc.
	//
	void Set(int iWidth, int iHeight);
};


/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CSize::CSize(void)
{
	Set(0, 0);
}

inline CSize::CSize(int iWidth, int iHeight)
{
	Set(iWidth, iHeight);
}

inline void CSize::Set(int iWidth, int iHeight)
{
	cx = iWidth;
	cy = iHeight;
}

#endif //SIZE_HPP
