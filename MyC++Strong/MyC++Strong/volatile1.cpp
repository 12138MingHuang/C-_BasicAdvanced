/**
 * @file volatile1.cpp
 * @brief volatile应用
 * @auther bin.zhang
 * @date 2024.04.30
 */

//被volatile修饰的变量，在对其进行读写操作时，会引发一些可观测的副作用，而这些可观测的副作用，是由程序之外的因素决定的。
//被volatile修饰的变量，编译器不会对其进行优化，每次都会从内存中读取

//(1) 并行设备的硬件寄存器(如状态寄存器)。假设要对一个设备进行初始化，此设备的某一个寄存器0xff800000

#include <iostream>


int* output = reinterpret_cast<int*>(0xff800000);//定义一个IO端口
int init(void) {
	int i;
	for (i = 0; i < 10; i++) {
		*output = i;
	}
}

//经过编译器优化后，编译器认为前面循环半天都是废话，对最后的结果毫无影响，
//因为最终只是将output这个指针赋值为 9，所以编译器最后给你编译编译的代码结果相当于：

int init(void) {
	*output = 9;
}

//如果你对此外部设备进行初始化的过程是必须是像上面代码一样顺序的对其赋值，显然优化过程并不能达到目的。
//反之如果你不是对此端口反复写操作，而是反复读操作，其结果是一样的，编译器在优化后，也许你的代码对此地址的读操作只做了一次。
//然而从代码角度看是没有任何问题的。这时候就该使用volatile通知编译器这个变量是一个不稳定的，在遇到此变量时候不要优化。
volatile int* output = reinterpret_cast<volatile int*>(0xff800000);





//(2) 一个中断服务子程序中访问到的变量；
static int i = 0;
void dosomething() {
	std::cout << "Doing something..." << std::endl;
}
int main() {
	while (1) {
		if (i) dosomething();
	}
}
//中断服务子程序
void IRS() {
	i = 1;
}

//上面示例程序的本意是产生中断时，由中断服务子程序IRS响应中断，变更程序变量i，使在main函数中调用dosomething函数，
//但是，由于编译器判断在main函数里面没有修改过i，因此可能只执行一次对从i到某寄存器的读操作，
//然后每次if判断都只使用这个寄存器里面的“i副本”，导致dosomething永远不会被调用。
//如果将变量i加上volatile修饰，则编译器保证对变量i的读写操作都不会被优化，从而保证了变量i被外部程序更改后能及时在原程序中得到感知。

//在这种情况下，i 变量被主程序和中断服务子程序共享。主程序中的 while 循环会不断地检查 i 的值，
//如果 i 变为非零，则调用 dosomething()。而中断服务子程序 IRS() 中将 i 设为 1，
//意味着在某个时间点上，中断服务子程序将触发主程序执行 dosomething()。
//然而，编译器可能会对主程序中的 if (i) 进行优化，认为 i 的值在主程序的执行过程中没有改变过（因为中断服务子程序的执行是由硬件中断触发的，
//与主程序的执行没有直接关系），从而导致主程序永远无法触发 dosomething()。

//为了避免这种优化，我们可以使用 volatile 关键字修饰 i，告诉编译器 i 是一个可能被外部程序更改的变量，不要对其进行优化。
static volatile int i = 0;




//(3) 多线程应用中被多个线程共享的变量；
//当多个线程共享某一个变量时，该变量的值会被某一个线程更改，应该用 volatile 声明。
//作用是防止编译器优化把变量从内存装入CPU寄存器中，当一个线程更改变量后，未及时同步到其它线程中导致程序出错。
//volatile的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值。

volatile bool bStop = false;  //bStop变量在多线程中被共享
//线程1
void Thread1() {
	while (!bStop) {
		//do something
	}
}

//线程2,终止上面的线程循环
void Thread2() {
	//do something
	bStop = true;
}

//要想通过第二个线程终止第一个线程循环，如果bStop不使用volatile定义，那么这个循环将是一个死循环，
//因为bStop已经读取到了寄存器中，寄存器中bStop的值永远不会变成FALSE，加上volatile，程序在执行时，
//每次均从内存中读出bStop的值，就不会死循环了。

//是否了解volatile的应用场景是区分C / C++程序员和嵌入式开发程序员的有效办法，搞嵌入式的家伙们经常同硬件、中断、RTOS等等打交道，
//这些都要求用到volatile变量，不懂得volatile将会带来程序设计的灾难。

#include <iostream>
#include <thread>
#include <chrono>

volatile bool bStop = false;  // bStop变量在多线程中被共享

// 线程1：持续检查bStop状态
void Thread1() {
    while (!bStop) {
        std::cout << "Thread1 is running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1秒钟的延迟
    }
    std::cout << "Thread1 is stopping..." << std::endl;
}

// 线程2：在一定条件下设置bStop为true，终止线程1的循环
void Thread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // 3秒钟的延迟
    std::cout << "Thread2 is setting bStop to true..." << std::endl;
    bStop = true;
}

int main() {
    // 创建两个线程
    std::thread t1(Thread1);
    std::thread t2(Thread2);

    // 等待两个线程完成
    t1.join();
    t2.join();

    std::cout << "Main thread is exiting..." << std::endl;

    return 0;
}
