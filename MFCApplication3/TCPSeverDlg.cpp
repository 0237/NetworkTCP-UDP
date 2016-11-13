// TCPSeverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "TCPSeverDlg.h"
#include "afxdialogex.h"


// TCPSeverDlg 对话框

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
	DDX_Control(pDX, IDC_LIST1, m_MSGS);
}


BEGIN_MESSAGE_MAP(TCPSeverDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BNListen, &TCPSeverDlg::OnBnClickedBnlisten)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// TCPSeverDlg 消息处理程序


void TCPSeverDlg::OnBnClickedBnlisten()
{
	// TODO: 在此添加控件通知处理程序代码
	//HWND hWnd = ::FindWindow(NULL, _T("TCPSever"));      //得到对话框的句柄
	//TCPSeverDlg* pWnd = (TCPSeverDlg*)FromHandle(hWnd); //由句柄得到对话框的对象指针
	if (m_srvrSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_srvrSocket.Create(1088, SOCK_STREAM, FD_ACCEPT);
		//服务器的端口号1088是写死的！
		if(!bFlag)
		{ 
			AfxMessageBox(_T("Socket Error!"));
			m_srvrSocket.Close();
			PostQuitMessage(0);
			return;
		}
	}
	//m_srvrSocket.SetParent(pWnd);
	//m_srvrSocket2.SetParent(pWnd);
	//“监听”成功，等待连接请求
	//pWnd->m_MSGS.InsertString(0, m_srvrSocket.m_MMS);
	//m_MSGS.AddString(_T("Listening...\n"));
	SetTimer(1, 1000, NULL);
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


void TCPSeverDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//m_MSGS.AddString(m_srvrSocket.m_MMS);
	if (m_srvrSocket.NewRequest)
	{
		CTime t = CTime::GetCurrentTime();
		//t.Format(_T("%Y/%m/%d %H:%M:%S:"));
		m_srvrSocket.NewRequest = false;
		m_MSGS.AddString(t.Format(_T("%Y/%m/%d %H:%M:%S:"))+m_srvrSocket.m_MMS);
		//UpdateData(TRUE);
	}
	if (m_srvrSocket.m_pSocket!=NULL&&m_srvrSocket.m_pSocket->NewRequest)
	{
		m_srvrSocket.m_pSocket->NewRequest = false;
		m_MSGS.AddString(m_srvrSocket.m_pSocket->m_MMS2);
		//UpdateData(TRUE);
	}
	CDialogEx::OnTimer(nIDEvent);
}
