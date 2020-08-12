
// MsystemcustomerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Msystemcustomer.h"
#include "MsystemcustomerDlg.h"
#include "afxdialogex.h"

#include "stdio.h"
#include "iostream"
#include"Cmange.h"
#include"Cregist.h"
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SOCKET Socket;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMsystemcustomerDlg 对话框




CMsystemcustomerDlg::CMsystemcustomerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMsystemcustomerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Lname = _T("");
	Lkey = _T("");
}

void CMsystemcustomerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Lname);
	DDX_Text(pDX, IDC_EDIT2, Lkey);
}

BEGIN_MESSAGE_MAP(CMsystemcustomerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMsystemcustomerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMsystemcustomerDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMsystemcustomerDlg 消息处理程序

BOOL CMsystemcustomerDlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	struct hostent*host;
	host=gethostbyname("localhost");
	SOCKADDR_IN SockAddr;
	SockAddr.sin_port=htons(20000904);
	SockAddr.sin_family=AF_INET;
	SockAddr.sin_addr.s_addr=*((unsigned long*)host->h_addr);
	for(;;)
	{
	if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr))==0)
	{
		MessageBox(_T("服务器连接成功"));
		break;
	}
	else
	{
		MessageBox(_T("服务器连接失败"));
	}
	}
	
	
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMsystemcustomerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMsystemcustomerDlg::OnPaint()
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
HCURSOR CMsystemcustomerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CMsystemcustomerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN)
		{
			OnBnClickedButton2();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMsystemcustomerDlg::OnBnClickedButton2()
{
	//UpdateData();
	//SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);
	//SOCKADDR_IN addrSrv;
	//addrSrv.sin_addr.S_un.S_addr=inet_addr("192.168.1.1");
	//addrSrv.sin_family=AF_INET;
	//addrSrv.sin_port=htons(20000904);
	//connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//向服务器发出连接请求connect
	//char recvBuf[100];
	//recv(sockClient,recvBuf,100,0);
	//printf("%s\n",recvBuf);
	//send(sockClient,Lname,strlen(Lname),0);
	//send(sockClient,Lkey,strlen(Lkey),0);
	//closesocket(sockClient);
	//WSACleanup();
	/*CSocket sockclient;
	UpdateData();
	send(sockclient,Lname,strlen(Lname),0);*/
	// TODO: 在此添加控件通知处理程序代码

	UpdateData();
	if(Lname==""||Lkey=="")
	{
		MessageBox(_T("请填写完整"));
		return;
	}
	unsigned char check[53];
	int m_len;
	::memset(check,0,53);
	check[0] = 0xF0;
	//check[0] = 'Y';//表示的是登录协议，包头1字节
	m_len = 48;
	memcpy(check+1,&m_len,4);//数据包占4字节
	memcpy(check+5,Lname.GetBuffer(Lkey.GetLength()),24);
	memcpy(check+29,Lkey.GetBuffer(Lname.GetLength()),24);
	send(Socket,(char*)check,53,0);
	//send(Socket,Lname,strlen(Lkey),0);
	char logincheck[10];
	CString mag;

	memset(logincheck,0,10);

	recv(Socket,logincheck,10,0);
	mag=logincheck;
	if(mag=="Y")
	{
		MessageBox(_T("登录成功"));
		Lname="";
		Lkey="";
		UpdateData(false);
		Cmange dlg;
		dlg.DoModal();
	}
	 if(mag=="N")
	{
		MessageBox(_T("密码错误！"));
		Lname="";
		Lkey="";
		UpdateData(false);
		return;
	}
	 if(mag=="R")
	{
		MessageBox(_T("用户名不存在，请先注册！"));
		Lname="";
		Lkey="";
		UpdateData(false);
		Cregist dlg;
		dlg.DoModal();
	}
		
}



void CMsystemcustomerDlg::OnBnClickedButton1()
{


	unsigned char check[10];
	int m_len;
	::memset(check,0,10);
	check[0] = 0x11;
	m_len = 0;
	memcpy(check+1,&m_len,4);
	send(Socket,(char*)check,10,0);

	shutdown(Socket,SD_SEND);//断开套接字，只接受不能发送
	closesocket(Socket);//关闭套接字

	CDialogEx::OnCancel();
	CDialogEx::OnDestroy();
	CDialogEx::PostNcDestroy();


	// TODO: 在此添加控件通知处理程序代码


}


void CMsystemcustomerDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	unsigned char check[10];
	int m_len;
	::memset(check,0,10);
	check[0] = 0x11;
	m_len = 0;
	memcpy(check+1,&m_len,4);
	send(Socket,(char*)check,10,0);

	shutdown(Socket,SD_SEND);//断开套接字，只接受不能发送
	closesocket(Socket);//关闭套接字

	
	CDialogEx::OnClose();
	CDialogEx::OnDestroy();
	CDialogEx::PostNcDestroy();
}
