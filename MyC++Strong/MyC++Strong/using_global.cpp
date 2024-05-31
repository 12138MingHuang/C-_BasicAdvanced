/**
 * @file using_global.cpp
 * @brief using的基本使用 全局
 * @auther bin.zhang
 * @date 2024.05.17
 */

#include <iostream>
#define isNs1 1
//#define isGlobal 2
using namespace std;

void func() {
	cout << "::func()" << endl;
}

namespace ns1 {
	void func() {
		cout << "ns1::func()" << endl;
	}
}

namespace ns2 {

#ifdef isNs1
	using ns1::func; // ns1中的函数

#elif isGlobal
	using ::func; // 全局中的函数
#else
	void func() {
		cout << "other::func" << endl;
	}
#endif
}

int main() {
	/**
	* 这就是为什么在C++中使用了cmath而不是math.h的原因，因为cmath中的函数都是在std命名空间中的，而math.h中的函数都是在全局命名空间中的。
	*/

	ns2::func();

	return 0;
}