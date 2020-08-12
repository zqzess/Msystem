#pragma once


// Cregist 对话框

class Cregist : public CDialogEx
{
	DECLARE_DYNAMIC(Cregist)

public:
	Cregist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cregist();

// 对话框数据
	enum { IDD = IDD_Cregist };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
