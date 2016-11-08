// UDPClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPClient.h"


// UDPClient

UDPClient::UDPClient()
{
	//m_charEcho = 0;
	//memset(m_charEcho, 0, sizeof(char));
}

UDPClient::~UDPClient()
{
}


// UDPClient 成员函数


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	UINT r4;
	CString r3;
	ri = ReceiveFrom(m_charEcho, sizeof(m_charEcho), r3, r4);
	CAsyncSocket::OnReceive(nErrorCode);
}
