#pragma once

// UDPClient ÃüÁîÄ¿±ê

class UDPClient : public CAsyncSocket
{
public:
	int ri;
	char m_charEcho[256]="";
	//CString m_charEcho;
	UDPClient();
	virtual ~UDPClient();
	virtual void OnReceive(int nErrorCode);
};


