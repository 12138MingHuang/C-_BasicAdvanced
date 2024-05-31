/**
 * @file using_global.cpp
 * @brief using�Ļ���ʹ�� ȫ��
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
	using ns1::func; // ns1�еĺ���

#elif isGlobal
	using ::func; // ȫ���еĺ���
#else
	void func() {
		cout << "other::func" << endl;
	}
#endif
}

int main() {
	/**
	* �����Ϊʲô��C++��ʹ����cmath������math.h��ԭ����Ϊcmath�еĺ���������std�����ռ��еģ���math.h�еĺ���������ȫ�������ռ��еġ�
	*/

	ns2::func();

	return 0;
}