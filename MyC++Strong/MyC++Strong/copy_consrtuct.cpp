/**
 * @file copy_consrtuct.cpp
 * @brief ���캯���������麯��
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
};

class Derived : public Base {
public:
	Derived() { cout << "Derived Created" << endl; }

	Derived(const Derived& rhs) { cout << "Derived Copied" << endl; }

	Derived& operator=(const Derived& rhs) { cout << "Derived Assigned" << endl; return *this; }

	~Derived() { cout << "Derived Destroyed" << endl; }
};

int main() {
	Derived s1;

	//Derived s2 = s1; ���д���ᴥ�����ƹ��캯���ĵ��á�
	//������Ϊ���������У����� s1 ���Ѿ����ڵ� Derived ���͵Ķ��󣬶� s2 ��Ҫͨ���� s1 ���Ƹ�������ʼ���ġ�
	//Ĭ������£�������������һ��Ĭ�ϵĸ��ƹ��캯�����ù��캯���������Ա�ظ���һ������ĳ�Ա����һ������
	//���������ʽ�ض����˸��ƹ��캯�����������Ͳ������Զ�����Ĭ�ϵĸ��ƹ��캯���ˡ�
	Derived s2 = s1;


	Derived d1;
	Derived d2;

	d2 = d1; // ʹ�����صĸ�ֵ������� d1 ��ֵ���� d2

	return 0;
}