// TCPSever.cpp : ʵ���ļ�
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


// TCPSever ��Ա����


void TCPSever::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	// ֱ��ת����Ϣ
	AsyncSelect(FD_WRITE);
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPSever::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	Send(m_szBuffer, m_nLength, 0);
	CAsyncSocket::OnSend(nErrorCode);
}
