class aa {
	public:
		int val1;
		aa (int i = 0) : val1(i) {};
};

class bb : public virtual aa {
	public:
		int val2;
		bb (int i = 0) : val2(i) {};
};

class cc : private virtual aa {
	public:
		int val3;
		cc (int i = 0) : val3(i) {};
};

class dd : public bb, public cc {
	public:
		int val4;
		dd (int i = 0) : val4(i) {};
};


class ee : public aa {
	public:
		int val2;
		ee (int i = 0) : val2(i) {};
};

class ff : private aa {
	public:
		int val3;
		ff (int i = 0) : val3(i) {};
};

class jj : public ee, public ff {
	public:
		int val4;
		jj (int i = 0) : val4(i) {};
};

int main() {

	//Несмотря на то, что cc наследует от aa через private, у объекта класса dd доступен член класса aa::val1, так как dd наследует через public и от bb, который наследует через public от aa. Вывод: если в классовой иерархии член класса недоступен, если он недоступен по всем путям к нему. 
	dd test;
	test.val1 = 1;
	test.val2 = 2;
	test.val3 = 3;
	test.val4 = 4;

	//Если не использовать виртуальные базовые классы, то общий базовый класс будет доступен в памяти несколько раз, каждый раз со своим доступом. Например, так как ff наследует от aa через private, то у объекта класса jj нельзя получить ff::aa::val1, и в тоже время можно получить ee::aa::val1. При расскоментировании строки кода ниже, компилятор выдаст ошибку. 
	jj test2;
	test2.ee::val1 = 1;
//	test2.ff::val1 = 1;
	test2.val2 = 2;
	test2.val3 = 3;
	test2.val4 = 4;

	return 0;
}
