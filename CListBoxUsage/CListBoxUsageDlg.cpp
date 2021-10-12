
// CListBoxUsageDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CListBoxUsage.h"
#include "CListBoxUsageDlg.h"
#include "afxdialogex.h"
#include <map>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum Month {
	Jan = 1, Feb, Marc, April, May, June, July, Aug, Sept, Oct, Nov, Dec
};

const std::map<Month, CString> monthStrings{
	{Jan, L"Január"},
	{Feb, L"Február"},
	{Marc, L"Március"},
	{April, L"Április"},
	{May, L"Május"},
	{June, L"Június"},
	{July, L"Július"},
	{Aug, L"Augusztus"},
	{Sept, L"Szeptember"},
	{Oct, L"Október"},
	{Nov, L"November"},
	{Dec, L"December"}
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCListBoxUsageDlg dialog



CCListBoxUsageDlg::CCListBoxUsageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLISTBOXUSAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCListBoxUsageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LST_AVAILABLE, m_listAvailable);
	DDX_Control(pDX, IDC_LST_TARGET, m_listTarget);
}

BEGIN_MESSAGE_MAP(CCListBoxUsageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CCListBoxUsageDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_REMOVE, &CCListBoxUsageDlg::OnBnClickedBtnRemove)
	ON_BN_CLICKED(IDC_BTN_REMOVEALL, &CCListBoxUsageDlg::OnBnClickedBtnRemoveall)
END_MESSAGE_MAP()


// CCListBoxUsageDlg message handlers

BOOL CCListBoxUsageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	int index = m_listAvailable.AddString(monthStrings.at(Jan));
	m_listAvailable.SetItemData(index, Jan);

	m_listAvailable.AddString(monthStrings.at(Feb));
	m_listAvailable.SetItemData(index, Feb);

	m_listAvailable.AddString(monthStrings.at(Marc));
	m_listAvailable.SetItemData(index, Marc);

	m_listAvailable.AddString(monthStrings.at(April));
	m_listAvailable.SetItemData(index, April);

	m_listAvailable.AddString(monthStrings.at(May));
	m_listAvailable.SetItemData(index, May);

	m_listAvailable.AddString(monthStrings.at(June));
	m_listAvailable.SetItemData(index, June);

	m_listAvailable.AddString(monthStrings.at(July));
	m_listAvailable.SetItemData(index, July);

	m_listAvailable.AddString(monthStrings.at(Aug));
	m_listAvailable.SetItemData(index, Aug);

	m_listAvailable.AddString(monthStrings.at(Sept));
	m_listAvailable.SetItemData(index, Sept);

	m_listAvailable.AddString(monthStrings.at(Oct));
	m_listAvailable.SetItemData(index, Oct);

	m_listAvailable.AddString(monthStrings.at(Nov));
	m_listAvailable.SetItemData(index, Nov);

	m_listAvailable.AddString(monthStrings.at(Dec));
	m_listAvailable.SetItemData(index, Dec);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCListBoxUsageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCListBoxUsageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCListBoxUsageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCListBoxUsageDlg::OnBnClickedBtnAdd()
{
	// TODO: Add your control notification handler code here
}


void CCListBoxUsageDlg::OnBnClickedBtnRemove()
{
	// TODO: Add your control notification handler code here
}


void CCListBoxUsageDlg::OnBnClickedBtnRemoveall()
{
	// TODO: Add your control notification handler code here
}
