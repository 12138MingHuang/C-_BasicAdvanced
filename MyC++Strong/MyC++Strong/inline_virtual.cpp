//虚函数可以是内联函数吗？
//1. 虚函数是可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
//2. 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时候不能内联。
//3. inline virtual唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如Base::who()），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

#include <iostream>
 using namespace std;

 class Base {
 public:
	 inline virtual void who() {
		 cout << "I am Base\n";
	 }
	 virtual ~Base() {}
 };

 class Derived :public Base {
 public:
	 inline void who() { // 不写inline时隐式内联
	 		 cout << "I am Derived\n";
	 }
 };

 int main() {
	 // 此处的虚函数who(),是通过类Base的具体对象b来调用的，编译期间就能确定了，所以它是可以内联的，但最终是否会内联取决于编译器。
	 Base b;
	 b.who(); // 调用基类函数

	 Derived d;
	 d.who(); // 调用派生类函数,同理能够内联

	 // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能内联。
	 Base *ptr = new Derived(); // Base指针指向派生类
	 ptr->who(); // 调用基类函数

	 // 因为Base有虚析构函数，所以delete的时候，会先调用派生类的析构函数，再调用基类的析构函数，防止内存泄漏。
	 delete ptr;
	 ptr = nullptr;

	 return 0;
 }