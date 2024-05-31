/**
 * @file using_typedef.cpp
 * @brief using的基本使用 取代typedef
 * @auther bin.zhang
 * @date 2024.05.17
 */

// C中常用typedef A B 这样的语法，将B定义为A类型，也就是给A类型起了一个别名B
// 对应typedef A B，使用using B = A 可以达到相同的效果

// typedef vector<int> Vec_Int;
// using Vec_Int = vector<int>;