#pragma once


// Cregist �Ի���

class Cregist : public CDialogEx
{
	DECLARE_DYNAMIC(Cregist)

public:
	Cregist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cregist();

// �Ի�������
	enum { IDD = IDD_Cregist };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString Rname;
	CString Rkey1;
	CString Rkey2;
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void clean();
	afx_msg void OnBnClickedButton2();
};
