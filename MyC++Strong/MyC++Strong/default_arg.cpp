/**
 * @file default_arg.cpp
 * @brief 虚函数中默认参数
 * 规则：默认参数是静态绑定的，而虚函数是动态绑定的。默认参数的使用需要看指针或者引用本身的类型，而不是对象的类型
 * @auther bin.zhang
 * @date 2024.04.30
 */

//默认参数是静态绑定的，而虚函数是动态绑定的。默认参数的使用需要看指针或者引用本身的类型，而不是对象的类型

#include <iostream>
using namespace std;

class Base {
	public:
		virtual void fun(int x = 10) { cout << "Base::fun(), x = " << x << endl; }
};

class Derived : public Base {
	public:
		virtual void fun(int x = 20) { cout << "Derived::fun(), x = " << x << endl; }
};

int main() {
	Derived d1;
	Base* bp = &d1;
	bp->fun();

	//对象 newBp 是通过派生类对象 d1 进行初始化的。这种初始化方式会触发对象切割（object slicing）。
	//对象切割意味着，当派生类对象被赋值给基类对象时，只会保留基类部分的内容，而派生类部分的内容将被丢弃。
	//换句话说，赋值操作将派生类对象“切割”为基类对象。
	//具体来说，在这个例子中，基类 Base 和派生类 Derived 各自有自己的成员函数 fun，但派生类 Derived 还有额外的成员函数（因为它是派生类）
	//当将派生类对象 d1 赋值给基类对象 newBp 时，只有基类 Base 部分的内容被保留在 newBp 中，而派生类 Derived 部分的内容被丢弃。
	Base newBp = d1;
	newBp.fun();
	return 0;
}