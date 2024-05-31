/**
 * @file maohao.cpp
 * @brief :: ��Χ�����������Щ��
 * @auther bin.zhang
 * @date 2024.05.17
 */

// ȫ���������(::name) ������������(�࣬���Ա����Ա����������)ǰ����ʾ������Ϊȫ�ֿռ�
// ���������(ClassName::name) ���ڱ�ʾָ�����͵�������Χ�Ǿ���ĳ�����
// �����ռ��������(namespace::name) ���ڱ�ʾָ�����͵�������Χ�Ǿ���ĳ�������ռ��

#include <iostream>

using namespace std;

int count = 0; // ȫ��(::)��count

class A {
	public:
		static int count; // ��A��count(A::count)
};

namespace MyNamespace {
	int count = 5;
}


//��̬���������ڴ˶���
int A::count;
int main() {
	::count = 1; // ����ȫ��count = 1
	A::count = 2; // ������A��count = 2
	int count = 3; // �ֲ�count

	cout << "ȫ��count = " << ::count << endl;
	cout << "�ֲ�count = " << count << endl;
	cout << "��A��count = " << A::count << endl;
	cout << "�����ռ�MyNamespace��count = " << MyNamespace::count << endl; // �����ռ�MyNamespace��count(MyNamespace::count)

	return 0;
}