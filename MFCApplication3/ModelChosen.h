#pragma once


// ModelChosen 对话框

class ModelChosen : public CDialogEx
{
	DECLARE_DYNAMIC(ModelChosen)

public:
	ModelChosen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ModelChosen();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
