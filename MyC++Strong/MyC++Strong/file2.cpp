#include <iostream>
using namespace std;

//Ҫʹ�����ܹ��������ļ��з��ʣ��������ļ�����ʽ��ָ����Ϊextern��
//�����ڲ�ͬ�ļ��ķ���
extern int ext; //��file2.cpp�ж���һ���µ�extֵ����������������ʱ��file1.cpp��file2.cpp������ext����ϲ�Ϊһ��ȫ�ֱ���
int main3() {
	cout << ext+10 << endl;
	ext = 42; // �⽫���±��������Ϊ��file2.cpp��û�ж���ext����ֵ

	return 0;
}