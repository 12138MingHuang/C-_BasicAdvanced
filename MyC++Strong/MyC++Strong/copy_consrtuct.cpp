/**
 * @file copy_consrtuct.cpp
 * @brief 构造函数不能是虚函数
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
};

class Derived : public Base {
public:
	Derived() { cout << "Derived Created" << endl; }

	Derived(const Derived& rhs) { cout << "Derived Copied" << endl; }

	Derived& operator=(const Derived& rhs) { cout << "Derived Assigned" << endl; return *this; }

	~Derived() { cout << "Derived Destroyed" << endl; }
};

int main() {
	Derived s1;

	//Derived s2 = s1; 这行代码会触发复制构造函数的调用。
	//这是因为在这个语句中，对象 s1 是已经存在的 Derived 类型的对象，而 s2 是要通过将 s1 复制给它来初始化的。
	//默认情况下，编译器会生成一个默认的复制构造函数，该构造函数会逐个成员地复制一个对象的成员到另一个对象。
	//如果我们显式地定义了复制构造函数，编译器就不会再自动生成默认的复制构造函数了。
	Derived s2 = s1;


	Derived d1;
	Derived d2;

	d2 = d1; // 使用重载的赋值运算符将 d1 的值赋给 d2

	return 0;
}