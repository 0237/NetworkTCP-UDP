#pragma once

// UPDClient ÃüÁîÄ¿±ê

class UPDClient : public CAsyncSocket
{
public:
	UPDClient();
	virtual ~UPDClient();
	virtual void OnReceive(int nErrorCode);
};


