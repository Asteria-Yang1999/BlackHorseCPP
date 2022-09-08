//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "test.h"

using namespace std;

//c++中想调用c语言方法

// extern "C" void show();  //show方法按照c语言方法连接
//解决的问题就是，在C++中调用c语言的函数
int main()
{

    show();   //一个无法解析的外部命令：链接不到函数或方法
    //在c++中，函数是可以发生重载的，编译器会把这个函数名称偷偷改变。

    return EXIT_SUCCESS;
}
