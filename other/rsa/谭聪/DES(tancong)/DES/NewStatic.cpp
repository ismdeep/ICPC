// NewStatic.cpp : implementation file
// Download by http://www.codefans.net

#include "stdafx.h"
#include "NewStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewStatic

CNewStatic::CNewStatic()
{
}

CNewStatic::~CNewStatic()
{
}


BEGIN_MESSAGE_MAP(CNewStatic, CStatic)
	//{{AFX_MSG_MAP(CNewStatic)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewStatic message handlers

void CNewStatic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	GetClientRect(&rc);
	CBrush brush, *pOldbrush;
	brush.CreateSolidBrush(RGB(236, 246, 255));
	pOldbrush=dc.SelectObject(&brush);
	dc.FillRect(&rc, &brush);
	dc.SelectObject(pOldbrush);

	CString text;
	GetWindowText(text);
	
	dc.SetBkMode(TRANSPARENT);
	dc.SelectObject(this->GetFont());
	dc.SetTextColor(RGB(0x00, 0x00, 0xff));
	dc.DrawText(text, rc, DT_SINGLELINE);
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
}
