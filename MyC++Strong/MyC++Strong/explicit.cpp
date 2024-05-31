/**
 * @file explicit.cpp
 * @brief explicit(��ʽ)�ؼ���
 * explicit���ι��캯��ʱ�����Է�ֹ��ʽת���͸��Ƴ�ʼ��
 * explicit����ת������ʱ�����Է�ֹ��ʽת���������ﾳת������
 */

#include <iostream>

using namespace std;

struct A {
	A(int) {}
	operator bool() const { return true; }
};

struct B {
	explicit B(int) {}
	explicit operator bool() const { return true; }
};

void doA(A a) {}

void doB(B b) {}

int main() {
	//A(int) ǿ�Ƴ�ʼ����ǿ���û��ڴ�������ʱ�ṩһ�� int ������ȷ������Ĵ����Ǵ���ĳ����ȷ����ͼ���ʼֵ��
	//A() �޲������죺���������û���κβ���������±��������ʺ϶����к���Ĭ��״̬�������
	// A a100;  // ����û���޲������캯��
	A a100(1);  // ��ȷ�������ṩ����

	A a1(1); // ֱ�ӳ�ʼ��
	A a2 = 1; //���Ƴ�ʼ��
	A a3{ 1 }; //ֱ���б��ʼ��
	A a4 = { 1 }; //�����б��ʼ��
	A a5 = (A)1; //����static_cast����ʽת��
	
	doA(1); //�����int��A����ʽת��

	if (a1); // ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��
	bool a6(a1); // ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��
	bool a7 = a1; // ʹ��ת������A::operator bool()�Ĵ�A��bool����ʽת��

	B b1(1); // ֱ�ӳ�ʼ��
	// B b2 = 1; // error ��explicit���εĹ��캯���Ķ��󲻿��Ը��Ƴ�ʼ��

	B b3{ 1 }; //ֱ���б��ʼ��
	// B b4 = { 1 }; // error ��explicit���εĹ��캯�����󲻿��Ը����б��ʼ��

	B b5 = (B)1; // ����static_cast����ʽת��
	//doB(1); // error ��explicit���εĹ��캯���Ķ��󲻿��Դ�int��B����ʽת��

	if (b1); // �� explicit ����ת������ B::operator bool() �Ķ�����Դ� B �� bool�İ��ﾳת��

	bool b6(b1); // �� explicit ����ת������ B::operator bool() �Ķ�����Դ� B�� bool �İ��ﾳת��
	// bool b7 = b1; // error �� explicit ����ת������
	// B::operator bool() �Ķ��󲻿�����ʽת��
	bool b8 = static_cast<bool>(b1); // static_cast ����ֱ�ӳ�ʼ��

	return 0;
}