/**
 * @file decltype2.cpp
 * @brief decltype��Щ��
 * �б����
 * decltype(e)
 * ����decltype(e)���ԣ����б�������������Ӱ��
 * ���e��һ��û�д����ŵı�Ƿ����ʽ�������Ա���ʱ��ʽ����ôdecltype(e)����e��������ʵ������͡�
 * ���⣬���e��һ�������صĺ�������ᵼ�±������
 * ���򣬼���e��������T�����e��һ������ֵ����ôdecltype(e)����T&&��
 * ���򣬼���e��������T�����e��һ����ֵ����ôdecltype(e)����T&��
 * ���򣬼���e��������T����ôdecltype(e)����T��
 * ��Ƿ�ָ���ǳ�ȥ�ؼ��֡��������ȱ�������Ҫʹ�õı��֮��ĳ���Ա�Լ�����ı�ǣ���������Ƕ�Ӧ�ı��ʽ���Ǳ�Ƿ����ʽ������
 * int arr[4];
 * ��arr����һ����Ƿ�����arr[3] + 0�Ͳ��Ǳ�Ƿ���
 * @auther bin.zhang
 * @date 2024.05.17
 */

int main() {
	int i = 4;
	int arr[5] = { 0 };
	int *ptr = arr;
	struct S {
		double d;
	} s;
	void Overloaded(int);
	void Overloaded(char);
	int && RvalRef();
	const bool Func(int);

	// ����1���Ƶ�Ϊ������
	decltype(arr) var1; // int[]��Ƿ����ʽ
	decltype(ptr) var2; // int*��Ƿ����ʽ
	decltype(s.d) var3; // double���Ա���ʱ��ʽ
	//decltype(Overloaded) var4; // ���غ������������

	// ����2������ֵ���Ƶ�Ϊ���͵���ֵ����
	decltype(RvalRef()) var5 = 1; // int&&

	// ����3����ֵ���Ƶ�Ϊ���͵���ֵ����
	decltype((i)) var6 = i; // int&
	decltype(true ? i : i) var7 = i; // int& �������ʽ������ֵ
	decltype(++i) var8 = i; // int& ǰ�õ���������ֵ
	decltype(arr[5]) var9 = i; // int& []�±����������ֵ
	decltype(*ptr) var10 = i; // int& *�����ò���������ֵ
	decltype("hello") var11 = "hello"; // const char(&)[9] �ַ������泣��Ϊ��ֵ,��Ϊconst��ֵ

	// ����4�����϶����ǣ��Ƶ�Ϊ���ͱ���
	decltype(1) var12; // const int
	decltype(Func(1)) var13 = true; // const bool
	decltype(i++) var14 = i; // int i++������ֵ
	
	return 0;
}