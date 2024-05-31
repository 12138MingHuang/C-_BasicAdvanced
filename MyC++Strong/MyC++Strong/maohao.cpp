/**
 * @file maohao.cpp
 * @brief :: 范围解析运算符那些事
 * @auther bin.zhang
 * @date 2024.05.17
 */

// 全局作用域符(::name) 用于类型名称(类，类成员，成员函数，变量)前，表示作用域为全局空间
// 类作用域符(ClassName::name) 用于表示指定类型的作用域范围是具体某个类的
// 命名空间作用域符(namespace::name) 用于表示指定类型的作用域范围是具体某个命名空间的

#include <iostream>

using namespace std;

int count = 0; // 全局(::)的count

class A {
	public:
		static int count; // 类A的count(A::count)
};

namespace MyNamespace {
	int count = 5;
}


//静态变量必须在此定义
int A::count;
int main() {
	::count = 1; // 设置全局count = 1
	A::count = 2; // 设置类A的count = 2
	int count = 3; // 局部count

	cout << "全局count = " << ::count << endl;
	cout << "局部count = " << count << endl;
	cout << "类A的count = " << A::count << endl;
	cout << "命名空间MyNamespace的count = " << MyNamespace::count << endl; // 命名空间MyNamespace的count(MyNamespace::count)

	return 0;
}