/**
 * @file abstract_base.cpp
 * @brief
 * c++中的纯虚函数(或者抽象函数)是没有具体实现的函数，只需要声明，通过声明中赋值0来表示纯虚函数。
 * 纯虚函数：没有函数体的虚函数
 * @author bin.zhang
 * date 2023-10-23
 */

class AbstractBase {
public:
	virtual void show() = 0; // 纯虚函数
};