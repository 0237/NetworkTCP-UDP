#pragma once


// TCPSeverDlg �Ի���

class TCPSeverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TCPSeverDlg)

public:
	TCPSeverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TCPSeverDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
