/**
 * @file interesting_facts2.cpp
 * @brief 抽象类类型的指针和引用
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;

/**
 * @brief 抽象类必须包含一个纯虚函数
 */
class Base {
	int x;

public:
	virtual void show() = 0; // 纯虚函数
	int getX() { return x; }
};
class Derived : public Base {
public:
	virtual void show() override {
		cout << "Derived::show()" << endl;
	}
	Derived() {}
};

int main(void) {
	//Base b; // error 抽象类不能创建对象
	//Base *b =new Base(); // error
	Base *b = new Derived(); // ok 抽象类的指针和引用->指向抽象类派生出来的类的对象
	b->show();
	cout << b->getX() << endl;
	return 0;
}


/*
对象的生存期：
A a = A();：这是在栈上创建对象 a，对象的生命周期与其所在的作用域（通常是代码块）相同。当超出该作用域时，对象将自动销毁，调用析构函数释放资源。
A* a = new A();：这是在堆上动态分配对象 a，对象的生命周期由程序员控制。必须显式调用 delete a; 来销毁对象，以防止内存泄漏。如果忘记释放堆上的内存，可能会导致内存泄漏。
对象的使用方式：
A a = A();：对象直接存储在栈上，通过对象名 a 直接访问成员函数和数据成员。
A* a = new A();：对象存储在堆上，需要通过指针 a 访问成员函数和数据成员，例如 a->g();。
初始化：
A a = A();：对象在创建时会调用默认构造函数进行初始化。在这种情况下，A 类没有提供自定义的构造函数，所以会调用默认的构造函数 A()。
A* a = new A();：对象在创建时同样会调用默认构造函数进行初始化。如果类提供了自定义的构造函数，也可以在这里进行初始化，例如 A* a = new A(参数);。
内存管理：
A a = A();：对象存储在栈上，不需要手动管理内存。
A* a = new A();：对象存储在堆上，需要手动管理内存。必须使用 delete a; 来释放分配的内存，以免出现内存泄漏。
异常安全性：
A a = A();：在构造对象 A 时发生异常，对象会自动销毁，不会导致内存泄漏。
A* a = new A();：在构造对象 A 时发生异常，需要手动释放内存，否则会导致内存泄漏。
*/