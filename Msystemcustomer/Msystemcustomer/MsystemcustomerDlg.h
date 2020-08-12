
// MsystemcustomerDlg.h : 头文件
//

#pragma once


// CMsystemcustomerDlg 对话框
class CMsystemcustomerDlg : public CDialogEx
{
// 构造
public:
	CMsystemcustomerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MSYSTEMCUSTOMER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton2();
	CString Lname;
	CString Lkey;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
};
