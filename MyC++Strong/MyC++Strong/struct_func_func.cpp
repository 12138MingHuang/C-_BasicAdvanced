/**
 * @file struct_func_func.cpp
 * @brief C++中的struct
 * C++结构体重不仅能定义数据，还可以定义函数
 * C++结构体中可以使用访问修饰符，如public、protected、private
 * C++结构体使用可以直接使用不带struct的形式
 * C++有继承
 * 若结构体的名字与函数名相同，可以正常运行且正常调用，但是定义结构体变量值只能带struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>
#include <stdio.h>

struct Base {
	int v1;
	int v3;
	public:
		int v2;
		void print() {
			printf("%s\n", "hello world");
		}
};

typedef struct Base1 {
	int v1;
	int v3;
	public:
		int v2;
		void print() {
			printf("%s\n", "hello world");
		}
} B;
void Base() {
	printf("%s", "I am Base func");
}
//void B() {} //error 符号B已经被定义为一个struct Base1的别名

int main() {
	struct Base base;
	//Base base1; //error

	base.v1 = 1;
	base.v3 = 3;
	base.print();

	printf("%d\n", base.v1);
	printf("%d\n", base.v3);

	Base();

	return 0;
}

// C与C++的struct区别

// C:
// 不能将函数放在结构体声明
// 在C结构体声明中不能使用C++访问修饰符
// 在C中定义结构体变量，如果没使用typedef  在使用时必须加上struct 例如  struct Person {} struct Person person1;  Person person1;(报错)
// 结构体不能继承 没有这一概念
// 若结构体的名字与函数名相同，可以正常运行且正常调用

// C++:
// 结构体中可以定义函数
// 结构体中可以使用访问修饰符，如public、protected、private
// 结构体使用可以直接使用不带struct的形式
// C++有继承
// 若结构体的名字与函数名相同，可以正常运行且正常调用，但是定义结构体变量值只能带struct