// UPDClient.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UPDClient.h"


// UPDClient

CUDPClient::CUDPClient()
{
	m_pDlg = NULL;
}

CUDPClient::~CUDPClient()
{
	m_pDlg = NULL;
}


// UPDClient 成员函数

void CUDPClient::SetParent(CMFCApplication3Dlg* pDlg) 
{
	m_pDlg = pDlg;
}

void CUDPClient::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	//if (nErrorCode == 0)
	//	m_pDlg->OnReceive();//具体实现在对话框类中
	//CAsyncSocket::OnReceive(nErrorCode);
}
