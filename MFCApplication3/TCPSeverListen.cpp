// TCPSeverListen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSeverListen.h"


// TCPSeverListen

TCPSeverListen::TCPSeverListen()
{
	m_MMS = _T("");
	m_MMS2 = _T("");
	//m_pDlg = NULL;
	NewRequest = false;
}

TCPSeverListen::~TCPSeverListen()
{
	//m_pDlg = NULL;
}


// TCPSeverListen ��Ա����
//void TCPSeverListen::SetParent(TCPSeverDlg* pDlg) {
//	m_pDlg = pDlg;
//}

void TCPSeverListen::OnAccept(int nErrorCode)
{
	// TODO: �ڴ����ר�ô����/����û���
	//�������������󣬵���Accept���� 
	NewRequest = true;
	m_MMS = _T("Connected!");
	TCPSever* pSocket = new TCPSever();
	//m_pDlg->m_MSGS.InsertString(0, _T("Listening..."));
	if (Accept(*pSocket))
	{
		pSocket->AsyncSelect(FD_READ);
		m_pSocket = pSocket;
		//SetTimer(1, 1000, NULL);
		//m_pSocket.NewRequest;
	}
	else
	{
		delete pSocket;
	}
	CAsyncSocket::OnAccept(nErrorCode);
}

//void TCPSeverListen::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//
//	//m_MSGS.AddString(m_srvrSocket.m_MMS);
//	if (m_pSocket->NewRequest)
//	{
//		m_MMS2 = m_pSocket->m_MMS2;
//		NewRequest = true;
//		m_pSocket->NewRequest = false;
//		//m_MSGS.AddString(m_pSocket.m_MMS);
//		//UpdateData(TRUE);
//	}
//	//CDialogEx::OnTimer(nIDEvent);
//}