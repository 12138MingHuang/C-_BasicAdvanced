/**
 * @file c++_polyExamp.cpp
 * @brief C++�Ķ�̬��
 * C++�л�ά��һ���麯�������ݸ�ֵ���ݹ�������֪�������ָ����������ǿ���ָ���������ġ�
 * ���һ�������ָ��������õ��ø�����麯����ø����ָ������Լ����麯�����в����Լ��ĺ�����ַ������ø�������ָ���������
 * ָ������Ķ��󣬶��Ҹ������Ѿ���д�˸�����麯�������ָ������������Լ���д���麯��
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>

using namespace std;

class Base {
	public:
		virtual void f() {//�麯��
			cout << "Base::f()" << endl;
		}
};

class Derived : public Base {
	public:
		void f() {//��д������麯��
					cout << "Derived::f()" << endl;
				}
};

int main() {
	Base b;
	Derived d;
	Base *pb = &b;
	pb->f();//Base::f()
	pb = &d;
	pb->f();//Derived::f()

	return 0;
}