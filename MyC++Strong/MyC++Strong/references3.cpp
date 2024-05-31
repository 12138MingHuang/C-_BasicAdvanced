/**
 * @file references3.cpp
 * @brief 引用与指针
 * 引用: 必须初始化,不能为空，不能更换目标
 * 指针: 可以不初始化，可以为空，可以更换目标
 * @auther bin.zhang
 * @date 2024.05.31
 */

// 指针与引用的性能差距

// 指针与引用之间有没有性能差距呢？这种问题就需要进入汇编层面去看一下。我们先写一个test1函数，参数传递使用指针：
void test1(int* p) {
	*p = 3;

	return;
}

//该代码段对应的汇编代码如下：
//
//(gdb) disassemble
//Dump of assembler code for function test1(int*) :
//	0x0000000000400886 < +0 > : push % rbp
//	0x0000000000400887 < +1 > : mov % rsp, % rbp
//	0x000000000040088a < +4 > : mov % rdi, -0x8(% rbp)
//	= > 0x000000000040088e < +8 > :  mov - 0x8(% rbp), % rax
//	0x0000000000400892 < +12 > : movl   $0x3, (% rax)
//	0x0000000000400898 < +18 > : nop
//	0x0000000000400899 < +19 > : pop % rbp
//	0x000000000040089a < +20 > : retq
//	End of assembler dump.
//	上述代码1、2行是参数调用保存现场操作；第3行是参数传递，函数调用第一个参数一般放在rdi寄存器，
//	此行代码把rdi寄存器值（指针p的值）写入栈中；第4行是把栈中p的值写入rax寄存器；
//	第5行是把立即数3写入到rax寄存器值所指向的内存中，此处要注意(% rax)两边的括号，
//	这个括号并并不是可有可无的，(% rax)和 % rax完全是两种意义，(% rax)代表rax寄存器中值所代表地址部分的内存，
//	即相当于C++代码中的 * p，而 % rax代表rax寄存器，相当于C++代码中的p值，所以汇编这里使用了(% rax)而不是 % rax。


// 我们再写出参数传递使用引用的C++代码段test2：
void test2(int& r) {
	r = 3;    //赋值前无需判断reference是否为空
	return;
}

//这段代码对应的汇编代码如下：
//
//(gdb) disassemble
//Dump of assembler code for function test2(int&) :
//	0x000000000040089b < +0 > : push % rbp
//	0x000000000040089c < +1 > : mov % rsp, % rbp
//	0x000000000040089f < +4 > : mov % rdi, -0x8(% rbp)
//	= > 0x00000000004008a3 < +8 > :  mov - 0x8(% rbp), % rax
//	0x00000000004008a7 < +12 > : movl   $0x3, (% rax)
//	0x00000000004008ad < +18 > : nop
//	0x00000000004008ae < +19 > : pop % rbp
//	0x00000000004008af < +20 > : retq
//	End of assembler dump.
//	我们发现test2对应的汇编代码和test1对应的汇编代码完全相同，这说明C++编译器在编译程序的时候将指针和引用编译成了完全一样的机器码。
//	所以C++中的引用只是C++对指针操作的一个“语法糖”，在底层实现时C++编译器实现这两种操作的方法完全相同

#include <iostream>
using namespace std;

class Copyable {
public:
	Copyable() {}
	Copyable(const Copyable& o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() {
	return Copyable(); // 返回一个临时对象
}
void AcceptVal(Copyable a) {}
void AcceptRef(const Copyable& a) {}

int main() {
	cout << "pass by value: " << endl;
	AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
	cout << "pass by reference: " << endl;
	AcceptRef(ReturnRvalue()); // 应该只调用一次拷贝构造函数
}

// 结论C++中引入了引用操作，在对引用的使用加了更多限制条件的情况下，保证了引用使用的安全性和便捷性，
// 还可以保持代码的优雅性。在适合的情况使用适合的操作，引用的使用可以一定程度避免“指针满天飞”的情况，
// 对于提升程序稳定性也有一定的积极意义。最后，指针与引用底层实现都是一样的，不用担心两者的性能差距。