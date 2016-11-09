#pragma once

// UDPClient ÃüÁîÄ¿±ê

class UDPClient : public CAsyncSocket
{
public:
	int ri;
	char m_charEcho[256];
	bool Reviewed;
	UDPClient();
	virtual ~UDPClient();
	virtual void OnReceive(int nErrorCode);
};