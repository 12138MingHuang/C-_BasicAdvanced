/**
 * @file static.cpp
 * @brief 静态数据成员
 * author bin.zhang
 * date 2023-10-30 
 */

#include <iostream>

using namespace std;
class A {
public:
	char b;
	void fun() {};
	virtual void virFun() {};
	static int c;
	static int d;
	static int f;
};

int main() {
	/**
	 * @brief 16 字节对齐、静态变量不影响、vptr指针占8字节
	 */
	cout << "sizeof(A) = " << sizeof(A) << endl;
	return 0;
}