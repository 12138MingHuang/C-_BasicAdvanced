/**
 * @file explicit.cpp
 * @brief explicit(显式)关键字
 * explicit修饰构造函数时，可以防止隐式转换和复制初始化
 * explicit修饰转换函数时，可以防止隐式转换，但按语境转换除外
 */

#include <iostream>

using namespace std;

struct A {
	A(int) {}
	operator bool() const { return true; }
};

struct B {
	explicit B(int) {}
	explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main() {
	//A(int) 强制初始化：强制用户在创建对象时提供一个 int 参数，确保对象的创建是带有某种明确的意图或初始值。
	//A() 无参数构造：允许对象在没有任何参数的情况下被创建，适合对象有合理默认状态的情况。
	// A a100;  // 错误：没有无参数构造函数
	A a100(1);  // 正确：必须提供参数

	A a1(1); // 直接初始化
	A a2 = 1; //复制初始化
	A a3{ 1 }; //直接列表初始化
	A a4 = { 1 }; //复制列表初始化
	A a5 = (A)1; //允许static_cast的显式转换
	
	doA(1); //允许从int到A的隐式转换

	if (a1); // 使用转换函数A::operator bool()的从A到bool的隐式转换
	bool a6(a1); // 使用转换函数A::operator bool()的从A到bool的隐式转换
	bool a7 = a1; // 使用转换函数A::operator bool()的从A到bool的隐式转换

	B b1(1); // 直接初始化
	// B b2 = 1; // error 被explicit修饰的构造函数的对象不可以复制初始化

	B b3{ 1 }; //直接列表初始化
	// B b4 = { 1 }; // error 被explicit修饰的构造函数对象不可以复制列表初始化

	B b5 = (B)1; // 允许static_cast的显式转换
	//doB(1); // error 被explicit修饰的构造函数的对象不可以从int到B的隐式转换

	if (b1); // 被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B 到 bool的按语境转换

	bool b6(b1); // 被 explicit 修饰转换函数 B::operator bool() 的对象可以从 B到 bool 的按语境转换
	// bool b7 = b1; // error 被 explicit 修饰转换函数
	// B::operator bool() 的对象不可以隐式转换
	bool b8 = static_cast<bool>(b1); // static_cast 进行直接初始化

	return 0;
}