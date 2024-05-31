/**
 * @file default_arg.cpp
 * @brief �麯����Ĭ�ϲ���
 * ����Ĭ�ϲ����Ǿ�̬�󶨵ģ����麯���Ƕ�̬�󶨵ġ�Ĭ�ϲ�����ʹ����Ҫ��ָ��������ñ�������ͣ������Ƕ��������
 * @auther bin.zhang
 * @date 2024.04.30
 */

//Ĭ�ϲ����Ǿ�̬�󶨵ģ����麯���Ƕ�̬�󶨵ġ�Ĭ�ϲ�����ʹ����Ҫ��ָ��������ñ�������ͣ������Ƕ��������

#include <iostream>
using namespace std;

class Base {
	public:
		virtual void fun(int x = 10) { cout << "Base::fun(), x = " << x << endl; }
};

class Derived : public Base {
	public:
		virtual void fun(int x = 20) { cout << "Derived::fun(), x = " << x << endl; }
};

int main() {
	Derived d1;
	Base* bp = &d1;
	bp->fun();

	//���� newBp ��ͨ����������� d1 ���г�ʼ���ġ����ֳ�ʼ����ʽ�ᴥ�������иobject slicing����
	//�����и���ζ�ţ�����������󱻸�ֵ���������ʱ��ֻ�ᱣ�����ಿ�ֵ����ݣ��������ಿ�ֵ����ݽ���������
	//���仰˵����ֵ����������������иΪ�������
	//������˵������������У����� Base �������� Derived �������Լ��ĳ�Ա���� fun���������� Derived ���ж���ĳ�Ա��������Ϊ���������ࣩ
	//������������� d1 ��ֵ��������� newBp ʱ��ֻ�л��� Base ���ֵ����ݱ������� newBp �У��������� Derived ���ֵ����ݱ�������
	Base newBp = d1;
	newBp.fun();
	return 0;
}