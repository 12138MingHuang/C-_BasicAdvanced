/**
 * @file interesting_facts3.cpp
 * @brief 如果我们不在派生类中覆盖基类中的纯虚函数，那么该派生类也将成为一个抽象类。
 * author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class Base {
	int x;
public:
	virtual void show() = 0; // 纯虚函数
	int getX() { return x; }
};

class Derived : public Base {
public:
	//void show() { cout << "Derived::show()" << endl; } // error 派生类没有实现基类中的纯虚函数，那么该派生类也将成为一个抽象类。
};

int main(void) {
	//Derived d; // error 抽象类不能创建对象
	return 0;
}