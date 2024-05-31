/**
 * @file friend_class.cpp
 * @brief 友元类
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


// 友元类
// 友元类的声明在该类的声明中，而实现在该类外
// friend class <友元类名>;
// 类B是类A的友元，那么类B可以直接访问A的私有成员

#include <iostream>

using namespace std;

class A {
	public:
		A(int _a) :a(_a) {};
		friend class B;

	private:
		int a;
};

class B {
	public:
		int getb(A ca) {
			return ca.a;
		}
};

int main() {
	A a(3);
	B b;
	cout << b.getb(a) << endl;

	return 0;
}



// 注意:
// 友元关系没有继承性 假如类B是类A的友元，类C继承类A，那么友元类B不能直接访问类C的私有成员或保护成员
// 友元关系没有传递性 假如类B是类A的友元，类C是类B的友元，那么类C不能直接访问类A的私有成员或保护成员，也就是"友元的友元"这种关系