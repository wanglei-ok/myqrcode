#if !defined(AFX_QRCODE_H__70E2B65F_17A0_4815_BAA3_53D7F835027B__INCLUDED_)
#define AFX_QRCODE_H__70E2B65F_17A0_4815_BAA3_53D7F835027B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QRCode.h : header file
//

#include "qrencode.h"


/////////////////////////////////////////////////////////////////////////////
// CQRCode window

class CQRCode : public CStatic
{
// Construction
public:
	CQRCode();

	void SetText(const CString &str, BOOL bTextMode = TRUE);

// Attributes
public:
	CBitmap * m_qrcode;
	CString m_text;
	BOOL m_bTextMode;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQRCode)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	void refresh();
	virtual ~CQRCode();

	// Generated message map functions
protected:
	//{{AFX_MSG(CQRCode)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QRCODE_H__70E2B65F_17A0_4815_BAA3_53D7F835027B__INCLUDED_)
