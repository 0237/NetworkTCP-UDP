// UPDClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UPDClient.h"


// UPDClient

UPDClient::UPDClient()
{
	m_pDlg = NULL;
}

UPDClient::~UPDClient()
{
	m_pDlg = NULL;
}


// UPDClient ��Ա����

void UPDClient::SetParent(CMFCApplication3Dlg* pDlg) 
{
	m_pDlg = pDlg;
}

void UPDClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0)
		m_pDlg->OnReceive();//����ʵ���ڶԻ�������
	//CAsyncSocket::OnReceive(nErrorCode);
}


void UPDClient::OnClose(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0)
		m_pDlg->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void UPDClient::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0)
		m_pDlg->OnConnect();
	//CAsyncSocket::OnConnect(nErrorCode);
}
