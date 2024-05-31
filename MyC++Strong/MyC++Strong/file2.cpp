#include <iostream>
using namespace std;

//要使变量能够在其他文件中访问，必须在文件中显式地指定它为extern。
//变量在不同文件的访问
extern int ext; //在file2.cpp中定义一个新的ext值，编译器将在链接时将file1.cpp和file2.cpp这两个ext定义合并为一个全局变量
int main3() {
	cout << ext+10 << endl;
	ext = 42; // 这将导致编译错误，因为在file2.cpp中没有定义ext的新值

	return 0;
}