/**
 * @file ignore_assert.cpp
 * @brief 忽略assert
 * assert主要用于检查逻辑上不可能的情况。
 * 例如，它们可用于检查代码在开始运行之前所期望的状态，或者在运行完成后检查状态。与正常的错误处理不同，断言通常在运行时被禁用。
 * @auther bin.zhang
 * @date 2024.04.30
 */

#define NDEBUG // 忽略assert

#include <assert.h>

int main() {
	assert(x == 5);

	return 0;
}