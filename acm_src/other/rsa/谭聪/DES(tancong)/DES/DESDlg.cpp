// DESDlg.cpp : implementation file
// Download by http://www.codefans.net

#include "stdafx.h"
#include "DES.h"
#include "DESDlg.h"
#include "table.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESDlg dialog

CDESDlg::CDESDlg(CWnd* pParent /*=NULL*/)
: CDialog(CDESDlg::IDD, pParent)
{
	item=0;
	//{{AFX_DATA_INIT(CDESDlg)
	m_key = _T("");
	m_old = _T("");
	m_new = _T("");
	m_Last = _T("");
	m_oldbin = _T("");
	m_keybin = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDESDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDESDlg)
	DDX_Control(pDX, IDC_STATIC13, m_static13);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC8, m_static8);
	DDX_Control(pDX, IDC_STATIC9, m_static9);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
	DDX_Control(pDX, IDC_STATIC11, m_static11);
	DDX_Control(pDX, IDC_STATIC12, m_static12);
	DDX_Control(pDX, IDC_LIST1, m_listdata);
	DDX_Text(pDX, IDC_EDIT2, m_key);
	DDV_MaxChars(pDX, m_key, 8);
	DDX_Text(pDX, IDC_EDIT1, m_old);
	DDV_MaxChars(pDX, m_old, 8);
	DDX_Text(pDX, IDC_EDIT3, m_new);
	DDX_Text(pDX, IDC_EDIT4, m_Last);
	DDX_Text(pDX, IDC_EDIT5, m_oldbin);
	DDX_Text(pDX, IDC_EDIT6, m_keybin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDESDlg, CDialog)
//{{AFX_MSG_MAP(CDESDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_ENCRYPT, OnEncrypt)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_DECRYPT, OnDecrypt)
	ON_BN_CLICKED(IDS_ABOUTBOX, OnAboutbox)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(IDC_HELPDES, OnHelpdes)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDESDlg message handlers

BOOL CDESDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_old="learning";
	m_key="computer";
	GetDlgItem(IDC_DECRYPT)->EnableWindow(false);
	UpdateData(false);
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CenterWindow(GetDesktopWindow());
	::SendMessage(m_listdata.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE,
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES,
		LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_listdata.InsertColumn(0,"NO.",LVCFMT_LEFT,30);
	m_listdata.InsertColumn(1,"L0",LVCFMT_LEFT,40);
	m_listdata.InsertColumn(2,"R0",LVCFMT_LEFT,40);
	m_listdata.InsertColumn(3,"F函数值",LVCFMT_LEFT,60);
	m_listdata.InsertColumn(4,"密钥Ki",LVCFMT_LEFT,50);
	m_listdata.InsertColumn(5,"S盒",LVCFMT_LEFT,45);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDESDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDESDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		CClientDC dc(this);
		SetBkMode(dc.m_hDC, TRANSPARENT);
		//dc.TextOut(10, 10,  "请在此处输入明文:");
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDESDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDESDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int m_nCurrentSel = pNMListView->iItem;
	CString info;
	info.Format("%s", m_listdata.GetItemText(m_nCurrentSel,1));
	GetDlgItem(IDC_EDIT7)->SetWindowText(info);
	info.Format("%s", m_listdata.GetItemText(m_nCurrentSel,2));
	GetDlgItem(IDC_EDIT8)->SetWindowText(info);
	info.Format("%s", m_listdata.GetItemText(m_nCurrentSel,3));
	GetDlgItem(IDC_EDIT9)->SetWindowText(info);
	info.Format("%s", m_listdata.GetItemText(m_nCurrentSel,4));
	GetDlgItem(IDC_EDIT10)->SetWindowText(info);
	info.Format("%s", m_listdata.GetItemText(m_nCurrentSel,5));
	GetDlgItem(IDC_EDIT11)->SetWindowText(info);
	*pResult = 0;
}

void CDESDlg::SaveToList()
{
	//////////////////////////////////////////////////////////////////////////
	// 测试数据,将L, R, K, F, S数据存入列表
	CString str, strl, strr, strs, strf, strk;
	str="", strl="", strr="", 
	strk="", strs="", strf="";
	item=m_listdata.InsertItem(0xffff, "N", 1);
	str.Format("%d", item+1);
	m_listdata.SetItem(item, 0, 1, str, NULL, 0, 0, 0);
	// 上面将第第一列的值插入，显示为迭代次数
	for(int k=0; k<32; k++)	
	{
		str.Format("%d", L0[k]);
		strl+=str;
		str.Format("%d", R0[k]);
		strr+=str;
	}
	for( k=0; k<32; k++)	
	{
		str.Format("%d", frk[k]);
		strf+=str;
	}
	for( k=0; k<48; k++)
	{
		str.Format("%d", k1[k]);
		strk+=str;
	}
	for( k=0; k<8; k++)	
	{
		str.Format("%d_", stmp[k]);
		strs+=str;
	}
	m_listdata.SetItem(item, 1, 1, strl, NULL, 0, 0, 0);
	m_listdata.SetItem(item, 2, 1, strr, NULL, 0, 0, 0);
	m_listdata.SetItem(item, 3, 1, strf, NULL, 0, 0, 0);
	m_listdata.SetItem(item, 4, 1, strk, NULL, 0, 0, 0);
	m_listdata.SetItem(item, 5, 1, strs, NULL, 0, 0, 0);
}

void CDESDlg::OnAboutbox() 
{
	// TODO: Add your control notification handler code here
	//SendMessage(WM_SYSCOMMAND, (WPARAM) IDM_ABOUTBOX, (LPARAM)0);
	OnSysCommand(IDM_ABOUTBOX, 0);
}

void CDESDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	PlaySound("KEYCLICK",  AfxGetResourceHandle(),
		SND_RESOURCE|SND_ASYNC|SND_NODEFAULT);	
}

void CDESDlg::OnChangeEdit2() 
{
	PlaySound("KEYCLICK",  AfxGetResourceHandle(),
		SND_RESOURCE|SND_ASYNC|SND_NODEFAULT);		
}

BOOL CDESDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	CRect rc;
	GetClientRect(&rc);
	CBrush brush, *pOldbrush;
	brush.CreateSolidBrush(RGB(236, 246, 255));
	pOldbrush=pDC->SelectObject(&brush);
	pDC->FillRect(&rc, &brush);
	pDC->SelectObject(pOldbrush);
	return true;
}


void CDESDlg::OnHelpdes() 
{
	// TODO: Add your control notification handler code here
	
	CFile f; 
	char* pFileName = "des.chm";
	if( !f.Open( pFileName, CFile::modeCreate | CFile::modeWrite, NULL ) )
	{
		AfxMessageBox("Can not create file!");
		return ;
	}
	CString path = f.GetFilePath();
	HGLOBAL hRes;
	HRSRC hResInfo;
	//获取应用实例 
	HINSTANCE insApp = AfxGetInstanceHandle();
	//寻找EXE资源名
	hResInfo = FindResource(insApp,"des.chm","CHM");
	hRes = LoadResource(insApp,hResInfo );   // Load it
	DWORD dFileLength = SizeofResource( insApp, hResInfo );  //计算EXE文件大小
	f.WriteHuge((LPSTR)hRes,dFileLength);  //写入临时文件
	f.Close();
	HINSTANCE HINSsd = ShellExecute(NULL, "open",path, NULL, NULL, SW_SHOWNORMAL); //运行它.  
	//WinExec(path, SW_SHOW);
}

void CDESDlg::OnEncrypt() 
{
	m_listdata.DeleteAllItems();				//清空列表项目
	// TODO: Add your control notification handler code here
	UpdateData(true);
	//////////////////////////////////////////////////////////////////////////
	// 对输入的数据进行验证
	if(m_old.GetLength()!=8)
	{
		MessageBox("请输入8位明文", "友情提示");
		return;
	}
	if(m_key.GetLength()!=8)
	{
		MessageBox("请输入8位密文", "友情提示");
		return;
	}
	PlaySound("BEGIN",  AfxGetResourceHandle(),
		SND_RESOURCE|SND_ASYNC|SND_NODEFAULT);
	// char plaintext[8];
	// strcpy(plaintext,m_old);

	// 让解密按钮有效;
	GetDlgItem(IDC_DECRYPT)->EnableWindow(true);
	CString str;			// 该字符串存储ASCII码
	//////////////////////////////////////////////////////////////////////////
	// 初始化数组元素清0
	memset(L0, 0, 32);		
	memset(R0, 0, 32);
	
	memset(k1, 0, 48);
	memset(Kc0, 0, 28);	
	memset(Kd0, 0, 28);
	
	memset(re, 0, 48);
	memset(old, 0, 64);
	
	memset(s, 0, 48);
	//////////////////////////////////////////////////////////////////////////
	// 此处开始加密
	m_new="";		//先将密文清空	
	
	//////////////////////////////////////////////////////////////////////////
	/// 此处对明文处理，将对应的ASCII码转化为二进制	
	int flag=true;
	for(int i=0; i<8; i++)
	{
		char ch=m_old.GetAt(i);
		if(ch&0x80&&flag)
		{
			MessageBox("含有中文字符,加密错误不负责任!", "友情提示");
			flag=false;
			//return;
		}
		memset(tmp, 0, 8);
		for(int j=0; j<8; j++)
		{
			tmp[j]=(ch%2+2)%2;
			ch/=2;
		}
		for(j=7; j>=0; j--)
		{
			old[i*8+7-j]=tmp[j];
		}	
	}
	
	// 此处显示明文二进制
	m_oldbin="";
	for(i=0; i<64; i++)	
	{
		str.Format("%d", old[i]);
		m_oldbin+=str;
	}
	GetDlgItem(IDC_EDIT5)->SetWindowText(m_oldbin);
	
	for(i=0; i<32; i++)
	{	
		L0[i]=old[IP_Table[i]-1];			/// 获得L0共32位
		R0[i]=old[IP_Table[i+32]-1];		/// 获得R0共32位
	}
	
	//////////////////////////////////////////////////////////////////////////
	/// 此处开始对C0,D0处理
	for(i=0; i<8; i++)
	{
		memset(tmp, 0, 8);
		char ch=m_key.GetAt(i);
		if(ch&0x80)
		{
			MessageBox("含有中文字符,加密失败", "友情提示");
			return;
		}
		for(int j=0; j<8; j++)
		{
			tmp[j]=ch%2;
			ch/=2;
		}
		for(j=7; j>=0; j--)
		{
			k[i*8+7-j]=tmp[j];
		}
	}
	
	for(i=0; i<28; i++)
	{
		Kc0[i]=k[PC1_Table[i]-1];			/// 获得c0共28位
		Kd0[i]=k[PC1_Table[i+28]-1];		/// 获得d0共28位
	}
	
	//////////////////////////////////////////////////////////////////////////
	/// 此处开始16迭代算法
	isDecrypt=false;
	for(i=1; i<=16; i++)
	{
		CDESDlg::Iterate(i);
	}

	//////////////////////////////////////////////////////////////////////////
	// 最后一次生成的L16与R16调换位置装入密文字符串里
	int miwen[64];
	memset(miwen, 0, 64);
	// 逆初始置换，真它MOTHER的麻烦!
	int mitmp[64];
	memset(mitmp, 0, 64);
	for(i=0; i<32; i++)	
	{
		mitmp[i]=R0[i];
		mitmp[32+i]=L0[i];
		//交换L0,R0的值
		L0[i]=mitmp[i];
		R0[i]=mitmp[i+32];
	}

	for(i=0; i<64; i++)	
	{
		miwen[i]=mitmp[IPR_Table[i]-1];
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 将密文2进制存入m_keybin
	str="";
	m_keybin="";
	for(i=0; i<64; i++)	
	{
		str.Format("%d", miwen[i]);
		m_keybin+=str;
	}
	GetDlgItem(IDC_EDIT6)->SetWindowText(m_keybin);

	//////////////////////////////////////////////////////////////////////////
	// 将密文ASCII码放入编辑框里面去
	m_new="";
	for(i=0; i<8; i++)
	{
		int tmp=0;
		tmp+=miwen[8*i];
		for(int j=1; j<8; j++)
		{
			tmp*=2;
			tmp+=miwen[i*8+j];
		}
		str.Format("%c", tmp);
		m_new+=str;
	}
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_new);
}

void CDESDlg::OnDecrypt() 
{
	PlaySound("BEGIN",  AfxGetResourceHandle(),
		SND_RESOURCE|SND_ASYNC|SND_NODEFAULT);
	m_listdata.DeleteAllItems();		//清空列表项目
	//////////////////////////////////////////////////////////////////////////
	///  重新开始16次迭代算法
	isDecrypt=true;
	int i;
	for(i=16; i>=1; i--)
	{
		CDESDlg::Iterate(i);
	}

	//////////////////////////////////////////////////////////////////////////
	// 最后一次生成的L16<->R16调换位置
	int minwen[64];
	memset(minwen, 0, 64);
	// 逆初始置换，真它MOTHER的麻烦!
	int mintmp[64];
	memset(mintmp, 0, 64);

	for(i=0; i<32; i++)	
	{
		mintmp[i]=R0[i];
		mintmp[32+i]=L0[i];
	}
	
	for(i=0; i<64; i++)	
	{
		minwen[i]=mintmp[IPR_Table[i]-1];
	}

	//////////////////////////////////////////////////////////////////////////
	// 将密文ASCII码放入编辑框里面去
	CString str;
	m_Last="";
	for(i=0; i<8; i++)
	{
		int tmp=0;
		tmp+=minwen[8*i];
		for(int j=1; j<8; j++)
		{
			tmp*=2;
			tmp+=minwen[i*8+j];
		}
		str.Format("%c", tmp);
		m_Last+=str;
	}
	UpdateData(false);
	// 让解密按钮无效;
	GetDlgItem(IDC_DECRYPT)->EnableWindow(false);
}

void CDESDlg::Iterate(int numOfIteration)
{
	//////////////////////////////////////////////////////////////////////////
	/// 此处迭代生成子密钥ki
	int j=2;					// 移位次数
	if(	numOfIteration==1||numOfIteration==2||
		numOfIteration==9||numOfIteration==16)
	{
		j=1;
	}
	//////////////////////////////////////////////////////////////////////////
	//如果为解密，迭代移位的次序变换相反方向
	if(isDecrypt)
	{
		if(numOfIteration==16)
		{
			j=0;
		}
		else if(numOfIteration==15||numOfIteration==8||numOfIteration==1)
		{
			j=-1;
		}
		else
		{
			j=-2;
		}
	}
	
	int Kctmp[28], Kdtmp[28];	//  C0, D0中间传递数据
	memset(Kctmp, 0, 28);
	memset(Kdtmp, 0, 28);
	for(int i=0; i<28; i++)
	{
		Kctmp[i]=Kc0[(i+j+28)%28];
		Kdtmp[i]=Kd0[(i+j+28)%28];
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 将KCTMP， KDTMP的数据存入KC，KD中去
	for(i=0; i<28; i++)
	{
		Kc0[i]=Kctmp[i];
		Kd0[i]=Kdtmp[i];
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 生成子密钥Ki,存储到数组k1[48]中去
	int ktmp[56];
	memset(ktmp, 0, 56);
	for(i=0; i<28; i++)
	{
		ktmp[i]=Kc0[i];
		ktmp[i+28]=Kd0[i];
	}
	
	memset(k1, 0, 48);
	for(i=0; i<48; i++)
	{
		k1[i]=ktmp[PC2_Table[i]-1];
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 将Ri-1扩充成48位并与Ki相加并模2
	memset(re, 0, 48);
	for(i=0; i<48; i++)
	{	
		re[i]=(R0[E_Table[i]-1]+k1[i])%2;
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 	分成8组, 每组6位,有一个二维数组s[8][6]存储
	for(i=0; i<6; i++)
	{
		for(int j=0; j<8; j++)
		{
			s[j][i]=re[6*j+i];
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	// 以下通过8个S盒得到8个S数并存到S[8]中S_Box[8][4][16] 
	memset(s0, 0, 8);
	for(i=0; i<8; i++)
	{
		s0[i]=S_Box[i][s[i][5]+s[i][0]*2][s[i][1]*8+s[i][2]*4+s[i][3]*2+s[i][4]];
	}
	
	memset(stmp, 0, 8);
	memcpy(stmp, s0, sizeof(s0));
	//////////////////////////////////////////////////////////////////////////
	// 将8个数分别转换成2进制，再存入到frk[32]
	int f[32];
	memset(f, 0, 32);
	for(i=0; i<8; i++)
	{
		int tmp[4];
		memset(tmp, 0, 4);
		for(int j=0; j<4; j++)
		{
			tmp[j]=s0[i]%2;
			s0[i]/=2;
		}
		for(j=0; j<4; j++)
		{
			f[4*i+j]=tmp[3-j];
		}
	}
	
	// 经过P变换存入frk[32]
	for(i=0; i<32; i++)
	{
		frk[i]=f[P_Table[i]-1];
	}
	
	int Ltmp[32], Rtmp[32];
	memset(Ltmp, 0, 32);
	memset(Rtmp, 0, 32);
	
	for(i=0; i<32; i++)
	{
		Ltmp[i]=R0[i];
		Rtmp[i]=(L0[i]+frk[i])%2;
	}
	
	// 最后将数据存入L0，RO里面去
	for(i=0; i<32; i++)
	{
		L0[i]=Ltmp[i];
		R0[i]=Rtmp[i];
	}
	
	CDESDlg::SaveToList();
	//////////////////////////////////////////////////////////////////////////
	// 16次迭代算法结束，真累呀^_^
}

