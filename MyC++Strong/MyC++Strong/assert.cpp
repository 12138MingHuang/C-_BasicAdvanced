/**
 * @file assert.cpp
 * @brief assert是宏，而不是函数
 * assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行。
 * 可以通过定义NDEBUG来关闭assert，例如：#define NDEBUG  但是需要在#include <assert.h>之前
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