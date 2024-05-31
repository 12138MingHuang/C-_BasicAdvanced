/**
 * @file c_polyExamp.c
 * @brief C的多态性
 * 封装
 * C语言中是没有class类这个概念的，但是有struct结构体，可以用struct来模拟
 * 使用函数指针把属性域方法封装到结构体中
 * 继承
 * 结构体嵌套
 * 多态
 * 类与子类的函数指针不同
 * 
 * 在C语言中的结构体内部是没有成员函数的，如果实现这个父结构体和子结构体共有的函数呢？可以考虑使用函数指针来模拟
 * 但是这样处理存在一个缺陷就是：父子各自的函数指针之间指向的不是类似C++中维护的虚函数表而是一块物理内存
 * 如果模拟的函数过多的话就会不容易维护了
 * 模拟多态，必须保持函数指针变量对齐(在内容上完全一致，而且变量对齐也完全一致)否则父类指针指向子类对象，运行崩溃
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <stdio.h>

// 重定义一个函数指针类型
typedef void(*pf) ();

/*
 * @brief 父类
 */
typedef struct Base {
	pf _b;
} B;

/*
 * @brief 子类
 */
typedef struct Derived {
	B _base;  //在子类中定义一个基类对象即可实现对父类的继承
} D;

void f1() {
	printf("Base::f1()\n");
}

void f2() {
	printf("Derived::f2()\n");
}

int main() {
	B b;
	D d;

	b._b = f1;
	d._base._b = f2;

	B* pb = &b;
	pb->_b();
	pb = (B*)&d; // 让父类指针指向子类对象，由于类型不匹配，所以需要强制类型转换
	pb->_b();

	return 0;
}