#include <iostream>

using namespace std;

//分类
//按照参数进行分类  无参构造函数（默认构造函数）    有参构造函数
//按照类型进行分类  普通构造函数      拷贝构造函数

class Person
{
public:    //构造和析构必须写在public下才可调用到

    Person()   //默认    无参构造函数
    {
        cout << "默认构造函数的调用" << endl;
    }

    Person(int a)
    {
        cout << "有参构造函数的调用" <<endl;
    }

    //拷贝构造函数
    Person(const Person& p)
    {
        m_Age = p.m_Age;
        cout << "拷贝构造函数的调用" << endl;
    }

    ~Person()
    {
        cout << "析构函数的调用" << endl;
    }

    int m_Age;
};

void test01()
{
//    //构造函数调用方式
//    //括号法调用
//    Person p1(1);   //有参
//    p1.m_Age = 10;
//    Person p2(p1);    //拷贝
//
//    cout << "p2的年龄" << p2.m_Age << endl;

//    Person p3;    //默认构造函数不要加（）

//    Person p3();   //编译器以为这行是函数的声明

    //显示法调用
    Person p4 = Person(100);
    Person p5 = Person(p4);

//    Person(100);//叫匿名对象  匿名对象的特点：如果编译器发现对象是匿名的，那么在这行代码结束之后就释放

    //不能用拷贝构造函数 初始化匿名构造对象

//    Person p6 = Person(p5);   //如果写成左值，编译器认为你写成了Person p5，是对象的声明。如果写成右值，可以

    Person p7 = 100;   //相当于调用了Person p7 = Person(100), 隐式类型转换

    Person p8 = p7;    //相当于Person p8 = Person(p7),


//cout << "aaaaaa" << endl;

}

int main()
{
    test01();

    return 0;
}
