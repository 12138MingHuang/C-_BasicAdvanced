class A {
public:
	void f1(int x); //声明后，要想成为内联函数，必须在定义时加上inline关键字

	void Foo(int x, int y) {

	}; //内联函数的定义要放在类的内部，类内部定义的函数自动成为内联函数，不需要inline关键字

	void f2(int x); //声明后，要想成为内联函数，必须在定义时加上inline关键字
};
