// UPDClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UPDClient.h"


// UPDClient

CUDPClient::CUDPClient()
{
	m_pDlg = NULL;
}

CUDPClient::~CUDPClient()
{
	m_pDlg = NULL;
}


// UPDClient ��Ա����

void CUDPClient::SetParent(CMFCApplication3Dlg* pDlg) 
{
	m_pDlg = pDlg;
}

void CUDPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	//if (nErrorCode == 0)
	//	m_pDlg->OnReceive();//����ʵ���ڶԻ�������
	//CAsyncSocket::OnReceive(nErrorCode);
}
