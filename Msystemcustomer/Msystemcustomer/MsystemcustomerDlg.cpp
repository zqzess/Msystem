
// MsystemcustomerDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMsystemcustomerDlg �Ի���




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


// CMsystemcustomerDlg ��Ϣ�������

BOOL CMsystemcustomerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
		MessageBox(_T("���������ӳɹ�"));
		break;
	}
	else
	{
		MessageBox(_T("����������ʧ��"));
	}
	}
	
	
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMsystemcustomerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMsystemcustomerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CMsystemcustomerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

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
	//connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//�������������������connect
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData();
	if(Lname==""||Lkey=="")
	{
		MessageBox(_T("����д����"));
		return;
	}
	unsigned char check[53];
	int m_len;
	::memset(check,0,53);
	check[0] = 0xF0;
	//check[0] = 'Y';//��ʾ���ǵ�¼Э�飬��ͷ1�ֽ�
	m_len = 48;
	memcpy(check+1,&m_len,4);//���ݰ�ռ4�ֽ�
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
		MessageBox(_T("��¼�ɹ�"));
		Lname="";
		Lkey="";
		UpdateData(false);
		Cmange dlg;
		dlg.DoModal();
	}
	 if(mag=="N")
	{
		MessageBox(_T("�������"));
		Lname="";
		Lkey="";
		UpdateData(false);
		return;
	}
	 if(mag=="R")
	{
		MessageBox(_T("�û��������ڣ�����ע�ᣡ"));
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

	shutdown(Socket,SD_SEND);//�Ͽ��׽��֣�ֻ���ܲ��ܷ���
	closesocket(Socket);//�ر��׽���

	CDialogEx::OnCancel();
	CDialogEx::OnDestroy();
	CDialogEx::PostNcDestroy();


	// TODO: �ڴ���ӿؼ�֪ͨ����������


}


void CMsystemcustomerDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	unsigned char check[10];
	int m_len;
	::memset(check,0,10);
	check[0] = 0x11;
	m_len = 0;
	memcpy(check+1,&m_len,4);
	send(Socket,(char*)check,10,0);

	shutdown(Socket,SD_SEND);//�Ͽ��׽��֣�ֻ���ܲ��ܷ���
	closesocket(Socket);//�ر��׽���

	
	CDialogEx::OnClose();
	CDialogEx::OnDestroy();
	CDialogEx::PostNcDestroy();
}
