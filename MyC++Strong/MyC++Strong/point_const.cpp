//指针与const

const char* a; //指向const对象的指针或者说指向常量的指针
char const* a; //指向const对象的指针或者说指向常量的指针，与上面等价
char* const a; //指向类型对象的const指针，const指针或者说常指针，指针指向不可变，但是指向的值可以变
const char* const a; //指向const对象的const指针，指针指向不可变，且指向的值也不可变

// 小结1：如果const位于星号左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
// 小结2：如果const位于星号右侧，const就是修饰指针本身，即指针本身是常量。

// (1) 指向常量的指针，指针指向可以变，但是指向的值不可以变
const int* ptr;
// *ptr = 10; //错误，指向的值不可以变
// ptr是一个指向int类型const对象的指针，const定义的是int类型，也就是ptr所指向的对象类型，而不是ptr本身，所以ptr可以不用赋初始值。但是不能通过ptr去修改所指对象的值。
// 除此之外，也不能使用void* 指针保存const对象的地址，必须使用const void* 类型的指针保存const对象的地址。
const int a = 10;
void* va = &a; //错误，不能使用void*指针保存const对象的地址
const void* va = &a; //正确，使用const void*指针保存const对象的地址
// 另外一个重点是：允许把非const对象的地址赋给指向const对象的指针，但是反过来不行。
const int* ptr2;
int val = 3;
//ptr2 = &val; //正确，把非const对象的地址赋给指向const对象的指针

// (2) 常指针，指针指向不可以变，但是指向的值可以变，且必须初始化
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int b = 20;
	int* const ptr = &a; // const指针必须初始化
	//ptr = &b; //错误(编译不通过)，指针指向不可以变
	*ptr = 30; //正确，指针指向的值可以变

	const int c = 10;
	//int* const ptr2 = &c; //错误(编译不通过)，ptr2是const指针，不能指向const对象，ptr2指向的是一个变量，而不是const常量
	//上述若改为 const int *ptr2或者改为const int *const ptr2，都可以正常！
	//const int* const ptr2 = &c; //正确，ptr2是const指针，且指向const对象
	//const int* ptr2 = &c; //正确，ptr2是指向const对象的指针
	return 0;
}

// (3) 指向常量的常指针，指针指向不可以变，指向的值也不可以变，且必须初始化
const int p = 10;
const int* const ptr = &p; //正确，ptr是一个指向const对象的const指针, ptr是一个const指针，且指向const对象