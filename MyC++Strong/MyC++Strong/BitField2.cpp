/**
 * @file BitField2.cpp
 * @brief 位域或位段是一种数据结构，可以把数据以位的形式紧凑的储存，并且允许对此结构的位进行操作
 * 这种数据结构的一个好处是它可以使数据单元节省储存空间，当程序需要成千上万个数据单元时，这种方法就显得尤为重要
 * 第二个好处是位段可以很方便的访问一个整数的部分内容从而可以简化程序源代码。
 * 而这种数据结构的缺点是在于，位域实现依赖于具体的机器和系统，在不同平台可能有不同的结果，这导致了位域在本质上是不可移植的
 * 位域在内存中的布局是与机器有关的。
 * 位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定。
 * 取地址符号&不能用于位域，因为位域不是存储在内存中的独立位置，所以不能对位域使用&运算符。任何指针都不能指向类的位域。
 * @auther bin.zhang
 * @date 2024.05.07
 */

// 位域的大小和对齐
// 位域的大小
struct box {
	unsigned int a : 1;
	unsigned int   : 3;
	unsigned int b : 4;
};
// 该结构体中间有一个未命名的位域，占据3Bits,仅仅起了填充作用，不占用内存空间。填充使得该结构总共使用了8Bits。
// C中使用unsigned int作为为域的基本单位，即使一个结构的唯一成员为1Bits的位域，该结构大小也和一个unsigned int 大小相同
// 有些系统中，unsigned int 大小为16Bits,在x86系统中为32Bits

// 位域的对齐
// 一个位域成员不允许跨越两个unsigned int的边界，如果成员的声明的总位数超过了一个unsigned int的大小，那么编辑器会自动
// 移位位域成员，使其按照unsigned int的边界对齐
struct stuff {
	unsigned int field1 : 30;
	unsigned int field2 : 4;
	unsigned int field3 : 3;
};

// field + field2 = 34Bits,超过了一个unsigned int的大小，编辑器会自动移位field2，使其按照unsigned int的边界对齐
// stuff.field1和stuff.field2之间会留下一个2Bits的空隙，stuff.field3紧跟在stuff.field2后面，该结构现在大小为2*32=64Bits
// 这个空隙可以用之前提到的未命名位域来填充，也可以用一个宽度为0的未命名位域成员与下一个整数对齐

struct stuff1 {
	unsigned int field1 : 30;
	unsigned int        : 2;
	unsigned int field2 : 4;
	unsigned int		: 0;
	unsigned int field3 : 3;
};

// 这里stuff.field1和stuff.field2之间有一个2Bits的空隙，stuff.field3则存储在下一个unsigned int中，该结构大小为3*32=96Bits

#include <iostream>

using namespace std;

int main() {
	struct stuff1 s = { 1,3,5 };
	cout << s.field1 << endl;
	cout << s.field2 << endl;
	cout << s.field3 << endl;
	cout << sizeof(s) << endl;

	return 0;
}