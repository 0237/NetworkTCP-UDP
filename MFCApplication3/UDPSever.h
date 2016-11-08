#pragma once

// UDPSever ÃüÁîÄ¿±ê

class UDPSever : public CAsyncSocket
{
public:
	bool NewRequest;
	UINT r4;
	CString r3;
	int si;
	char m_charRequst[256] = "";
	CString m_strLog;
	CString m_strMsg;
	UDPSever();
	virtual ~UDPSever();
	virtual void OnReceive(int nErrorCode);
};


