#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <codecvt>
#include <tchar.h>

int main() {

	setlocale(LC_ALL, "Russian");

	std::wifstream filein;
	filein.open("text.txt");
	if (!filein.is_open()) { std::cout << "File not found!" << std::endl; }

	std::wofstream fileout;
	fileout.open("Received_Information.txt");
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

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
	int counterMax = 0;

	std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
	fileout.imbue(loc);

	fileout << _TEXT("Самые длинные слова: длина ") << max << _T('\n') << std::endl;
	for (auto length : text) {
		if (length.size() == max) {
			fileout << length << std::endl;
			++counterMax;
		}
	}
	fileout << _TEXT("\nИх количество: ") << counterMax << _T('\n');
	fileout << std::endl;

	int min = text.front().size();
	for (auto length : text) {
		if (length.size() < min)
			min = length.size();
	}
	int counterMin = 0;
	std::set<std::wstring> mini;
	fileout << _TEXT("Самые короткие слова : длина ") << min << _T('\n') << std::endl;
	for (auto length : text) {
		if (length.size() == min) {
			if (!mini.count(length)) {
				fileout << length << std::endl;
				mini.insert(length);
			}
			++counterMin;
		}
	}
	fileout << _TEXT("\nИх количество: ") << counterMin << std::endl;

	int size = 0;
	int del = 0;
	for (auto length : text)
	{
		size += length.size();
		++del;
	}
	fileout << _TEXT("\nСредняя длина слов: ") << size / del;

	filein.close();
	fileout.close();

	return 0;
}
