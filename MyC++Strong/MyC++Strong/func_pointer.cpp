/**
 * @file func_pointer.cpp
 * @brief 函数指针
 * @author bin.zhang
 * @date 2023-10-30
 */

#include <iostream>

using namespace std;

/**
 * @brief 函数指针
 * 定义了一个变量pFun，这个变量是个指针，指向返回值为空和参数为int的函数的指针
 */
void (*pFun)(int);

/**
 * @brief 代表一种新类型，不是变量，所以与上述的pFun不同
 */
typedef void (*func)(void);

void myfunc(void) {
	cout << "myfunc" << endl;
}

void glFun(int a) {
	cout << a << endl;
}

int main() {
	func pfun = myfunc; // pfun是一个函数指针，指向myfunc函数
	pfun(); // 调用myfunc函数
	pFun = glFun; // pFun是一个函数指针，指向glFun函数
	(*pFun)(10); // 调用glFun函数     //使用指针解引用 *pFun 来获取函数，然后传递参数 (10) 给函数。这种写法非常明确，可以清晰地看到你在调用一个函数指针。
	pFun(100); //这是一种简化的写法，它将函数指针当作函数名来使用，直接传递参数(100) 给函数指针。编译器会自动解引用函数指针并调用函数。这种写法更加简洁，但也可能引起一些混淆，因为函数指针的调用看起来就像在调用普通函数。
}