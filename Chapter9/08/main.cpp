#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>    //使用控制符的头文件
using namespace std;

void test01()
{
//    cout.put('a').put('b');

    char buf[1024] = "hello world";
    cout.write(buf, strlen(buf));
}

void test02()
{
    //通过流成员函数

    int number = 99;
    cout.width(20);
    cout.fill('*');
    cout.setf(ios::left);   //设置格式，输出内容左对齐
    cout.unsetf(ios::dec);    //卸载十进制
    cout.setf(ios::hex);    //安装十六进制
    cout.setf(ios::showbase);    //强制输出整数基数 0   0x
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);    //安装八进制
    cout << number << endl;
}

//控制符的方式显示
void test03()
{
    int number = 99;
    cout << setw(20)
         << setfill('^')
         << setiosflags(ios::showbase)  //基数
         << setiosflags(ios::left)    //左对齐
         << hex    //十六进制
         << number
         << endl;
}

int main() {
//    test01();
//    test02();
    test03();
    return 0;
}
