
// MFCApplication3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "UPDClient.h"

// CMFCApplication3Dlg �Ի���
class CMFCApplication3Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CUDPClient m_sConnectSocket;
	void OnReceive();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// ������IP��ַ
	CString m_strServName;
	// �������˿�
	int m_strServPort;
	// ��������
	CString m_strMsg;
	// ��������Ӧ
	CString m_strEcho;
	// ���Ͱ�ť
	CButton m_btnSend;
};
