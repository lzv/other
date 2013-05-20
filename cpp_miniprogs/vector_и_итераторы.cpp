#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main() {

	std::vector<int> test(10);
	for (int i = 0; i < 10; ++i) test[i] = i + 1;
	cout << "Размер массива: " << test.size() << endl;
	cout << "Элементы массива: ";
	for (std::vector<int>::iterator i = test.begin(); i != test.end(); ++i) cout << *i << " ";
	cout << endl;
	cout << "Элементы массива в обратном порядке: ";
	for (std::vector<int>::reverse_iterator i = test.rbegin(); i != test.rend(); ) cout << *i++ << " ";
	cout << endl;

	//У типа reverse_iterator есть операция base(), которая возвращает тип iterator, но на позицию дальше. Хотя это нелогично, но может быть использовано. Однако, что если элемент типа reverse_iterator указывает на последний в списке (первый в обратном порядке)? Можно ли вернуться из test.end() на шаг назад, вдруг он возвращает не адрес, а что то типа NULL?
	std::vector<int>::reverse_iterator rit = test.rbegin();
	std::vector<int>::iterator it = rit.base();
	cout << "Предположительно, последний элемент массива: " << *--it << endl;
	//Последний элемент отображается корректно, значит беспокойства были излишни. 
	
	return 0;
}
