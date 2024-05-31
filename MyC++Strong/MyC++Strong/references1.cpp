/**
 * @file references1.cpp
 * @brief 引用与指针
 * 引用: 必须初始化,不能为空，不能更换目标
 * 指针: 可以不初始化，可以为空，可以更换目标
 * @auther bin.zhang
 * @date 2024.05.31
 */

// 在定义一个引用的时候必须为其指定一个初始值，但是指针不需要
int& r; // error 没有初始化引用
int* p; // 可以，但是p为野指针

// 由于引用不能为空，所以我们在使用引用的时候不需要测试其合法性，而在使用指针的时候需要首先判断指针是否为空指针，否则可以会引起程序崩溃
void test_p(int* p) {
	if (p != nullptr)
		*p = 3; // 对p所指对象赋值时候需先判断p是否为空指针

	return;
}

void test_r(int& r) {
	r = 3; // 对r所指对象赋值不需要判断r是否为空引用

	return;
}

// 指针可以随时改变目标指向，但是引用只能指向初始化时指向的对象，无法改变
int a = 1;
int b = 2;

int &r1 = a; // 引用r1指向a
int *p1 = &a; // 指针p1指向a

// p1 = &b; // 指针p1指向b
// r1 = b; // 是r1依然指向a，但是a的值已经变成了b

#include <iostream>

using namespace std;

void test1(int* p) {
	*p = 3; //此处应该首先判断p是否为空，为了测试的需要，此处没加。

	return;
}

void test2(int& r) {
	r = 30;

	return;
}

int main() {
	int a = 10;
	int *p = &a;
	test1(p);
	test2(a);
	cout << "a = " << a << endl;

	return 0;
}