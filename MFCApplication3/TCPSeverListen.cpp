// TCPSeverListen.cpp : ʵ���ļ�
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


// TCPSeverListen ��Ա����


void TCPSeverListen::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	//�������������󣬵���Accept���� 
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
