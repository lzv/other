#include <iostream>

using std::cout;
using std::wcout;
using std::endl;

int main() {

//	setlocale(LC_ALL, "ru_RU.UTF8");
	std::locale current_locale("");
	std::locale::global(current_locale);
	
	std::ios::sync_with_stdio(false);

	/*
		В случае отсутствия sync_with_stdio(false), при любом методе локализации (setlocale или std::locale):
			если первым в программе выводится cout, то wcout выводит непонятные значения вместо русских букв
			если первым в программе выводится wcout, то cout не выводится вообще
		При использовании sync_with_stdio(false):
			В случае использования setlocale: выводится только cout (что бы ни выводилось первым)
			В случае использования std::locale: выводится все правильно (что бы ни выводилось первым) 
	*/

	cout << "Тест 1" << endl;
	wcout << L"Тест 1 L" << endl;
	cout << "Тест 1" << endl;
	wcout << L"Тест 1 L" << endl; //*/

/*	wcout << L"Тест 2 L" << endl;
	cout << "Тест 2" << endl;
	wcout << L"Тест 2 L" << endl;
	cout << "Тест 2" << endl; //*/

	return 0;
}
