/**
 * @file interesting_facts1.cpp
 * @brief 纯虚函数 使得一个可变成抽象类
 * @author bin.zhang
 * date 2023-10-23
 */

#include <iostream>

using namespace std;

/**
 * @brief 抽象类必须包含一个纯虚函数
 */
class Test {
	int x;

	public:
		virtual void show() = 0; // 纯虚函数
		int getX() { return x; }
};

int main(void) {
	//Test t; // error 抽象类不能创建对象
	return 0;
}