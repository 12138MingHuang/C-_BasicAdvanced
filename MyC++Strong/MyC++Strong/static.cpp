/**
 * @file static.cpp
 * @brief ��̬���ݳ�Ա
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
	 * @brief 16 �ֽڶ��롢��̬������Ӱ�졢vptrָ��ռ8�ֽ�
	 */
	cout << "sizeof(A) = " << sizeof(A) << endl;
	return 0;
}