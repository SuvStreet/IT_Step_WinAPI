#include "MyWindow.h"
#include "resource.h"

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	MyWindow wnd;

	HWND hwnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, MyWindow::DlgProc);

	ShowWindow(hwnd, SW_NORMAL);

	MSG uMsg;
	while (GetMessage(&uMsg, 0, 0, 0)) {
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return uMsg.wParam;
}
