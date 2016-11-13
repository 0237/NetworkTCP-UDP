// TCPClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPClientDlg.h"
#include "afxdialogex.h"
#include "TCPClient.h"


// TCPClientDlg �Ի���

IMPLEMENT_DYNAMIC(TCPClientDlg, CDialogEx)

TCPClientDlg::TCPClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_Iport(0)
	, m_IPaddr(_T(""))
{

}

TCPClientDlg::~TCPClientDlg()
{
}

void TCPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITMSG, m_MSG);
	DDX_Control(pDX, IDC_LISTMSG, m_MSGS);
	DDX_Text(pDX, IDC_EDITMSG3, m_Iport);
	DDV_MinMaxUInt(pDX, m_Iport, 0, 65535);
	DDX_Text(pDX, IDC_EDITMSG2, m_IPaddr);
}


BEGIN_MESSAGE_MAP(TCPClientDlg, CDialogEx)
	ON_BN_CLICKED(ID_Connect, &TCPClientDlg::OnBnClickedConnect)
	ON_WM_TIMER()
	ON_BN_CLICKED(ID_Exit, &TCPClientDlg::OnBnClickedExit)
	ON_BN_CLICKED(ID_Send, &TCPClientDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// TCPClientDlg ��Ϣ�������


void TCPClientDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_clientSocket.ShutDown(2);
	m_clientSocket.m_hSocket = INVALID_SOCKET;
	m_clientSocket.m_bConnected = FALSE;
	//CAddrDlg m_Dlg; 
	HWND hWnd = ::FindWindow(NULL, _T("TCPClient"));      //�õ��Ի���ľ��
	TCPClientDlg* pWnd = (TCPClientDlg*)FromHandle(hWnd); //�ɾ���õ��Ի���Ķ���ָ��                                            //����C***Dialog�еĺ���xxx();
	m_clientSocket.SetParent(pWnd);
	UpdateData(TRUE);
	if (m_Iport == 0 || m_IPaddr == _T(""))
	{
		//Ĭ�϶˿�1088
		m_Iport = 1088;
		//Ĭ��IP��ַ127.0.0.1
		m_IPaddr = _T("127.0.0.1");
	}
	UpdateData(FALSE);
	//if (m_Dlg.DoModal() == IDOK && !m_Dlg.m_Addr.IsEmpty()) 
	//{
		memcpy(m_szServerAdr, m_IPaddr.GetBuffer(), m_IPaddr.GetLength() + 1);
		//m_szPort = m_Dlg.m_Port; 
		//������ʱ����ÿ1�볢������һ�Σ�ֱ�����ϻ�TryCount>10
		SetTimer(1,1000,NULL); 
		TryCount = 0;
	//}
}


void TCPClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_clientSocket.m_bConnected) { KillTimer(1);return; }
	if (m_clientSocket.m_hSocket == INVALID_SOCKET) 
	{
		BOOL bFlag = m_clientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if (!bFlag) 
		{
			AfxMessageBox(_T("Socket Error!"));
			m_clientSocket.Close();
			PostMessage(0);
			return;
		}
	}
	int errorNUM = m_clientSocket.Connect(m_IPaddr, m_Iport);
	//if (errorNUM)
	//{
		TryCount++;
		if (TryCount >= 10) //|| m_clientSocket.m_bConnected
		{
			KillTimer(1);
			if (TryCount >= 10)
				AfxMessageBox(_T("Connect Failed!"));
			return;
		}
	//}
	CDialogEx::OnTimer(nIDEvent);
}


void TCPClientDlg::OnBnClickedExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ر�Socket
	m_clientSocket.ShutDown(2); 
	m_MSGS.InsertString(0, _T("Shutdown the socket"));
	//�رնԻ���
	//EndDialog(0);
}


void TCPClientDlg::OnBnClickedSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_clientSocket.m_bConnected)
	{
		CString buffer1;
		m_MSG.GetWindowText(buffer1);
		m_clientSocket.m_nLength = buffer1.GetLength();
		int len = WideCharToMultiByte(CP_ACP, 0, buffer1, -1, NULL, 0, NULL, NULL);
		char *buffer2 = new char[len + 1];
		WideCharToMultiByte(CP_ACP, 0, buffer1, -1, buffer2, len, NULL, NULL);
		strcpy_s(m_clientSocket.m_szBuffer, buffer2);
		m_clientSocket.AsyncSelect(FD_WRITE);
		m_MSG.SetWindowText(_T(""));
	}
}
