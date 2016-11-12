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
	ON_BN_CLICKED(IDC_BNListen, &TCPSeverDlg::OnBnClickedBnlisten)
END_MESSAGE_MAP()


// TCPSeverDlg 消息处理程序


void TCPSeverDlg::OnBnClickedBnlisten()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_srvrSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_srvrSocket.Create(1088, SOCK_STREAM, FD_ACCEPT);
		//服务器的端口号1088是写死的！
		if(!bFlag)
		{ 
			AfxMessageBox(_T("Socket Error!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	//“监听”成功，等待连接请求
	if (!m_srvrSocket.Listen(1))
	{ 
		int nErrorCode = m_srvrSocket.GetLastError();
		if (nErrorCode != WSAEWOULDBLOCK)
		{
			AfxMessageBox(_T("Socket Error!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
}
