/**
 * @file decltype2.cpp
 * @brief decltype那些事
 * 判别规则
 * decltype(e)
 * 对于decltype(e)而言，其判别结果受以下条件影响
 * 如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么decltype(e)就是e所命名的实体的类型。
 * 此外，如果e是一个被重载的函数，则会导致编译错误。
 * 否则，假设e的类型是T，如果e是一个将亡值，那么decltype(e)就是T&&。
 * 否则，假设e的类型是T，如果e是一个左值，那么decltype(e)就是T&。
 * 否则，假设e的类型是T，那么decltype(e)就是T。
 * 标记符指的是除去关键字、字面量等编译器需要使用的标记之外的程序员自己定义的标记，而单个标记对应的表达式就是标记符表达式。例如
 * int arr[4];
 * 则arr就是一个标记符，而arr[3] + 0就不是标记符。
 * @auther bin.zhang
 * @date 2024.05.17
 */

int main() {
	int i = 4;
	int arr[5] = { 0 };
	int *ptr = arr;
	struct S {
		double d;
	} s;
	void Overloaded(int);
	void Overloaded(char);
	int && RvalRef();
	const bool Func(int);

	// 规则1：推导为其类型
	decltype(arr) var1; // int[]标记符表达式
	decltype(ptr) var2; // int*标记符表达式
	decltype(s.d) var3; // double类成员访问表达式
	//decltype(Overloaded) var4; // 重载函数，编译错误

	// 规则2：将亡值，推导为类型的右值引用
	decltype(RvalRef()) var5 = 1; // int&&

	// 规则3：左值，推导为类型的左值引用
	decltype((i)) var6 = i; // int&
	decltype(true ? i : i) var7 = i; // int& 条件表达式返回左值
	decltype(++i) var8 = i; // int& 前置递增返回左值
	decltype(arr[5]) var9 = i; // int& []下标操作返回左值
	decltype(*ptr) var10 = i; // int& *解引用操作返回左值
	decltype("hello") var11 = "hello"; // const char(&)[9] 字符串字面常量为左值,且为const左值

	// 规则4：以上都不是，推导为类型本身
	decltype(1) var12; // const int
	decltype(Func(1)) var13 = true; // const bool
	decltype(i++) var14 = i; // int i++返回右值
	
	return 0;
}