/**
 * @file interesting_facts3.cpp
 * @brief ������ǲ����������и��ǻ����еĴ��麯������ô��������Ҳ����Ϊһ�������ࡣ
 * author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class Base {
	int x;
public:
	virtual void show() = 0; // ���麯��
	int getX() { return x; }
};

class Derived : public Base {
public:
	//void show() { cout << "Derived::show()" << endl; } // error ������û��ʵ�ֻ����еĴ��麯������ô��������Ҳ����Ϊһ�������ࡣ
};

int main(void) {
	//Derived d; // error �����಻�ܴ�������
	return 0;
}