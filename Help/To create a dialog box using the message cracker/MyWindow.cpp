#include "MyWindow.h"
#include <tchar.h>

MyWindow* MyWindow::ptr = NULL;

MyWindow::MyWindow() {
	ptr = this;
}

void MyWindow::Cls_OnClose(HWND hwnd) {
	DestroyWindow(hwnd);
	PostQuitMessage(0);
}

void MyWindow::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {
	if (id == IDOK) {
		MessageBox(hDialog, _TEXT("OK!"), _TEXT("Info"), MB_OK);
	}
	else if (id == IDCANCEL){
		MessageBox(hDialog, _TEXT("CANCEL!"), _TEXT("Info"), MB_OK);
		SendMessage(hDialog, WM_CLOSE, 0, 0);
	}
}

BOOL MyWindow::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) {
	hDialog = hwnd;
	hButOK = GetDlgItem(hDialog, IDOK);
	hButCancel = GetDlgItem(hDialog, IDCANCEL);
	return true;
}

BOOL CALLBACK MyWindow::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	
	switch (uMsg){
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return false;
}
