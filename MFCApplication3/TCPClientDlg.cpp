// TCPClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPClientDlg.h"
#include "afxdialogex.h"


// TCPClientDlg 对话框

IMPLEMENT_DYNAMIC(TCPClientDlg, CDialogEx)

TCPClientDlg::TCPClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

TCPClientDlg::~TCPClientDlg()
{
}

void TCPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TCPClientDlg, CDialogEx)
END_MESSAGE_MAP()


// TCPClientDlg 消息处理程序
