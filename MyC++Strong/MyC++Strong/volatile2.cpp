/**
 * @file volatile2.cpp
 * @brief volatile常见问题
 * @auther bin.zhang
 * @date 2024.04.30
 */

//(1)一个参数既可以是const还可以是volatile吗？为什么？ 
//可以。一个例子是只读的状态寄存器。它是volatile因为它可能被意想不到地改变。它是const因为程序不应该试图去修改它。

//(2)一个指针可以是volatile吗？为什么？ 
//可以。尽管这并不常见。一个例子是当一个中断服务子程序修改一个指向一个buffer的指针时。

//(3)下面的函数有什么错误？

int square(volatile int* ptr) {
	return *ptr * *ptr;
}

//其目的是用来返回指针ptr指向值的平方，但是，由于ptr指向一个volatile型参数，编译器将产生类似下面的代码

int square(volatile int* ptr) {
	int a, b;
	a = *ptr;
	b = *ptr;
	return a * b;
}

//由于*ptr的值可能被意想不到地改变，因此a和b可能是不同的。结果，这段代码可能返回的不是你所期望的平方值！正确的代码如下：

int square(volatile int* ptr) {
	int a;
	a = *ptr;
	return a * a;
}