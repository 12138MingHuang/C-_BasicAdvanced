/**
 * @file derived_full.cpp
 * @brief 抽象类由派生类继承实现
 * author bin.zhang
 * date 2023-11-02
 */

#include <iostream>

 using namespace std;
 class Base {
	 int x;

 public:
	 virtual void fun() = 0;
	 int getX() { return x; }
 };
 class Derived :public Base {
 public:
	 void fun() override {
		 cout << "fun() called"; //实现了fun()函数
	 }
 };

 int main(void) {
	 Derived d;
	 d.fun();
	 return 0;
 }