/**
 * @file vptr1.cpp
 * @brief c++�麯��vptr��vtable
 * @auther bin.zhang
 * @date 2023.12.04
 */

#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * @brief ����ָ��
 */
typedef void (*Fun)();

/*
 * @brief ����Base
 */
class Base {
public:
	Base() {};
	virtual void fun1() { cout << "Base::fun1()" << endl; }
	virtual void fun2() { cout << "Base::fun2()" << endl; }
	virtual void fun3() { cout << "Base::fun3()" << endl; }
	~Base() {};
};

/*
 * @brief ������Derived
 */
class Derived : public Base {
public:
	Derived() {};
	void fun1() { cout << "Derived::fun1()" << endl; }
	void fun2() { cout << "DerivedClass::fun2()" << endl; }
	~Derived() {};
};

/**
 * @brief ��ȡvptr��ַ��func��ַ��vptrָ�����һ���ڴ棬����ڴ��ŵ����麯���ĵ�ַ������ڴ����������˵�����
 * @param[in] obj ����
 * @param[in] offset ƫ����
 * @return vptr��ַ
 */
Fun getAddr(void* obj, unsigned int offset) {
	cout << "======================" << endl;
	// ȷ�� obj ָ������Ч��
	if (obj == nullptr) {
		cout << "Error: Invalid object pointer!" << endl;
		return nullptr;
	}

	// ��ȡ������麯����ָ��
	//reinterpret_cast<void***> �� obj ת��Ϊһ��ָ�� void** ���͵�ָ�롣������� obj ��һ��ָ������麯���Ķ����ָ�롣
	//�麯����ָ��ͨ���洢�ڶ�����ڴ沼�ֵĿ�ͷ���������ǽ� obj �ĵ�ַǿ��ת��Ϊһ��ָ��ָ���ָ�룬
	//�Ա����ǿ��Է��ʵ��ö�����麯����ָ�롣
	//* ���������������ָ�룬�õ�ָ���麯�����ָ�롣
	void** vptr_addr = *reinterpret_cast<void***>(obj);
	cout << "vptr_addr:" << vptr_addr << endl;

	// ��ȡ�麯����ַ
	//ͨ��ƫ���� offset ���麯�������ҵ��ض����麯��ָ�룬�����丳ֵ�� func_addr��
	//offset ͨ����һ������ֵ����ʾ��Ҫ��ȡ���麯�����麯�����е�����λ�á�
	//�����麯�����е�ÿ����Ŀͨ����һ��ָ���麯���ĺ���ָ�룬����ͨ�� offset ���ǿ����ҵ��ض��麯���ĵ�ַ��
	void* func_addr = vptr_addr[offset];
	cout << "func_addr:" << func_addr << endl;

	return reinterpret_cast<Fun>(func_addr);
}

int main(void) {
	Base ptr;
	Derived d;
	Base* pt = new Derived();	//����ָ��ָ�����������
	Base& pp = ptr;	//��������ָ��������
	Base& p = d;	//��������ָ�����������
	cout << "�������ֱ�ӵ���" << endl;
	ptr.fun1();
	cout << "��������ָ�����ʵ��" << endl;
	pp.fun1();
	cout << "����ָ��ָ��������ʵ���������麯��" << endl;
	pt->fun1();
	cout << "��������ָ��������ʵ���������麯��" << endl;
	p.fun1();

	//�ֶ�����vptr��ַ��vtable
	Fun f1 = getAddr(pt, 0);
	(*f1)();
	Fun f2 = getAddr(pt, 1);
	(*f2)();
	Fun f3 = getAddr(pt, 2);
	(*f3)();
	delete pt;

	return 0;
}