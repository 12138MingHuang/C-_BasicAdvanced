//ָ����const

const char* a; //ָ��const�����ָ�����˵ָ������ָ��
char const* a; //ָ��const�����ָ�����˵ָ������ָ�룬������ȼ�
char* const a; //ָ�����Ͷ����constָ�룬constָ�����˵��ָ�룬ָ��ָ�򲻿ɱ䣬����ָ���ֵ���Ա�
const char* const a; //ָ��const�����constָ�룬ָ��ָ�򲻿ɱ䣬��ָ���ֵҲ���ɱ�

// С��1�����constλ���Ǻ���࣬��const������������ָ����ָ��ı�������ָ��ָ��Ϊ������
// С��2�����constλ���Ǻ��Ҳ࣬const��������ָ�뱾����ָ�뱾���ǳ�����

// (1) ָ������ָ�룬ָ��ָ����Ա䣬����ָ���ֵ�����Ա�
const int* ptr;
// *ptr = 10; //����ָ���ֵ�����Ա�
// ptr��һ��ָ��int����const�����ָ�룬const�������int���ͣ�Ҳ����ptr��ָ��Ķ������ͣ�������ptr��������ptr���Բ��ø���ʼֵ�����ǲ���ͨ��ptrȥ�޸���ָ�����ֵ��
// ����֮�⣬Ҳ����ʹ��void* ָ�뱣��const����ĵ�ַ������ʹ��const void* ���͵�ָ�뱣��const����ĵ�ַ��
const int a = 10;
void* va = &a; //���󣬲���ʹ��void*ָ�뱣��const����ĵ�ַ
const void* va = &a; //��ȷ��ʹ��const void*ָ�뱣��const����ĵ�ַ
// ����һ���ص��ǣ�����ѷ�const����ĵ�ַ����ָ��const�����ָ�룬���Ƿ��������С�
const int* ptr2;
int val = 3;
//ptr2 = &val; //��ȷ���ѷ�const����ĵ�ַ����ָ��const�����ָ��

// (2) ��ָ�룬ָ��ָ�򲻿��Ա䣬����ָ���ֵ���Ա䣬�ұ����ʼ��
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 20;
	int* const ptr = &a; // constָ������ʼ��
	//ptr = &b; //����(���벻ͨ��)��ָ��ָ�򲻿��Ա�
	*ptr = 30; //��ȷ��ָ��ָ���ֵ���Ա�

	const int c = 10;
	//int* const ptr2 = &c; //����(���벻ͨ��)��ptr2��constָ�룬����ָ��const����ptr2ָ�����һ��������������const����
	//��������Ϊ const int *ptr2���߸�Ϊconst int *const ptr2��������������
	//const int* const ptr2 = &c; //��ȷ��ptr2��constָ�룬��ָ��const����
	//const int* ptr2 = &c; //��ȷ��ptr2��ָ��const�����ָ��
	return 0;
}

// (3) ָ�����ĳ�ָ�룬ָ��ָ�򲻿��Ա䣬ָ���ֵҲ�����Ա䣬�ұ����ʼ��
const int p = 10;
const int* const ptr = &p; //��ȷ��ptr��һ��ָ��const�����constָ��, ptr��һ��constָ�룬��ָ��const����