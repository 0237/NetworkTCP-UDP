#pragma once
#include "TCPSever.h"
//#include "TCPSeverDlg.h"
// TCPSeverListen ����Ŀ��

//class TCPSever;
//class TCPSeverDlg;
class TCPSeverListen : public CAsyncSocket
{
public:
	TCPSeverListen();
	virtual ~TCPSeverListen();
	TCPSever* m_pSocket;
	virtual void OnAccept(int nErrorCode);
	CString m_MMS;//������Ϣ
	CString m_MMS2;//��־��Ϣ
	//void SetParent(TCPSeverDlg* pDlg);
	// ����ָ��
	//TCPSeverDlg* m_pDlg;
	bool NewRequest;
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
};


