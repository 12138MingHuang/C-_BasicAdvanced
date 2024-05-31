// const常量在不同文件的访问

extern const int ext = 12;

//可以发现未被const修饰的变量不需要extern显式声明！
//而const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。