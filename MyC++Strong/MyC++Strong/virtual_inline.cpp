/**
 * @file virtual_inline.cpp
 * @brief ͨ�����Ա�������ᱻ�����������Ƿ��������
 * ��ͨ������ָ��������õ��õ��麯���ض����ܱ�����
 * ��Ȼ��ʵ���������麯�����߾�̬����ʱ���Ա������������������ľ�̬����Ҳһ���ᱻ����չ��
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
	public:
		virtual void who() { cout << "I am Base\n"; }
};

class Derived : public Base {
	public:
		void who() { cout << "I am Derived\n"; }
};

int main() {
	Base b;
	b.who();

	Base* ptr = new Derived();
	ptr->who();

	return 0;
}