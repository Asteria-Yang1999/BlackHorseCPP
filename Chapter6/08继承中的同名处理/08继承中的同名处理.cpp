#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base func调用" << endl;
    }

    void func(int a)
    {
        cout << "Base func(int a)调用" << endl;
    }


    int m_A;
};

class Daughter:public Base
{
public:
    Daughter()
    {
        m_A = 200;
    }

//    void func()
//    {
//        cout << "Daughter func调用" << endl;
//    }


    int m_A;
};

void test01()
{
    Daughter d1;
    cout << d1.m_A << endl;
    //想 调用父类中的 m_A

    cout << d1.Base::m_A << endl;

    d1.func(10);

    //调用母类的func
    d1.Base::func();
}

//如果子类和母类拥有同名的函数，属性， 子类不会覆盖母类的成员
//如果子类和母类的成员函数名称相同，子类会把母类的所有的同名版本都隐藏掉
//想调用母类的方法，必须加作用域

int main()
{
    test01();
    return 0;
}
