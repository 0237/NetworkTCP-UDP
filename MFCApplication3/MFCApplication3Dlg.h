
// MFCApplication3Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "UPDClient.h"

// CMFCApplication3Dlg 对话框
class CMFCApplication3Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CUDPClient m_sConnectSocket;
	void OnReceive();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// 服务器IP地址
	CString m_strServName;
	// 服务器端口
	int m_strServPort;
	// 请求命令
	CString m_strMsg;
	// 服务器响应
	CString m_strEcho;
	// 发送按钮
	CButton m_btnSend;
};
