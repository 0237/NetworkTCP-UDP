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
	DDX_Control(pDX, IDC_EDITMSG, m_MSG);
	DDX_Control(pDX, IDC_LISTMSG, m_MSGS);
}


BEGIN_MESSAGE_MAP(TCPClientDlg, CDialogEx)
	ON_BN_CLICKED(ID_Connect, &TCPClientDlg::OnBnClickedConnect)
	ON_WM_TIMER()
	ON_BN_CLICKED(ID_Exit, &TCPClientDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// TCPClientDlg 消息处理程序


void TCPClientDlg::OnBnClickedConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	m_clientSocket.ShutDown(2);
	m_clientSocket.m_hSocket = INVALID_SOCKET;
	m_clientSocket.m_bConnected = FALSE;
	CAddrDlg m_Dlg; 
	//默认端口1088
	m_Dlg.m_Port=1088; 
	if (m_Dlg.DoModal() == IDOK && !m_Dlg.m_Addr.IsEmpty()) {
		memcpy(m_szServerAdr, m_Dlg.m_Addr, sizeof(m_szServerAdr));
		m_szPort = m_Dlg.m_Port; 
		//建立计时器，每1秒尝试连接一次，直到连上或TryCount>10
		SetTimer(1,1000,NULL); 
		TryCount = 0;
	}
}


void TCPClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_clientSocket.m_hSocket == INVALID_SOCKET) 
	{
		BOOL bFlag = m_clientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if (!bFlag) 
		{
			AfxMessageBox(_T("Socket Error!"));
			m_clientSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	m_clientSocket.Connect((LPCTSTR)(LPTSTR)m_szServerAdr, m_szPort);
	TryCount++;
	if (TryCount >= 10 || m_clientSocket.m_bConnected) 
	{
		KillTimer(1);
		if (TryCount >= 10) 
			AfxMessageBox(_T("Connect Failed!"));
		return;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void TCPClientDlg::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	//关闭Socket
	m_clientSocket.ShutDown(2); 
	//关闭对话框
	//EndDialog(0);
}
