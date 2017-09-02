#include <windows.h>
#include <tchar.h>
#include <string>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow) {
	
	return DialogBox(
		hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		NULL,
		DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {

	RECT rect;
	static HWND hWndBut1, hWndBut2;
	
	static int x = 0;
	std::wstring str = _TEXT("");

	switch (iMsg) {
	
	case WM_INITDIALOG:

		hWndBut1 = GetDlgItem(hWnd, ID_OK);
		hWndBut2 = GetDlgItem(hWnd, ID_CANCEL);

		GetClientRect(hWnd, &rect);

		return true;

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

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return true;
	}
	return false;
}
