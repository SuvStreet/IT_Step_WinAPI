#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <codecvt>
#include <tchar.h>

int main() {
	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);

	std::wifstream filein;
	filein.open("karatkevich.txt");
	if (!filein.is_open()) { std::wcout << _TEXT("File not found!") << std::endl; }
	filein.imbue(loc);

	std::wofstream fileout;
	fileout.open("Received_Information.txt");
	if (!fileout.is_open()) { std::wcout << _TEXT("The file is not created!") << std::endl; }
	fileout.imbue(loc);

	std::vector<std::wstring> text;
	std::wstring temp;
	while (filein >> temp) {
		text.push_back(temp);
	}

	int max = 0;
	for (auto length : text) {
		if (length.size() > max)
			max = length.size();
	}

	fileout << _TEXT("Самыя доўгія словы: даўжыня ") << max << _T('\n') << std::endl;

	int counterMax = 0;
	for (auto length : text) {
		if (length.size() == max) {
			fileout << length << std::endl;
			++counterMax;
		}
	}
	fileout << _TEXT("\nІх колькасць: ") << counterMax << _T('\n');
	fileout << std::endl;

	int min = text.front().size();
	for (auto length : text) {
		if (length.size() < min)
			min = length.size();
	}
	fileout << _TEXT("Самыя кароткія словы : даўжыня ") << min << _T('\n') << std::endl;

	std::set<std::wstring> mini;
	int counterMin = 0;
	for (auto length : text) {
		if (length.size() == min) {
			if (!mini.count(length)) {
				fileout << length << std::endl;
				mini.insert(length);
			}
			++counterMin;
		}
	}
	fileout << _TEXT("\nІх колькасць: ") << counterMin << std::endl;

	int size = 0;
	int del = 0;
	for (auto length : text)
	{
		size += length.size();
		++del;
	}
	fileout << _TEXT("\nСярэдняя даўжыня слоў: ") << size / del;

	filein.close();
	fileout.close();

	return 0;
}
