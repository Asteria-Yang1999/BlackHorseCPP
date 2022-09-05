#include <iostream>
using namespace std;

void mySwap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout << "mySwap::a = " << a << endl;
    cout << "mySwap::b = " << b << endl;
}

void test01()
{
    int a = 10;
    int b = 20;
    mySwap(a, b); //值传递：只做逻辑上的判断，不改变传递进去的值

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//地址传递
void mySwap2(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void test02()
{
    int a = 10;
    int b = 20;
    mySwap2(&a, &b); //地址传递

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用传递 类似传地址
void mySwap3(int &a, int &b)  //&a = a &b = b
{
    int tmp = a;
    a = b;
    b = tmp;
}
void test03()
{
    int a = 10;
    int b = 20;
    mySwap3(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 引用的注意事项
// 1. 引用必须引一块合法的内存空间
// 2. 不要返回局部变量的引用
// 3. 不能引用null

int& doWork()
{
    int a = 10;
    return a;
}

void test04()
{
    //int &a = 10; //引用必须引一块合法的内存空间

    int &ret = doWork();
    cout << "ret = " << ret << endl;  //warning: reference to local variable 'a' returned 
}

int& doWork2()
{
    static int a = 10;
    return a;
}

void test05()
{
    int &ret = doWork2();
    cout << "ret = " << ret << endl;  

    //如果函数的返回值是引用，那么这个函数调用可以作为左值
    doWork2() = 1000; //相当于写了a = 1000
    cout << "doWork2() = " << doWork2() << endl;  
}

int main() {

    // test01();
    // test02();
    // test03();
    // test04();
    test05();
    return EXIT_SUCCESS;
}