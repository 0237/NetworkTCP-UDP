#pragma once
//#include "TCPClientDlg.h"
// TCPClient ����Ŀ��
class TCPClientDlg;
class TCPClient : public CAsyncSocket
{
public:
	TCPClient();
	virtual ~TCPClient();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	void SetParent(TCPClientDlg* pDlg);
	// �Ƿ�����
	BOOL m_bConnected;
	// ��Ϣ����
	UINT m_nLength;
	// ��Ϣ������
	char m_szBuffer[4096];
	// ����ָ��
	TCPClientDlg* m_pDlg;
};


