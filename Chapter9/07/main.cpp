#include <iostream>
#include <string>
using namespace std;

void test01()
{
    //输入as 缓冲区中 a s 换行  第一个拿 a 第二个拿 s 第三次拿换行 第四次等待下次输入
    char c = cin.get();
    cout << "c = "  << c << endl;

    c = cin.get();
    cout << "c = "  << c << endl;

    c = cin.get();
    cout << "c = "  << c << endl;

    c = cin.get();
    cout << "c = "  << c << endl;
}

void test02()
{
    //cin.get(两个参数)   //可以读字符串
    char buf[1024];
    cin.get(buf, 1024);

    char c = cin.get();

    if (c == '\n')
    {
        cout << "换行还在缓冲区" << endl;
    }
    else
    {
        cout << "换行不在缓冲区" << endl;
    }
    cout << buf << endl;
}
//cin.get(两个参数)读取字符串时，不会把换行符拿走哦，遗留在缓冲区里

//cin.getline()
void test03()
{
    char buf[1024];
    cin.getline(buf, 1024);

    char c = cin.get();
    if (c == '\n')
    {
        cout << "换行还在缓冲区" << endl;
    }
    else
    {
        cout << "换行不在缓冲区" << endl;
    }
    //cin.getline 把换行符读取，并且扔掉
}

//cin.ignore() 忽略

void test04()
{
    cin.ignore(2);    //没有参数，代表忽略一个字符，带参数N，代表忽略N个字符

    char c = cin.get();

    cout << "c = " << c << endl;
}

//cin.peek() 偷窥
void test05()
{
    //输入as 偷看一眼a，然后再放回缓冲区 缓冲区中还是as
    char c = cin.peek();
    cout << "c = " << c << endl;
    c = cin.get();
    cout << "c = " << c << endl;
}

//cin.putback() 放回
void test06()
{
    char c = cin.get();
    cin.putback(c);

    char buf[1024];
    cin.getline(buf, 1024);
    cout << buf << endl;
}

//案例1 判断用户输入的是字符串 还是数字？
void test07()
{
    cout << "请输入一串数字或者字符串：" << endl;

    //偷窥
    char c = cin.peek();

    if (c >= '0' && c <= '9')
    {
        int num;
        cin >> num;
        cout << "您输入的是数字，数字为" << num << endl;
    }
    else
    {
        char buf[1024];
        cin >> buf;
        cout << "您输入的是字符串，字符串为" << buf << endl;
    }
}

//案例2 让用户输入1 到 10的数字，如果输入有误 重新输入
void test08()
{
    int num;

    cout << "请输入一个1到10的数字" << endl;

    while (true)
    {
        cin >> num;
        if (num > 0 && num <= 10)
        {
            cout << "输入的数字为" << num << endl;
            break;
        }
//        cout << "对不起，请重新输入" << endl;
//重置标志位
        cin.clear();
        cin.sync();    //清空缓冲区
//        cout << "标志位：" << cin.fail() << endl;    //标志位0是正常的， 1是不正常的
    }
}

int main() {
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
//    test07();
    test08();
    return 0;

}
