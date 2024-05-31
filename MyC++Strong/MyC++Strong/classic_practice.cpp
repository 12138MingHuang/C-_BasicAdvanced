/**
 * @file classic_practice.cpp
 * @brief 从初级到高级的enum那些事
 * 经典行为
 * 解决作用域不受限带来的命名冲突问题的一个简单方法是，给枚举变量命名时加上前缀，如COLOR_BLUE，FEELING_BLUE
 * 一般来说，为了一致性我们会把所有常量统一加上前缀。但是这样定义枚举变量的代码就显得累赘。
 * C语言程序中可能不得不这样做，不过C++程序就不喜欢用这样的方法，替代方案是命名空间
 * @auther bin.zhang
 * @date 2024.05.19
 */

#include <iostream>
using namespace std;

namespace Color {
	enum Type {
		Red,
		Blue,
		Green
	};
}

// 这样之后就可以用Color::Type c = Color::Red;来定义枚举变量了。如果using namespace Color后，前缀还可以省去，使得代码更加简洁
// 不过，因为命名空间是可以随后被扩充内容的，所以它提供的作用域封闭性不高，在大项目中，还是有可能不同人给不同的东西起同样的枚举类型名
// 更有效的办法是同一个类或结构体来限定其作用域，例如：定义新变量的方法和上面命名空间的相同。
// 不过这样就不用担心类在别处被修改内容，这里用结构体而非类，是因为本身希望这些常量可以公开访问。

struct Color1 {
	enum Type {
		Red,
		Blue,
		Green
	};
};


// C++11中的枚举类
// 上面的做法解决了第一个问题，但对于后两个仍无能为力。C++11中引入了枚举类，解决了这些问题。
// 新的enum的作用域不再是全局的，而是在类内部，这样就不会引起命名冲突了。
// 不能隐式转换成其他类型

/**
 * @brief 枚举类
 * 下面等价于enum class Color2:int
*/
enum class Color2 {
	Red = 2,
	Yellow,
	Blue
};

// 可以指定用特定的类型来存储enum
enum class Color3 : char {
	Red = 'r',
	Yellow = 'y',
	Blue = 'b'
};

int main() {
	Color2 c2 = Color2::Red;
	cout << static_cast<int>(c2) << endl;

	char c3 = static_cast<char>(Color3::Red);
	cout << c3 << endl;

	return 0;