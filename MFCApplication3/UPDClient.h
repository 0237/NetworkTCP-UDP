#pragma once
//#include "MFCApplication3Dlg.h"
// UPDClient 命令目标
class CMFCApplication3Dlg;
class CUDPClient : public CAsyncSocket
{
public:
	CUDPClient();
	virtual ~CUDPClient();
	virtual void OnReceive(int nErrorCode);
	void SetParent(CMFCApplication3Dlg * pDlg);
private:
	CMFCApplication3Dlg* m_pDlg;//对话框类指针变量
};


