#include <iostream>

using std::cout;
using std::endl;

class aa {
	public:
		int val;
		aa (int i = 0) : val(i) {};
};

class bb : public aa {
	public:
		int val;
		bb (int i = 0) : val(i) {};
		int& get_paretn_val () {return aa::val;}
};

class cc : public aa {
};

class dd : public aa {
	public:
		int val;
		dd (int i = 0) : val(i) {};
		int& get_paretn_val () {return aa::val;}
};

class bbdd : public bb, public dd {
	public:
		int val;
		bbdd (int i = 0) : val(i) {};
};

int main() {

	//Если в классе-наследние прописан член класса с тем же именем, что и в родительском, то в памяти он сохраняется отдельно. Код ниже выведет 3 5
	bb test1;
	test1.val = 3;
	test1.aa::val = 5;
	cout << test1.val << " " << test1.aa::val << endl;

	//Но если из класса-наследника убрать этот член класса, то в памяти будет только член родительского класса. И хотя к нему можно обращаться cc::val, но по сути обращение идет к члену родительского класса. И код ниже выведет 5 5 5 
	cc test2;
	test2.val = 3;
	test2.cc::val = 4;
	test2.aa::val = 5;
	cout << test2.val << " " << test2.cc::val << " " << test2.aa::val << endl;

	//Так же члены класса с одинаковыми именами хранятся отдельно, если один класс выступает в качестве родительского несколько раз (не используются виртуальные базовые классы). Правда, что бы добраться до значений членов этого класса, нужно использовать ухищрение с get_paretn_val(). К сожалению, если написать test3.bb::aa::val, компилятор пожалуется на неоднозначность. Видимо, в квалиффикации :: он воспринимает только последниее имя класса.
	//Код ниже выведет 1 2 3 4 5 
	bbdd test3;
	test3.val = 1;
	test3.bb::val = 2;
	test3.dd::val = 3;
	test3.bb::get_paretn_val() = 4;
	test3.dd::get_paretn_val() = 5;
	cout << test3.val << " " << test3.bb::val << " " << test3.dd::val << " " << test3.bb::get_paretn_val() << " " << test3.dd::get_paretn_val() << endl;
//	test3.bb::aa::val = 4;
//	test3.dd::aa::val = 5;

	return 0;
}
