#pragma once


// UDPSeverDlg �Ի���

class UDPSeverDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UDPSeverDlg)

public:
	UDPSeverDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UDPSeverDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
