/**
 * @file interesting_facts5.cpp
 * @brief 构造函数不能是虚函数，而析构函数可以是虚析构函数
 * 例如：当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。如果析构函数不是虚拟的，那么只会调用基类的析构函数，而不会调用派生类的析构函数。
 * @author bin.zhang
 * date 2023-11-02
 */

#include <iostream>

using namespace std;
class Base {
public:
	Base() {
		cout << "Constructing Base \n";
	}
	virtual ~Base() {
		cout << "Destructing Base \n";
	}
};
class Derived :public Base {
public:
	Derived() {
		cout << "Constructing Derived \n";
	}
	~Derived() {
		cout << "Destructing Derived \n";
	}
};

int main(void) {
	Base *b = new Derived();
	delete b;
	return 0;
}