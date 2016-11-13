// TCPClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPClient.h"
#include "TCPClientDlg.h"


// TCPClient

TCPClient::TCPClient()
{
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	m_bConnected = FALSE;
	m_pDlg = NULL;
}

TCPClient::~TCPClient()
{//关闭套接字
	if(m_hSocket!=INVALID_SOCKET) 
	Close();
	m_pDlg = NULL;
}


// TCPClient 成员函数
void TCPClient::SetParent(TCPClientDlg* pDlg) {
	m_pDlg = pDlg;
}

void TCPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	//下面两行代码用来获取对话框指针
	CMFCApplication3App* pApp=(CMFCApplication3App*)AfxGetApp();
	TCPClientDlg* pDlg = (TCPClientDlg*)pApp ->m_pMainWnd;
	pDlg ->m_MSGS.InsertString(0, (LPCTSTR)(LPTSTR)m_szBuffer);//这里可能有错误！！！
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPClient::OnSend(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	Send(m_szBuffer, m_nLength, 0); 
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	//继续提请一个“读”的网络事件，接收Server消息
	AsyncSelect(FD_READ); 
	CAsyncSocket::OnSend(nErrorCode);
}


void TCPClient::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0) 
	{
		m_bConnected = TRUE;
		//CMFCApplication3App* pApp = (CMFCApplication3App*)AfxGetApp();
		//TCPClientDlg* pDlg = (TCPClientDlg*)pApp->m_pMainWnd;
		CString buffer1 = _T("Connected to ");
		buffer1 += m_pDlg->m_IPaddr;
		memcpy(m_szBuffer, "Connected to ", 13);
		char buffer2[256];
		memcpy(buffer2, m_pDlg->m_IPaddr, m_pDlg->m_IPaddr.GetLength());
		strncat_s(m_szBuffer, buffer2, sizeof(buffer2));
		m_pDlg->m_MSGS.InsertString(0, buffer1);
		AsyncSelect(FD_READ);
		//提请一个“读”的网络事件，准备接收 
	} 
	CAsyncSocket::OnConnect(nErrorCode);
}
