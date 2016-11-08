// UDPSeverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPSeverDlg.h"
#include "afxdialogex.h"
#include "UDPSever.h"


// UDPSeverDlg 对话框

IMPLEMENT_DYNAMIC(UDPSeverDlg, CDialogEx)

UDPSeverDlg::UDPSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_strLog(_T(""))
	, testtttt(_T(""))
{
	
}

UDPSeverDlg::~UDPSeverDlg()
{
}

void UDPSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST2, m_strLog);
	DDX_Text(pDX, IDC_EDIT1, testtttt);
	DDX_Control(pDX, IDC_LIST2, m_ListBox_Content);
}


BEGIN_MESSAGE_MAP(UDPSeverDlg, CDialogEx)
//	ON_LBN_SELCHANGE(IDC_LIST2, &UDPSeverDlg::OnLbnSelchangeList2)
ON_LBN_SELCHANGE(IDC_LIST2, &UDPSeverDlg::OnLbnSelchangeList2)
//ON_EN_CHANGE(IDC_EDIT1, &UDPSeverDlg::OnEnChangeEdit1)
ON_WM_TIMER()
END_MESSAGE_MAP()


// UDPSeverDlg 消息处理程序

BOOL UDPSeverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO: 在此添加额外的初始化代码
	m_ListBox_Content.AddString(_T("127.0.0.1"));
	SetTimer(1, 1000, NULL);         //启动定时器
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



void UDPSeverDlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void UDPSeverDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UDPSever MySock;
	BOOL bFlag = MySock.Create(2000, SOCK_DGRAM, FD_READ);
	CTime t = CTime::GetCurrentTime();
	m_strLog = t.Format(_T("%Y/%m/%d %H:%M:%S:"));
	if (!bFlag)
	{
	m_strLog += "创建套接口错误!";
	}
	else
	{
	UINT r4 = 1242;
	char buffer[256];
	CString r3;
	int si = MySock.ReceiveFrom(buffer, sizeof(buffer), r3, r4);
	if (si == SOCKET_ERROR)
	{
	m_strLog += "接收请求错误!";
	}
	else
	{
	CString m_strMsg;
	m_strMsg = buffer;
	m_strLog += _T("收到IP=") + r3 + _T(" Port=") + (TCHAR)r4 + _T("请求【") + m_strMsg + _T("】,响应【");
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
	m_strMsg = t.Format(_T("错误请求"));
	}
	m_strLog += m_strMsg + _T("】\n");
	int ri = MySock.SendTo(m_strMsg, sizeof(m_strMsg), r4, r3);
	if (ri == SOCKET_ERROR)
	{
	m_strLog += "响应错误!\n";
	}
	}
	}
	m_ListBox_Content.AddString(m_strLog);
	UpdateData(TRUE);
	CDialogEx::OnTimer(nIDEvent);
}
