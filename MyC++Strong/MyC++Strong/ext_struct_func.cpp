/**
 * @file ext_struct_func.cpp
 * @brief C++中的struct
 * C++结构体重不仅能定义数据，还可以定义函数
 * C++结构体中可以使用访问修饰符，如public、protected、private
 * C++结构体使用可以直接使用不带struct的形式
 * C++有继承
 * 若结构体的名字与函数名相同，可以正常运行且正常调用，但是定义结构体变量值只能带struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

// 继承案例
#include <iostream>
#include <stdio.h>

struct Base {
	int v1;
	int v3;
	public://显示声明public
		int v2;
		void print() {
			printf("%s\n", "Base");
		};
};

struct Derived :Base {
	public:
		int v2;
		void print() {
			printf("%s\n", "Derived");
		};
};

int main() {
	Base *b = new Derived();
	b->print();

	return 0;
}