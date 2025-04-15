
// integrali1labaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "integrali1laba.h"
#include "integrali1labaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CalculatingIntegral.h"


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно Cintegrali1labaDlg



Cintegrali1labaDlg::Cintegrali1labaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INTEGRALI1LABA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cintegrali1labaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, kakoi_metod);
}

BEGIN_MESSAGE_MAP(Cintegrali1labaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cintegrali1labaDlg::OnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cintegrali1labaDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// Обработчики сообщений Cintegrali1labaDlg

BOOL Cintegrali1labaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	CComboBox* combo = (CComboBox*)GetDlgItem(IDC_COMBO1);

	combo->AddString(L"Метод трапеции");
	combo->AddString(L"Метод средних прямоугольников");
	combo->AddString(L"Метод Симпсона");

	combo->SetCurSel(2);  
	m_pMetodByCombo = 1;

	CListCtrl* listIntegral = (CListCtrl*)GetDlgItem(IDC_LIST1);

	CRect rect;
	listIntegral->GetClientRect(rect);
	listIntegral->InsertColumn(0, L"Метод", 0, rect.Width() / 2);
	listIntegral->InsertColumn(1, L"Ответ", 0, rect.Width() / 2);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Cintegrali1labaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Cintegrali1labaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Cintegrali1labaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cintegrali1labaDlg::OnClickedButton1()
{
	CalculatingIntegral m;
	CString msg;
	CListCtrl* listIntegral = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int nitem;
	if (m_pMetodByCombo == 1) {
		msg.Format(L"%lf", m.metodTrapecii());
		nitem = listIntegral->InsertItem(0, L"Метод трапеции");
		listIntegral->SetItemText(nitem, 1, msg);
	}
	else if (m_pMetodByCombo == 2) {
		msg.Format(L"%lf", m.metodPrymoygolnikov());
		nitem = listIntegral->InsertItem(0, L"Метод средних прямоугольников");
		listIntegral->SetItemText(nitem, 1, msg);
	}
	if (m_pMetodByCombo == 3) {
		msg.Format(L"%lf", m.metodSimpsona());
		nitem = listIntegral->InsertItem(0, L"Метод Симпсона");
		listIntegral->SetItemText(nitem, 1, msg);
	}
	//AfxMessageBox(m_pMetodByCombo);
}

void Cintegrali1labaDlg::OnCbnSelchangeCombo1()
{
	CString msg;

	CComboBox* comboForMetod = (CComboBox*)GetDlgItem(IDC_COMBO1);

	int cursel = comboForMetod->GetCurSel();

	if (cursel != CB_ERR) {
		comboForMetod->GetLBText(cursel, msg);
	}

	if (msg == "Метод трапеции") {
		m_pMetodByCombo = 1;
	}
	else if (msg == "Метод средних прямоугольников") {
		m_pMetodByCombo = 2;
	}
	else if (msg == "Метод Симпсона") {
		m_pMetodByCombo = 3;
	}
}
