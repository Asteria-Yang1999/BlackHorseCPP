#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

//公有继承
class Daughter:public Base1
{
public:
    void func()
    {
//        cout << m_C << endl;    //基类中私有的属性 不可继承
        cout << m_A << endl;    //基类中的公有属性 可继承，还是public
        cout << m_B << endl;    //基类中保护的属性 可继承 还是protected
    }

};

void myFunc()
{
    Daughter d1;
    d1.m_A;
//    d1.m_B;
}

///////////////////////////////////////////保护继承
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Daughter2:protected Base2
{
public:
    void func()
    {
//        cout << m_C << endl;    //基类中私有的属性 不可继承
        cout << m_A << endl;    //基类中公有的属性 可继承 还是protected
        cout << m_B << endl;    //基类中保护的属性 可继承 还是protected
    }
};

void myFunc2()
{
    Daughter2 d;
//    d.m_A;    //不能访问
//    d.m_B;
}

//////////////////////////私有继承
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Daughter3:private Base3
{
public:
    void func()
    {
//        cout << m_C << endl;    //基类中私有的属性 不可继承
        cout << m_A << endl;    //基类中公有的属性 可继承 还是private
        cout << m_B << endl;    //基类中保护的属性 可继承 还是private
    }
};

class GrandDaughter3:public Daughter3
{
public:
    void myFunc()
    {
/*        cout << m_A << endl;    //在孙女类中 访问不到m_A,因为在Daughter3中m_A已经是私有属性了
        cout << m_B << endl;*/
    }
};

int main() {

    return 0;
}
