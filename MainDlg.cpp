#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
	, title_tekst(_T(""))
	, year_tekst(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lctrl);
	DDX_Text(pDX, IDC_EDIT1, title_tekst);
	DDX_Text(pDX, IDC_EDIT2, year_tekst);
	DDX_Control(pDX, IDC_EDIT1, ed1_ctrl);
	DDX_Control(pDX, IDC_EDIT2, ed2_ctrl);
	DDX_Control(pDX, IDC_BUTTON2, delBtnctrl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	lctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_SHOWSELALWAYS);
	lctrl.InsertColumn(0, _T("Title"), LVCFMT_LEFT,120);
	lctrl.InsertColumn(1, _T("Year"), LVCFMT_CENTER,60);
	delBtnctrl.EnableWindow(false);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	GetDlgItemText(IDC_EDIT1, title_tekst);
	GetDlgItemText(IDC_EDIT2, year_tekst);
	if (title_tekst != _T("") && year_tekst != _T("")) {
		lctrl.InsertItem(0, title_tekst);
		lctrl.SetItemText(0, 1, year_tekst);
		lctrl.SetItemState(0, LVIS_FOCUSED | LVIS_SELECTED , LVIS_FOCUSED | LVIS_SELECTED);
		delBtnctrl.EnableWindow(true);
	}
	ed1_ctrl.SetWindowText(_T(""));
	ed2_ctrl.SetWindowText(_T(""));
}


void MainDlg::OnBnClickedButton2()
{
	lctrl.DeleteItem(lctrl.GetNextItem(-1, LVNI_SELECTED));
	lctrl.SetItemState(0, LVIS_SELECTED, LVIS_SELECTED);
	if (!lctrl.GetItemCount())
		delBtnctrl.EnableWindow(false);
}
