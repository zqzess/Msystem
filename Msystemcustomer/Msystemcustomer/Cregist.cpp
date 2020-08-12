// Cregist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Msystemcustomer.h"
#include "Cregist.h"
#include "afxdialogex.h"

extern SOCKET Socket;
// Cregist �Ի���

IMPLEMENT_DYNAMIC(Cregist, CDialogEx)

Cregist::Cregist(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cregist::IDD, pParent)
	, Rname(_T(""))
	, Rkey1(_T(""))
	, Rkey2(_T(""))
{

}

Cregist::~Cregist()
{
}

void Cregist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Rname);
	DDX_Text(pDX, IDC_EDIT2, Rkey1);
	DDX_Text(pDX, IDC_EDIT3, Rkey2);
}


BEGIN_MESSAGE_MAP(Cregist, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cregist::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cregist::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cregist ��Ϣ�������

void Cregist::clean()
{
	Rname="";
	Rkey1="";
	Rkey2="";
	UpdateData(false);
}
void Cregist::OnBnClickedButton1()
{

	UpdateData();
	if(Rname==""||Rkey1==""||Rkey2=="")
	{
		MessageBox(_T("����д����"));
		return;
	}

	unsigned char check[77];
	int len;
	::memset(check,0,77);
	check[0]=0xF1;
	len=72;
	memcpy(check+1,&len,4);
	memcpy(check+5,Rname.GetBuffer(Rname.GetLength()),24);
	memcpy(check+29,Rkey1.GetBuffer(Rkey1.GetLength()),24);
	memcpy(check+53,Rkey2.GetBuffer(Rkey2.GetLength()),24);
	send(Socket,(char*)check,77,0);
	
	
	CString mag;
	char registcheck[5];
	memset(registcheck,0,5);
	recv(Socket,registcheck,5,0);
	mag=registcheck;
	
	if(mag=="Y")
	{
		MessageBox(_T("ע��ɹ�"));
		clean();
	}
	 if(mag=="N")
	{
		MessageBox(_T("�û����Ѵ���"));
		clean();
		return;
	}
	 if(mag=="R")
	{
		MessageBox(_T("�����������벻һ��"));
		return;
	}
	



	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Cregist::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���

	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN)
		{
			OnBnClickedButton1();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void Cregist::OnBnClickedButton2()
{
	GetParent()->ShowWindow(SW_SHOW);
    OnCancel();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
