#pragma once
#include "afxwin.h"


// TCPClientDlg �Ի���

class TCPClientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPClientDlg)

public:
	TCPClientDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TCPClientDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_MSG;
	CListBox m_MSGS;
};
