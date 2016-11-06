// UPDClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UPDClient.h"


// UPDClient

UPDClient::UPDClient()
{
}

UPDClient::~UPDClient()
{
}


// UPDClient 成员函数


void UPDClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CAsyncSocket::OnReceive(nErrorCode);
}
