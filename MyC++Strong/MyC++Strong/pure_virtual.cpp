/**
 * @file pure_virtual.cpp
 * @brief 纯虚函数：没有函数体的虚函数
 * 抽象类：包含纯虚函数的类
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class A {
private:
	int a;

public:
	virtual void show() = 0; // 纯虚函数
};

class B : public A {
	void show() {
		cout << "B::show()" << endl;
	}
};

int main() {
	/*
	 * 1.抽象类只能作为基类来派生新类使用。
	 * 2.抽象类的指针和引用->指向抽象类派生出来的类的对象
	 */

	//A a; //error 抽象类不能创建对象

	A* a1 = nullptr; //ok，可以定义抽象类的指针

	//A *a2 = new A(); //error 抽象类不能创建对象

	B b;
	A& a3 = b; //ok，可以定义抽象类的引用,但必须指向抽象类派生出来的类的对象，即赋值为派生类的对象
	a3.show();
}