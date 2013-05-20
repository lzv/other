#include <string>
#include <map>
#include <iostream>

using std::cout;
using std::wcout;
using std::endl;
using std::flush;
using std::string;
using std::wstring;
using std::map;

// Простой примитивный способ, только для русского, и на другом компьютере может не сработать. Но пока не разобрался с более сложным.

// Каждому широкому символу ставим в соответствие строку обычных символов. Делаем только для русских букв, так как остальные занимают 1 байт. 

map <wchar_t, string> w2stab;

void w2stab_init () {
	if (w2stab.size() == 0) {
		w2stab[L'А'] = string("А");
		w2stab[L'Б'] = string("Б");
		w2stab[L'В'] = string("В");
		w2stab[L'Г'] = string("Г");
		w2stab[L'Д'] = string("Д");
		w2stab[L'Е'] = string("Е");
		w2stab[L'Ё'] = string("Ё");
		w2stab[L'Ж'] = string("Ж");
		w2stab[L'З'] = string("З");
		w2stab[L'И'] = string("И");
		w2stab[L'Й'] = string("Й");
		w2stab[L'К'] = string("К");
		w2stab[L'Л'] = string("Л");
		w2stab[L'М'] = string("М");
		w2stab[L'Н'] = string("Н");
		w2stab[L'О'] = string("О");
		w2stab[L'П'] = string("П");
		w2stab[L'Р'] = string("Р");
		w2stab[L'С'] = string("С");
		w2stab[L'Т'] = string("Т");
		w2stab[L'У'] = string("У");
		w2stab[L'Ф'] = string("Ф");
		w2stab[L'Х'] = string("Х");
		w2stab[L'Ц'] = string("Ц");
		w2stab[L'Ч'] = string("Ч");
		w2stab[L'Ш'] = string("Ш");
		w2stab[L'Щ'] = string("Щ");
		w2stab[L'Ъ'] = string("Ъ");
		w2stab[L'Ы'] = string("Ы");
		w2stab[L'Ь'] = string("Ь");
		w2stab[L'Э'] = string("Э");
		w2stab[L'Ю'] = string("Ю");
		w2stab[L'Я'] = string("Я");
		w2stab[L'а'] = string("а");
		w2stab[L'б'] = string("б");
		w2stab[L'в'] = string("в");
		w2stab[L'г'] = string("г");
		w2stab[L'д'] = string("д");
		w2stab[L'е'] = string("е");
		w2stab[L'ё'] = string("ё");
		w2stab[L'ж'] = string("ж");
		w2stab[L'з'] = string("з");
		w2stab[L'и'] = string("и");
		w2stab[L'й'] = string("й");
		w2stab[L'к'] = string("к");
		w2stab[L'л'] = string("л");
		w2stab[L'м'] = string("м");
		w2stab[L'н'] = string("н");
		w2stab[L'о'] = string("о");
		w2stab[L'п'] = string("п");
		w2stab[L'р'] = string("р");
		w2stab[L'с'] = string("с");
		w2stab[L'т'] = string("т");
		w2stab[L'у'] = string("у");
		w2stab[L'ф'] = string("ф");
		w2stab[L'х'] = string("х");
		w2stab[L'ц'] = string("ц");
		w2stab[L'ч'] = string("ч");
		w2stab[L'ш'] = string("ш");
		w2stab[L'щ'] = string("щ");
		w2stab[L'ъ'] = string("ъ");
		w2stab[L'ы'] = string("ы");
		w2stab[L'ь'] = string("ь");
		w2stab[L'э'] = string("э");
		w2stab[L'ю'] = string("ю");
		w2stab[L'я'] = string("я");
	}
}

// Просто ищем широкий символ и берем соответствующую строку обычных символов. Символы по 1 байту можно преобразовать напрямую. 

string wstr2str (const wstring & str) {
	w2stab_init();
	string result;
	size_t i, len = str.length();
	map <wchar_t, string> :: const_iterator s, end = w2stab.end();
	for (i = 0; i < len; ++i) {
		s = w2stab.find(str[i]);
		if (s == end) result += static_cast<char>(str[i]);
		else result += s->second;
	}
	return result;
};

// Из обычных символов в широкие - не так просто, как наоборот. Подготовим пару байтов, которые в сумме будут обозначать русский символ. Хотя тут небольшое усложнение для универсальности (поддержка так же символов в 1 байт), возможно оно излишне. 

class char_pair {

	public:
		char first;
		char second;
		short int len;

		char_pair (const string & val) : first(0), second(0), len(0) {
			size_t val_len = val.length();
			if (val_len == 1) {
				second = val[0];
				len = 1;
			} else if (val_len > 1) {
				first = val[0];
				second = val[1];
				len = 2;
			}
		};
		bool operator == (const char_pair & val) const {
			return len == val.len and first == val.first and second == val.second;
		};
		bool operator < (const char_pair & val) const {
			return first < val.first or (first == val.first and second < val.second);
		};
		bool check_match (const string & val, size_t n) const {
			size_t val_len = val.length();
			return (len == 1 and n < val_len and first == 0 and second == val[n])
				or (len == 2 and (n + 1) < val_len and first == val[n] and second == val[n + 1]);
		};
};

map <char_pair, wchar_t> s2wtab;

void s2wtab_init () {
	if (s2wtab.size() == 0) {
		s2wtab[string("А")] = L'А';
		s2wtab[string("Б")] = L'Б';
		s2wtab[string("В")] = L'В';
		s2wtab[string("Г")] = L'Г';
		s2wtab[string("Д")] = L'Д';
		s2wtab[string("Е")] = L'Е';
		s2wtab[string("Ё")] = L'Ё';
		s2wtab[string("Ж")] = L'Ж';
		s2wtab[string("З")] = L'З';
		s2wtab[string("И")] = L'И';
		s2wtab[string("Й")] = L'Й';
		s2wtab[string("К")] = L'К';
		s2wtab[string("Л")] = L'Л';
		s2wtab[string("М")] = L'М';
		s2wtab[string("Н")] = L'Н';
		s2wtab[string("О")] = L'О';
		s2wtab[string("П")] = L'П';
		s2wtab[string("Р")] = L'Р';
		s2wtab[string("С")] = L'С';
		s2wtab[string("Т")] = L'Т';
		s2wtab[string("У")] = L'У';
		s2wtab[string("Ф")] = L'Ф';
		s2wtab[string("Х")] = L'Х';
		s2wtab[string("Ц")] = L'Ц';
		s2wtab[string("Ч")] = L'Ч';
		s2wtab[string("Ш")] = L'Ш';
		s2wtab[string("Щ")] = L'Щ';
		s2wtab[string("Ъ")] = L'Ъ';
		s2wtab[string("Ы")] = L'Ы';
		s2wtab[string("Ь")] = L'Ь';
		s2wtab[string("Э")] = L'Э';
		s2wtab[string("Ю")] = L'Ю';
		s2wtab[string("Я")] = L'Я';
		s2wtab[string("а")] = L'а';
		s2wtab[string("б")] = L'б';
		s2wtab[string("в")] = L'в';
		s2wtab[string("г")] = L'г';
		s2wtab[string("д")] = L'д';
		s2wtab[string("е")] = L'е';
		s2wtab[string("ё")] = L'ё';
		s2wtab[string("ж")] = L'ж';
		s2wtab[string("з")] = L'з';
		s2wtab[string("и")] = L'и';
		s2wtab[string("й")] = L'й';
		s2wtab[string("к")] = L'к';
		s2wtab[string("л")] = L'л';
		s2wtab[string("м")] = L'м';
		s2wtab[string("н")] = L'н';
		s2wtab[string("о")] = L'о';
		s2wtab[string("п")] = L'п';
		s2wtab[string("р")] = L'р';
		s2wtab[string("с")] = L'с';
		s2wtab[string("т")] = L'т';
		s2wtab[string("у")] = L'у';
		s2wtab[string("ф")] = L'ф';
		s2wtab[string("х")] = L'х';
		s2wtab[string("ц")] = L'ц';
		s2wtab[string("ч")] = L'ч';
		s2wtab[string("ш")] = L'ш';
		s2wtab[string("щ")] = L'щ';
		s2wtab[string("ъ")] = L'ъ';
		s2wtab[string("ы")] = L'ы';
		s2wtab[string("ь")] = L'ь';
		s2wtab[string("э")] = L'э';
		s2wtab[string("ю")] = L'ю';
		s2wtab[string("я")] = L'я';
	}
}

// Теперь, если в исходной строке найдется пара байтов, соответствующих русскому символу, берем широкий символ. Остальные символы в 1 байт, преобразовываем их напрямую. 

wstring str2wstr (const string & val) {
	s2wtab_init();
	wstring result;
	size_t i, len = val.length();
	map <char_pair, wchar_t> :: const_iterator tab_i, tab_begin = s2wtab.begin(), tab_end = s2wtab.end();
	bool was_finded;
	for (i = 0; i < len; ++i) {
		was_finded = false;
		for (tab_i = tab_begin; tab_i != tab_end; ++tab_i)
			if (tab_i->first.check_match(val, i)) {
				result += tab_i->second;
				if (tab_i->first.len == 2) ++i;
				was_finded = true;
				break;
			}
		if (!was_finded) result += static_cast<wchar_t>(val[i]);
	}
	return result;
}

int main () {

	std::locale::global(std::locale("")); // Настройка русского ввода-вывода. 
	std::ios::sync_with_stdio(false); // Позволяет одновременно использовать cout и wcout.

	wstring test1 = L"Моя тестовая строка";
	string test2 = wstr2str(test1);
	wstring test3 = str2wstr(test2);

	wcout << test1 << L" длинна " << test1.length() << endl << flush;
	cout << test2 << " длинна " << test2.length() << endl << flush;
	wcout << test3 << L" длинна " << test3.length() << endl << flush;

	return 0;
}
