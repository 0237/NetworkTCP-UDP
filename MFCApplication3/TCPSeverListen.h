#pragma once
#include "TCPSever.h"
//#include "TCPSeverDlg.h"
// TCPSeverListen 命令目标

//class TCPSever;
//class TCPSeverDlg;
class TCPSeverListen : public CAsyncSocket
{
public:
	TCPSeverListen();
	virtual ~TCPSeverListen();
	TCPSever* m_pSocket;
	virtual void OnAccept(int nErrorCode);
	CString m_MMS;//监听信息
	CString m_MMS2;//日志信息
	//void SetParent(TCPSeverDlg* pDlg);
	// 窗口指针
	//TCPSeverDlg* m_pDlg;
	bool NewRequest;
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
};


