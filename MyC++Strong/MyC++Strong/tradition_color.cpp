/**
 * @file tradition_color.cpp
 * @brief 从初级到高级的enum那些事
 * 传统行为
 * 枚举有以下问题：作用域不受限，会容易引起命名冲突
 * @auther bin.zhang
 * @date 2024.05.17
 */

#include <iostream>

enum Color {
	Red,
	Blue,
	Green
};
enum Feeling {
	Excited,
	Blue
};

int main() {
	//Color color = Blue;
	Feeling feeling = Blue;
	std::cout << feeling << std::endl;
	return 0;
}

// 会隐式转换为int，导致编译错误
// 用来表征枚举变量的实际类型不能明确指定，从而无法支持枚举类型的前向声明