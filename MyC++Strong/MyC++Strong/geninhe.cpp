/**
 * @file geninhe.cpp
 * @brief 1.��ͨ���̳У��̳о��ǻ���+������Ĵ�С(ע���ֽڶ���)
 * ע�⣺������ݳ�Ա��������˳������ڴ棬�����Ȩ���޹أ�ֻ������˳��
 * 2.�鵥�̳У�������̳��˻����vptr��
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;
class A {
public:
	char a;
	int b;
};
class B : A {
public:
	short a;
	long b;
};
class C {
	A a;
	char c;
};

class A1 {
	virtual void fun() {};
};
class C1 :public A1 {
	virtual void fun2();
};

int main() {
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	cout << "sizeof(A1) = " << sizeof(A1) << endl;

	/**
	 * @brief �����鵥�����̳У�������Ҳ�̳��˻����vptr��������8�ֽ�
	 */
	cout << "sizeof(C1) = " << sizeof(C1) << endl;
	return 0;
}