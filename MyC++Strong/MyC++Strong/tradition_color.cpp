/**
 * @file tradition_color.cpp
 * @brief �ӳ������߼���enum��Щ��
 * ��ͳ��Ϊ
 * ö�����������⣺���������ޣ�����������������ͻ
 * @auther bin.zhang
 * @date 2024.05.17
 */

#include <iostream>

enum Color {
	Red,
	Blue,
	Green
};
enum Feeling {
	Excited,
	Blue
};

int main() {
	//Color color = Blue;
	Feeling feeling = Blue;
	std::cout << feeling << std::endl;
	return 0;
}

// ����ʽת��Ϊint�����±������
// ��������ö�ٱ�����ʵ�����Ͳ�����ȷָ�����Ӷ��޷�֧��ö�����͵�ǰ������