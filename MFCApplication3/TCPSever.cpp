// TCPSever.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSever.h"


// TCPSever

TCPSever::TCPSever()
{
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
}

TCPSever::~TCPSever()
{
	if (m_hSocket != INVALID_SOCKET)
		Close();
}


// TCPSever 成员函数


void TCPSever::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	// 直接转发消息
	AsyncSelect(FD_WRITE);
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPSever::OnSend(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	Send(m_szBuffer, m_nLength, 0);
	CAsyncSocket::OnSend(nErrorCode);
}
