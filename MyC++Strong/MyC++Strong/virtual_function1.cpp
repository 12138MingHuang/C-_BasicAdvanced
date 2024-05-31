/**
 * @file virtual_function1.cpp
 * @brief 虚函数可以被私有化
 * ptr无法访问私有函数，当然，把基类声明为public
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
	virtual void fun() { cout << "Base::fun()" << endl; }
};

class Derived : public Base {
private:
	void fun() { cout << "Derived::fun()" << endl; }
};

int main() {
	Base* ptr = new Derived();
	ptr->fun();

	return 0;
}

//Derived 类中的 fun() 函数而言，它确实是被声明为私有的。
//然而，在面向对象编程中，对于成员函数的访问权限，主要是在编译阶段进行检查的，而在运行时并不会对成员函数的访问权限进行检查。
//在这种情况下，尽管 fun() 函数在 Derived 类中是私有的，但在 Base 类中它被声明为虚函数，
//因此它仍然可以被 Base 类及其派生类中的成员函数调用。
//在运行时，通过 Base 类型的指针或引用调用 fun() 函数时，实际上是调用了 Derived 类中重写的 fun() 函数，
//因为它是根据指针或引用所指向对象的动态类型来决定调用哪个版本的虚函数。