
// MsystemServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MsystemServer.h"
#include "MsystemServerDlg.h"
#include "afxdialogex.h"
#include"winsock2.h"
#include"stdio.h"
#include"fstream"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//SOCKET Socket;
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


// CMsystemServerDlg 对话框




CMsystemServerDlg::CMsystemServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMsystemServerDlg::IDD, pParent)
	/*, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))*/
	/*, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))*/
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMsystemServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_edit1);
	//  DDX_Text(pDX, IDC_EDIT2, m_edit2);
	//  DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//DDX_Text(pDX, IDC_EDIT4, m_edit1);
	//DDX_Text(pDX, IDC_EDIT5, m_edit2);
	//DDX_Text(pDX, IDC_EDIT6, m_edit3);
	//  DDX_Control(pDX, IDC_LIST1, m_listshow);
	//  DDX_Control(pDX, IDC_LIST2, m_listview);
	DDX_Control(pDX, IDC_STATIC_NOTIFY, m_notify);
}

BEGIN_MESSAGE_MAP(CMsystemServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CMsystemServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMsystemServerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMsystemServerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMsystemServerDlg 消息处理程序

BOOL CMsystemServerDlg::OnInitDialog()
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



	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMsystemServerDlg::windowshow()
{
	
}
void CMsystemServerDlg::read()
{
	ifstream fin("学生个数.txt",ios::in);
		fin>>num;
		fin.close();

		CStdioFile file;
		CString strTemp;
		file.Open("学生信息.txt",CFile::modeCreate|CFile::modeRead|CFile::modeNoTruncate,0);
		for (int i=0; file.ReadString(strTemp);i++)
		{
			mstu[i].mNum = strTemp.Left(strTemp.Find(" "));
			strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			mstu[i].mName  = strTemp.Left(strTemp.Find(" "));
			strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			mstu[i].mGender = strTemp.Left(strTemp.Find(" "));
			strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			mstu[i].mClass  = strTemp.Left(strTemp.Find(" "));
			strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			mstu[i].mGrade  = strTemp.Trim();
		}
		file.Close();
}
void CMsystemServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMsystemServerDlg::OnPaint()
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
HCURSOR CMsystemServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


DWORD WINAPI ConnectThread(LPVOID lpParameter);
DWORD WINAPI ConnectEvent(LPVOID lpParameter);
//SOCKET TempSock = SOCKET_ERROR;

DWORD WINAPI ConnectThread(LPVOID lpParameter)
{
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN serverInf;
	serverInf.sin_family = AF_INET;
	serverInf.sin_addr.s_addr = INADDR_ANY;
	serverInf.sin_port = htons(20000904);
	bind(ListenSocket, (SOCKADDR*)(&serverInf), sizeof(serverInf));
	listen(ListenSocket, 5);
	//SOCKET TempSock = SOCKET_ERROR;
	//while (TempSock == SOCKET_ERROR)
	//{
	//	//MessageBox(_T("等待客户端连接"));
	//	MessageBox(NULL, _T("等待客户端连接"), _T("提示"), NULL);
	//	
	//	TempSock = accept(Socket, NULL, NULL);
	//	/*if(nError!=WSAEWOULDBLOCK && nError!=0)
	//	{
	//	MessageBox(_T("客户端连接中断"));
	//	}*/
	//}

	CMsystemServerDlg*app = (CMsystemServerDlg*)AfxGetApp();
	while (1)
	{
		CString text;
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		HWND hwnd2 = ::FindWindow(NULL, _T("MsystemServer"));
		HWND hwnd = GetDlgItem(hwnd2,IDC_STATIC_NOTIFY);//获取控件句柄
		SetWindowText(hwnd, _T("\n等待客户端连接"));
		//MessageBox(NULL, _T("等待客户端连接"), _T("提示"), NULL);
		int tmp=*ClientSocket = accept(ListenSocket, 0, 0);
		//MessageBox(NULL, _T("一个客户端成功连接"), _T("提示"), NULL);
		//HANDLE hThread;
		CreateThread(NULL, 0, &ConnectEvent, ClientSocket, 0, NULL);
		//CloseHandle(hThread);
	}
	closesocket(ListenSocket);
	return 0;
}

DWORD WINAPI ConnectEvent(LPVOID lpParameter)
{
	SOCKET *ClientSocket = (SOCKET*)lpParameter;//获取主线程传递的套接字
	for (;;)
	{
		unsigned char check[125];
		memset(check, 0, 125);
		while (1)
		{
			int nRecv = recv(*ClientSocket, (char*)check, 125, 0);
			if (nRecv > 0)
				break;
		}
		//recv(Socket, (char*)check, 125, 0);


		if (check[0] == 0xF0)
		{
			char c_name[25];
			char c_key[25];
			CString m_name;
			CString m_key;

			memset(c_name, 0, 25);
			memset(c_key, 0, 25);
			memcpy(c_name, check + 5, 24);
			memcpy(c_key, check + 29, 24);

			m_name.Format("%s", c_name);
			m_key.Format("%s", c_key);

			CStdioFile file;
			CString strTemp;
			file.Open("登录信息.txt", CFile::modeCreate | CFile::modeRead | CFile::modeNoTruncate, 0);
			for (int i = 0; file.ReadString(strTemp); i++)
			{

				stu[i].Name = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				stu[i].Key = strTemp.Trim();
				//strTemp = strTemp.Mid(strTemp.Find(" ")+1);

			}
			file.Close();


			BOOL SFCZ = FALSE;
			for (int i = 0; i<2048; i++)
			{
				if (m_name == stu[i].Name)
				{

					if (m_key != stu[i].Key)
					{
						//密码不正确
						char*logincheck = "N";
						send(*ClientSocket, logincheck, strlen(logincheck), 0);

					}
					else
					{
						//登录成功
						char *logincheck = "Y";
						send(*ClientSocket, logincheck, strlen(logincheck), 0);

					}
					SFCZ = TRUE;
				}


			}
			if (!SFCZ)
			{//注册
				SFCZ = FALSE;
				char*logincheck = "R";
				send(*ClientSocket, logincheck, strlen(logincheck), 0);
			}
		}




		else if (check[0] == 0xF3)
		{//列表框信息的初始化
			ifstream fin("学生个数.txt", ios::in);
			fin >> num;
			fin.close();
			char number[4];
			itoa(num, number, 10);
			//memcpy(number,&num,4);
			send(*ClientSocket, number, 4, 0);

			CStdioFile file;
			CString strTemp;
			file.Open("学生信息.txt", CFile::modeCreate | CFile::modeRead | CFile::modeNoTruncate, 0);
			for (int i = 0; file.ReadString(strTemp); i++)

			{

				mstu[i].mNum = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mName = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mGender = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mClass = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mGrade = strTemp.Trim();
				//strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			}
			file.Close();


			char search[125];
			int len;
			::memset(search, 0, 125);


			for (int i = 0; i<num; i++)
			{
				search[0] = 0xF7;
				len = 120;
				memset(search, 0, 125);
				memcpy(search + 1, &len, 4);
				memcpy(search + 5, mstu[i].mNum.GetBuffer(mstu[i].mNum.GetLength()), 24);
				memcpy(search + 29, mstu[i].mName.GetBuffer(mstu[i].mName.GetLength()), 24);
				memcpy(search + 53, mstu[i].mGender.GetBuffer(mstu[i].mGender.GetLength()), 24);
				memcpy(search + 77, mstu[i].mClass.GetBuffer(mstu[i].mClass.GetLength()), 24);
				memcpy(search + 101, mstu[i].mGrade.GetBuffer(mstu[i].mGrade.GetLength()), 24);
				send(*ClientSocket, search, 125, 0);
			}
		}





		else if (check[0] == 0xF1)
		{
			//注册
			CString Rname;
			CString Rkey1;
			CString Rkey2;
			char mRname[25];
			char mRkey1[25];
			char mRkey2[25];
			memset(mRname, 0, 25);
			memset(mRkey1, 0, 25);
			memset(mRkey2, 0, 25);

			memcpy(mRname, check + 5, 24);
			memcpy(mRkey1, check + 29, 24);
			memcpy(mRkey2, check + 53, 24);

			Rname.Format("%s", mRname);
			Rkey1.Format("%s", mRkey1);
			Rkey2.Format("%s", mRkey2);

			CStdioFile file;
			CString strTemp;
			file.Open("登录信息.txt", CFile::modeCreate | CFile::modeRead | CFile::modeNoTruncate, 0);
			for (int i = 0; file.ReadString(strTemp); i++)
			{

				stu[i].Name = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				stu[i].Key = strTemp.Trim();
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

			}
			file.Close();

			BOOL SFCZ = FALSE;
			for (int i = 0; i<2048; i++)
			{
				if (Rname == stu[i].Name)
				{
					//用户名已存在
					char*registcheck = "N";
					send(*ClientSocket, registcheck, strlen(registcheck), 0);
					SFCZ = TRUE;
				}
			}
			if (!SFCZ)
			{
				//两次密码输入不一致
				SFCZ = FALSE;
				if (Rkey1 != Rkey2)
				{

					char *registcheck = "R";
					send(*ClientSocket, registcheck, strlen(registcheck), 0);

				}

				else
				{//注册成功

					char*registcheck = "Y";
					send(*ClientSocket, registcheck, strlen(registcheck), 0);

					CString saveXx = "";
					saveXx = Rname + " " + Rkey1 + "\r\n";
					CFile file;
					file.Open("登录信息.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL);
					file.SeekToEnd();
					file.Write(saveXx, strlen(saveXx));
					file.Close();
				}
			}
		}

		else if (check[0] == 0xF6)
		{//录入
			CString Num;
			CString Name;
			CString Gender;
			CString Class;
			CString Grade;
			char mNum[25];
			char mName[25];
			char mGender[25];
			char mClass[25];
			char mGrade[25];

			memset(mNum, 0, 24);
			memset(mName, 0, 24);
			memset(mGender, 0, 24);
			memset(mClass, 0, 24);
			memset(mGrade, 0, 24);

			memcpy(mNum, check + 5, 24);
			memcpy(mName, check + 29, 24);
			memcpy(mGender, check + 53, 24);
			memcpy(mClass, check + 77, 24);
			memcpy(mGrade, check + 101, 24);

			Num.Format("%s", mNum);
			Name.Format("%s", mName);
			Gender.Format("%s", mGender);
			Class.Format("%s", mClass);
			Grade.Format("%s", mGrade);


			ifstream fin("学生个数.txt", ios::in);
			fin >> num;
			fin.close();

			CStdioFile file;
			CString strTemp;
			file.Open("学生信息.txt", CFile::modeCreate | CFile::modeRead | CFile::modeNoTruncate, 0);
			for (int i = 0; file.ReadString(strTemp); i++)

			{

				mstu[i].mNum = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mName = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mGender = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mClass = strTemp.Left(strTemp.Find(" "));
				strTemp = strTemp.Mid(strTemp.Find(" ") + 1);

				mstu[i].mGrade = strTemp.Trim();
				//strTemp = strTemp.Mid(strTemp.Find(" ")+1);
			}
			file.Close();

			BOOL SFCZ = FALSE;
			for (int i = 0; i<num; i++)
			{
				if (Num == mstu[i].mNum)
				{
					SFCZ = FALSE;
					unsigned char mangecheck[6];
					::memset(mangecheck, 0, 6);
					int len;
					len = 0;
					mangecheck[0] = 0xA0;
					memcpy(mangecheck + 1, &len, 4);
					send(*ClientSocket, (char*)mangecheck, 6, 0);


					/*CString aaa;
					aaa = "";*/

				}
			}
			if (!SFCZ)
			{
				SFCZ = TRUE;
				unsigned char mangecheck[6];
				::memset(mangecheck, 0, 6);
				int len;
				len = 5;
				mangecheck[0] = 0xA1;
				memcpy(mangecheck + 1, &len, 4);
				send(*ClientSocket, (char*)mangecheck, 6, 0);

				num++;
				fstream out;
				out.open("学生个数.txt", ios::out);
				out << num;
				out.close();

				//send(Socket,num,24,0);

				CString saveXx = "";
				mstu[num].mNum = Num;
				mstu[num].mName = Name;
				mstu[num].mGender = Gender;
				mstu[num].mClass = Class;
				mstu[num].mGrade = Grade;
				saveXx = mstu[num].mNum + " " + mstu[num].mName + " " + mstu[num].mGender + " " + mstu[num].mClass + " " + mstu[num].mGrade + " " + "\r\n";
				CFile file;
				file.Open("学生信息.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL);
				file.SeekToEnd();
				file.Write(saveXx, strlen(saveXx));
				file.Close();
			}
		}

		else if (check[0] == 0xE0)
		{
			ifstream fin("学生个数.txt", ios::in);
			fin >> num;
			fin.close();
			char number[4];
			itoa(num, number, 10);
			//memcpy(number,&num,4);
			send(*ClientSocket, number, 4, 0);
		}

		else if (check[0] == 0xE1)
		{
			shutdown(*ClientSocket, SD_SEND);//断开套接字，只接受不能发送
			closesocket(*ClientSocket);//关闭套接字
			break;
			//free(ClientSocket);
			
		}

	}//for大循环	
		
	return 0;
}
void CMsystemServerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	HANDLE hThread;
	hThread = CreateThread(NULL, 0, ConnectThread, NULL, 0, NULL);
	CloseHandle(hThread);	
}


void CMsystemServerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxGetMainWnd()->SendMessage(WM_CLOSE);//退出程序
	
	//关闭当前窗口用DestroyWindow( );

	//关闭模式对话框用EndDialog(0);
}
