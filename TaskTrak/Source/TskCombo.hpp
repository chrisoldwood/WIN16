/******************************************************************************
** (C) Chris Wood 1998
**
** MODULE:		TSKCOMBO.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTaskCombo class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef TSKCOMBO_HPP
#define TSKCOMBO_HPP

/******************************************************************************
** 
** This is a combo box used to display the list of previous tasks.
**
*******************************************************************************
*/

class CTaskCombo : public CComboBox
{
public:
	//
	// Constructors/Destructor.
	//
	CTaskCombo(void);
	~CTaskCombo(void);
	
protected:
	//
	// Members.
	//

	//
	// Message processors.
	//
	virtual void OnCreate(void);
};

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/

#endif //TSKCOMBO_HPP
