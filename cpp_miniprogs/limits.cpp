#include <limits>
#include <iostream>

int main() {

	std::cout << "char байт " << sizeof(char) << ", максимум " << int(std::numeric_limits<char>::max()) << ", минимум " << int(std::numeric_limits<char>::min()) << std::endl;
	std::cout << "wchar_t байт " << sizeof(wchar_t) << ", максимум " << int(std::numeric_limits<wchar_t>::max()) << ", минимум " << int(std::numeric_limits<wchar_t>::min()) << std::endl;
	std::cout << "float байт " << sizeof(float) << ", максимум " << std::numeric_limits<float>::max() << ", минимум " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "double байт " << sizeof(double) << ", максимум " << std::numeric_limits<double>::max() << ", минимум " << std::numeric_limits<double>::min() << std::endl;
	std::cout << "int байт " << sizeof(int) << ", максимум " << std::numeric_limits<int>::max() << ", минимум " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "long int байт " << sizeof(long int) << ", максимум " << std::numeric_limits<long int>::max() << ", минимум " << std::numeric_limits<long int>::min() << std::endl;
	std::cout << "long long int байт " << sizeof(long long int) << ", максимум " << std::numeric_limits<long long int>::max() << ", минимум " << std::numeric_limits<long long int>::min() << std::endl;

	return 0;
}

