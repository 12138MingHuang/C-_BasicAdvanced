//��̬��Ա


//(1)�����Ϊ��̬
//�������һ��������Ҳ������Ϊstaticʱ���з�Χ��ֱ��������������ڡ�

//�������£����ж����ǷǾ�̬�ġ�
#include <iostream>
using namespace std;

class Apple {
	int i;
	public:
		Apple() {
			i = 0;
			cout << "Inside Constructor\n";
		}
		~Apple() {
			cout << "Inside Destructor\n";
		}
};

int main() {
	int x = 0;
	if (x == 0) {
		Apple obj;
	}
	cout << "End of main\n";
}
// �����
//Inside Constructor
//Inside Destructor
//End of main
//������ĳ����У�������if��������Ϊ�Ǿ�̬����ˣ������ķ�Χ����if���ڡ�
//��ˣ�����������ʱ�������ù��캯����������if��Ŀ���ȨԽ������������ͬʱ���ã���Ϊ����ķ�Χ������������if���ڡ�


//������ǽ���������Ϊ��̬
class Banana {
	int i;
	public:
		Banana() {
			i = 0;
			cout << "Inside Constructor\n";
		}
		~Banana() {
			cout << "Inside Destructor\n";
		}
};

int main() {
	int x = 0;
	if (x == 0) {
		static Banana obj;
	}
	cout << "End of main\n";
}
// �����
//Inside Constructor
//End of main
//Inside Destructor
//���ڣ���main�������������������������Ϊ��̬����ķ�Χ�ǹᴩ������������ڡ�


//���еľ�̬��Ա����
//�������еľ�̬���ݳ�Ա��̬����һ������̬��Ա����Ҳ����������Ķ���
//���Ǳ�����ʹ�ö����'.'�����þ�̬��Ա������������ʹ�������ͷ�Χ������������þ�̬��Ա��
//����̬��Ա���������ʾ�̬���ݳ�Ա��������̬��Ա�����������޷�������ķǾ�̬���ݳ�Ա���Ա������

class Apple {
	public:
		void print() {
			cout << "Hello";
		}
		static void printMsg() {
			//print(); //error ��̬��Ա�������ܵ��÷Ǿ�̬��Ա����
			cout << "Welcome to Apple!\n";
		}
};

int main() {
	Apple obj;
	obj.printMsg();// Ҳ����ʹ�ö�����ã������Ƽ�

	Apple::printMsg();// �Ƽ���ʽ
	return 0;

	//1.������⣺ͨ��ʹ������������ȷ�ر�������һ����̬��Ա������������ʵ��������
	//2.����Ŀɶ��ԣ�����������ߴ���Ŀɶ��ԣ���Ϊ����ȷ��ָʾ����һ����̬����������Ҫһ������Ķ�������������
	//3.���ⲻ��Ҫ�Ķ��󴴽��������ʹ�ö��������þ�̬��Ա��������ᴴ��һ����ʱ��������ܻ����벻��Ҫ�Ŀ����͸����ԡ�
}
// �����
//Welcome to Apple!
//Welcome to Apple!
