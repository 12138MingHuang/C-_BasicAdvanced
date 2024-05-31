/**
 * @file virtual_inline.cpp
 * @brief 通常类成员函数都会被编译器考虑是否进行内联
 * 但通过基类指针或者引用调用的虚函数必定不能被内联
 * 当然，实体对象调用虚函数或者静态调用时可以被内敛，虚析构函数的静态调用也一定会被内联展开
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
	public:
		virtual void who() { cout << "I am Base\n"; }
};

class Derived : public Base {
	public:
		void who() { cout << "I am Derived\n"; }
};

int main() {
	Base b;
	b.who();

	Base* ptr = new Derived();
	ptr->who();

	return 0;
}