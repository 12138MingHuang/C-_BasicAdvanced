//thisָ��
//��1��һ�������thisָ�벢���Ƕ������һ���֣�����Ӱ��sizeof(����)�Ľ����
//��2��this�������������ڲ���������ķǾ�̬��Ա�����з�����ķǾ�̬��Ա��ʱ�򣬱��������Զ���������ĵ�ַ��Ϊһ�������������ݸ�������
//Ҳ����˵����ʹ��û��д��thisָ�룬�������ڱ����ʱ��Ҳ�Ǽ���this�ģ�����Ϊ�Ǿ�̬��Ա�����������βΣ��Ը���Ա�ķ��ʾ�ͨ��this���С�

//thisָ���ʹ�ã�
//��1������ķǾ�̬��Ա�����з�����������ʱ��ֱ��ʹ�� return *this��
//��2�����������Ա��������ͬʱ����this->n = n ������д��n = n)��

#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	typedef enum {
		BOY = 0,
		GIRL
	} SexType;
	/*ʹ�� strcpy ����ʱ������һ��������󣬴�����Ϣ�ᵽ strcpy ���ܲ���ȫ������ʹ�� strcpy_s��
	������Ϊ strcpy ��C++�б���Ϊ�ǲ���ȫ�ģ���Ϊ��û�б߽��飬���ܵ��»����������
	strcpy_s ��C11��׼����İ�ȫ�汾���ַ�������������
	�����ھ������μ��� #pragma warning(disable : 4996) ���ƹ��˾���*/
	//#pragma warning(disable : 4996)  // ����C4996����
	Person(const char* n, int a, SexType s) {
		//Ϊ name ��Ա���������ڴ棬strlen(n) + 1 ��Ϊ�˴洢�ַ��� n �������Լ��ַ�����β�Ŀ��ַ� '\0'��
		//��C�ַ����У��ַ����Կ��ַ� '\0' ��β��������ַ���ʾ�ַ����Ľ����������������������ַ����ĳ����ڡ�
		//strlen �������ڼ����ַ����ĳ��ȣ�����������β�Ŀ��ַ���
		//��ˣ�������Ϊ�洢�ַ�������������ڴ�ʱ��������Ҫ�����һ���ֽ����洢��β�Ŀ��ַ� '\0'��
		//���� + 1 ��Ŀ����Ϊ��ȷ��������ڴ��㹻�������������ַ��������Լ���β�Ŀ��ַ���
		name = new char[strlen(n) + 1]; //����д��this->name = new char[strlen(n) + 1];
		//ʹ�� strcpy_s ���������� n ָ����ַ��������� name ��Ա������ָ����ڴ��С�
		strcpy_s(name, strlen(n) + 1, n);
		//strcpy(name, n);
		age = a;
		sex = s;
	}
	//#pragma warning(default : 4996)  // �ָ�C4996����
	int get_age() const {
		return this->age;
	}
	Person& add_age(int a) {
		age += a;
		return *this;
	}
	~Person() {
		delete[]name;
	}

private:
	char* name;
	int age;
	SexType sex;
};

int main() {
	Person p("ZhangSan", 20, Person::BOY);
	cout << p.get_age() << endl;
	cout << p.add_age(5).get_age() << endl;
	return 0;
}

//�ܽ᣺this�ڳ�Ա�����Ŀ�ʼִ��ǰ���죬�ڳ�Ա��ִ�н����������
//������get_age�����ᱻ������get_age(const A* const this), add_age�����ᱻ������add_age(A* const this, int a)��
//��C++����ͽṹ��ֻ��һ������ģ���ĳ�ԱĬ����private�����ṹ��public��this�����ָ�룬������ɽṹ����this���ǽṹ��ָ���ˡ�