#pragma once

// UDPSever ÃüÁîÄ¿±ê

class UDPSever : public CAsyncSocket
{
public:
	UDPSever();
	virtual ~UDPSever();
	virtual void OnReceive(int nErrorCode);
};


