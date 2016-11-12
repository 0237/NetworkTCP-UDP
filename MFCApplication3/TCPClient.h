#pragma once

// TCPClient 命令目标

class TCPClient : public CAsyncSocket
{
public:
	TCPClient();
	virtual ~TCPClient();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	// 是否连接
	BOOL m_bConnected;
	// 消息长度
	UINT m_nLength;
	// 消息缓冲区
	char m_szBuffer[4096];
};


