// ModelChosen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "ModelChosen.h"
#include "afxdialogex.h"
#include "MFCApplication3Dlg.h"
#include "UDPSeverDlg.h"

// ModelChosen �Ի���

IMPLEMENT_DYNAMIC(ModelChosen, CDialogEx)

ModelChosen::ModelChosen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ModelChosen::~ModelChosen()
{
}

void ModelChosen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ModelChosen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ModelChosen::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ModelChosen::OnBnClickedButton2)
END_MESSAGE_MAP()


// ModelChosen ��Ϣ�������


void ModelChosen::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


void ModelChosen::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMFCApplication3Dlg *tcpc = new CMFCApplication3Dlg;
	tcpc->Create(IDD_MFCAPPLICATION3_DIALOG, this);
	tcpc->ShowWindow(SW_SHOW);
	UDPSeverDlg *tcps = new UDPSeverDlg;
	tcps->Create(IDD_DIALOG2, this);
	tcps->ShowWindow(SW_SHOW);
}
