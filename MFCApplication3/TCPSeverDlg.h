#pragma once
//#include "TCPSever.h"
#include "TCPSeverListen.h"
#include "afxwin.h"

// TCPSeverDlg �Ի���
//class TCPSever;
//class TCPSeverListen;
class TCPSeverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPSeverDlg)

public:
	TCPSeverDlg(CWnd* pParent = NULL);// ��׼���캯��
	virtual ~TCPSeverDlg();
	TCPSeverListen m_srvrSocket;
	//TCPSever m_srvrSocket2;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnlisten();
	CListBox m_MSGS;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
