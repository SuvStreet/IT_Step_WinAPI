#include <windows.h>
#include <tchar.h>
#include <string>

#define ID_OK 101
#define ID_CANCEL 102

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow) {
	LPTSTR szClassName = _TEXT("MyWindowClass");
	LPTSTR szTitleName = _TEXT("My first window");

	// регистрация оконного класса
	WNDCLASSEX wndclass;
	//memset(&wndclass, 0, sizeof(wndclass));			// предворительное обнуление = ! выстовление параметров важных полей
	wndclass.cbSize = sizeof(wndclass);				// (!) размер структуры							[UINT]	  	cbSize
	wndclass.style = CS_HREDRAW | CS_VREDRAW;			// (!) стиль окна							[UINT]	  	style
	wndclass.lpfnWndProc = WndProc;					// (!) указатель на оконную функцию					[WNDPROC]	lpfnWndProc
	wndclass.cbClsExtra = 0;					// количество байт доп. инф. о классе					[int]	  	cbClsExtra
	wndclass.cbWndExtra = 0;					// к-во байт доп. инф. об окне						[int]		cbWndExtra
	wndclass.hInstance = hInstance;					// (!) дескриптор приложения						[HINSTANCE] 	hInstance
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);			// дескриптор курсора мыши						[HCURSOR]	hCursor
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// дескриптор пиктограммы						[HICON]	  	hIcon
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); 	// CreateSolidBrush(RGB(0, 0, 0)); // дескриптор кисти для фона 	[HBRUSH]	hbrBackground
	wndclass.lpszMenuName = NULL;					// имя меню								[LPCWSTR]	lpszMenuName
	wndclass.lpszClassName = szClassName;				// имя класса окна							[LPCWSTR]   	lpszClassName
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);		// дескриптор маленькой иконки						[HICON]	  	hIconSm

	if (!RegisterClassEx(&wndclass)) {
		MessageBox(NULL, _TEXT("1"), NULL, MB_OK | MB_ICONSTOP);
		return false;
	}

	// создание окна
	HWND hWnd = CreateWindowEx(
		WS_EX_TOPMOST,				// [DWORD]		dwExStyle
		szClassName,				// [LPSTR]		lpClassName
		_TEXT("My first window"),		// [LPSTR]		lpWindowName
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME,	// [DWORD]		dwStyle
		10, 10, 500, 500,			// [int]		X, Y, nWidth, nHeight,
		HWND_DESKTOP,				// [HWND]		hWndParent
		NULL,					// [HMENU]		hMenu
		hInstance,				// [HINSTANCE]		hInstance
		NULL);					// [LPVOID]		lpParam

	if (!hWnd) {

		// окно сообщений
		MessageBox(
			NULL,			// дескриптор родителя		[HWND]		hWnd
			_TEXT("2"),		// текст внутри окна		[LPCWSTR]	lpText
			NULL,			// заголовок окна		[LPCWSTR]	lpCaption
			MB_OK | MB_ICONSTOP);	// набор кнопок, тип окна	[UINT]		uType
		return false;
	}

	// показ окна
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	// цикл сообщений
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	RECT rect; 				// коордионаты рабочей области
	static HWND hWndBut1, hWndBut2; 	// дискрипторы кнопок

	static int x = 0;
	std::wstring str = _TEXT("");

	// обработка сообщений
	switch (iMsg) {

	case WM_CREATE:

		GetClientRect(hWnd, &rect);

		hWndBut1 = CreateWindowEx(
			WS_EX_TOPMOST,
			_TEXT("BUTTON"),
			_TEXT("OK"),              			// Текст на кнопке
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,    	// Стиль
			rect.right - 240, rect.bottom - 30, 130, 30,
			hWnd,					  	// Родитель
			(HMENU)ID_OK,		  			// ID кнопки
			GetModuleHandle(NULL),
			NULL);

		hWndBut2 = CreateWindowEx(
			WS_EX_TOPMOST,
			_TEXT("BUTTON"),
			_TEXT("Сancel"),          			// Текст на кнопке
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,    	// Стиль
			rect.right - 100, rect.bottom - 30, 100, 30,
			hWnd,					  	// Родитель
			(HMENU)ID_CANCEL,		  		// ID кнопки
			GetModuleHandle(NULL),
			NULL);
		break;

	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(hWndBut1, rect.right - 245, rect.bottom - 40, 130, 30, true);
		MoveWindow(hWndBut2, rect.right - 110, rect.bottom - 40, 100, 30, true);
		return true;

	case WM_COMMAND:

		if (LOWORD(wParam) == ID_OK){
			str = _TEXT("Нажато");
			str += _T(' ');
			++x;
			str += std::to_wstring(x);
			str += _TEXT(" раз(a)");
			SetWindowText(hWndBut1, str.c_str());
		}

		if (LOWORD(wParam) == ID_CANCEL) {
			DestroyWindow(hWnd);
			PostQuitMessage(0);
		}
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
	}
	return 0;
}
