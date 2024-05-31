#include <iostream>
using namespace std;

// const的含义
// 常类型是指使用类型修饰符const说明的类型，常类型的对象或变量，一旦创建后其值就不能被改变
// 1.定义常量
const int a = 10;

//防止修改，起保护作用，增强程序的健壮性
void test01(const int i) {
	//i++; //报错
}

int main1() {
	const int myConst = 10;
	int myVar = 5;

	// 下面这行代码时合法的，因为myConst有明确的类型（int）
	myVar = myConst;

	// 下面这行代码会导致编译报错，因为myConst时常量，不能被修改
	// 试图修改一个常量会引发编译错误
	// myConst = 20;

	cout<< "myVar = " << myVar << endl;

	return 0;
}


//#define MY_MACRO 10为什么编译器会提示宏可以转换为constexpr

// 当您定义一个宏使用#define关键字时，它实际上是一个文本替换。
// 编译器在预处理阶段会将宏的所有引用替换为宏的文本内容。
// 如果您在代码中使用这个宏，编译器会将其替换为10。
// 然后，由于它是一个编译时已知的常量，编译器可能会自动将其视为constexpr。

// 这意味着在某些情况下，如果您使用一个宏，而宏的值是在编译时就已知的，编译器可能会将其视为constexpr 常量。
// 这并不是说宏本身就是constexpr，而是它的值可以在编译时计算，并且在一些上下文中，编译器可能会将其视为constexpr。

// 宏定义只是简单的文本替换
// 因为MY_MACRO没有数据类型，而且它只是简单的文本替换
#define MY_MACRO 10

int main2() {
	int myVar = 5;

	// 下面这行代码实际上是这样的：myVar = 10;
	myVar = MY_MACRO;

	// 下面这行代码会导致编译错误，因为宏定义不能被修改
	// MY_MACRO = 20;

	myVar = MY_MACRO;

	std::cout << "myVar: " << myVar << std::endl;
	return 0;
}


const int runtimeConst = 10; // const变量，值在运行时确定
constexpr int compileTimeConst = 20; // constexpr变量，值在编译时确定


// 内存分配：
// const 定义的常量在内存中分配一份存储空间，因此占用实际的内存。
// #define 定义的宏常量不会分配内存，它们只是文本替换，因此不占用额外的内存。

// 多次求值：
// const 常量在程序中只有一份拷贝，因此无论多少次使用它，它都是同一个值。
// #define 宏常量在每次使用时都会进行文本替换，因此在代码中可能会有多个拷贝。

// 类型信息：
// const 常量具有明确的数据类型，因此在使用时需要进行类型转换。
// #define 宏常量是文本替换，没有类型信息，因此在使用时不需要类型转换。

// 虽然 #define 定义的宏常量可以减少内存使用，但它们缺乏类型信息，可能会引发类型错误。
// 另一方面，const 常量具有类型信息，因此在使用时更安全，但会占用额外的内存。
// 在编程时，通常应该优先选择使用 const 常量，因为它们提供了更多的类型安全性和可读性，并且通常不会对内存使用造成显著的影响。
// #define 宏常量通常更适合一些特殊的情况，例如需要进行文本替换的宏定义，而不是用于定义常量值。


const int b = 10;
//b = 0; // 错误，b是常量，不能被修改
const string s = "hello";
//const int i,j=0 // 错误，i 为常量，必须进行初始化！(因为常量在定义后就不能被修改，所以定义时必须初始化。)


