#pragma once

// UDPClient ÃüÁîÄ¿±ê

class UDPClient : public CAsyncSocket
{
public:
	UDPClient();
	virtual ~UDPClient();
	virtual void OnReceive(int nErrorCode);
};


