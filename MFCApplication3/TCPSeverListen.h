#pragma once
#include "TCPSever.h"
// TCPSeverListen ����Ŀ��

class TCPSeverListen : public CAsyncSocket
{
public:
	TCPSeverListen();
	virtual ~TCPSeverListen();
	TCPSever* m_pSocket;
	virtual void OnAccept(int nErrorCode);
};


