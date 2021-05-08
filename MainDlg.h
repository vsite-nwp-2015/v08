#pragma once

#include "resource.h"	

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
	CListCtrl lctrl;
	CString title_tekst;
	CString year_tekst;
	afx_msg void OnBnClickedButton1();
	CEdit ed1_ctrl;
	CEdit ed2_ctrl;
	afx_msg void OnBnClickedButton2();
	CButton delBtnctrl;
};
