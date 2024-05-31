//静态变量

//当变量声明为static时，空间将在程序的生命周期内分配。
//即使多次调用该函数，静态变量的空间也只分配一次，前一次调用中的变量值通过下一次函数调用传递。

#include <iostream>
#include <string>
using namespace std;

// (1)函数中的静态变量
void demo() {
	static int i = 0; // i是一个静态变量
	cout << i << " ";
	i++;
}

int main() {
	for (int i = 0; i < 5; i++) {
		demo();
	}
	return 0;
}
// 输出：0 1 2 3 4
//在上面的程序中看到变量count被声明为static。因此，它的值通过函数调用来传递。每次调用函数时，都不会对变量计数进行初始化。


// (2)类中的静态变量
//由于声明为static的变量只被初始化一次，因为它们在单独的静态存储中分配了空间，因此类中的静态变量由对象共享。
//对于不同的对象，不能有相同静态变量的多个副本。也是因为这个原因，静态变量不能使用构造函数初始化。

class Apple {
public:
	static int i;

	Apple() {// 静态成员变量不能在初始化列表中初始化
		//i = 0; //error 静态成员变量不能在构造函数中初始化
	};
};

int main() {
	Apple obj1;
	Apple obj2;
	obj1.i = 1;
	obj2.i = 2;
	cout << obj1.i << " " << obj2.i;
	return 0;
}
// 输出：2 2

//类中的静态变量应由用户使用类外的类名和范围解析运算符显式初始化
class Banana {
	public:
		static int i;

		Banana() {

		};
};
int Banana::i = 1; //正确 静态成员变量在类外初始化

int main() {
	Banana obj;
	cout << obj.i;
	return 0;
}
// 输出：1