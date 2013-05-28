#if !defined(AFX_NEWSTATIC_H__F2977C0C_B378_4D66_B572_EC4282E805B4__INCLUDED_)
#define AFX_NEWSTATIC_H__F2977C0C_B378_4D66_B572_EC4282E805B4__INCLUDED_
// Download by http://www.codefans.net
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewStatic window

class CNewStatic : public CStatic
{
// Construction
public:
	CNewStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNewStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNewStatic)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSTATIC_H__F2977C0C_B378_4D66_B572_EC4282E805B4__INCLUDED_)
