#pragma once

// TCPClient ����Ŀ��

class TCPClient : public CAsyncSocket
{
public:
	TCPClient();
	virtual ~TCPClient();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	// �Ƿ�����
	BOOL m_bConnected;
	// ��Ϣ����
	UINT m_nLength;
	// ��Ϣ������
	char m_szBuffer[4096];
};


