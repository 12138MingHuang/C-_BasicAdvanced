#include <iostream>
extern "C" {
	#include "add.h"
}

using namespace std;

int main() {
	add(2, 3);

	return 0;
}

// 没有添加extern "C" 报错

// 应该改成
// extern "C" {
	// #include "add.h"
//};