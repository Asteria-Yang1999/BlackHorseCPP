#include <iostream>

using namespace std;

class Base
{
public:
    static void func()
    {
        cout << "Base func()" << endl;
    }
    static void func(int a)
    {
        cout << "Base func(int)" << endl;
    }

    static int m_A;
};

int Base::m_A = 10;

class Daughter:public Base
{
public:
    static void func()
    {
        cout << "Daughter func()" << endl;
    }
    static void func(int a)
    {
        cout << "Daughter func(int)" << endl;
    }

    static int m_A;
};
int Daughter::m_A = 20;

//静态成员属性 子类可以继承下来
void test01()
{
    cout << Daughter::m_A << endl;
    //访问母类的m_A
    cout << Base::m_A << endl;

    Daughter::func();
    //通过子类访问母类中同名的函数
    Daughter::Base::func(10);

}

int main()
{
    test01();
    return 0;
}
