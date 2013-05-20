#include <iostream>

using std::cout;
using std::endl;

class aa {
	private:
		int a, b;
	public:
		aa (int i = 0, int j = 0) : a(i), b(j) {}
		aa (const aa & temp) {
			a = temp.a;
			b = temp.b;
			cout << "init aa" << endl;
		}
		virtual aa & operator= (const aa & temp) {
			this->a = temp.a;
			this->b = temp.b;
			cout << "eql aa" << endl;
			return *this;
		}
		virtual void print (bool show_endl = 1) {
			cout << a << " " << b;
			if (show_endl) cout << endl; 
		}
};

class bb : public aa {
	private:
		int c;
	public:
		bb (int i = 0, int j = 0, int k = 0) : aa(i, j), c(k) {}
		bb (const bb & temp) : aa(temp) {
			c = temp.c;
			cout << "inti bb" << endl;
		}
		bb & operator= (const bb & temp) {
			aa::operator= (temp);
			this->c = temp.c;
			cout << "eql bb" << endl;
			return *this;
		}
		void print () {
			aa::print(0);
			cout << " " << c << endl; 
		}
};

int main () {
	
	aa test(4, 7);
	bb test2 (5, 6, 7);

	aa ita = test;
	ita.print();
	bb itb = test2;
	itb.print();

	cout << endl;

	aa cta;
	cta = test;
	cta.print();

	bb ctb;
	ctb = test2;
	ctb.print();
	
	return 0;
}
