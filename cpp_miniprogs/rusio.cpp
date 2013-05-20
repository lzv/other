#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <locale>

int main() {

	std::locale current_locale(""); // возможно, для надежности будет лучше явно указать ru_RU.UTF8 
	std::locale::global(current_locale);
//	setlocale(LC_ALL, "ru_RU.UTF8"); //если раскомментировать эту строку, и закомментировать связанное с locale, тогда тоже русский будет отображаться верно, но кроме чтения из файла с помощью потоков. Поэтому способ с locale остается единственным. 

	//выводим символ 
	wchar_t ttest = L'п';
	std::wcout << ttest << std::endl;

	//выводим строку 
	std::wstring mystr = L"тестtest";
	std::wcout << L"длинна тестовой строки: " << mystr.length() << std::endl;
	std::wcout << L"тестовая строка: " << mystr << std::endl;

	//После вывода в wcout вывод в cout не работает. Так же не работает printf. Но проверим вывод обычной, не широкой, строки с помощью wprintf
	char my_simple_string[] = "проверка обычной строки";
	wchar_t my_w_string[] = L"проверка широкой строки";
	int tempvar = 15;
	wprintf(L"Проверка с wprintf: число %d, строка1 %s, строка2 %ls, число %d\n", tempvar, my_simple_string, my_w_string, tempvar);

	//для проверки ввода пишем смешанную строку, с русскими и английскими символами, без пробелов
	std::wcout << L"Введите строку без пробелов, для проверки ввода:" << std::endl;
	std::wstring myen;
	std::wcin >> myen;
	std::wcout << L"длинна введеной строки: " << myen.length() << std::endl;
	std::wcout << L"введеная строка: " << myen << std::endl;

	//чтение из файла и вывод в консоль 
	std::wifstream my_file ("./rusio.readme"); //можно добавить параметр std::ios_base::in, но необходимость в этом есть, если используется wfstream 
	if (my_file) {
		std::wstring fcontent;
		getline(my_file, fcontent);
		std::wcout << L"Длинна строки из текстового файла в формате UTF-8: " << fcontent.length() << std::endl;
		std::wcout << L"Содержимое строки: " << std::endl << fcontent << std::endl;
		my_file.close();
	} else {
		std::wcout << L"Ошибка: не удалось открыть текстовый файл в формате UTF-8. " << std::endl;
	}
	
	// другой способ. Длинна строки тут будет показана на 1 больше, чем в предыдущем способе, так как считается еще и конец строки \n 
	FILE* tf = fopen ("./rusio.readme", "rt");
	if (tf) {
		wchar_t fcontent[150];
		fgetws(fcontent, 150, tf); // безопасно, но первая строка может оказаться больше 150-и символов 
		std::wcout << L"Длинна строки из текстового файла в формате UTF-8: " << wcslen(fcontent) << std::endl;
		std::wcout << L"Содержимое строки: " << std::endl << fcontent << std::endl;
		fclose(tf);
	} else {
		std::wcout << L"Ошибка: не удалось открыть текстовый файл в формате UTF-8. " << std::endl;
	}

	return 0;
}
