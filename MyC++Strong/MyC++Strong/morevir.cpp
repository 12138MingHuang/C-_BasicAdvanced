/**
 * @file morevir.cpp
 * @brief ���ڰ����麯�����࣬�����ж��ٸ��麯����ֻ��һ����ָ�룬vptr�Ĵ�С
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
	virtual void fun() {};
	virtual void fun1() {};
	virtual void fun2() {};
	virtual void fun3() {};
};

int main() {
	cout << "sizeof(A) = " << sizeof(A) << endl;
	return 0;
}