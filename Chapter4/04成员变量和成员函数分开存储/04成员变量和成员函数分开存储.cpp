#include <iostream>

using namespace std;
//#pragma pack(1)    影响字节对齐方式

class Person
{
public:
    int m_A;    //非静态成员变量  属于对象身上
    void func() {};    //非静态成员函数， 不属于对象身上

    static int m_B;   //静态成员变量， 不属于对象身上
    static void func2() {};  //静态成员函数，不属于对象身上
    double m_C;    //非静态成员变量  16正确    字节对齐


};

//结论： 只有非静态成员变量，才属于对象身上

void test01()
{
    // 6    0    4    1
    cout << "size of (Person) = " << sizeof(Person) << endl;
    //空类的大小为1   每一个实例的对象都有独一无二的地址，char维护这个地址
    //Person p[10]    p[0] p[1] ……
}

void test02()
{
    //this指针指向被调用的成员函数所属的对象

    Person p1;
    p1.func();    //编译器会偷偷 加入一个 this指针 Person * this

    Person p2;
    p2.func();
}

int main()
{

    test01();
    return 0;
}
