/**
 * @file warn_rtti.cpp
 * @brief 在面对对象程序设计中，有时候我们需要在运行时查询一个对象是否能作为某种多态类型使用，与Java的instanceof类似
 * 以及C#的is和as操作符类似，C++提供了dynamic_cast函数来用于动态转型，相比于C风格的强制类型转换和C++的reinterpret_cast，而dynamic_cast
 * 提供了类型安全检查，是一种基于能力查询的转换，所以在多态类型间进行转换时，dynamic_cast是最安全的转换方式
 * @auther bin.zhang
 * @date 2024.04.30
 */

//在使用时需要注意：被转换对象obj的类型T1必须是多态类型，
//即T1必须公有继承自其它类，或者T1拥有虚函数（继承或自定义）。若T1为非多态类型，使用dynamic_cast会报编译错误。

#include <iostream>

using namespace std;

//A为非多态类型，因为它没有虚函数
class A {};

//B为多态类型
class B {
	public:
		virtual ~B() {}
};

//D为非多态类型
class D : public A {};

//E为非多态类型
class E : private A {};

//F为非多态类型
class F : private B {};

int main() {
	
}