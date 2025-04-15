
// integrali1laba.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Cintegrali1labaApp:
// Сведения о реализации этого класса: integrali1laba.cpp
//

class Cintegrali1labaApp : public CWinApp
{
public:
	Cintegrali1labaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Cintegrali1labaApp theApp;
