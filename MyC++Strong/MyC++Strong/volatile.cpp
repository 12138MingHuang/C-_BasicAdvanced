/**
 * @file noopt_vola.cpp
 * @brief volatile使用
 * volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素（操作系统、硬件、其它线程等）更改。
 * 所以使用 volatile 告诉编译器不应对这样的对象进行优化。
 * volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）
 * const 可以是 volatile （如只读的状态寄存器）
 * 指针可以是 volatile （如中断服务子程序修改一个指向一个 buffer 的指针）
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <stdio.h>

int main(void) {
	const volatile int local = 10;
	int* ptr = const_cast<int*> (&local);

	printf("Initial value of local: %d\n", local);

	*ptr = 100;

	printf("Modified value of local: %d\n", local);

	return 0;
}