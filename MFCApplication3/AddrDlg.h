#pragma once


// CAddrDlg �Ի���

class CAddrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddrDlg)

public:
	CAddrDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddrDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Addr };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Addr;
	int m_Port;
};
