#include <iostream>
#include <tchar.h>

int main() {
	char x = 'H';
	char* str = "ello world!";

	std::cout << x << str << std::endl;
	// кодировка ANCI 1 байт

	/*wchar_t y = 'H';
	wchar_t* str1 = L"ello world!!";

	std::wcout << y << str1 << std::endl;*/
	// кодировка Unicode 2 байт

	/*TCHAR y = 'H';
	TCHAR* str1 = L"ello world!!!";

	std::wcout << y << str1 << std::endl;*/
	// настройки проекта Unicode замена

	/*TCHAR x = 'H';
	TCHAR* str = _TEXT("ello world!!!!");

	std::cout << x << str << std::endl;*/
	// настройки проекта ANCI

	TCHAR y = 'H';
	TCHAR* str1 = _TEXT("ello world!!!!!");

	std::wcout << y << str1 << std::endl;
	// настройки проекта Unicode

	return 0;
}
