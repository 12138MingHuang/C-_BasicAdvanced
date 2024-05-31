/**
 * @file abstract.cpp
 * @brief 纯虚函数：没有函数体的虚函数
 * 抽象类中：在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能调用纯虚函数
 * 如果一个类从抽象类派生而来，那么它必须实现基类中的所有纯虚函数，才能成为非抽象类，否则它也是一个抽象类
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class A {
public:
	virtual void f() = 0; // 纯虚函数
	virtual void show() = 0; // 纯虚函数
	void g() { this->f(); }
	A() {};
};
class B :public A {
public:
	void f() { cout << "B::f()" << endl; } // 重写纯虚函数或虚函数写不写 virtual和override 都可以

	virtual void show() override { // 重写纯虚函数或虚函数写不写 virtual和override 都可以，写上就是提高代码的可读性，使用 override 有助于减少潜在的错误和增强代码的清晰性。在出现错误时提供编译器错误消息。
		cout << "B::show()" << endl;
	}
};

int main() {
	//B b; //error 如果B没有实现A中全部的纯虚函数，那么B也还是是一个抽象类，不能创建对象
	B b;
	b.g();
	b.show();
	return 0;
}