// UDPClient.cpp : ʵ���ļ�
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


// UDPClient ��Ա����


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	UINT r4;
	CString r3;
	ri = ReceiveFrom(m_charEcho, sizeof(m_charEcho), r3, r4);
	CAsyncSocket::OnReceive(nErrorCode);
}
