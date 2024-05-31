/**
 * @file static_error.cpp
 * @brief 静态函数不可以声明为虚函数，同时不能被const(常量成员函数)、volatile、const volatile修饰
 * 原因如下：
 * static成员函数不属于任何类对象或类实例，所以即使给此函数加上virtual关键字也没有任何意义。
 * 虚函数依靠vptr和vtable来处理。vptr是一个指针，在类的构造函数中创建生成，并且只能用this指针访问它，静态成员函数没有this指针，所以无法访问vptr。
 * @auther bin.zhang
 * @date 2024.04.30
 */

class Base {
	public:
		//virtual static void fun() {} //error 仅非静态成员函数可以是虚拟的
		//static void fun() const {} //error 静态成员函数上不允许使用类型限定符
};