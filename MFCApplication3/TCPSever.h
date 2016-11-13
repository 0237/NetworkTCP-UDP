#pragma once
//#include "TCPSeverDlg.h"

// TCPSever 命令目标
//class TCPSeverDlg;
class TCPSever : public CAsyncSocket
{
public:
	TCPSever();
	virtual ~TCPSever();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//void SetParent(TCPSeverDlg* pDlg);
	// 消息长度
	UINT m_nLength;
	// 消息缓冲区
	char m_szBuffer[4096];
	// 窗口指针
	//TCPSeverDlg* m_pDlg;
	//日志信息
	CString m_MMS2;
	CString m_strMsg;
	bool NewRequest;
};


