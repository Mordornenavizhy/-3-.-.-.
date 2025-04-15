
// integrali1labaDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно Cintegrali1labaDlg
class Cintegrali1labaDlg : public CDialogEx
{
// Создание
public:
	Cintegrali1labaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTEGRALI1LABA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CStatic m_picControl;
	CBitmap m_bmp;
public:
	afx_msg void OnBnClickedKakoimetod();
	
	CComboBox kakoi_metod;
	int m_pMetodByCombo;
	afx_msg void OnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
};
