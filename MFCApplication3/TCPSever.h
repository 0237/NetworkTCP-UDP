#pragma once

// TCPSever ����Ŀ��

class TCPSever : public CAsyncSocket
{
public:
	TCPSever();
	virtual ~TCPSever();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	// ��Ϣ����
	UINT m_nLength;
	// ��Ϣ������
	char m_szBuffer[4096];
};


