// UDPClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPClient.h"
#include "MFCApplication3Dlg.h"

// UDPClient

UDPClient::UDPClient()
{
	//m_charEcho = 0;
	//memset(m_charEcho, 0, sizeof(char));
	Reviewed = false;
}

UDPClient::~UDPClient()
{
}


// UDPClient 成员函数


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	Reviewed = true;
	UINT r4;
	CString r1,r3;
	ri = ReceiveFrom(m_charEcho, sizeof(m_charEcho), r3, r4);
	m_charEcho[strlen(m_charEcho)] = '\0';
	r1 = m_charEcho;
	CAsyncSocket::OnReceive(nErrorCode);
}