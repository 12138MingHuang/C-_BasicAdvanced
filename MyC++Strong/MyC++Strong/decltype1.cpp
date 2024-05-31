/**
 * @file decltype1.cpp
 * @brief decltype那些事
 * 基本使用
 * decltype(expression)
 * 这里的括号是必不可少的，decltype的作用是"查询表达式的类型"，因此，上诉语句的效果是返回expression的类型。
 * 注意，decltype仅仅"查询"表达式的类型，而不会对表达式进行求值。
 * @auther bin.zhang
 * @date 2024.05.17
 */


// 推导出表达式的类型
#include <vector>
#include <iostream>

using namespace std;

//int i = 4;
//decltype(i) a; // a的类型是int

// 与using/typedef结合使用, 用于定义类型

//using size_t = decltype(sizeof(0)); // sizeoft(a)的返回值是size_t类型
//using ptrdiff_t = decltype((int*)0 - (int*)0);
//using nullptr_t = decltype(nullptr);
// 这样和auto一样，也可以用于定义复杂的类型

// 重用匿名类型
// 在C++中，有时候会遇到一些匿名类型
//struct {
//	int d;
//	double b;
//} anon_s;
// 而借助decltype，可以重新使用这个匿名的结构体
//decltype(anon_s) as; // as的类型是struct {int d; double b;}

// 泛型编程结合auto，用于追踪函数的返回值类型
// 这也是decltype最大的用途之一
template <typename T>
auto multiply(T x, T y) -> decltype(x* y) {
	return x * y;
}


int main() {
	int nums[] = {1, 2, 3, 4, 5};
	vector<int> vec(nums, nums + 5);
	vector<int>::iterator it;
	
	for (it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << endl;

	using nullptr_t = decltype(nullptr);
	nullptr_t np = nullptr;
	int* p = NULL;
	if (np == p)
		cout << "np == p" << endl;
	else
		cout << "np != p" << endl;

	typedef decltype(vec.begin()) vectype; // vectype的类型是vector<int>::iterator
	for (vectype i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;

	struct {
		int d;
		double b;
	} anon_s;
	decltype(anon_s) as{1, 2.0};
	cout << multiply(11, 2) << ":" << as.b << endl;

	return 0;
}