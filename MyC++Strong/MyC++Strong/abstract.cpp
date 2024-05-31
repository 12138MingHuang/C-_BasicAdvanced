/**
 * @file abstract.cpp
 * @brief ���麯����û�к�������麯��
 * �������У��ڳ�Ա�����ڿ��Ե��ô��麯�����ڹ��캯��/���������ڲ����ܵ��ô��麯��
 * ���һ����ӳ�����������������ô������ʵ�ֻ����е����д��麯�������ܳ�Ϊ�ǳ����࣬������Ҳ��һ��������
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;
class A {
public:
	virtual void f() = 0; // ���麯��
	virtual void show() = 0; // ���麯��
	void g() { this->f(); }
	A() {};
};
class B :public A {
public:
	void f() { cout << "B::f()" << endl; } // ��д���麯�����麯��д��д virtual��override ������

	virtual void show() override { // ��д���麯�����麯��д��д virtual��override �����ԣ�д�Ͼ�����ߴ���Ŀɶ��ԣ�ʹ�� override �����ڼ���Ǳ�ڵĴ������ǿ����������ԡ��ڳ��ִ���ʱ�ṩ������������Ϣ��
		cout << "B::show()" << endl;
	}
};

int main() {
	//B b; //error ���Bû��ʵ��A��ȫ���Ĵ��麯������ôBҲ������һ�������࣬���ܴ�������
	B b;
	b.g();
	b.show();
	return 0;
}