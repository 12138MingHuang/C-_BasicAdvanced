/**
 * @file add.cpp
 * @brief C++与C编译的区别
 * C++调用C函数
 * 在C++中常在头文件见到extern "C"修饰函数，是用于C++链接在C语言模块中定义的函数
 * C++虽然兼容C，但C++文件中编译后生成的符号与C语言生成的不同。因为C++支持重载，C++函数编译后产生的符号是带有参数类型的，而C语言没有
 * 例如int add(int a, int b)函数经过C++编译器生成.o文件后，add会变成形如add_int_int的符号之类的，而C的话则会是形如_add,就是说：
 * 相同的函数，在C与C++中，编译后产生的符号不同。
 * 这就导致一个问题：如果C++中使用C语言实现的函数，在编译链接的时候，会报错，提示找不到对应的符号。
 * 此时extern "C"就起了作用：告诉链接器去寻找_add这类的C语言符号，而不是经过C++修饰的符号
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include "add.h"

int add(int x, int y) {
	return x + y;
}



//综上，总结出使用方法，在C语言的头文件中，对其外部函数只能指定为extern类型，C语言中不支持extern "C"声明，
//在.c文件中包含了extern "C"时会出现编译语法错误。所以使用extern "C"全部都放在于cpp程序相关文件或其头文件中。
//
//总结出如下形式：
//
//（1）C++调用C函数：
//
////xx.h
//extern int add(...)
//
////xx.c
//int add() {
//
//}
//
////xx.cpp
//extern "C" {
//#include "xx.h"
//}
//（2）C调用C++函数
//
////xx.h
//extern "C" {
//    int add();
//}
////xx.cpp
//int add() {
//
//}
////xx.c
//extern int add();
//不过与C++调用C接口不同，C++确实是能够调用编译好的C函数，而这里C调用C++，不过是把C++代码当成C代码编译后调用而已。
//也就是说，C并不能直接调用C++库函数。