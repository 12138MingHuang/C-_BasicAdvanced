//静态成员


//(1)类对象为静态
//就像变量一样，对象也在声明为static时具有范围，直到程序的生命周期。

//比如以下，其中对象是非静态的。
#include <iostream>
using namespace std;

class Apple {
	int i;
	public:
		Apple() {
			i = 0;
			cout << "Inside Constructor\n";
		}
		~Apple() {
			cout << "Inside Destructor\n";
		}
};

int main() {
	int x = 0;
	if (x == 0) {
		Apple obj;
	}
	cout << "End of main\n";
}
// 输出：
//Inside Constructor
//Inside Destructor
//End of main
//在上面的程序中，对象在if块内声明为非静态。因此，变量的范围仅在if块内。
//因此，当创建对象时，将调用构造函数，并且在if块的控制权越过析构函数的同时调用，因为对象的范围仅在声明它的if块内。


//如果我们将对象声明为静态
class Banana {
	int i;
	public:
		Banana() {
			i = 0;
			cout << "Inside Constructor\n";
		}
		~Banana() {
			cout << "Inside Destructor\n";
		}
};

int main() {
	int x = 0;
	if (x == 0) {
		static Banana obj;
	}
	cout << "End of main\n";
}
// 输出：
//Inside Constructor
//End of main
//Inside Destructor
//现在，在main结束后调用析构函数。这是因为静态对象的范围是贯穿程序的生命周期。


//类中的静态成员函数
//就像类中的静态数据成员或静态变量一样，静态成员函数也不依赖于类的对象。
//我们被允许使用对象和'.'来调用静态成员函数。但建议使用类名和范围解析运算符调用静态成员。
//允许静态成员函数仅访问静态数据成员或其他静态成员函数，它们无法访问类的非静态数据成员或成员函数。

class Apple {
	public:
		void print() {
			cout << "Hello";
		}
		static void printMsg() {
			//print(); //error 静态成员函数不能调用非静态成员函数
			cout << "Welcome to Apple!\n";
		}
};

int main() {
	Apple obj;
	obj.printMsg();// 也可以使用对象调用，但不推荐

	Apple::printMsg();// 推荐方式
	return 0;

	//1.易于理解：通过使用类名，你明确地表明这是一个静态成员函数，而不是实例方法。
	//2.代码的可读性：这有助于提高代码的可读性，因为它明确地指示这是一个静态操作，不需要一个具体的对象来调用它。
	//3.避免不必要的对象创建：如果你使用对象来调用静态成员函数，你会创建一个临时对象，这可能会引入不必要的开销和复杂性。
}
// 输出：
//Welcome to Apple!
//Welcome to Apple!
