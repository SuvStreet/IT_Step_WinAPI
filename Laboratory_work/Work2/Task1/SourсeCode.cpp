#include <windows.h>
#include <tchar.h>
#include <ctime>

#define ID_TIMER2 100
#define ID_TIMER3 101
#define ID_TIMER4 102

HWND hWnd1, hWnd2, hWnd3, hWnd4;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND Window(LPWSTR classname, LPWSTR title, HINSTANCE hInstance, int x, int y, HBRUSH hbrBackground) {
	WNDCLASSEX wndclass;
	memset(&wndclass, 0, sizeof(wndclass));
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hbrBackground = hbrBackground;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = classname;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wndclass)) {
		MessageBox(NULL, _TEXT("1"), NULL, MB_OK | MB_ICONSTOP);
		return false;
	}

	HWND hWnd = CreateWindowEx(
		WS_EX_TOPMOST,
		classname,
		title,
		WS_OVERLAPPEDWINDOW,
		x, y, 500, 500,
		HWND_DESKTOP,
		NULL,
		hInstance,
		NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("2"), NULL, MB_OK | MB_ICONSTOP);
		return false;
	}
	return hWnd;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow) {
	
	srand((unsigned)time(0));
	hWnd1 = Window(_TEXT("ClassName1"), _TEXT("Window1"), hInstance, 10, 10, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
	hWnd2 = Window(_TEXT("ClassName2"), _TEXT("Window2"), hInstance, 20, 20, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
	hWnd3 = Window(_TEXT("ClassName3"), _TEXT("Window3"), hInstance, 30, 30, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));
	hWnd4 = Window(_TEXT("ClassName4"), _TEXT("Window4"), hInstance, 40, 40, CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)));

	ShowWindow(hWnd1, 1);
	UpdateWindow(hWnd1);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	
	switch (iMsg) {
	
	case WM_CREATE:
		SetTimer(hWnd2, ID_TIMER2, 3000, NULL);
		break;

	case WM_TIMER:
		if (wParam == ID_TIMER2) {
			ShowWindow(hWnd2, SW_SHOWNORMAL);
			KillTimer(hWnd2, ID_TIMER2);
			SetTimer(hWnd3, ID_TIMER3, 3000, NULL);
		}
		else if (wParam == ID_TIMER3) {
			ShowWindow(hWnd3, SW_SHOWNORMAL);
			KillTimer(hWnd3, ID_TIMER3);
			SetTimer(hWnd4, ID_TIMER4, 3000, NULL);
		}
		else if (wParam == ID_TIMER4) {
			ShowWindow(hWnd4, SW_SHOWNORMAL);
			KillTimer(hWnd4, ID_TIMER4);
		}
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
	}
	return 0;
}
