#pragma once


// ModelChosen �Ի���

class ModelChosen : public CDialogEx
{
	DECLARE_DYNAMIC(ModelChosen)

public:
	ModelChosen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ModelChosen();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
