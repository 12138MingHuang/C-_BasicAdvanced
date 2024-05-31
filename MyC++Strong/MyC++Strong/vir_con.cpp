/**
 * @file vir_con.cpp
 * @brief 构造函数不能声明位虚函数。同是除了inline和explicit之外，构造函数不能使用其他任何关键字
 *
 * 为什么构造函数不能是虚函数？
 *
 * 尽管虚函数表vtable在编译阶段就已经建立的，但指向虚函数表的指针vptr是在运行阶段实例化对象时才产生的。
 * 如果类含有虚函数，编译器会在构造函数中添加代码来初始化vptr。
 * 问题来了，如果构造函数是虚函数，那么塔需要vptr来访问vtable，可这个时候vptr还没有初始化，那么如何访问vtable呢？
 * 因此，构造函数不能是虚函数。
 * 尽管构造函数不可以是虚函数，但是有些场景我们确实需要"Virtual Copy Constructor"
 * "虚复制构造函数"的说法并不严谨，其只是一个概念，其只是一个实现了对象复制的功能的类内函数
 * 举一个应用场景，比如剪切板功能
 * 复制内容作为基类，但派生类可能包含文字，图片，视频。
 * 我们只有在程序运行的时候才能知道我们需要复制的具体是什么类型的数据
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
	User() : pBase(0) {//将其初始化为 0 表示将其设置为空指针，即不指向任何对象。
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