/**
 * @file sig_examp.cpp
 * @brief �궨��
 * @auther bin.zhang
 * @date 2024.05.31
 */

#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

///===========================================
/**
 * (#)�ַ���������
 */
 ///===========================================
#define exp(s) printf("test s is:%s\n", s)
#define exp1(s) printf("test s is:%s\n", #s)

#define exp2(s) #s

///===========================================
/**
 *��##���������Ӳ�����
 */
 ///===========================================
#define expA(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n", gc_##s) // gc_s�������

#define expB(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n", gc_##s) // gc_s�������

#define gc_hello1 "I am gc_hello1"

///===========================================
/**
 * (\)���в�����
 */
 ///===========================================
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
	///===========================================
	/**
	 * (#)�ַ���������
	 */
	 ///===========================================
	exp("hello");
	exp1(hello);

	string str = exp2(bac);
	cout << str << " " << str.size() << endl;
	/**
	 * ���Դ��������ǰ��ͺ���Ŀո�
	 */
	string str1 = exp2(asda bac);
	/**
	 * ���������������ڿո�ʱ�������������Զ����Ӹ������ַ�����
	 * ��ÿ�����ַ���֮����һ���ո����ӣ�����ʣ��ո�
	 */
	cout << str1 << " " << str1.size() << endl;

	///===========================================
	/**
	 * (#)�ַ���������
	 */
	 ///===========================================

	const char* gc_hello = "I am gc_hello";
	expA(hello);
	expB(hello1);

	char var1_p[20];
	char var2_p[20];

	// ���Ӻ��ʵ�ʲ�������ֵ
	strcpy(var1_p, "aaaa");
	strcpy(var2_p, "bbbb");

	///===========================================
	/**
	 * (\)���в�����
	 */
	 ///===========================================
	int max_val = MAX(3, 6);
	cout << max_val << endl;
	return 0;
}