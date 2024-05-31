/**
 * @file virnhe.cpp
 * @brief 虚继承
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
	virtual void fun() {};
};
class B {
	virtual void fun2() {};
};
class C : virtual public A, virtual public B {
public:
	virtual void fun3() {};
};

int main() {
	/**
	 * @brief 按理来说是16，但是根据编译器这里是32  派生类虚继承多个虚函数，会继承所有虚函数的vptr
	 */
	cout << "sizeof(C) = " << sizeof(C) << endl;
}