/**
 * @file struct_func.cpp
 * @brief C++中的struct
 * C++结构体重不仅能定义数据，还可以定义函数
 * C++结构体中可以使用访问修饰符，如public、protected、private
 * C++结构体使用可以直接使用不带struct的形式
 * C++有继承
 * 若结构体的名字与函数名相同，可以正常运行且正常调用，但是定义结构体变量值只能带struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <stdio.h>
#include <iostream>

#pragma region 是否添加同名函数
 // 未添加同名函数
struct Student {

};

struct Student s;
Student s;


// 添加同名函数后:
struct Teacher {

};
void Teacher() {

}
struct Teacher t;
// Teacher t; //error
#pragma endregion


#pragma region 是否使用typedef定义结构体别名
// 不使用typedef定义结构体别名
struct Base {
	int v1;
	int v3;
public:     //显示声明public
	int v2;
	void print() {
		printf("%s\n", "hello world");
	};
};


// 使用typedef定义结构体别名
typedef struct Base1 {
	int v1;
	int v3;
public:
	int v2;
	void print() {
		printf("%s\n", "hello world");
	}
} B;
// void B() {} //error 符号B已经被定义为结构体别名
#pragma endregion



int main() {
	struct Base base1 {};
	Base base2{};
	
	Base base{};
	base.v1 = 1;
	base.v3 = 2;
	base.print();
	printf("------------------------\n");
	B b{};
	b.v1 = 1;
	b.v3 = 2;
	b.print();
}