/**
 * @file BitField1.cpp
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

// 位域的使用
// 位域通常使用结构体声明，该结构声明为每个位域成员设置名称，并决定其宽度

/*struct bit_field_name {
	type member_name : width;
};*/

// bit_field_name: 结构体的名称
// type: 位域的类型，必须是int、unsigned int、signed int
// member_name: 位域的名称
// width: 位域的宽度

struct _PRCODE {
	unsigned int code1 : 2;
	unsigned int code2 : 2;
	unsigned int code3 : 8;
};
int main() {
	struct _PRCODE prcode;
	// 该定义使prcode包含2个2Bits位域和1个8Bits位域，可以使用结构体的成员运算符.来访问位域
	prcode.code1 = 0;
	prcode.code2 = 3;
	prcode.code3 = 102;
	// 赋值的时候需要注意值的大小不能超过位于成员的容量，例如prcode.code3为8Bits的位域成员，其容量为2^8=256,即赋值范围为[0,255]
 }