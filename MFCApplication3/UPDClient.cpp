// UPDClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UPDClient.h"


// UPDClient

UPDClient::UPDClient()
{
	m_pDlg = NULL;
}

UPDClient::~UPDClient()
{
	m_pDlg = NULL;
}


// UPDClient 成员函数

void UPDClient::SetParent(CMFCApplication3Dlg* pDlg) 
{
	m_pDlg = pDlg;
}

void UPDClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnReceive();//具体实现在对话框类中
	//CAsyncSocket::OnReceive(nErrorCode);
}


void UPDClient::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void UPDClient::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (nErrorCode == 0)
		m_pDlg->OnConnect();
	//CAsyncSocket::OnConnect(nErrorCode);
}
