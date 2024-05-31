/**
 * @file enum_3.cpp
 * @brief �ӳ������߼���enum��Щ��
 * ���е�ö������
 * ��ʱ����ϣ��ĳЩ��������ֻ��������Ч������#define����ĳ�����ȫ�ֵģ����ܴﵽĿ�ģ������뵽ʹ��const�������ݳ�Ա��ʵ�֡���const
 * ���ݳ�Ա��ȷ���ڵģ����京��ȴ���������������ġ�
 * const���ݳ�Աֻ��ĳ�����������������ǳ��������������������ȴ�ǿɱ�ģ���Ϊ������ж�����󣬲�ͬ������const���ݳ�Ա��ֵ���Բ�ͬ
 * �������������г�ʼ��const��Ա�������÷��Ǵ���ģ���Ϊ�����δ������ʱ����������֪��SIZE��ֵ ��ʲô(C++11��׼ǰ)
 * @auther bin.zhang
 * @date 2024.05.19
 */

#include <iostream>
class A {
	const int SIZE = 100; // ����,��ͼ���������г�ʼ��const��Ա
	//int array[SIZE]; // ����,SIZE��ֵδ֪
};

// ��ȷӦ������Ĺ��캯���ĳ�ʼ���б��н���
class B {
public:
	B(int size);
	const int SIZE;
};

B::B(int size) :SIZE(size) { //���캯���Ķ���

}

// �������ܽ������������ж��㶨�ĳ���
// ��ָ��const���ݳ�Ա�ˣ�Ӧ�������е�ö�ٱ�����ʵ��
class Person {
public:
	typedef enum {
		Boy = 0,
		Girl
	} SexType;
};

// ö�ٳ�������ռ�ö���Ĵ洢�ռ䣬���Ǳ���ʱ��ȫ����ֵ
// ö�ٳ�����ȱ�㣺�����������������������������ֵ���ޣ��Ҳ��ܱ�ʾ����


int main() {
	B b1(100);
	B b2(200);

	std::cout << "B1 SIZE: " << b1.SIZE << std::endl;
	std::cout << "B2 SIZE: " << b2.SIZE << std::endl;

	Person::SexType sex = Person::Boy;
	std::cout << "Sex: " << sex << std::endl;

	return 0;
}