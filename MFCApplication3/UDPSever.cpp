// UDPSever.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPSever.h"


// UDPSever

UDPSever::UDPSever()
{
}

UDPSever::~UDPSever()
{
}


// UDPSever ��Ա����


void UDPSever::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnReceive(nErrorCode);
}
