/**
 * @file morevir.cpp
 * @brief 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针，vptr的大小
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
	virtual void fun() {};
	virtual void fun1() {};
	virtual void fun2() {};
	virtual void fun3() {};
};

int main() {
	cout << "sizeof(A) = " << sizeof(A) << endl;
	return 0;
}