
// MsystemServerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMsystemServerDlg 对话框
class CMsystemServerDlg : public CDialogEx
{
// 构造
public:
	CMsystemServerDlg(CWnd* pParent = NULL);
	void read();// 标准构造函数
	void windowshow();

// 对话框数据
	enum { IDD = IDD_MSYSTEMSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
//	CString m_edit1;
//	CString m_edit2;
//	CString m_edit3;
	//CString m_edit1;
	//CString m_edit2;
	//CString m_edit3;
//	CListBox m_listshow;
	//afx_msg void OnBnClickedButton1();
//	CListCtrl m_listview;
	afx_msg void OnBnClickedButton2();
	CStatic m_notify;
};

