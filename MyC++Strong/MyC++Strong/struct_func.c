/**
 * @file struct_func.c
 * @brief C中的struct
 * 在C中struct只单纯的用作数据的复合类型，也就是说，在结构体声明中只能将数据成员放在里面，而不能将函数放在里面
 * 在C结构体中不能使用C++访问修饰符，如public、protected、private 而在C++中可以使用
 * 在C中定义结构体变量，如果使用了下面定义必须加上struct
 * C的结构体不能继承，没有这一概念
 * 若结构体的名字与函数名相同，可以正常运行且调用 例如:可以定义与struct Base不冲突的void Base()函数
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include<stdio.h>

struct Base {
	int v1;
	// public //error
	int v2;
	// private: //error
	int v3;
	/*void print() {
		printf("v1=%d, v2=%d, v3=%d\n", v1, v2, v3);
	}*/ //error C中结构体不能嵌入函数
};

void Base() {
	printf("Base\n");
}

int main() {
	struct Base base;
	base.v1 = 1;
	printf("v1=%d\n", base.v1);
	Base();

	return 0;
}