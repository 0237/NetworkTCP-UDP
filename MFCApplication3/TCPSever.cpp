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
	//m_pDlg = NULL;
	m_MMS2 = _T("");
	NewRequest = false;
}

TCPSever::~TCPSever()
{
	if (m_hSocket != INVALID_SOCKET)
		Close();
	//m_pDlg = NULL;
}


// TCPSever ��Ա����
//void TCPSever::SetParent(TCPSeverDlg* pDlg) {
//	m_pDlg = pDlg;
//}

void TCPSever::OnReceive(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	NewRequest = true;
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	CTime t = CTime::GetCurrentTime();
	m_MMS2 = t.Format(_T("%Y/%m/%d %H:%M:%S:"));
	m_strMsg = m_szBuffer;
	m_MMS2 += _T("�յ�����") + m_strMsg + _T("��,��Ӧ��");
	m_strMsg.MakeLower();
	if (m_strMsg == "date")
	{
		m_strMsg = t.Format(_T("%Y/%m/%d"));
	}
	else if (m_strMsg == "time")
	{
		m_strMsg = t.Format(_T("%H:%M:%S"));
	}
	else
	{
		m_strMsg = "��������";
	}
	m_MMS2 += m_strMsg + _T("��");
	int len = WideCharToMultiByte(CP_ACP, 0, m_strMsg, -1, NULL, 0, NULL, NULL);
	char *buffer = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, m_strMsg, -1, buffer, len, NULL, NULL);
	strcpy_s(m_szBuffer,buffer);
	AsyncSelect(FD_WRITE);
	CAsyncSocket::OnReceive(nErrorCode);
}


void TCPSever::OnSend(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	Send(m_szBuffer, sizeof(m_szBuffer), 0);
	CAsyncSocket::OnSend(nErrorCode);
}
