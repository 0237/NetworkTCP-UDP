#pragma once

// UPDClient ����Ŀ��

class UPDClient : public CAsyncSocket
{
public:
	UPDClient();
	virtual ~UPDClient();
	virtual void OnReceive(int nErrorCode);
};


