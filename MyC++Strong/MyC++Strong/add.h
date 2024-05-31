#ifndef  ADD_H
#define ADD_H
int add(int x, int y);
#endif


// 而通常为了C代码能够通用，即既能被C调用，又能被C++调用，头文件通常会有如下写法：
//#ifdef __cplusplus
//extern "C" {
//#endif
//	int add(int x, int y);
//#ifdef __cplusplus
//}
//#endif