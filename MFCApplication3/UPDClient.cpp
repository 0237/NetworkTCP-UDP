// UPDClient.cpp : ʵ���ļ�
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


// UPDClient ��Ա����


void UPDClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnReceive(nErrorCode);
}
