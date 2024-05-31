/**
 * @file decltype1.cpp
 * @brief decltype��Щ��
 * ����ʹ��
 * decltype(expression)
 * ����������Ǳز����ٵģ�decltype��������"��ѯ���ʽ������"����ˣ���������Ч���Ƿ���expression�����͡�
 * ע�⣬decltype����"��ѯ"���ʽ�����ͣ�������Ա��ʽ������ֵ��
 * @auther bin.zhang
 * @date 2024.05.17
 */


// �Ƶ������ʽ������
#include <vector>
#include <iostream>

using namespace std;

//int i = 4;
//decltype(i) a; // a��������int

// ��using/typedef���ʹ��, ���ڶ�������

//using size_t = decltype(sizeof(0)); // sizeoft(a)�ķ���ֵ��size_t����
//using ptrdiff_t = decltype((int*)0 - (int*)0);
//using nullptr_t = decltype(nullptr);
// ������autoһ����Ҳ�������ڶ��帴�ӵ�����

// ������������
// ��C++�У���ʱ�������һЩ��������
//struct {
//	int d;
//	double b;
//} anon_s;
// ������decltype����������ʹ����������Ľṹ��
//decltype(anon_s) as; // as��������struct {int d; double b;}

// ���ͱ�̽��auto������׷�ٺ����ķ���ֵ����
// ��Ҳ��decltype������;֮һ
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

	typedef decltype(vec.begin()) vectype; // vectype��������vector<int>::iterator
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