
// MsystemServerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMsystemServerDlg �Ի���
class CMsystemServerDlg : public CDialogEx
{
// ����
public:
	CMsystemServerDlg(CWnd* pParent = NULL);
	void read();// ��׼���캯��
	void windowshow();

// �Ի�������
	enum { IDD = IDD_MSYSTEMSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

