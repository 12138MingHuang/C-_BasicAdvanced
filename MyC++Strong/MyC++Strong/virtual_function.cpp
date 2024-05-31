/**
 * @file virtual_function.cpp
 * @brief 虚函数可以被私有化
 * 基类指针指向继承类对象，则调用继承类对象的函数
 * int main()必须声明位Base类的友元函数，否则编译失败
 * ptr无法访问私有函数，当然，把基类声明为public
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Derived;

class Base {
	private:
		virtual void fun() { cout << "Base::fun()" << endl; }
		friend int main();
};

class Derived : public Base {
	public:
		void fun() { cout << "Derived::fun()" << endl; }
};

int main() {
	Base* ptr = new Derived();
	ptr->fun();
	return 0;
}