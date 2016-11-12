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
}

TCPClient::~TCPClient()
{//关闭套接字
	if(m_hSocket!=INVALID_SOCKET) 
	Close();
}


// TCPClient 成员函数


void TCPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	//下面两行代码用来获取对话框指针
	CMFCApplication3App* pApp=(CMFCApplication3App*)AfxGetApp();
	TCPClientDlg* pDlg = (TCPClientDlg*)pApp ->m_pMainWnd;
	DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, m_szBuffer, -1, NULL, 0);
	pDlg ->m_MSGS.InsertString(0, (LPCTSTR)(LPTSTR)m_szBuffer);//这里可能有错误！！！
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPClient::OnSend(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnSend(nErrorCode);
}


void TCPClient::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnConnect(nErrorCode);
}
