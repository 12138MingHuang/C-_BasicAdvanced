//类中使用const

//在一个类中，任何不会修改数据成员的函数都应该声明为const类型。
//如果在编写const成员函数时，不慎修改 数据成员，或者调用了其它非const成员函数，编译器将指出错误，这无疑会提高程序的健壮性。
// ------------------------
//使用const关键字进行说明的成员函数，称为常成员函数。
//只有常成员函数才有资格操作常量或常对象，没有使用const关键字进行说明的成员函数不能用来操作常对象。


//对于类中的const成员变量必须通过初始化列表进行初始化，如下所示：
#include <iostream>
class Banana{
	private:
		int people[100];
	public:
		Banana(int a);
		const int banana_num;
};

Banana::Banana(int a) :banana_num(a) {
	//banana_num = a; //error const成员变量只能在初始化列表中进行初始化，不能在构造函数中进行初始化
}
//第一个类的构造函数使用初始化列表：在第一个类中，构造函数使用了初始化列表:a(i) 来直接初始化成员变量 a。
//这意味着在对象被创建时，成员变量 a 会立即被设置为传递给构造函数的值 i。
//
//第二个类的构造函数在函数体内赋值：在第二个类中，构造函数没有使用初始化列表，而是在构造函数的函数体内赋值 a = i。
//这意味着对象在构造后，首先会创建 a，然后才会在构造函数的函数体内赋予它一个值。
//
//尽管这两种方式在功能上是等效的，它们在某些情况下可能会有微小的性能差异。
//通常情况下，使用初始化列表可以更高效，因为它可以直接初始化成员变量，而不需要额外的赋值操作。
//
//所以，通常情况下，建议在构造函数中使用初始化列表来初始化成员变量，特别是对于类中包含非内置数据类型的成员变量时，这可以提高效率。
//但在某些情况下，如果你需要进行更复杂的逻辑来初始化成员变量，你可能会选择在函数体内进行初始化。


// const对象只能访问const成员函数，而非const对象可以访问任意的成员函数，包括const成员函数。
class Apple {
	private:
		int people[100];
	public:
		Apple(int a);
		const int apple_num;
		void take(int num) const;
		int add();
		int add(int num) const;
		int getCount() const;

		//static int ap = 5; //error 静态成员变量不能在类内初始化，必现在类外初始化
		static int ap1;
		static const int ap2 = 5; //正确 const修饰的静态成员变量可以在类内初始化
};
int Apple::ap1 = 5; //正确 静态成员变量在类外初始化

Apple::Apple(int a) :apple_num(a) {

}
int Apple::add(int num) const {
	take(num);
	return 0;
}
void Apple::take(int num) const {
	std::cout<< "take func" << num << std::endl;
}
int Apple::getCount() const {
	take(1);
	//add(); //error add方法并非const修饰，所以运行报错。也就是说const成员函数只能访问const成员函数。
	return apple_num;
}

int main() {
	Apple a(10);
	std::cout<< a.getCount() << std::endl;
	a.add(10);
	const Apple b(20);
	b.add(100);

	const Apple c(7);
	//c.add(); //error add方法并非const修饰，所以运行报错。也就是说const对象只能访问const成员函数。
	return 0;
}
