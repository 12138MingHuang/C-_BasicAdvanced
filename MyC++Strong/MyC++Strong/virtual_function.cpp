/**
 * @file virtual_function.cpp
 * @brief �麯�����Ա�˽�л�
 * ����ָ��ָ��̳����������ü̳������ĺ���
 * int main()��������λBase�����Ԫ�������������ʧ��
 * ptr�޷�����˽�к�������Ȼ���ѻ�������Ϊpublic
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Derived;

class Base {
	private:
		virtual void fun() { cout << "Base::fun()" << endl; }
		friend int main();
};

class Derived : public Base {
	public:
		void fun() { cout << "Derived::fun()" << endl; }
};

int main() {
	Base* ptr = new Derived();
	ptr->fun();
	return 0;
}