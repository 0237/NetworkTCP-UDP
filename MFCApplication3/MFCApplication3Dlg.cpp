
// MFCApplication3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "UPDClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 对话框



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, m_strServName(_T(""))
	, m_strServPort(0)
	, m_strMsg(_T(""))
	, m_strEcho(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_strServName);
	DDX_Text(pDX, IDC_EDIT2, m_strServPort);
	DDV_MinMaxInt(pDX, m_strServPort, 0, 65535);
	DDX_Text(pDX, IDC_EDIT1, m_strMsg);
	DDX_Text(pDX, IDC_EDIT3, m_strEcho);
	DDX_Control(pDX, IDC_BUTTON1, m_btnSend);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication3Dlg 消息处理程序

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	m_strServName = "127.0.0.1";
	m_strServPort = 1000;
	UpdateData(FALSE);
	m_sConnectSocket.SetParent(this);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//CDialogEx::OnOK();

	UpdateData(TRUE);
	//创建套接字,使用默认参数
	m_sConnectSocket.Create();
	//连接到服务器
	m_sConnectSocket.Connect(m_strServName, m_strServPort);
	
	//发送
	int nLen;//消息的长度
	int nSent;//被发送的消息的长度
	if (!m_strMsg.IsEmpty()) {
		nLen = m_strMsg.GetLength();
		nSent = m_sConnectSocket.Send(LPCTSTR(m_strMsg), nLen);//发送消息，返回实际发送的字节长度
		if (nSent != SOCKET_ERROR)//发送成功
		{
			m_strEcho = m_strMsg;
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox(_T("信息发送失败！"), MB_OK | MB_ICONSTOP);
		}
		m_strMsg.Empty();
		UpdateData(FALSE);
	}

	//接收
	char *pBuf = new char[1025];//数据接收缓冲区
	int nBufSize = 1024;//可接收的最大长度
	int nReceived;//接收的实际长度
	CString strReceived;

	//接收套接字中的服务器发来的消息
	nReceived = m_sConnectSocket.Receive(pBuf, nBufSize);
	if (nReceived != SOCKET_ERROR)//接收成功
	{
		pBuf[nReceived] = NULL;//结尾置为空
		strReceived = pBuf;
		m_strEcho = strReceived;//显示消息
		UpdateData(FALSE);
	}
	else
		AfxMessageBox(_T("信息接收失败！"), MB_OK | MB_ICONSTOP);
	m_sConnectSocket.Close();
}

void CMFCApplication3Dlg::OnReceive()
{
}