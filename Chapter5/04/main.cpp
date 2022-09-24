#include <iostream>

using namespace std;

class MyInteger
{
    friend ostream & operator<< (ostream & os, const MyInteger & myInt);
public:
    MyInteger()
    {
        m_Num = 0;
    }

    //前置++重载
    MyInteger& operator++ ()
    {
        this->m_Num++;
        return *this;
    }

    //后置++重载   用占位参数区分
    MyInteger operator++ (int)
    {
        //先保存目前数据
        MyInteger tmp = *this;
        this->m_Num++;
        return tmp;
    }

    int m_Num;

};

ostream & operator<< (ostream & os, const MyInteger & myInt)
{
    cout << myInt.m_Num;
    return os;
}


void test01()
{
    MyInteger myInt;
//    ++myInt;      //前置++

    cout << ++myInt << endl;

//    myInt++;      //后置++
    cout << myInt++ << endl;

    cout << myInt << endl;

}

int main()
{
    test01();
    return 0;
}
