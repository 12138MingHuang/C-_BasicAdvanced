/**
 * @file emp.cpp
 * @brief 虚函数与运行多态
 * @auther bin.zhang
 * @date 2024.04.29
 */

 //虚函数的调用取决于指向或者引用的对象的类型，而不是指针或者引用本身的类型

#include <iostream>
using namespace std;

class Employee {
	public:
		/**
		 * @brief 加薪
		 */
		virtual void raiseSalary() { cout << 0 << endl; }
		
		/**
		 * @brief 升职
		 */
		virtual void promote() { }

		/**
		 * @brief 加薪函数
		 * @param[in] emp 员工数组
		 * @param[in] n 数组大小
		 */
		static void globalRaiseSalary(Employee* emp[], int n) {
			for (int i = 0; i < n; i++) {
				emp[i]->raiseSalary();
			}
		}
};

class Manager : public Employee {
	public:
		virtual void raiseSalary() { cout << 100 << endl; }

		virtual void promote() { }
};

class Engineer : public Employee {
	public:
		virtual void raiseSalary() { cout << 200 << endl; }

		virtual void promote() { }
};

//同样，可能还有其他类型的员工
//我们需要一个非常简单的函数来增加所有员工的工资
//请注意，emp[]是一个指针数组，实际指向的对象可以,是任何类型的员工。理想情况下，此函数应该在类中
//我们使其全局化，以保持简单
void globalRaiseSalary(Employee* emp[], int n) {
	for (int i = 0; i < n; i++) {
		emp[i]->raiseSalary();
	}
}

//多态调用：调用raiseSalary（）
//根据实际对象，而根据指针的类型
int main() {
	Employee* emp[] = {new Employee(), new Manager(), new Engineer()};
	Employee::globalRaiseSalary(emp, 3);
	globalRaiseSalary(emp, 3);

	Employee::globalRaiseSalary(emp, sizeof(emp) / sizeof(emp[0]));
	globalRaiseSalary(emp, sizeof(emp) / sizeof(emp[0]));

	return 0;
}