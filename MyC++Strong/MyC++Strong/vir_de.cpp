/**
 * @file vir_de.cpp
 * @brief ���������������û�б�����
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
	public:
		Base() { cout << "Constructing Base" << endl; }

		~Base() { cout << "Destructing Base" << endl; }
};

class Derived : public Base {
	public:
		Derived() { cout << "Constructing Derived" << endl; }

		~Derived() { cout << "Destructing Derived" << endl; }
};

int main(void) {
	Derived *d = new Derived();
	Base *b = d;
	delete b;

	return 0;
}