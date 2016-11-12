#pragma once

// TCPSever 命令目标

class TCPSever : public CAsyncSocket
{
public:
	TCPSever();
	virtual ~TCPSever();
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	// 消息长度
	UINT m_nLength;
	// 消息缓冲区
	char m_szBuffer[4096];
};


