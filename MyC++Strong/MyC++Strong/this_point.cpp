//this指针
//（1）一个对象的this指针并不是对象本身的一部分，不会影响sizeof(对象)的结果。
//（2）this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。
//也就是说，即使你没有写上this指针，编译器在编译的时候也是加上this的，它作为非静态成员函数的隐含形参，对各成员的访问均通过this进行。

//this指针的使用：
//（1）在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this。
//（2）当参数与成员变量名相同时，如this->n = n （不能写成n = n)。

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	typedef enum {
		BOY = 0,
		GIRL
	} SexType;
	/*使用 strcpy 函数时遇到了一个编译错误，错误信息提到 strcpy 可能不安全，建议使用 strcpy_s。
	这是因为 strcpy 在C++中被认为是不安全的，因为它没有边界检查，可能导致缓冲区溢出。
	strcpy_s 是C11标准引入的安全版本的字符串拷贝函数。
	或者在警告代码段加上 #pragma warning(disable : 4996) 来绕过此警告*/
	//#pragma warning(disable : 4996)  // 禁用C4996警告
	Person(const char* n, int a, SexType s) {
		//为 name 成员变量分配内存，strlen(n) + 1 是为了存储字符串 n 的内容以及字符串结尾的空字符 '\0'。
		//在C字符串中，字符串以空字符 '\0' 结尾。这个空字符表示字符串的结束，但它本身并不包含在字符串的长度内。
		//strlen 函数用于计算字符串的长度，但不包括结尾的空字符。
		//因此，当我们为存储字符串的数组分配内存时，我们需要额外的一个字节来存储结尾的空字符 '\0'。
		//所以 + 1 的目的是为了确保分配的内存足够大，以容纳整个字符串内容以及结尾的空字符。
		name = new char[strlen(n) + 1]; //或者写成this->name = new char[strlen(n) + 1];
		//使用 strcpy_s 函数将参数 n 指向的字符串拷贝到 name 成员变量所指向的内存中。
		strcpy_s(name, strlen(n) + 1, n);
		//strcpy(name, n);
		age = a;
		sex = s;
	}
	//#pragma warning(default : 4996)  // 恢复C4996警告
	int get_age() const {
		return this->age;
	}
	Person& add_age(int a) {
		age += a;
		return *this;
	}
	~Person() {
		delete[]name;
	}

private:
	char* name;
	int age;
	SexType sex;
};

int main() {
	Person p("ZhangSan", 20, Person::BOY);
	cout << p.get_age() << endl;
	cout << p.add_age(5).get_age() << endl;
	return 0;
}

//总结：this在成员函数的开始执行前构造，在成员的执行结束后清除。
//上述的get_age函数会被解析成get_age(const A* const this), add_age函数会被解析成add_age(A* const this, int a)。
//在C++中类和结构是只有一个区别的：类的成员默认是private，而结构是public。this是类的指针，如果换成结构，那this就是结构的指针了。