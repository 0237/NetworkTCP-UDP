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
}

TCPClient::~TCPClient()
{//�ر��׽���
	if(m_hSocket!=INVALID_SOCKET) 
	Close();
}


// TCPClient ��Ա����


void TCPClient::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	//�������д���������ȡ�Ի���ָ��
	CMFCApplication3App* pApp=(CMFCApplication3App*)AfxGetApp();
	TCPClientDlg* pDlg = (TCPClientDlg*)pApp ->m_pMainWnd;
	DWORD dwNum = MultiByteToWideChar(CP_ACP, 0, m_szBuffer, -1, NULL, 0);
	pDlg ->m_MSGS.InsertString(0, (LPCTSTR)(LPTSTR)m_szBuffer);//��������д��󣡣���
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPClient::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnSend(nErrorCode);
}


void TCPClient::OnConnect(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���

	CAsyncSocket::OnConnect(nErrorCode);
}
