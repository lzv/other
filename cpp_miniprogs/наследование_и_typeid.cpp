#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

class aa {
	public:
		virtual ~aa(){};
};
class bb : public aa {};

class cc {};
class dd : public cc {};

int main() {

	//Класс aa - полиморфный (с виртуальными функциями), поэтому тип *tc определяется верно. 
	aa * tc = new bb(); 
	cout << typeid(tc).name() << " " << typeid(*tc).name() << endl;
	delete tc;

	//Класс cc - не полиморфный, поэтому тип *td определяется как cc, хотя он объявлен как new dd. 
	cc * td = new dd();
	cout << typeid(td).name() << " " << typeid(*td).name() << endl;
	delete td; //Здесь возможна утечка памяти 
	
	return 0;
}
