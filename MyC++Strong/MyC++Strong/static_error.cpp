/**
 * @file static_error.cpp
 * @brief ��̬��������������Ϊ�麯����ͬʱ���ܱ�const(������Ա����)��volatile��const volatile����
 * ԭ�����£�
 * static��Ա�����������κ���������ʵ�������Լ�ʹ���˺�������virtual�ؼ���Ҳû���κ����塣
 * �麯������vptr��vtable������vptr��һ��ָ�룬����Ĺ��캯���д������ɣ�����ֻ����thisָ�����������̬��Ա����û��thisָ�룬�����޷�����vptr��
 * @auther bin.zhang
 * @date 2024.04.30
 */

class Base {
	public:
		//virtual static void fun() {} //error ���Ǿ�̬��Ա���������������
		//static void fun() const {} //error ��̬��Ա�����ϲ�����ʹ�������޶���
};