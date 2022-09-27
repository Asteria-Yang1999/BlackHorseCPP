#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base默认构造函数调用" << endl;
    }
    ~Base()
    {
        cout << "Base析构函数调用" << endl;
    }
};

class Daughter:public Base
{
public:
    Daughter()
    {
        cout << "Daughter默认构造函数调用" << endl;
    }
    ~Daughter()
    {
        cout << "Daughter析构函数调用" << endl;
    }
};

//子类会继承母亲的成员属性，成员函数
//但是子类不会继承母类的构造函数和析构函数
//只有母类自己知道如何构造和析构自己的属性，而子类不知道

void test01()
{
//    Base b1;
    Daughter d1;
}

class Base2
{
public:
    Base2(int a)
    {
        this->m_A = a;
        cout << "有参构造函数调用" << endl;
    }
    int m_A;
};

class Daughter2:public Base2
{
public:
    Daughter2(int a) : Base2(a)   //利用初始化列表方式 显式调用 有参构造
    {

    }
};

void test02()
{
    Daughter2 d2(1000);
}

int main()
{
    test01();
    return 0;
}
