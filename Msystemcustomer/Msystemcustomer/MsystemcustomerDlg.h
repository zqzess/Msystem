
// MsystemcustomerDlg.h : ͷ�ļ�
//

#pragma once


// CMsystemcustomerDlg �Ի���
class CMsystemcustomerDlg : public CDialogEx
{
// ����
public:
	CMsystemcustomerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MSYSTEMCUSTOMER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	
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
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton2();
	CString Lname;
	CString Lkey;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
};
