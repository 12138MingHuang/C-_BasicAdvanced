//限定访问范围

//source1.cpp
extern void sayHello();
const char* msg = "Hello World!\n";

int main() {
	sayHello();
	return 0;
}

//g++对于上面两个代码文件是可以正常编译并且打印Hello World!，
//但如果给source1.cpp中的msg加上static，则会导致undefined reference to 'msg'的编译错误：