// AddrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "AddrDlg.h"
#include "afxdialogex.h"


// CAddrDlg 对话框

IMPLEMENT_DYNAMIC(CAddrDlg, CDialogEx)

CAddrDlg::CAddrDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Addr, pParent)
	, m_Addr(_T(""))
	, m_Port(0)
{

}

CAddrDlg::~CAddrDlg()
{
}

void CAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Addr, m_Addr);
	DDX_Text(pDX, IDC_Port, m_Port);
}


BEGIN_MESSAGE_MAP(CAddrDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddrDlg 消息处理程序
