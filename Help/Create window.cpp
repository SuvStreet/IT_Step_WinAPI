#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow) {
	LPTSTR szClassName = _TEXT("MyWindowClass");
	LPTSTR szTitleName = _TEXT("My first window");
	
	// регистрация оконного класса
	WNDCLASSEX wndclass;
	//memset(&wndclass, 0, sizeof(wndclass));						// предворительное обнуление = ! выстовление параметров важных полей
	wndclass.cbSize = sizeof(wndclass);								// (!) размер структуры												[UINT]	  	cbSize
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						// (!) стиль окна												  	[UINT]	  	style
	wndclass.lpfnWndProc = WndProc;									// (!) указатель на оконную функцию						      		[WNDPROC]	lpfnWndProc
	wndclass.cbClsExtra = 0;										// количество байт доп. инф. о классе							  	[int]	  	cbClsExtra
	wndclass.cbWndExtra = 0;										// к-во байт доп. инф. об окне								  		[int]		cbWndExtra
	wndclass.hInstance = hInstance;									// (!) дескриптор приложения									  	[HINSTANCE] hInstance
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);					// дескриптор курсора мыши									  		[HCURSOR]	hCursor
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// дескриптор пиктограммы										  	[HICON]	  	hIcon
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 	// CreateSolidBrush(RGB(0, 0, 0)); // дескриптор кисти для фона 	[HBRUSH]	hbrBackground
	wndclass.lpszMenuName = NULL;									// имя меню													  		[LPCWSTR]	lpszMenuName
	wndclass.lpszClassName = szClassName;							// имя класса окна											  		[LPCWSTR]   lpszClassName
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);				// дескриптор маленькой иконки								  		[HICON]	  	hIconSm

	if (!RegisterClassEx(&wndclass)) {
		MessageBox(NULL, L"1", L"!", MB_OK);
		return false;
	}
	
	// создание окна
	HWND hWnd = CreateWindowEx(		
		WS_EX_TOPMOST,				// [DWORD]		dwExStyle
		szClassName,				// [LPSTR]		lpClassName
		_TEXT("My first window"),	// [LPSTR]		lpWindowName
		WS_OVERLAPPEDWINDOW,		// [DWORD]		dwStyle
		10, 10, 500, 500,			// [int]		X, [int] Y, [int] nWidth, [int] nHeight,
		HWND_DESKTOP,				// [HWND]		hWndParent
		NULL,						// [HMENU]		hMenu
		hInstance,					// [HINSTANCE]	hInstance
		NULL);						// [LPVOID]		lpParam

	if (!hWnd) {

		// окно сообщений
		MessageBox(
			NULL,					// дескриптор родителя		[HWND]		hWnd
			L"2",					// текст внутри окна		[LPCWSTR]	lpText
			NULL,					// заголовок окна			[LPCWSTR]	lpCaption
			MB_OK | MB_ICONSTOP);	// набор кнопок, тип окна	[UINT]		uType
		return false;
	}

	// показ окна
	ShowWindow(hWnd, 1);
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
	HDC hdc;			// Если нужно рисовать  в окне
	PAINTSTRUCT ps;
	RECT rect;

	// обработка сообщений
	switch (iMsg) {
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rect);
			DrawText(hdc, _TEXT("Hello, Step"), -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, iMsg, wParam, lParam);
	}
	return 0;
}
