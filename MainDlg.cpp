#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include <string>
#include <map>

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
	DDX_Control(pDX, IDC_LIST1, list);

}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

void MainDlg::AddColumnsName() {
	std::map<std::string, int> columnMap;
	columnMap.insert(std::make_pair(_T("Title"), 130));
	columnMap.insert(std::make_pair(_T("Year"), 50));

	int index = 0;
		for (auto const& x : columnMap)
			list.InsertColumn(index++, x.first.c_str(), LVCFMT_CENTER, x.second);
}

void MainDlg::SetEditToDefaultValue() {
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	AddColumnsName();
	list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;

}void MainDlg::OnBnClickedButton1()
{
	CString title, year;

	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	int numberOfInsertedMovies = list.GetItemCount();


	if (title != "" && year != "" && isdigit(atoi(year))) {
		list.InsertItem(numberOfInsertedMovies, title);
		list.SetItemText(numberOfInsertedMovies, 1, year);

		SetEditToDefaultValue();
	}
}

void MainDlg::OnBnClickedButton2()
{
	int selectedRow = list.GetNextItem(-1, LVNI_SELECTED);
	if (selectedRow != -1) 
			list.DeleteItem(selectedRow);
}



