/**
 * @file pure_virtual.cpp
 * @brief ���麯����û�к�������麯��
 * �����ࣺ�������麯������
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class A {
private:
	int a;

public:
	virtual void show() = 0; // ���麯��
};

class B : public A {
	void show() {
		cout << "B::show()" << endl;
	}
};

int main() {
	/*
	 * 1.������ֻ����Ϊ��������������ʹ�á�
	 * 2.�������ָ�������->ָ�������������������Ķ���
	 */

	//A a; //error �����಻�ܴ�������

	A* a1 = nullptr; //ok�����Զ���������ָ��

	//A *a2 = new A(); //error �����಻�ܴ�������

	B b;
	A& a3 = b; //ok�����Զ�������������,������ָ�������������������Ķ��󣬼���ֵΪ������Ķ���
	a3.show();
}