/**
 * @file func_pointer.cpp
 * @brief ����ָ��
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;

/**
 * @brief ����ָ��
 * ������һ������pFun����������Ǹ�ָ�룬ָ�򷵻�ֵΪ�պͲ���Ϊint�ĺ�����ָ��
 */
void (*pFun)(int);

/**
 * @brief ����һ�������ͣ����Ǳ�����������������pFun��ͬ
 */
typedef void (*func)(void);

void myfunc(void) {
	cout << "myfunc" << endl;
}

void glFun(int a) {
	cout << a << endl;
}

int main() {
	func pfun = myfunc; // pfun��һ������ָ�룬ָ��myfunc����
	pfun(); // ����myfunc����
	pFun = glFun; // pFun��һ������ָ�룬ָ��glFun����
	(*pFun)(10); // ����glFun����     //ʹ��ָ������� *pFun ����ȡ������Ȼ�󴫵ݲ��� (10) ������������д���ǳ���ȷ�����������ؿ������ڵ���һ������ָ�롣
	pFun(100); //����һ�ּ򻯵�д������������ָ�뵱����������ʹ�ã�ֱ�Ӵ��ݲ���(100) ������ָ�롣���������Զ������ú���ָ�벢���ú���������д�����Ӽ�࣬��Ҳ��������һЩ��������Ϊ����ָ��ĵ��ÿ����������ڵ�����ͨ������
}