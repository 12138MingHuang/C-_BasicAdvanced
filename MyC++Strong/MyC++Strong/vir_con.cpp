/**
 * @file vir_con.cpp
 * @brief ���캯����������λ�麯����ͬ�ǳ���inline��explicit֮�⣬���캯������ʹ�������κιؼ���
 *
 * Ϊʲô���캯���������麯����
 *
 * �����麯����vtable�ڱ���׶ξ��Ѿ������ģ���ָ���麯�����ָ��vptr�������н׶�ʵ��������ʱ�Ų����ġ�
 * ����ຬ���麯�������������ڹ��캯������Ӵ�������ʼ��vptr��
 * �������ˣ�������캯�����麯������ô����Ҫvptr������vtable�������ʱ��vptr��û�г�ʼ������ô��η���vtable�أ�
 * ��ˣ����캯���������麯����
 * ���ܹ��캯�����������麯����������Щ��������ȷʵ��Ҫ"Virtual Copy Constructor"
 * "�鸴�ƹ��캯��"��˵�������Ͻ�����ֻ��һ�������ֻ��һ��ʵ���˶����ƵĹ��ܵ����ں���
 * ��һ��Ӧ�ó�����������а幦��
 * ����������Ϊ���࣬����������ܰ������֣�ͼƬ����Ƶ��
 * ����ֻ���ڳ������е�ʱ�����֪��������Ҫ���Ƶľ�����ʲô���͵�����
 * @auther bin.zhang
 * @date 2024.04.30
 */

#include <iostream>

using namespace std;

class Base {
public:
	Base() {}

	virtual ~Base() {}

	virtual void ChangeAttributes() = 0;

	static Base* Create(int id);

	virtual Base* Clone() = 0;
};

class Derived1 : public Base {
public:
	Derived1() { cout << "Derived1 Created" << endl; }

	Derived1(const Derived1& rhs) { cout << "Derived1 Copied" << endl; }

	~Derived1() { cout << "Derived1 Destroyed" << endl; }

	void ChangeAttributes() { cout << "Derived1 Attributes Changed" << endl; }

	Base* Clone() { return new Derived1(*this); }
};

class Derived2 : public Base {
public:
	Derived2() { cout << "Derived2 Created" << endl; }

	Derived2(const Derived2& rhs) { cout << "Derived2 Copied" << endl; }

	~Derived2() { cout << "Derived2 Destroyed" << endl; }

	void ChangeAttributes() { cout << "Derived2 Attributes Changed" << endl; }

	Base* Clone() { return new Derived2(*this); }
};

class Derived3 : public Base {
public:
	Derived3() { cout << "Derived3 Created" << endl; }

	Derived3(const Derived3& rhs) { cout << "Derived3 Copied" << endl; }

	~Derived3() { cout << "Derived3 Destroyed" << endl; }

	void ChangeAttributes() { cout << "Derived3 Attributes Changed" << endl; }

	Base* Clone() { return new Derived3(*this); }
};

Base* Base::Create(int id) {
	if (id == 1) {
		return new Derived1;
	}
	else if (id == 2) {
		return new Derived2;
	}
	else {
		return new Derived3;
	}
}

class User {
public:
	User() : pBase(0) {//�����ʼ��Ϊ 0 ��ʾ��������Ϊ��ָ�룬����ָ���κζ���
		int input;

		cout << "Please Enter ID (1, 2 or 3): ";
		cin >> input;

		while ((input != 1) && (input != 2) && (input != 3)) {
			cout << "Invalid Input. Please Enter ID (1, 2 or 3): ";
			cin >> input;
		}

		pBase = Base::Create(input);
	}

	~User() {
		if (pBase) {
			delete pBase;
			pBase = 0;
		}
	}

	void Action() {
		Base* pNewBase = pBase->Clone();
		pNewBase->ChangeAttributes();
		delete pNewBase;
	}

private:
	Base* pBase;
};

int main() {
	User* user = new User;
	user->Action();
	delete user;

	return 0;
}