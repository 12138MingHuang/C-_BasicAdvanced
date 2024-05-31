/**
 * @file interesting_facts5.cpp
 * @brief ���캯���������麯������������������������������
 * ���磺������ָ��ָ�����������ɾ������ʱ�����ǿ���ϣ�������ʵ��������������������������������ģ���ôֻ����û����������������������������������������
 * @author bin.zhang
 * date 2023-11-02
 */

#include <iostream>

using namespace std;
class Base {
public:
	Base() {
		cout << "Constructing Base \n";
	}
	virtual ~Base() {
		cout << "Destructing Base \n";
	}
};
class Derived :public Base {
public:
	Derived() {
		cout << "Constructing Derived \n";
	}
	~Derived() {
		cout << "Destructing Derived \n";
	}
};

int main(void) {
	Base *b = new Derived();
	delete b;
	return 0;
}