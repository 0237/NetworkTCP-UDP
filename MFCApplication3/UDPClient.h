#pragma once

// UDPClient ����Ŀ��

class UDPClient : public CAsyncSocket
{
public:
	UDPClient();
	virtual ~UDPClient();
	virtual void OnReceive(int nErrorCode);
};


