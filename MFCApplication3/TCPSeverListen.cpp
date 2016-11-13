// TCPSeverListen.cpp : 实现文件
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


// TCPSeverListen 成员函数
//void TCPSeverListen::SetParent(TCPSeverDlg* pDlg) {
//	m_pDlg = pDlg;
//}

void TCPSeverListen::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	//监听到连接请求，调用Accept函数 
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
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
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