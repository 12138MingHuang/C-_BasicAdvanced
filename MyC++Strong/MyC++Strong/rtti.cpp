/**
 * @file rtti.cpp
 * @brief 在面对对象程序设计中，有时候我们需要在运行时查询一个对象是否能作为某种多态类型使用，与Java的instanceof类似
 * 以及C#的is和as操作符类似，C++提供了dynamic_cast函数来用于动态转型，相比于C风格的强制类型转换和C++的reinterpret_cast，而dynamic_cast
 * 提供了类型安全检查，是一种基于能力查询的转换，所以在多态类型间进行转换时，dynamic_cast是最安全的转换方式
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class B {
	virtual void fun() {}
};

class D : public B {};

int main() {
	B* b = new D; //向上转型
	B& obj = *b;
	D* d = dynamic_cast<D*>(b); //向下转型

	if (d != NULL)
		cout << "works" << endl;
	else
		cout << "cannot cast B* to D*" << endl;

	try {
		D& dobj = dynamic_cast<D&>(obj);
		cout << "works" << endl;
	}
	catch (bad_cast bc) {
		cout << bc.what() << endl;
	}

	const std::type_info& ti = typeid(d); // 获取类型信息
	std::cout << "Type of i: " << ti.name() << std::endl; // 输出类型的名称

	return 0;
}

//在使用 dynamic_cast 进行类型转换时，基类必须至少拥有一个虚函数，否则编译器会报错。