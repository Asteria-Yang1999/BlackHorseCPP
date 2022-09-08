#include <iostream>

using namespace std;

//定义一个加法
#define MyAdd(x, y)  ((x) + (y))

void test01()
{
    int ret = MyAdd(10, 20) *20; //预期结果 600   10+20*20

    cout << "ret = " << ret << endl;
}

#define MyCompare(a, b) ((a) < (b) ? (a) : (b))

inline void mycompare(int a, int b)
{
    int ret = a < b ? a : b;
    cout << "ret ::::: " << ret << endl;
}

//1.内联函数的注意事项
//类内部的成员函数 默认前面会加inline关键字
inline void func(); //内联函数声明
inline void func() {}; //如果函数实现时候，没有加inline关键字，那么这个函数依然不算内联函数

void test02()
{
    int a = 10;
    int b = 20;

    // int ret = MyCompare(++a, b);   // 预期结果：11  ((a++) < (b) ? (a++) : (b))
    // cout << "ret = " << ret << endl;

    mycompare(++a, b);
}

int main()
{
    test02();

    return 0;
}


//内联函数相当于用空间换时间，省去调用函数入栈出栈的损耗，直接执行内联函数内部的代码

/*内联函数里不能存在任何形式的循环语句
不能存在过多的条件判断语句
函数体不能过于庞大
不能对函数进行取址操作

内联函数 解决宏缺陷问题

内联仅仅是给编译器一个建议，编译器不一定接受
一个好的编译器会内联小的、简单的函数
*/
