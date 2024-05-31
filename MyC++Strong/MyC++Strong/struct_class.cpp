/**
 * @file struct_class.cpp
 * @brief C++中的struct与类
 * struct更适合看成是一个数据结构的实现体，class更适合看成是一个对象的实现体
 * 最本质的一个区别就是默认的访问控制
 * struct默认是public的，class默认是private的
 * struct作为数据结构的实现体，它默认的数据访问控制是public的，而class作为对象的实现体，它默认的成员变量访问控制是private的
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
    int privateMember1; // 默认是private
    int privateMember2; // 默认是private

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
    ds.publicMember1 = 10; // 直接访问public成员
    ds.publicMember2 = 20; // 直接访问public成员
    ds.display(); // 调用public成员函数

    DataClass dc;
    //dc.privateMember1 = 10; // 错误：privateMember1是private的，不能直接访问
    // dc.privateMember2 = 20; // 错误：privateMember2是private的，不能直接访问
    dc.setMembers(10, 20); // 通过public成员函数访问private成员
    dc.display(); // 调用public成员函数
}
