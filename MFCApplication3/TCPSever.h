#pragma once
//#include "TCPSeverDlg.h"

// TCPSever ����Ŀ��
//class TCPSeverDlg;
class TCPSever : public CAsyncSocket
{
public:
	TCPSever();
	virtual ~TCPSever();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//void SetParent(TCPSeverDlg* pDlg);
	// ��Ϣ����
	UINT m_nLength;
	// ��Ϣ������
	char m_szBuffer[4096];
	// ����ָ��
	//TCPSeverDlg* m_pDlg;
	//��־��Ϣ
	CString m_MMS2;
	CString m_strMsg;
	bool NewRequest;
};


