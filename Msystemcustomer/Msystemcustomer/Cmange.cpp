// Cmange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Msystemcustomer.h"
#include "Cmange.h"
#include "afxdialogex.h"

extern SOCKET Socket;
// Cmange �Ի���

IMPLEMENT_DYNAMIC(Cmange, CDialogEx)

Cmange::Cmange(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmange::IDD, pParent)
	/*, Mname1(_T(""))
	, mName1(_T(""))*/
	, Mnum1(_T(""))
	, Mclass1(_T(""))
	, Mnum2(_T(""))
	, Mname2(_T(""))
	, Mgender(_T(""))
	, Mclass2(_T(""))
	, Mgrade(_T(""))
	, Mname1(_T(""))
{

}

Cmange::~Cmange()
{
}

void Cmange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, Mname1);
	//  DDX_Text(pDX, IDC_EDIT1, Mname1);
	//  DDX_Text(pDX, IDC_EDIT2, mName1);
	DDX_Text(pDX, IDC_EDIT1, Mnum1);
	DDX_Text(pDX, IDC_EDIT3, Mclass1);
	DDX_Text(pDX, IDC_EDIT4, Mnum2);
	DDX_Text(pDX, IDC_EDIT5, Mname2);
	DDX_Text(pDX, IDC_EDIT6, Mgender);
	DDX_Text(pDX, IDC_EDIT7, Mclass2);
	DDX_Text(pDX, IDC_EDIT8, Mgrade);
	DDX_Text(pDX, IDC_EDIT2, Mname1);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(Cmange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmange::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmange::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmange::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmange::OnBnClickedButton4)
END_MESSAGE_MAP()


// Cmange ��Ϣ�������


void Cmange::OnBnClickedButton3()
{

	GetParent()->ShowWindow(SW_SHOW);
    OnCancel();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Cmange::OnBnClickedButton1()
{
	unsigned char check[29];
	::memset(check,0,29);
	check[0]=0xE0;
	int len1=0;
	memcpy(check+1,&len1,4);
	send(Socket,(char*)check,29,0);

	char number[4];
	memset(number,0,4);
	recv(Socket,number,4,0);
	num= atoi(number);


	UpdateData();
	if(Mnum1==""&&Mname1==""&&Mclass1=="")
	{
		
	}
	
	if(Mnum1!=""&&Mname1==""&&Mclass1=="")
	{//��ѧ�Ų�ѯ
		//unsigned char check[29];
		//::memset(check,0,29);
		//check[0]=0xE0;
		//int len1=0;
		//memcpy(check+1,&len1,4);
		////memcpy(check+5,Mnum1.GetBuffer(Mnum1.GetLength()),24);
		//send(Socket,(char*)check,29,0);
		//
		//char number[4];
		//memset(number,0,4);
		//recv(Socket,number,4,0);
		//num= atoi(number);

		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mnum1==mstu[i].mNum)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("ѧ�Ų�����"));
			clean();
		}
	}

	if(Mnum1==""&&Mname1!=""&&Mclass1=="")
	{	
		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mname1==mstu[i].mName)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("����������"));
			clean();
		}
	}

	if(Mnum1==""&&Mname1==""&&Mclass1!="")
	{
		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mclass1==mstu[i].mClass)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("��ѯ��Ϣ������"));
			clean();
		}

	}


	if(Mnum1!=""&&Mname1!=""&&Mclass1=="")
	{
		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mnum1==mstu[i].mNum && Mname1==mstu[i].mName)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("��ѯ��Ϣ������"));
			clean();
		}

	}

	if(Mnum1!=""&&Mname1==""&&Mclass1!="")
	{
		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mnum1==mstu[i].mNum && Mclass1==mstu[i].mClass)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("��ѯ��Ϣ������"));
			clean();
		}
	}
	if(Mnum1==""&&Mname1!=""&&Mclass1!="")
	{
		m_list.DeleteAllItems();
		int Item;
		BOOL SFCZ=FALSE;
		for(int i=0;i<num;i++)
		{
			if(Mname1==mstu[i].mName && Mclass1==mstu[i].mClass)
			{
				Item = m_list.GetItemCount();  
				m_list.InsertItem(Item,mstu[i].mNum); 
				m_list.SetItemText(Item, 1, mstu[i].mName); 
				m_list.SetItemText(Item, 2, mstu[i].mGender); 
				m_list.SetItemText(Item, 3, mstu[i].mClass);
				m_list.SetItemText(Item, 4, mstu[i].mGrade);
				SFCZ=TRUE;
			}
		}
		if(!SFCZ)
		{
			SFCZ=FALSE;
			MessageBox(_T("��ѯ��Ϣ������"));
			clean();
		}

	}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Cmange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	unsigned char check[6];
	::memset(check,0,6);
	check[0]=0xF3;
	int len;
	len=0;
	memcpy(check+1,&len,4);
	send(Socket,(char*)check,6,0);

	//Sleep(2000);
	char number[4];
	memset(number,0,4);
	recv(Socket,number,4,0);
	num= atoi(number);

	char search[125];
	char mNum[25];
	char mName[25];
	char mGender[25];
	char mClass[25];
	char mGrade[25];

	//	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);
		m_list.InsertColumn(0,"ѧ��",0,70);
		m_list.InsertColumn(1,"����",0,100);
		m_list.InsertColumn(2,"�Ա�",0,100);
		m_list.InsertColumn(3,"�༶",0,70);
		m_list.InsertColumn(4,"�ɼ�",0,70);
		
		
	
		
	for(int i=0;i<num;i++)
	{
		memset(search,0,125);
		
		recv(Socket,search,125,0);

		memset(mNum,0,24);
		memset(mName,0,24);
		memset(mGender,0,24);
		memset(mClass,0,24);
		memset(mGrade,0,24);
	
		memcpy(mNum,search+5,24);
		memcpy(mName,search+29,24);
		memcpy(mGender,search+53,24);
		memcpy(mClass,search+77,24);
		memcpy(mGrade,search+101,24);

		mstu[i].mNum.Format("%s",mNum);
		mstu[i].mName.Format("%s",mName);
		mstu[i].mGender.Format("%s",mGender);
		mstu[i].mClass.Format("%s",mClass);
		mstu[i].mGrade.Format("%s",mGrade);
	}

		m_list.DeleteAllItems();
		int count=m_list.GetItemCount();
		for(int i=0;i<num;i++)
		{
			m_list.InsertItem(count,mstu[i].mNum); // ������
			m_list.SetItemText(count, 1, mstu[i].mName); 
			m_list.SetItemText(count, 2, mstu[i].mGender); 
			m_list.SetItemText(count, 3, mstu[i].mClass);
			m_list.SetItemText(count, 4, mstu[i].mGrade);
		}
	
		


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void Cmange::clean()
{
	Mnum1="";
	Mnum2="";
	Mname1="";
	Mname2="";
	Mclass1="";
	Mclass2="";
	Mgender="";
	Mgrade="";
	UpdateData(false);
}



void Cmange::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//¼��
	UpdateData();
	if(Mnum2==""||Mname2==""||Mgender==""||Mclass2==""||Mgrade=="")
	{
		MessageBox(_T("�뽫��Ϣ��д����"));
		return;
	}
	unsigned char check[125];
	int len2;
	::memset(check,0,125);
	len2=120;
	check[0]=0xF6;
	memcpy(check+1,&len2,4);
	memcpy(check+5,Mnum2.GetBuffer(Mnum2.GetLength()),24);
	memcpy(check+29,Mname2.GetBuffer(Mname2.GetLength()),24);
	memcpy(check+53,Mgender.GetBuffer(Mgender.GetLength()),24);
	memcpy(check+77,Mclass2.GetBuffer(Mclass2.GetLength()),24);
	memcpy(check+101,Mgrade.GetBuffer(Mgrade.GetLength()),24);
	send(Socket,(char*)check,125,0);
	
	CString mag;
	unsigned char mangecheck[64];
	memset(mangecheck,0,64);
	Sleep(1000);
	recv(Socket,(char*)mangecheck,64,0);
	
	
	if(mangecheck[0]==0xA1)
	{
		MessageBox(_T("¼��ɹ�"));
		UpdateData();
		num++;
		
		mstu[num].mNum=Mnum2;
		mstu[num].mName=Mname2;
		mstu[num].mGender=Mgender;
		mstu[num].mClass=Mclass2;
		mstu[num].mGrade=Mgrade;
		//m_list.DeleteAllItems();
		int count=m_list.GetItemCount();
		//for(int i=0;i<num;i++)
		//{
		//m_list.InsertItem(count,mstu[i].mNum); // ������
		//m_list.SetItemText(count, 1, mstu[i].mName); 
		//m_list.SetItemText(count, 2, mstu[i].mGender); 
		//m_list.SetItemText(count, 3, mstu[i].mClass);
		//m_list.SetItemText(count, 4, mstu[i].mGrade);
		//}
		m_list.InsertItem(count,Mnum2);
		m_list.SetItemText(count,1,Mname2);
		m_list.SetItemText(count,2,Mgender);
		m_list.SetItemText(count,3,Mclass2);
		m_list.SetItemText(count,4,Mgrade);
		
		clean();
		return;
	}
	else if(mangecheck[0]==0xA0)
	{
		MessageBox(_T("��ѧ����Ϣ�Ѵ���,�����ظ�¼��"));
		clean();
		return;
	}


}


void Cmange::OnBnClickedButton4()
{
	clean();
	m_list.DeleteAllItems();
	int Item;
	for(int i=0;i<num;i++)
	{	
		Item = m_list.GetItemCount();  
		m_list.InsertItem(Item,mstu[i].mNum); 
		m_list.SetItemText(Item, 1, mstu[i].mName); 
		m_list.SetItemText(Item, 2, mstu[i].mGender); 
		m_list.SetItemText(Item, 3, mstu[i].mClass);
		m_list.SetItemText(Item, 4, mstu[i].mGrade);	
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Cmange::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���


	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
