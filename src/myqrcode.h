// myqrcode.h : main header file for the MYQRCODE application
//

#if !defined(AFX_MYQRCODE_H__4C3595B6_3AF5_42A1_891A_3D1866799391__INCLUDED_)
#define AFX_MYQRCODE_H__4C3595B6_3AF5_42A1_891A_3D1866799391__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyqrcodeApp:
// See myqrcode.cpp for the implementation of this class
//

class CMyqrcodeApp : public CWinApp
{
public:
	CMyqrcodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyqrcodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyqrcodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYQRCODE_H__4C3595B6_3AF5_42A1_891A_3D1866799391__INCLUDED_)
