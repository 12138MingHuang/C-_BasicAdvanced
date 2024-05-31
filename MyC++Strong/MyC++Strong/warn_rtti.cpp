/**
 * @file warn_rtti.cpp
 * @brief ����Զ����������У���ʱ��������Ҫ������ʱ��ѯһ�������Ƿ�����Ϊĳ�ֶ�̬����ʹ�ã���Java��instanceof����
 * �Լ�C#��is��as���������ƣ�C++�ṩ��dynamic_cast���������ڶ�̬ת�ͣ������C����ǿ������ת����C++��reinterpret_cast����dynamic_cast
 * �ṩ�����Ͱ�ȫ��飬��һ�ֻ���������ѯ��ת���������ڶ�̬���ͼ����ת��ʱ��dynamic_cast���ȫ��ת����ʽ
 * @auther bin.zhang
 * @date 2024.04.30
 */

//��ʹ��ʱ��Ҫע�⣺��ת������obj������T1�����Ƕ�̬���ͣ�
//��T1���빫�м̳��������࣬����T1ӵ���麯�����̳л��Զ��壩����T1Ϊ�Ƕ�̬���ͣ�ʹ��dynamic_cast�ᱨ�������

#include <iostream>

using namespace std;

//AΪ�Ƕ�̬���ͣ���Ϊ��û���麯��
class A {};

//BΪ��̬����
class B {
	public:
		virtual ~B() {}
};

//DΪ�Ƕ�̬����
class D : public A {};

//EΪ�Ƕ�̬����
class E : private A {};

//FΪ�Ƕ�̬����
class F : private B {};

int main() {
	
}