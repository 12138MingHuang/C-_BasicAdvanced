/**
 * @file union.cpp
 * @brief union那些事
 * union(联合)是一种节省内存空间的特殊的类，一个union可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值
 * 当某个成员被赋值后其他成员变为未定义状态
 * 默认访问修饰符为public
 * 可以有构造函数和析构函数
 * 不能含有引用类型的成员
 * 不能继承自其他类，不能作为基类
 * 不能包含虚函数
 * 匿名union指一个没有名字的联合体, 匿名联合体的定义形式为union { 成员列表 };
 * 匿名union在定义所在引用域可直接访问union成员
 * 匿名union不能包含protected或private成员
 * 全局匿名union必须是静态(staic)的
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>

using namespace std;

/**
 * 可以有构造函数和析构函数 
 */
union UnionTest {
	UnionTest() : i(10) { print(i); };
	~UnionTest() {};

	int i;

	private:
		void print(int i) {
			cout << "i: " << i << endl;
		};
};

/*
 * 全局匿名联合必须是静态的
 */
static union {
	int i;
	double d;
};

int main() {
	UnionTest u;

	union {
		int i;
		double d;
	};

	cout << u.i << endl; // 输出UnionTest的构造函数中的i  10

	::i = 20;
	cout << ::i << endl; // 输出全局静态匿名联合的i  20

	/*
	 * 匿名联合在定义所在引用域可直接访问union成员
	 */
	i = 30;
	cout << i << endl; // 输出局部匿名联合的i  30

	return 0;
}