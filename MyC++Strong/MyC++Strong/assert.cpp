/**
 * @file assert.cpp
 * @brief assert�Ǻ꣬�����Ǻ���
 * assert���ԭ�Ͷ�����<assert.h>�У�����������������������ش�������ֹ����ִ�С�
 * ����ͨ������NDEBUG���ر�assert�����磺#define NDEBUG  ������Ҫ��#include <assert.h>֮ǰ
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <assert.h>
#include <stdio.h>

int main() {
	int x = 7;

	x = 9;

	assert(x == 7);

	return 0;
}