#pragma once
#include "MFCApplication3Dlg.h"
// UPDClient ����Ŀ��
class CMFCApplication3Dlg;
class UPDClient : public CAsyncSocket
{
public:
	UPDClient();
	virtual ~UPDClient();
	virtual void OnReceive(int nErrorCode);
	void SetParent(CMFCApplication3Dlg * pDlg);
private:
	CMFCApplication3Dlg* m_pDlg;//�Ի�����ָ�����
public:
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
};


