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
private:
	CListCtrl movies;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
//	afx_msg void OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMKillfocusList1(NMHDR *pNMHDR, LRESULT *pResult);
};
