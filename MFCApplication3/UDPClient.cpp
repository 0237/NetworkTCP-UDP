// UDPClient.cpp : ʵ���ļ�
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


// UDPClient ��Ա����


void UDPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	Reviewed = true;
	UINT r4;
	CString r1,r3;
	ri = ReceiveFrom(m_charEcho, sizeof(m_charEcho), r3, r4);
	m_charEcho[strlen(m_charEcho)] = '\0';
	r1 = m_charEcho;
	CAsyncSocket::OnReceive(nErrorCode);
}