/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		BITMAP.HPP
** COMPONENT:	Windows C++ Library.
** DESCRIPTION:	The CBitmap class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef BITMAP_HPP
#define BITMAP_HPP

// Forward reference.
class CDC;

/******************************************************************************
** 
** This encapsulates a device dependant bitmap.
**
*******************************************************************************
*/

WCLCLASS CBitmap
{
public:
	//
	// Constructors/Destructor.
	//
	CBitmap(void);
	~CBitmap(void);

	void Create(const CSize& rSize, int iBitsPerPixel = 1);
	void Create(const CSize& rSize, const CDC& rDC);
		
	//
	// Member access.
	//
	HBITMAP Handle(void) const;
	const CSize& Size(void) const;

	//
	// Member setting.
	//
	void LoadRsc(uint iID);
	
protected:
	//
	// Members.
	//
	HBITMAP	m_hBitmap;
	CSize	m_Size;
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

inline CBitmap::CBitmap(void)
{
	m_hBitmap = NULL;
}

inline CBitmap::~CBitmap(void)
{
	if (m_hBitmap)
		DeleteObject(m_hBitmap);
}

inline HBITMAP CBitmap::Handle(void) const
{
	return m_hBitmap;
}

inline const CSize& CBitmap::Size(void) const
{
	ASSERT(m_hBitmap);
	
	return m_Size;
}

#endif //BITMAP_HPP
