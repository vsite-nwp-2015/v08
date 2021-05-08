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
	DDX_Control(pDX, IDC_LIST1,movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)

END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	movies.InsertColumn(0, "Title", LVCFMT_LEFT,100);
	movies.InsertColumn(1, "Year", LVCFMT_LEFT,50);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString Naziv;
	CString Godina;
	GetDlgItemText(IDC_EDIT1, Naziv);
	GetDlgItemText(IDC_EDIT2, Godina);
	int x = Naziv.GetLength();
	int y = Godina.GetLength();
	if (((int)Naziv.GetLength()) == 0 || ((int)Godina.GetLength()) !=4) {
		return;
	}
	movies.InsertItem(movies.GetItemCount(), Naziv);
	movies.SetItemText(movies.GetItemCount()-1, 1, Godina);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
}


void MainDlg::OnBnClickedButton2()
{
	int selectedCount = movies.GetSelectedCount();
	UINT i;
	int nitem;
	if (selectedCount > 0)
	{
		for (i = 0; i < selectedCount; i++)
		{
			nitem = movies.GetNextItem(-1, LVNI_SELECTED);
			if (nitem != -1) {
				movies.DeleteItem(nitem);
			}
		}
	}
	if (movies.GetItemCount() == 0) {
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	}
}


