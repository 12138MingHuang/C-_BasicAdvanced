/**
 * @file ignore_assert.cpp
 * @brief ����assert
 * assert��Ҫ���ڼ���߼��ϲ����ܵ������
 * ���磬���ǿ����ڼ������ڿ�ʼ����֮ǰ��������״̬��������������ɺ���״̬���������Ĵ�����ͬ������ͨ��������ʱ�����á�
 * @auther bin.zhang
 * @date 2024.04.30
 */

#define NDEBUG // ����assert

#include <assert.h>

int main() {
	assert(x == 5);

	return 0;
}