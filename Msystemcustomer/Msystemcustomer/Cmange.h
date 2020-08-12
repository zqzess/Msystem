#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Cmange 对话框

class Cmange : public CDialogEx
{
	DECLARE_DYNAMIC(Cmange)

public:
	Cmange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cmange();

// 对话框数据
	enum { IDD = IDD_Cmange };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
//	CEdit Mname1;
//	CString Mname1;
//	CString mName1;
	CString Mnum1;
	CString Mclass1;
	CString Mnum2;
	CString Mname2;
	CString Mgender;
	CString Mclass2;
	CString Mgrade;
	CString Mname1;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	void clean();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton4();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
