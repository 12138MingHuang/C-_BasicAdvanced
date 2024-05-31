/**
 * @file struct_func.c
 * @brief C�е�struct
 * ��C��structֻ�������������ݵĸ������ͣ�Ҳ����˵���ڽṹ��������ֻ�ܽ����ݳ�Ա�������棬�����ܽ�������������
 * ��C�ṹ���в���ʹ��C++�������η�����public��protected��private ����C++�п���ʹ��
 * ��C�ж���ṹ����������ʹ�������涨��������struct
 * C�Ľṹ�岻�ܼ̳У�û����һ����
 * ���ṹ��������뺯������ͬ���������������ҵ��� ����:���Զ�����struct Base����ͻ��void Base()����
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include<stdio.h>

struct Base {
	int v1;
	// public //error
	int v2;
	// private: //error
	int v3;
	/*void print() {
		printf("v1=%d, v2=%d, v3=%d\n", v1, v2, v3);
	}*/ //error C�нṹ�岻��Ƕ�뺯��
};

void Base() {
	printf("Base\n");
}

int main() {
	struct Base base;
	base.v1 = 1;
	printf("v1=%d\n", base.v1);
	Base();

	return 0;
}