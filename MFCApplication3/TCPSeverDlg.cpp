// TCPSeverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSeverDlg.h"
#include "afxdialogex.h"


// TCPSeverDlg 对话框

IMPLEMENT_DYNAMIC(TCPSeverDlg, CDialogEx)

TCPSeverDlg::TCPSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

TCPSeverDlg::~TCPSeverDlg()
{
}

void TCPSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TCPSeverDlg, CDialogEx)
END_MESSAGE_MAP()


// TCPSeverDlg 消息处理程序
