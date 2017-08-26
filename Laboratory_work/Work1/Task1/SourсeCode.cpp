#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <codecvt>

int main() {

	setlocale(LC_ALL, "Russian");

	std::ifstream filein;
	filein.open("text.txt");
	if (!filein.is_open()) { std::cout << "File not found!" << std::endl; }

	std::wofstream fileout;
	fileout.open("Ltext.txt");
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	fileout.imbue(loc);

	std::string str;
	while (std::getline(filein, str)) {
		size_t len = mbstowcs(NULL, str.c_str(), 0) + 1;
		wchar_t* str0 = new wchar_t[len];
		int count = mbstowcs(str0, str.c_str(), len);
		fileout << str0;
		fileout << std::endl;
		delete[] str0;
	}

	filein.close();
	fileout.close();

	return 0;
}
