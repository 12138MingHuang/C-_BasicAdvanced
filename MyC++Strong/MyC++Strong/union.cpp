/**
 * @file union.cpp
 * @brief union��Щ��
 * union(����)��һ�ֽ�ʡ�ڴ�ռ��������࣬һ��union�����ж�����ݳ�Ա������������ʱ��ֻ��һ�����ݳ�Ա������ֵ
 * ��ĳ����Ա����ֵ��������Ա��Ϊδ����״̬
 * Ĭ�Ϸ������η�Ϊpublic
 * �����й��캯������������
 * ���ܺ����������͵ĳ�Ա
 * ���ܼ̳��������࣬������Ϊ����
 * ���ܰ����麯��
 * ����unionָһ��û�����ֵ�������, ����������Ķ�����ʽΪunion { ��Ա�б� };
 * ����union�ڶ��������������ֱ�ӷ���union��Ա
 * ����union���ܰ���protected��private��Ա
 * ȫ������union�����Ǿ�̬(staic)��
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>

using namespace std;

/**
 * �����й��캯������������ 
 */
union UnionTest {
	UnionTest() : i(10) { print(i); };
	~UnionTest() {};

	int i;

	private:
		void print(int i) {
			cout << "i: " << i << endl;
		};
};

/*
 * ȫ���������ϱ����Ǿ�̬��
 */
static union {
	int i;
	double d;
};

int main() {
	UnionTest u;

	union {
		int i;
		double d;
	};

	cout << u.i << endl; // ���UnionTest�Ĺ��캯���е�i  10

	::i = 20;
	cout << ::i << endl; // ���ȫ�־�̬�������ϵ�i  20

	/*
	 * ���������ڶ��������������ֱ�ӷ���union��Ա
	 */
	i = 30;
	cout << i << endl; // ����ֲ��������ϵ�i  30

	return 0;
}