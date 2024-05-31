/**
 * @file c++_polyExamp.cpp
 * @brief C++的多态性
 * C++中会维护一张虚函数表，根据赋值兼容规则，我们知道父类的指针或者引用是可以指向子类对象的。
 * 如果一个父类的指针或者引用调用父类的虚函数则该父类的指针会在自己的虚函数表中查找自己的函数地址，如果该父类对象的指针或者引用
 * 指向子类的对象，而且该子类已经重写了父类的虚函数，则该指针会调用子类的以及重写的虚函数
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>

using namespace std;

class Base {
	public:
		virtual void f() {//虚函数
			cout << "Base::f()" << endl;
		}
};

class Derived : public Base {
	public:
		void f() {//重写父类的虚函数
					cout << "Derived::f()" << endl;
				}
};

int main() {
	Base b;
	Derived d;
	Base *pb = &b;
	pb->f();//Base::f()
	pb = &d;
	pb->f();//Derived::f()

	return 0;
}