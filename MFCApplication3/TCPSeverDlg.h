#pragma once
#include "TCPSeverListen.h"

// TCPSeverDlg 对话框

class TCPSeverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPSeverDlg)

public:
	TCPSeverDlg(CWnd* pParent = NULL);// 标准构造函数
	virtual ~TCPSeverDlg();
	TCPSeverListen m_srvrSocket;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnlisten();
};
