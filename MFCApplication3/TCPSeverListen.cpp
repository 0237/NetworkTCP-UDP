// TCPSeverListen.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSeverListen.h"


// TCPSeverListen

TCPSeverListen::TCPSeverListen()
{
}

TCPSeverListen::~TCPSeverListen()
{
}


// TCPSeverListen 成员函数


void TCPSeverListen::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	//侦听到连接请求，调用Accept函数 
	TCPSever* pSocket = new TCPSever();
	if (Accept(*pSocket))
	{
		pSocket->AsyncSelect(FD_READ);
		m_pSocket = pSocket;
	}
	else
		delete pSocket;
	CAsyncSocket::OnAccept(nErrorCode);
}
