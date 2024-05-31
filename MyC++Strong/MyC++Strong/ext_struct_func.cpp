/**
 * @file ext_struct_func.cpp
 * @brief C++�е�struct
 * C++�ṹ���ز����ܶ������ݣ������Զ��庯��
 * C++�ṹ���п���ʹ�÷������η�����public��protected��private
 * C++�ṹ��ʹ�ÿ���ֱ��ʹ�ò���struct����ʽ
 * C++�м̳�
 * ���ṹ��������뺯������ͬ�����������������������ã����Ƕ���ṹ�����ֵֻ�ܴ�struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

// �̳а���
#include <iostream>
#include <stdio.h>

struct Base {
	int v1;
	int v3;
	public://��ʾ����public
		int v2;
		void print() {
			printf("%s\n", "Base");
		};
};

struct Derived :Base {
	public:
		int v2;
		void print() {
			printf("%s\n", "Derived");
		};
};

int main() {
	Base *b = new Derived();
	b->print();

	return 0;
}