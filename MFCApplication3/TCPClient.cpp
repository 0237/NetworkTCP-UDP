// TCPClient.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPClient.h"
#include "TCPClientDlg.h"


// TCPClient

TCPClient::TCPClient()
{
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	m_bConnected = FALSE;
	m_pDlg = NULL;
}

TCPClient::~TCPClient()
{//�ر��׽���
	if(m_hSocket!=INVALID_SOCKET) 
	Close();
	m_pDlg = NULL;
}


// TCPClient ��Ա����
void TCPClient::SetParent(TCPClientDlg* pDlg) {
	m_pDlg = pDlg;
}

void TCPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CString buffer = _T("Receive:");
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	//�������д���������ȡ�Ի���ָ��
	//CMFCApplication3App* pApp = (CMFCApplication3App*)AfxGetApp()
	//TCPClientDlg* pDlg = (TCPClientDlg*)pApp->m_pMainWnd
	buffer += m_szBuffer;
	m_pDlg->m_MSGS.InsertString(0, buffer);//��������д��󣡣���
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPClient::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	CString buffer = _T("Requst:");
	buffer += m_szBuffer;
	m_pDlg->m_MSGS.InsertString(0, buffer);
	Send(m_szBuffer, m_nLength, 0); 
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	//��������һ���������������¼�������Server��Ϣ
	AsyncSelect(FD_READ); 
	CAsyncSocket::OnSend(nErrorCode);
}


void TCPClient::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (nErrorCode == 0) 
	{
		m_bConnected = TRUE;
		//CMFCApplication3App* pApp = (CMFCApplication3App*)AfxGetApp();
		//TCPClientDlg* pDlg = (TCPClientDlg*)pApp->m_pMainWnd;
		CString buffer1 = _T("Connected to ");
		CString Port;Port.Format(_T("%d"), m_pDlg->m_Iport);
		buffer1 += m_pDlg->m_IPaddr + _T(" Port:") + Port;
		memcpy(m_szBuffer, "Connected to ", 13);
		char buffer2[256];
		memcpy(buffer2, m_pDlg->m_IPaddr, m_pDlg->m_IPaddr.GetLength());
		strncat_s(m_szBuffer, buffer2, sizeof(buffer2));
		m_pDlg->m_MSGS.InsertString(0, buffer1);
		AsyncSelect(FD_READ);
		//����һ���������������¼���׼������ 
	} 
	CAsyncSocket::OnConnect(nErrorCode);
}
