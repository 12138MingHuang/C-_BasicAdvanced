/**
 * @file classic_practice.cpp
 * @brief �ӳ������߼���enum��Щ��
 * ������Ϊ
 * ������������޴�����������ͻ�����һ���򵥷����ǣ���ö�ٱ�������ʱ����ǰ׺����COLOR_BLUE��FEELING_BLUE
 * һ����˵��Ϊ��һ�������ǻ�����г���ͳһ����ǰ׺��������������ö�ٱ����Ĵ�����Ե���׸��
 * C���Գ����п��ܲ��ò�������������C++����Ͳ�ϲ���������ķ�������������������ռ�
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

// ����֮��Ϳ�����Color::Type c = Color::Red;������ö�ٱ����ˡ����using namespace Color��ǰ׺������ʡȥ��ʹ�ô�����Ӽ��
// ��������Ϊ�����ռ��ǿ�������������ݵģ��������ṩ�����������Բ��ߣ��ڴ���Ŀ�У������п��ܲ�ͬ�˸���ͬ�Ķ�����ͬ����ö��������
// ����Ч�İ취��ͬһ�����ṹ�����޶������������磺�����±����ķ��������������ռ����ͬ��
// ���������Ͳ��õ������ڱ𴦱��޸����ݣ������ýṹ������࣬����Ϊ����ϣ����Щ�������Թ������ʡ�

struct Color1 {
	enum Type {
		Red,
		Blue,
		Green
	};
};


// C++11�е�ö����
// �������������˵�һ�����⣬�����ں�����������Ϊ����C++11��������ö���࣬�������Щ���⡣
// �µ�enum������������ȫ�ֵģ����������ڲ��������Ͳ�������������ͻ�ˡ�
// ������ʽת������������

/**
 * @brief ö����
 * ����ȼ���enum class Color2:int
*/
enum class Color2 {
	Red = 2,
	Yellow,
	Blue
};

// ����ָ�����ض����������洢enum
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