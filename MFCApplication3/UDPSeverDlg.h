#pragma once
#include "afxwin.h"


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
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLbnSelchangeList2();
	CString m_strLog;
	afx_msg void OnLbnSelchangeList2();
//	afx_msg void OnEnChangeEdit1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString testtttt;
	CListBox m_ListBox_Content;
};
