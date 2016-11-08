// UDPSever.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "UDPSever.h"


// UDPSever

UDPSever::UDPSever()
{
	//strcpy(m_charRequst,0);
	//memset(m_charRequst, 0, sizeof(char));
	NewRequest = false;
}

UDPSever::~UDPSever()
{
}


// UDPSever 成员函数


void UDPSever::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	NewRequest = true;
	CTime t = CTime::GetCurrentTime();
	m_strLog = t.Format(_T("%Y/%m/%d %H:%M:%S:"));
	si = ReceiveFrom(m_charRequst, sizeof(m_charRequst), r3, r4);
	if (si == SOCKET_ERROR)
	{
		m_strLog += "接收请求错误!";
	}
	else
	{
		m_strMsg = m_charRequst;CString R4;R4.Format(_T("%d"), r4);;
		m_strLog += _T("收到IP=") + r3 + _T(" Port=") + R4 + _T("请求【") + m_strMsg + _T("】,响应【");
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
	}
	CAsyncSocket::OnReceive(nErrorCode);
}
