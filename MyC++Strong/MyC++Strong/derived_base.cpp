/**
 * @file derived_base.cpp
 * @brief using的基本使用 改变访问性
 * @auther bin.zhang
 * @date 2024.05.17
 */

#include <cstddef>
class Base {
	public:
		std::size_t size() const {
			return n;
		}
	protected:
		std::size_t n;
};

class Detived : private Base {
	public:
		using Base::size;
	protected:
		using Base::n;
};

// 类Detived私有继承了类Base，对于它来说成员变量n和成员函数size都是私有的，如果使用了using语句，可以改变他们的可访问性
// 如上诉例子，size可以按public的权限访问，n可以按protect的权限访问