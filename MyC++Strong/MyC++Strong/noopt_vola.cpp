/**
 * @file noopt_vola.cpp
 * @brief volatileʹ��
 * volatile �ؼ�����һ���������η����������������ͱ�����ʾ���Ա�ĳЩ������δ֪�����أ�����ϵͳ��Ӳ���������̵߳ȣ����ġ�
 * ����ʹ�� volatile ���߱�������Ӧ�������Ķ�������Ż���
 * volatile �ؼ��������ı�����ÿ�η���ʱ��������ڴ���ȡ��ֵ��û�б� volatile ���εı������������ڱ��������Ż����� CPU �Ĵ�����ȡֵ��
 * const ������ volatile ����ֻ����״̬�Ĵ�����
 * ָ������� volatile �����жϷ����ӳ����޸�һ��ָ��һ�� buffer ��ָ�룩
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <stdio.h>

int main(void) {
	const int local = 10;
	int* ptr = const_cast<int*> (&local);

	printf("Initial value of local: %d\n", local);

	*ptr = 100;

	printf("Modified value of local: %d\n", local);

	return 0;
}