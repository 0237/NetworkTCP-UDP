#pragma once

// UDPSever ����Ŀ��

class UDPSever : public CAsyncSocket
{
public:
	UDPSever();
	virtual ~UDPSever();
	virtual void OnReceive(int nErrorCode);
};


