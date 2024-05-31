/**
 * @file derived_base.cpp
 * @brief using�Ļ���ʹ�� �ı������
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

// ��Detived˽�м̳�����Base����������˵��Ա����n�ͳ�Ա����size����˽�еģ����ʹ����using��䣬���Ըı����ǵĿɷ�����
// ���������ӣ�size���԰�public��Ȩ�޷��ʣ�n���԰�protect��Ȩ�޷���