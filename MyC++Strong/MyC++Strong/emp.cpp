/**
 * @file emp.cpp
 * @brief �麯�������ж�̬
 * @auther bin.zhang
 * @date 2024.04.29
 */

 //�麯���ĵ���ȡ����ָ��������õĶ�������ͣ�������ָ��������ñ��������

#include <iostream>
using namespace std;

class Employee {
	public:
		/**
		 * @brief ��н
		 */
		virtual void raiseSalary() { cout << 0 << endl; }
		
		/**
		 * @brief ��ְ
		 */
		virtual void promote() { }

		/**
		 * @brief ��н����
		 * @param[in] emp Ա������
		 * @param[in] n �����С
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

//ͬ�������ܻ����������͵�Ա��
//������Ҫһ���ǳ��򵥵ĺ�������������Ա���Ĺ���
//��ע�⣬emp[]��һ��ָ�����飬ʵ��ָ��Ķ������,���κ����͵�Ա������������£��˺���Ӧ��������
//����ʹ��ȫ�ֻ����Ա��ּ�
void globalRaiseSalary(Employee* emp[], int n) {
	for (int i = 0; i < n; i++) {
		emp[i]->raiseSalary();
	}
}

//��̬���ã�����raiseSalary����
//����ʵ�ʶ��󣬶�����ָ�������
int main() {
	Employee* emp[] = {new Employee(), new Manager(), new Engineer()};
	Employee::globalRaiseSalary(emp, 3);
	globalRaiseSalary(emp, 3);

	Employee::globalRaiseSalary(emp, sizeof(emp) / sizeof(emp[0]));
	globalRaiseSalary(emp, sizeof(emp) / sizeof(emp[0]));

	return 0;
}