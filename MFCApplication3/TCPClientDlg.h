#pragma once
#include "afxwin.h"
#include "AddrDlg.h"
#include "TCPClient.h"

// TCPClientDlg 对话框
// class TCPClient;
class TCPClientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPClientDlg)

public:
	int TryCount;
	TCPClient m_clientSocket;
	UINT m_szPort;
public: 
	char m_szServerAdr[256];

public:
	TCPClientDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TCPClientDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_MSG;
	CListBox m_MSGS;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedSend();
	// 端口号
	UINT m_Iport;
	// IP地址
	CString m_IPaddr;
};
