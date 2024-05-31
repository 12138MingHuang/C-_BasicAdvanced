//����ʹ��const

//��һ�����У��κβ����޸����ݳ�Ա�ĺ�����Ӧ������Ϊconst���͡�
//����ڱ�дconst��Ա����ʱ�������޸� ���ݳ�Ա�����ߵ�����������const��Ա��������������ָ�����������ɻ���߳���Ľ�׳�ԡ�
// ------------------------
//ʹ��const�ؼ��ֽ���˵���ĳ�Ա��������Ϊ����Ա������
//ֻ�г���Ա���������ʸ���������򳣶���û��ʹ��const�ؼ��ֽ���˵���ĳ�Ա����������������������


//�������е�const��Ա��������ͨ����ʼ���б���г�ʼ����������ʾ��
#include <iostream>
class Banana{
	private:
		int people[100];
	public:
		Banana(int a);
		const int banana_num;
};

Banana::Banana(int a) :banana_num(a) {
	//banana_num = a; //error const��Ա����ֻ���ڳ�ʼ���б��н��г�ʼ���������ڹ��캯���н��г�ʼ��
}
//��һ����Ĺ��캯��ʹ�ó�ʼ���б��ڵ�һ�����У����캯��ʹ���˳�ʼ���б�:a(i) ��ֱ�ӳ�ʼ����Ա���� a��
//����ζ���ڶ��󱻴���ʱ����Ա���� a ������������Ϊ���ݸ����캯����ֵ i��
//
//�ڶ�����Ĺ��캯���ں������ڸ�ֵ���ڵڶ������У����캯��û��ʹ�ó�ʼ���б������ڹ��캯���ĺ������ڸ�ֵ a = i��
//����ζ�Ŷ����ڹ�������Ȼᴴ�� a��Ȼ��Ż��ڹ��캯���ĺ������ڸ�����һ��ֵ��
//
//���������ַ�ʽ�ڹ������ǵ�Ч�ģ�������ĳЩ����¿��ܻ���΢С�����ܲ��졣
//ͨ������£�ʹ�ó�ʼ���б���Ը���Ч����Ϊ������ֱ�ӳ�ʼ����Ա������������Ҫ����ĸ�ֵ������
//
//���ԣ�ͨ������£������ڹ��캯����ʹ�ó�ʼ���б�����ʼ����Ա�������ر��Ƕ������а����������������͵ĳ�Ա����ʱ����������Ч�ʡ�
//����ĳЩ����£��������Ҫ���и����ӵ��߼�����ʼ����Ա����������ܻ�ѡ���ں������ڽ��г�ʼ����


// const����ֻ�ܷ���const��Ա����������const������Է�������ĳ�Ա����������const��Ա������
class Apple {
	private:
		int people[100];
	public:
		Apple(int a);
		const int apple_num;
		void take(int num) const;
		int add();
		int add(int num) const;
		int getCount() const;

		//static int ap = 5; //error ��̬��Ա�������������ڳ�ʼ���������������ʼ��
		static int ap1;
		static const int ap2 = 5; //��ȷ const���εľ�̬��Ա�������������ڳ�ʼ��
};
int Apple::ap1 = 5; //��ȷ ��̬��Ա�����������ʼ��

Apple::Apple(int a) :apple_num(a) {

}
int Apple::add(int num) const {
	take(num);
	return 0;
}
void Apple::take(int num) const {
	std::cout<< "take func" << num << std::endl;
}
int Apple::getCount() const {
	take(1);
	//add(); //error add��������const���Σ��������б���Ҳ����˵const��Ա����ֻ�ܷ���const��Ա������
	return apple_num;
}

int main() {
	Apple a(10);
	std::cout<< a.getCount() << std::endl;
	a.add(10);
	const Apple b(20);
	b.add(100);

	const Apple c(7);
	//c.add(); //error add��������const���Σ��������б���Ҳ����˵const����ֻ�ܷ���const��Ա������
	return 0;
}
