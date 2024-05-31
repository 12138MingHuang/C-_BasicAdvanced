/**
 * @file struct_func.cpp
 * @brief C++�е�struct
 * C++�ṹ���ز����ܶ������ݣ������Զ��庯��
 * C++�ṹ���п���ʹ�÷������η�����public��protected��private
 * C++�ṹ��ʹ�ÿ���ֱ��ʹ�ò���struct����ʽ
 * C++�м̳�
 * ���ṹ��������뺯������ͬ�����������������������ã����Ƕ���ṹ�����ֵֻ�ܴ�struct
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <stdio.h>
#include <iostream>

#pragma region �Ƿ����ͬ������
 // δ���ͬ������
struct Student {

};

struct Student s;
Student s;


// ���ͬ��������:
struct Teacher {

};
void Teacher() {

}
struct Teacher t;
// Teacher t; //error
#pragma endregion


#pragma region �Ƿ�ʹ��typedef����ṹ�����
// ��ʹ��typedef����ṹ�����
struct Base {
	int v1;
	int v3;
public:     //��ʾ����public
	int v2;
	void print() {
		printf("%s\n", "hello world");
	};
};


// ʹ��typedef����ṹ�����
typedef struct Base1 {
	int v1;
	int v3;
public:
	int v2;
	void print() {
		printf("%s\n", "hello world");
	}
} B;
// void B() {} //error ����B�Ѿ�������Ϊ�ṹ�����
#pragma endregion



int main() {
	struct Base base1 {};
	Base base2{};
	
	Base base{};
	base.v1 = 1;
	base.v3 = 2;
	base.print();
	printf("------------------------\n");
	B b{};
	b.v1 = 1;
	b.v3 = 2;
	b.print();
}