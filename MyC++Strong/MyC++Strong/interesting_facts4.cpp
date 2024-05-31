/**
 * @file interesting_facts4.cpp
 * @brief ����������й��캯��
 * @author bin.zhang
 * date 2023-11-02
 */

#include <iostream>

using namespace std;
class Base {
protected:
	int x;

public:
	virtual  void fun() = 0;
	Base(int i):x(i) {}
};
class Derived :public Base {
	int y;

public:
	Derived(int i, int j) :Base(i), y(j) {}
	void fun() override {
		cout << "x=" << x << ",y=" << y << endl;
	}
};

int main(void) {
	Derived d(4, 5);
	d.fun();

	return 0;
}