/**
 * @file full_virde.cpp
 * @brief ���������������麯��
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
	Base() { cout << "Constructing Base" << endl; }

	virtual ~Base() { cout << "Destructing Base" << endl; }
};

class Derived : public Base {
public:
	Derived() { cout << "Constructing Derived" << endl; }

	~Derived() { cout << "Destructing Derived" << endl; }
};

int main(int argc, char* argv[]) {
	// ��������в����ĸ���
	std::cout << "Number of command-line arguments: " << argc << std::endl;

	// ���ÿ�������в���
	std::cout << "Command-line arguments:" << std::endl;
	for (int i = 0; i < argc; ++i) {
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
	}
	Derived* d = new Derived();
	Base* b = d;
	delete b;

	return 0;
}