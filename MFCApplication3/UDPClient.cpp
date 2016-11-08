// UDPClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPClient.h"


// UDPClient

UDPClient::UDPClient()
{
}

UDPClient::~UDPClient()
{
}


// UDPClient 成员函数


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnReceive(nErrorCode);
}
