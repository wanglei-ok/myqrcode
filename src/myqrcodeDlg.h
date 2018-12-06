// myqrcodeDlg.h : header file
//

#if !defined(AFX_MYQRCODEDLG_H__1DEBEFF6_72DF_44C8_8575_CF3EAB844E09__INCLUDED_)
#define AFX_MYQRCODEDLG_H__1DEBEFF6_72DF_44C8_8575_CF3EAB844E09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "qrcode.h"

/////////////////////////////////////////////////////////////////////////////
// CMyqrcodeDlg dialog

class CMyqrcodeDlg : public CDialog
{
// Construction
public:
	CMyqrcodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyqrcodeDlg)
	enum { IDD = IDD_MYQRCODE_DIALOG };
	CQRCode	m_ctrlQrcode;
	CString	m_szUrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyqrcodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyqrcodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangeUrl();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYQRCODEDLG_H__1DEBEFF6_72DF_44C8_8575_CF3EAB844E09__INCLUDED_)
