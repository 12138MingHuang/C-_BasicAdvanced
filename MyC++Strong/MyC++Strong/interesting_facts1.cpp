/**
 * @file interesting_facts1.cpp
 * @brief ���麯�� ʹ��һ���ɱ�ɳ�����
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;

/**
 * @brief ������������һ�����麯��
 */
class Test {
	int x;

	public:
		virtual void show() = 0; // ���麯��
		int getX() { return x; }
};

int main(void) {
	//Test t; // error �����಻�ܴ�������
	return 0;
}