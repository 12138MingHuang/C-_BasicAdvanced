/**
 * @file virnhe.cpp
 * @brief ��̳�
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
	virtual void fun() {};
};
class B {
	virtual void fun2() {};
};
class C : virtual public A, virtual public B {
public:
	virtual void fun3() {};
};

int main() {
	/**
	 * @brief ������˵��16�����Ǹ��ݱ�����������32  ��������̳ж���麯������̳������麯����vptr
	 */
	cout << "sizeof(C) = " << sizeof(C) << endl;
}