#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>

namespace {
	std::unordered_set<char> symbol = { 'а',  'у', 'о', 'ы', 'и', 'э', 'я', 'ю',  'ё', 'е' };
}

bool func(char value) {
	return ::symbol.count(value);
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::ifstream filein;
	filein.open("Lopatin.txt");
	if (!filein.is_open()) { std::cout << "File not found!" << std::endl; }

	std::ofstream fileout;
	fileout.open("Result.txt");
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

	size_t size;
	std::cout << "Введите размер слова: ";
	std::cin >> size;
	std::cout << "Найденные слова:" << std::endl;

	int counter = 0;
	std::string temp;
	while (filein >> temp) {
		
		if (temp.size() == size) {
			counter = std::count_if(temp.begin(), temp.end(), func);
		}

		if (counter == 2) {
			std::cout << temp << std::endl;
			fileout << temp << std::endl;
			}
		counter = 0;
	}

	filein.close();
	fileout.close();
  
  return 0;
}
