/**
 * @file struct_class.cpp
 * @brief C++�е�struct����
 * struct���ʺϿ�����һ�����ݽṹ��ʵ���壬class���ʺϿ�����һ�������ʵ����
 * ��ʵ�һ���������Ĭ�ϵķ��ʿ���
 * structĬ����public�ģ�classĬ����private��
 * struct��Ϊ���ݽṹ��ʵ���壬��Ĭ�ϵ����ݷ��ʿ�����public�ģ���class��Ϊ�����ʵ���壬��Ĭ�ϵĳ�Ա�������ʿ�����private��
 * @auther bin.zhang
 * @date 2024.05.14
 */

#include <iostream>

using namespace std;

struct DataStruct {
    int publicMember1;
    int publicMember2;

    void display() {
        std::cout << "publicMember1: " << publicMember1 << std::endl;
        std::cout << "publicMember2: " << publicMember2 << std::endl;
    }
};

class DataClass {
    int privateMember1; // Ĭ����private
    int privateMember2; // Ĭ����private

public:
    void setMembers(int value1, int value2) {
        privateMember1 = value1;
        privateMember2 = value2;
    }

    void display() {
        std::cout << "privateMember1: " << privateMember1 << std::endl;
        std::cout << "privateMember2: " << privateMember2 << std::endl;
    }
};

int main() {
    DataStruct ds;
    ds.publicMember1 = 10; // ֱ�ӷ���public��Ա
    ds.publicMember2 = 20; // ֱ�ӷ���public��Ա
    ds.display(); // ����public��Ա����

    DataClass dc;
    //dc.privateMember1 = 10; // ����privateMember1��private�ģ�����ֱ�ӷ���
    // dc.privateMember2 = 20; // ����privateMember2��private�ģ�����ֱ�ӷ���
    dc.setMembers(10, 20); // ͨ��public��Ա��������private��Ա
    dc.display(); // ����public��Ա����
}
