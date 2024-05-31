/**
 * @file BitField2.cpp
 * @brief λ���λ����һ�����ݽṹ�����԰�������λ����ʽ���յĴ��棬��������Դ˽ṹ��λ���в���
 * �������ݽṹ��һ���ô���������ʹ���ݵ�Ԫ��ʡ����ռ䣬��������Ҫ��ǧ��������ݵ�Ԫʱ�����ַ������Ե���Ϊ��Ҫ
 * �ڶ����ô���λ�ο��Ժܷ���ķ���һ�������Ĳ������ݴӶ����Լ򻯳���Դ���롣
 * ���������ݽṹ��ȱ�������ڣ�λ��ʵ�������ھ���Ļ�����ϵͳ���ڲ�ͬƽ̨�����в�ͬ�Ľ�����⵼����λ���ڱ������ǲ�����ֲ��
 * λ�����ڴ��еĲ�����������йصġ�
 * λ������ͱ��������ͻ�ö�����ͣ������������е�λ�����Ϊ�������ʵ�ֶ�����
 * ȡ��ַ����&��������λ����Ϊλ���Ǵ洢���ڴ��еĶ���λ�ã����Բ��ܶ�λ��ʹ��&��������κ�ָ�붼����ָ�����λ��
 * @auther bin.zhang
 * @date 2024.05.07
 */

// λ��Ĵ�С�Ͷ���
// λ��Ĵ�С
struct box {
	unsigned int a : 1;
	unsigned int   : 3;
	unsigned int b : 4;
};
// �ýṹ���м���һ��δ������λ��ռ��3Bits,��������������ã���ռ���ڴ�ռ䡣���ʹ�øýṹ�ܹ�ʹ����8Bits��
// C��ʹ��unsigned int��ΪΪ��Ļ�����λ����ʹһ���ṹ��Ψһ��ԱΪ1Bits��λ�򣬸ýṹ��СҲ��һ��unsigned int ��С��ͬ
// ��Щϵͳ�У�unsigned int ��СΪ16Bits,��x86ϵͳ��Ϊ32Bits

// λ��Ķ���
// һ��λ���Ա�������Խ����unsigned int�ı߽磬�����Ա����������λ��������һ��unsigned int�Ĵ�С����ô�༭�����Զ�
// ��λλ���Ա��ʹ�䰴��unsigned int�ı߽����
struct stuff {
	unsigned int field1 : 30;
	unsigned int field2 : 4;
	unsigned int field3 : 3;
};

// field + field2 = 34Bits,������һ��unsigned int�Ĵ�С���༭�����Զ���λfield2��ʹ�䰴��unsigned int�ı߽����
// stuff.field1��stuff.field2֮�������һ��2Bits�Ŀ�϶��stuff.field3������stuff.field2���棬�ýṹ���ڴ�СΪ2*32=64Bits
// �����϶������֮ǰ�ᵽ��δ����λ������䣬Ҳ������һ�����Ϊ0��δ����λ���Ա����һ����������

struct stuff1 {
	unsigned int field1 : 30;
	unsigned int        : 2;
	unsigned int field2 : 4;
	unsigned int		: 0;
	unsigned int field3 : 3;
};

// ����stuff.field1��stuff.field2֮����һ��2Bits�Ŀ�϶��stuff.field3��洢����һ��unsigned int�У��ýṹ��СΪ3*32=96Bits

#include <iostream>

using namespace std;

int main() {
	struct stuff1 s = { 1,3,5 };
	cout << s.field1 << endl;
	cout << s.field2 << endl;
	cout << s.field3 << endl;
	cout << sizeof(s) << endl;

	return 0;
}