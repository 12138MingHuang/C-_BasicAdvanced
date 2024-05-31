/**
 * @file define2.cpp
 * @brief 宏定义
 * @auther bin.zhang
 * @date 2024.05.31
 */

// do{...}while(0)的使用

//#define fun() f1();f2();
//if (a > 0)
//fun()
//
//// 这个宏被展开后就是：
//if (a > 0)
//f1();
//f2();
//
//// 本意是a > 0执行f1 f2，而实际是f2每次都会执行，所以就错误了。
//// 为了解决这种问题，在写代码的时候，通常可以采用{}块。
//#define fun() {f1();f2();}
//if (a > 0)
//fun();
//// 宏展开
//if (a > 0)
//{
//    f1();
//    f2();
//};

// 但是会发现上述宏展开后多了一个分号，实际语法不太对。(虽然编译运行没问题，正常没分号)。


// 避免使用goto控制流
// 在一些函数中，我们可能需要在return语句之前做一些清理工作，比如释放在函数开始处由malloc申请的内存空间，使用goto总是一种简单的方法：

//int f() {
//    int* p = (int*)malloc(sizeof(int));
//    *p = 10;
//    cout << *p << endl;
//#ifndef DEBUG
//    int error = 1;
//#endif
//    if (error)
//        goto END;
//    // dosomething
//END:
//    cout << "free" << endl;
//    free(p);
//    return 0;
//}

// 但由于goto不符合软件工程的结构化，而且有可能使得代码难懂，所以很多人都不倡导使用
// 这个时候我们可以使用do{...}while(0)来做同样的事情：

//int ff() {
//    int* p = (int*)malloc(sizeof(int));
//    *p = 10;
//    cout << *p << endl;
//    do {
//#ifndef DEBUG
//        int error = 1;
//#endif
//        if (error)
//            break;
//        //dosomething
//    } while (0);
//    cout << "free" << endl;
//    free(p);
//    return 0;
//}

// 这里将函数主体部分使用do{...}while(0)包含起来，使用break来代替goto
// 后续的清理工作在while之后，现在既能达到同样的效果，而且代码的可读性、可维护性都要比上面的goto代码好的多了。


// 避免由宏引起的警告

// 内核中由于不同架构的限制，很多时候会用到空宏，。
// 在编译的时候，这些空宏会给出warning，为了避免这样的warning，我们可以使用do{...}while(0)来定义空宏：

#define EMPTYMICRO do{}while(0)


// 定义单一的函数块来完成复杂的操作
// 如果你有一个复杂的函数，变量很多，而且你不想要增加新的函数，可以使用do{...}while(0)，
// 将你的代码写在里面，里面可以定义变量而不用考虑变量名会同函数之前或者之后的重复。 
// 这种情况应该是指一个变量多处使用（但每处的意义还不同），我们可以在每个do-while中缩小作用域，比如：

//int fc()
//{
//    int k1 = 10;
//    cout << k1 << endl;
//    do {
//        int k1 = 100;
//        cout << k1 << endl;
//    } while (0);
//    cout << k1 << endl;
//}