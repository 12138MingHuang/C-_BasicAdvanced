/**
 * @file virtual_function1.cpp
 * @brief �麯�����Ա�˽�л�
 * ptr�޷�����˽�к�������Ȼ���ѻ�������Ϊpublic
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
	virtual void fun() { cout << "Base::fun()" << endl; }
};

class Derived : public Base {
private:
	void fun() { cout << "Derived::fun()" << endl; }
};

int main() {
	Base* ptr = new Derived();
	ptr->fun();

	return 0;
}

//Derived ���е� fun() �������ԣ���ȷʵ�Ǳ�����Ϊ˽�еġ�
//Ȼ����������������У����ڳ�Ա�����ķ���Ȩ�ޣ���Ҫ���ڱ���׶ν��м��ģ���������ʱ������Գ�Ա�����ķ���Ȩ�޽��м�顣
//����������£����� fun() ������ Derived ������˽�еģ����� Base ������������Ϊ�麯����
//�������Ȼ���Ա� Base �༰���������еĳ�Ա�������á�
//������ʱ��ͨ�� Base ���͵�ָ������õ��� fun() ����ʱ��ʵ�����ǵ����� Derived ������д�� fun() ������
//��Ϊ���Ǹ���ָ���������ָ�����Ķ�̬���������������ĸ��汾���麯����