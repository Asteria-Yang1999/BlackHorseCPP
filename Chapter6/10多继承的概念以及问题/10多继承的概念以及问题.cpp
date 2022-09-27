#include <iostream>

using namespace std;

class Base1
{
public:
    Base1()
    {
        m_A = 10;
    }
    int m_A;
};

class Base2
{
public:
    Base2()
    {
        m_A = 20;
    }
    int m_A;
};

//多继承
class Daughter:public Base1, public Base2
{
public:
    int m_C;
    int m_D;
};

//多继承中很容易引发二义性
void test01()
{
    cout << sizeof(Daughter) << endl;

    Daughter d1;
//    d1.m_A;  //二义性
    cout << d1.Base1::m_A << endl;
    cout << d1.Base2::m_A << endl;
}

int main()
{
    test01();
    return 0;
}
