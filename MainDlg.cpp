#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, List);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, BtnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, BtnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	List.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 156);
	List.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 100);

	List.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}

void MainDlg::BtnAdd()
{
	CString movieName;
	CString movieYear;

	const int index = List.GetItemCount();

	GetDlgItemText(IDC_EDIT1, movieName);
	GetDlgItemText(IDC_EDIT2, movieYear);

	if (movieName == "" || movieYear == "" || !atoi(movieYear))
		return;

	List.InsertItem(index, movieName);
	List.SetItemText(index, 1, movieYear);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::BtnDelete()
{
	List.DeleteItem(List.GetNextItem(-1, LVNI_SELECTED));
}
