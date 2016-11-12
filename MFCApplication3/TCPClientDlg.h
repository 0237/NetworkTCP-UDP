#pragma once
#include "afxwin.h"


// TCPClientDlg 对话框

class TCPClientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPClientDlg)

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
};
