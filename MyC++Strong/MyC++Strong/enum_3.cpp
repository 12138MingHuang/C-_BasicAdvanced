/**
 * @file enum_3.cpp
 * @brief 从初级到高级的enum那些事
 * 类中的枚举类型
 * 有时我们希望某些常量定义只在类中有效。由于#define定义的常量是全局的，不能达到目的，于是想到使用const修饰数据成员来实现。而const
 * 数据成员的确存在的，但其含义却不是我们所期望的。
 * const数据成员只在某个对象生存其期内是常量，而对于整个类而言却是可变的，因为类可以有多个对象，不同对象其const数据成员的值可以不同
 * 不能在类声明中初始化const成员。以下用法是错误的，因为类对象未被创建时，编译器不知道SIZE的值 是什么(C++11标准前)
 * @auther bin.zhang
 * @date 2024.05.19
 */

#include <iostream>
class A {
	const int SIZE = 100; // 错误,企图在类声明中初始化const成员
	//int array[SIZE]; // 错误,SIZE的值未知
};

// 正确应该在类的构造函数的初始化列表中进行
class B {
public:
	B(int size);
	const int SIZE;
};

B::B(int size) :SIZE(size) { //构造函数的定义

}

// 怎样才能建立在整个类中都恒定的常量
// 别指望const数据成员了，应该用类中的枚举变量来实现
class Person {
public:
	typedef enum {
		Boy = 0,
		Girl
	} SexType;
};

// 枚举常量不会占用对象的存储空间，它们编译时被全部求值
// 枚举常量的缺点：它的隐含数据类型是整数，其最大值有限，且不能表示浮点


int main() {
	B b1(100);
	B b2(200);

	std::cout << "B1 SIZE: " << b1.SIZE << std::endl;
	std::cout << "B2 SIZE: " << b2.SIZE << std::endl;

	Person::SexType sex = Person::Boy;
	std::cout << "Sex: " << sex << std::endl;

	return 0;
}