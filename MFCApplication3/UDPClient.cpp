// UDPClient.cpp : ʵ���ļ�
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


// UDPClient ��Ա����


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnReceive(nErrorCode);
}
