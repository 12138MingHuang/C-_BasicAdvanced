/**
 * @file friend_func.cpp
 * @brief 友元函数
 * 友元提供了一种普通函数或者类成员函数访问另一个类的私有或保护成员的机制，也就是说有两种形式的友元
 * 友元函数:普通函数对一个访问某个类中的私有成员或保护成员
 * 友元类:类A中的成员函数可以访问类B中的私有成员或保护成员
 * 
 * 优点:提高了程序的运行效率
 * 缺点:破坏了类的封装性和数据的透明性
 * 
 * 总结:
 * 能访问私有成员
 * 破坏封装性
 * 友元关系不可传递
 * 友元关系的单向性
 * 友元声明形式及数量不受限制
 * @auther bin.zhang
 * @date 2024.05.17
 */

// 友元函数
// 在类声明的任何区域中声明，而定义则在类的外部
// friend <类型><友元函数名>(<参数表>);
// 注意，友元函数只是一个普通函数，并不是该类的类成员函数，他可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员

#include <iostream>

using namespace std;

class A {
	public:
		A(int _a) :a(_a) {};
		friend int geta(A& ca); //友元函数

	private:
		int a;
};

int geta(A& ca) {
	return ca.a;
}

int main() {
	A a(3);
	cout << geta(a) << endl;

	return 0;
}