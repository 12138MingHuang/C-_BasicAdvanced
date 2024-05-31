/**
 * @file define1.cpp
 * @brief 宏定义
 * @auther bin.zhang
 * @date 2024.05.31
 */

// 宏中包含特殊符号
// # ## \

// 字符串化操作符(#)
// 在一个宏中的参数前面使用一个#，预处理器会把这个参数转换为一个字符数组
// 换言之就是#是字符串化的意思，出现在宏定义中的#是把跟在后面的参数换成一个字符串
// 注意：其只能用于有传入参数的宏定义中，且必须置于宏定义体中的参数名前

#include <string>
#include <iostream>

using namespace std;

#define exp(s) printf("test s is: %s\n",s)
#define exp1(s) printf("test s is: %s\n",#s)
#define exp2(s) #s

int main() {
	exp("hello");
	exp1(hello);

	string str = exp2(  bac  );
	cout << str << " " << str.size() << endl;

	/**
	 * 忽略传入的参数名前面和后面的空格
	 */
	string str1 = exp2( asda  bac  );
	/**
	 * 当传入参数名中间存在空格时，编译器会自动连接各个子字符串
	 * 用每个子字符串之间以一个空格连接，忽略剩余空格
	 */
	cout << str1 <<" " << str1.size() << endl;

	return 0;
}


// 符号连接操作符(##)
// ##是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。将宏定义的多个形参转换成一个实际的参数名
// 当用##连接形参时，##前后的空格可有可无
// 连接后的实际参数名，必须为实际存在的参数名或是编译器已知的宏定义
// 如果##后的参数本身也是一个宏的话，##会阻止这个宏的展开


#define expA(s) printf("前缀加上后的字符串为:%s\n",gc_##s)  //gc_s必须存在
// 注意事项2
#define expB(s) printf("前缀加上后的字符串为:%s\n",gc_  ##  s)  //gc_s必须存在
// 注意事项1
#define gc_hello1 "I am gc_hello1"
int main() {
	// 注意事项1
	const char* gc_hello = "I am gc_hello";
	expA(hello);
	expB(hello1);
}


// 续行操作符（\）
// 当定义的宏不能用一行表达完整时，可以用”\”表示下一行继续此宏的定义。
// 注意 \ 前留空格。

#define MAX(a,b) ((a)>(b) ? (a) \
   :(b))  
int main() {
	int max_val = MAX(3, 6);
	cout << max_val << endl;
}