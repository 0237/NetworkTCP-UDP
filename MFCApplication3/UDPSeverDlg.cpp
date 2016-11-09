// UDPSeverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPSeverDlg.h"
#include "afxdialogex.h"
#include "UDPSever.h"


// UDPSeverDlg �Ի���

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
	DDX_Control(pDX, IDC_LIST2, m_ListBox_Content);
}


BEGIN_MESSAGE_MAP(UDPSeverDlg, CDialogEx)
//	ON_LBN_SELCHANGE(IDC_LIST2, &UDPSeverDlg::OnLbnSelchangeList2)
ON_LBN_SELCHANGE(IDC_LIST2, &UDPSeverDlg::OnLbnSelchangeList2)
//ON_EN_CHANGE(IDC_EDIT1, &UDPSeverDlg::OnEnChangeEdit1)
ON_WM_TIMER()
END_MESSAGE_MAP()


// UDPSeverDlg ��Ϣ�������

BOOL UDPSeverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	MySock.Create(2000, SOCK_DGRAM, FD_READ);
	//m_ListBox_Content.AddString(_T("127.0.0.1"));
	SetTimer(1, 1000, NULL);         //������ʱ��
	//UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}



void UDPSeverDlg::OnLbnSelchangeList2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void UDPSeverDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (MySock.NewRequest)
	{
		m_strLog = MySock.m_strLog;
		MySock.NewRequest = false;
		m_ListBox_Content.AddString(m_strLog);
		//UpdateData(TRUE);
	}
	CDialogEx::OnTimer(nIDEvent);
}
