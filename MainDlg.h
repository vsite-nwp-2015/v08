#pragma once

#include "resource.h"	
#include "afxcmn.h"
#include "afxwin.h"

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	CListCtrl List;
	afx_msg void OnClickedButton2();
};
