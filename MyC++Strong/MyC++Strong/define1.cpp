/**
 * @file define1.cpp
 * @brief �궨��
 * @auther bin.zhang
 * @date 2024.05.31
 */

// ���а����������
// # ## \

// �ַ�����������(#)
// ��һ�����еĲ���ǰ��ʹ��һ��#��Ԥ����������������ת��Ϊһ���ַ�����
// ����֮����#���ַ���������˼�������ں궨���е�#�ǰѸ��ں���Ĳ�������һ���ַ���
// ע�⣺��ֻ�������д�������ĺ궨���У��ұ������ں궨�����еĲ�����ǰ

#include <string>
#include <iostream>

using namespace std;

#define exp(s) printf("test s is: %s\n",s)
#define exp1(s) printf("test s is: %s\n",#s)
#define exp2(s) #s

int main() {
	exp("hello");
	exp1(hello);

	string str = exp2(  bac  );
	cout << str << " " << str.size() << endl;

	/**
	 * ���Դ���Ĳ�����ǰ��ͺ���Ŀո�
	 */
	string str1 = exp2( asda  bac  );
	/**
	 * ������������м���ڿո�ʱ�����������Զ����Ӹ������ַ���
	 * ��ÿ�����ַ���֮����һ���ո����ӣ�����ʣ��ո�
	 */
	cout << str1 <<" " << str1.size() << endl;

	return 0;
}


// �������Ӳ�����(##)
// ##��һ�ַָ����ӷ�ʽ�������������ȷָ���Ȼ�����ǿ�����ӡ����궨��Ķ���β�ת����һ��ʵ�ʵĲ�����
// ����##�����β�ʱ��##ǰ��Ŀո���п���
// ���Ӻ��ʵ�ʲ�����������Ϊʵ�ʴ��ڵĲ��������Ǳ�������֪�ĺ궨��
// ���##��Ĳ�������Ҳ��һ����Ļ���##����ֹ������չ��


#define expA(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n",gc_##s)  //gc_s�������
// ע������2
#define expB(s) printf("ǰ׺���Ϻ���ַ���Ϊ:%s\n",gc_  ##  s)  //gc_s�������
// ע������1
#define gc_hello1 "I am gc_hello1"
int main() {
	// ע������1
	const char* gc_hello = "I am gc_hello";
	expA(hello);
	expB(hello1);
}


// ���в�������\��
// ������ĺ겻����һ�б������ʱ�������á�\����ʾ��һ�м����˺�Ķ��塣
// ע�� \ ǰ���ո�

#define MAX(a,b) ((a)>(b) ? (a) \
   :(b))  
int main() {
	int max_val = MAX(3, 6);
	cout << max_val << endl;
}