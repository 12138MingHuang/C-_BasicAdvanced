/**
 * @file struct_func_func.cpp
 * @brief C++�е�struct
 * C++�ṹ���ز����ܶ������ݣ������Զ��庯��
 * C++�ṹ���п���ʹ�÷������η�����public��protected��private
 * C++�ṹ��ʹ�ÿ���ֱ��ʹ�ò���struct����ʽ
 * C++�м̳�
 * ���ṹ��������뺯������ͬ�����������������������ã����Ƕ���ṹ�����ֵֻ�ܴ�struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>
#include <stdio.h>

struct Base {
	int v1;
	int v3;
	public:
		int v2;
		void print() {
			printf("%s\n", "hello world");
		}
};

typedef struct Base1 {
	int v1;
	int v3;
	public:
		int v2;
		void print() {
			printf("%s\n", "hello world");
		}
} B;
void Base() {
	printf("%s", "I am Base func");
}
//void B() {} //error ����B�Ѿ�������Ϊһ��struct Base1�ı���

int main() {
	struct Base base;
	//Base base1; //error

	base.v1 = 1;
	base.v3 = 3;
	base.print();

	printf("%d\n", base.v1);
	printf("%d\n", base.v3);

	Base();

	return 0;
}

// C��C++��struct����

// C:
// ���ܽ��������ڽṹ������
// ��C�ṹ�������в���ʹ��C++�������η�
// ��C�ж���ṹ����������ûʹ��typedef  ��ʹ��ʱ�������struct ����  struct Person {} struct Person person1;  Person person1;(����)
// �ṹ�岻�ܼ̳� û����һ����
// ���ṹ��������뺯������ͬ������������������������

// C++:
// �ṹ���п��Զ��庯��
// �ṹ���п���ʹ�÷������η�����public��protected��private
// �ṹ��ʹ�ÿ���ֱ��ʹ�ò���struct����ʽ
// C++�м̳�
// ���ṹ��������뺯������ͬ�����������������������ã����Ƕ���ṹ�����ֵֻ�ܴ�struct