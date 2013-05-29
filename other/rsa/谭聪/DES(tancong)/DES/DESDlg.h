// DESDlg.h : header file
//

#if !defined(AFX_DESDLG_H__C2E19856_4E3B_42FF_A1D6_8BF1858B2E7C__INCLUDED_)
#define AFX_DESDLG_H__C2E19856_4E3B_42FF_A1D6_8BF1858B2E7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

# include "newstatic.h"
# include <mmsystem.h>
/////////////////////////////////////////////////////////////////////////////
// CDESDlg dialog

class CDESDlg : public CDialog
{
// Construction
public:
	void Iterate(int numOfIteration);
	CDESDlg(CWnd* pParent = NULL);	// standard constructor

public:
	void SaveToList();
	int old[64];			//	原明文
	int tmp[8];				//	临时存储字符的二进制
	int k[64];				//	64位的密钥
	int k1[48];				//  48位子密钥

	int L0[32], R0[32];		//	L0，R0初始明文
	int Ltmp[32], Rtmp[32]; //  L0，R0中间传递数据
	int Kc0[28], Kd0[28];	//  C0, D0初始密钥

	int re[48];				//  移位与Ki生成F

	int s[8][6];
	int s0[8];
	int frk[32];			//f函数的32位数与Ri做模2运算

	int stmp[8];				//将S0存储S盒的值
	int item;
	bool isDecrypt;
// Dialog Data
	//{{AFX_DATA(CDESDlg)
	enum { IDD = IDD_DES_DIALOG };
	CNewStatic	m_static13;
	CNewStatic	m_static1;
	CNewStatic	m_static2;
	CNewStatic	m_static3;
	CNewStatic	m_static4;
	CNewStatic	m_static5;
	CNewStatic	m_static6;
	CNewStatic	m_static7;
	CNewStatic	m_static8;
	CNewStatic	m_static9;
	CNewStatic	m_static10;
	CNewStatic	m_static11;
	CNewStatic	m_static12;
	CListCtrl	m_listdata;
	CString	m_key;
	CString	m_old;
	CString	m_new;
	CString	m_Last;
	CString	m_oldbin;
	CString	m_keybin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDESDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDESDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEncrypt();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDecrypt();
	afx_msg void OnAboutbox();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnHelpdes();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESDLG_H__C2E19856_4E3B_42FF_A1D6_8BF1858B2E7C__INCLUDED_)
