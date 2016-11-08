// UDPSeverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPSeverDlg.h"
#include "afxdialogex.h"


// UDPSeverDlg 对话框

IMPLEMENT_DYNAMIC(UDPSeverDlg, CDialogEx)

UDPSeverDlg::UDPSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

UDPSeverDlg::~UDPSeverDlg()
{
}

void UDPSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UDPSeverDlg, CDialogEx)
END_MESSAGE_MAP()


// UDPSeverDlg 消息处理程序
