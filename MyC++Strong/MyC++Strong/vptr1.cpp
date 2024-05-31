/**
 * @file vptr1.cpp
 * @brief c++虚函数vptr和vtable
 * @auther bin.zhang
 * @date 2023.12.04
 */

#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * @brief 函数指针
 */
typedef void (*Fun)();

/*
 * @brief 基类Base
 */
class Base {
public:
	Base() {};
	virtual void fun1() { cout << "Base::fun1()" << endl; }
	virtual void fun2() { cout << "Base::fun2()" << endl; }
	virtual void fun3() { cout << "Base::fun3()" << endl; }
	~Base() {};
};

/*
 * @brief 派生类Derived
 */
class Derived : public Base {
public:
	Derived() {};
	void fun1() { cout << "Derived::fun1()" << endl; }
	void fun2() { cout << "DerivedClass::fun2()" << endl; }
	~Derived() {};
};

/**
 * @brief 获取vptr地址与func地址，vptr指向的是一块内存，这块内存存放的是虚函数的地址，这块内存就是我们所说的虚表
 * @param[in] obj 对象
 * @param[in] offset 偏移量
 * @return vptr地址
 */
Fun getAddr(void* obj, unsigned int offset) {
	cout << "======================" << endl;
	// 确保 obj 指针是有效的
	if (obj == nullptr) {
		cout << "Error: Invalid object pointer!" << endl;
		return nullptr;
	}

	// 获取对象的虚函数表指针
	//reinterpret_cast<void***> 将 obj 转换为一个指向 void** 类型的指针。这里假设 obj 是一个指向具有虚函数的对象的指针。
	//虚函数表指针通常存储在对象的内存布局的开头，所以我们将 obj 的地址强制转换为一个指向指针的指针，
	//以便我们可以访问到该对象的虚函数表指针。
	//* 操作符解引用这个指针，得到指向虚函数表的指针。
	void** vptr_addr = *reinterpret_cast<void***>(obj);
	cout << "vptr_addr:" << vptr_addr << endl;

	// 获取虚函数地址
	//通过偏移量 offset 在虚函数表中找到特定的虚函数指针，并将其赋值给 func_addr。
	//offset 通常是一个整数值，表示想要获取的虚函数在虚函数表中的索引位置。
	//由于虚函数表中的每个条目通常是一个指向虚函数的函数指针，所以通过 offset 我们可以找到特定虚函数的地址。
	void* func_addr = vptr_addr[offset];
	cout << "func_addr:" << func_addr << endl;

	return reinterpret_cast<Fun>(func_addr);
}

int main(void) {
	Base ptr;
	Derived d;
	Base* pt = new Derived();	//基类指针指向派生类对象
	Base& pp = ptr;	//基类引用指向基类对象
	Base& p = d;	//基类引用指向派生类对象
	cout << "基类对象直接调用" << endl;
	ptr.fun1();
	cout << "基类引用指向基类实例" << endl;
	pp.fun1();
	cout << "基类指针指向派生类实例并调用虚函数" << endl;
	pt->fun1();
	cout << "基类引用指向派生类实例并调用虚函数" << endl;
	p.fun1();

	//手动查找vptr地址和vtable
	Fun f1 = getAddr(pt, 0);
	(*f1)();
	Fun f2 = getAddr(pt, 1);
	(*f2)();
	Fun f3 = getAddr(pt, 2);
	(*f3)();
	delete pt;

	return 0;
}