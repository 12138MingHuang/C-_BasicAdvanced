/**
 * @file rtti.cpp
 * @brief ����Զ����������У���ʱ��������Ҫ������ʱ��ѯһ�������Ƿ�����Ϊĳ�ֶ�̬����ʹ�ã���Java��instanceof����
 * �Լ�C#��is��as���������ƣ�C++�ṩ��dynamic_cast���������ڶ�̬ת�ͣ������C����ǿ������ת����C++��reinterpret_cast����dynamic_cast
 * �ṩ�����Ͱ�ȫ��飬��һ�ֻ���������ѯ��ת���������ڶ�̬���ͼ����ת��ʱ��dynamic_cast���ȫ��ת����ʽ
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class B {
	virtual void fun() {}
};

class D : public B {};

int main() {
	B* b = new D; //����ת��
	B& obj = *b;
	D* d = dynamic_cast<D*>(b); //����ת��

	if (d != NULL)
		cout << "works" << endl;
	else
		cout << "cannot cast B* to D*" << endl;

	try {
		D& dobj = dynamic_cast<D&>(obj);
		cout << "works" << endl;
	}
	catch (bad_cast bc) {
		cout << bc.what() << endl;
	}

	const std::type_info& ti = typeid(d); // ��ȡ������Ϣ
	std::cout << "Type of i: " << ti.name() << std::endl; // ������͵�����

	return 0;
}

//��ʹ�� dynamic_cast ��������ת��ʱ�������������ӵ��һ���麯��������������ᱨ��