#pragma once

#include <Windows.h>
#include <WindowsX.h>
#include "resource.h"

class MyWindow
{
	static MyWindow* ptr;
	HWND hDialog;
	HWND hButOK, hButCancel;

	void Cls_OnClose(HWND);
	void Cls_OnCommand(HWND, int, HWND, UINT);
	BOOL Cls_OnInitDialog(HWND, HWND, LPARAM);

public:
	MyWindow();
	static BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
};
