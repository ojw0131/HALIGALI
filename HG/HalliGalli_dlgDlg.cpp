
// HalliGalli_dlgDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "HalliGalli_dlgDlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CHalliGalli_dlgDlg 대화 상자



CHalliGalli_dlgDlg::CHalliGalli_dlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HALLIGALLI_DLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHalliGalli_dlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHalliGalli_dlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BELLRING, &CHalliGalli_dlgDlg::OnBnClickedButtonBellring)
	ON_UPDATE_COMMAND_UI(ID_HIGH, &CHalliGalli_dlgDlg::OnUpdateHigh)
	ON_UPDATE_COMMAND_UI(ID_LOW, &CHalliGalli_dlgDlg::OnUpdateLow)
	ON_UPDATE_COMMAND_UI(ID_MIDDLE, &CHalliGalli_dlgDlg::OnUpdateMiddle)
	ON_COMMAND(ID_HIGH, &CHalliGalli_dlgDlg::OnHigh)
	ON_COMMAND(ID_LOW, &CHalliGalli_dlgDlg::OnLow)
	ON_COMMAND(ID_MIDDLE, &CHalliGalli_dlgDlg::OnMiddle)
	ON_COMMAND(ID_EXIT, &CHalliGalli_dlgDlg::OnExit)
END_MESSAGE_MAP()


// CHalliGalli_dlgDlg 메시지 처리기

BOOL CHalliGalli_dlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHalliGalli_dlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHalliGalli_dlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHalliGalli_dlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHalliGalli_dlgDlg::OnBnClickedButtonBellring()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PlaySound(_T("./res/bell.wav"), NULL, SND_ASYNC);
	CArrow dlg;
	
	if (dlg.DoModal() == IDOK)
	{
		
		AfxMessageBox(_T("성공"));
	}
	else {
		AfxMessageBox(_T("실패"));
	}

}


void CHalliGalli_dlgDlg::OnUpdateHigh(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck( m_level == 0);
	UpdateData(FALSE);


}


void CHalliGalli_dlgDlg::OnUpdateLow(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_level == 2);
	UpdateData(FALSE);
}


void CHalliGalli_dlgDlg::OnUpdateMiddle(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_level == 1);
	UpdateData(FALSE);
}


void CHalliGalli_dlgDlg::OnHigh()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 0;
	MessageBox(_T("상 눌림"));
	//Invalidate();

}


void CHalliGalli_dlgDlg::OnLow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 2;
//	Invalidate();

}


void CHalliGalli_dlgDlg::OnMiddle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 1;
	//Invalidate();

}


void CHalliGalli_dlgDlg::OnExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnCancel();
}
