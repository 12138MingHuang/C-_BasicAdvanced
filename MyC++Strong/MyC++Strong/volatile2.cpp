/**
 * @file volatile2.cpp
 * @brief volatile��������
 * @auther bin.zhang
 * @date 2024.04.30
 */

//(1)һ�������ȿ�����const��������volatile��Ϊʲô�� 
//���ԡ�һ��������ֻ����״̬�Ĵ���������volatile��Ϊ�����ܱ����벻���ظı䡣����const��Ϊ����Ӧ����ͼȥ�޸�����

//(2)һ��ָ�������volatile��Ϊʲô�� 
//���ԡ������Ⲣ��������һ�������ǵ�һ���жϷ����ӳ����޸�һ��ָ��һ��buffer��ָ��ʱ��

//(3)����ĺ�����ʲô����

int square(volatile int* ptr) {
	return *ptr * *ptr;
}

//��Ŀ������������ָ��ptrָ��ֵ��ƽ�������ǣ�����ptrָ��һ��volatile�Ͳ�������������������������Ĵ���

int square(volatile int* ptr) {
	int a, b;
	a = *ptr;
	b = *ptr;
	return a * b;
}

//����*ptr��ֵ���ܱ����벻���ظı䣬���a��b�����ǲ�ͬ�ġ��������δ�����ܷ��صĲ�������������ƽ��ֵ����ȷ�Ĵ������£�

int square(volatile int* ptr) {
	int a;
	a = *ptr;
	return a * a;
}