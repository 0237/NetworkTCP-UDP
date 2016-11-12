// TCPSeverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSeverDlg.h"
#include "afxdialogex.h"


// TCPSeverDlg �Ի���

IMPLEMENT_DYNAMIC(TCPSeverDlg, CDialogEx)

TCPSeverDlg::TCPSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

TCPSeverDlg::~TCPSeverDlg()
{
}

void TCPSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TCPSeverDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BNListen, &TCPSeverDlg::OnBnClickedBnlisten)
END_MESSAGE_MAP()


// TCPSeverDlg ��Ϣ�������


void TCPSeverDlg::OnBnClickedBnlisten()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_srvrSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_srvrSocket.Create(1088, SOCK_STREAM, FD_ACCEPT);
		//�������Ķ˿ں�1088��д���ģ�
		if(!bFlag)
		{ 
			AfxMessageBox(_T("Socket Error!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	//���������ɹ����ȴ���������
	if (!m_srvrSocket.Listen(1))
	{ 
		int nErrorCode = m_srvrSocket.GetLastError();
		if (nErrorCode != WSAEWOULDBLOCK)
		{
			AfxMessageBox(_T("Socket Error!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
}
