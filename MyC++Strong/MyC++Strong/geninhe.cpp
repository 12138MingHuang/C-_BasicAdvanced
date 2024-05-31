/**
 * @file geninhe.cpp
 * @brief 1.普通单继承，继承就是基类+派生类的大小(注意字节对齐)
 * 注意：类的数据成员按其生命顺序加入内存，与访问权限无关，只看声明顺序
 * 2.虚单继承，派生类继承了基类的vptr。
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
public:
	char a;
	int b;
};
class B : A {
public:
	short a;
	long b;
};
class C {
	A a;
	char c;
};

class A1 {
	virtual void fun() {};
};
class C1 :public A1 {
	virtual void fun2();
};

int main() {
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	cout << "sizeof(A1) = " << sizeof(A1) << endl;

	/**
	 * @brief 对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节
	 */
	cout << "sizeof(C1) = " << sizeof(C1) << endl;
	return 0;
}